import sys
import pygame
import ctypes
import math
from PIL import Image
import numpy as np
import time
import win32gui
import win32con
import socket

HOST = '192.168.2.99'
PORT = 9005

MAX_RETRIES = 3
RETRY_DELAY = 2  # seconds

python_win_title = "BarrierDrawingApplication"
unity_win_title = "Fluid_Simulation_Test"

ctypes.windll.shcore.SetProcessDpiAwareness(True)
pygame.init()
fps = 60
fpsClock = pygame.time.Clock()

canvasSize = [800, 800]
buttonAreaWidth = 200
width, height = canvasSize[0] + buttonAreaWidth, canvasSize[1]
screen = pygame.display.set_mode((width, height), pygame.RESIZABLE)

font = pygame.font.SysFont('Lato', 30)

pygame.display.set_caption(python_win_title)
pygame.display.flip() # force window creation

# Wait a moment for windows to be created
time.sleep(1)

# Find your Python window (Pygame window) by class name or title
def find_window(title):
    hwnd = win32gui.FindWindow(None, title)
    if hwnd == 0:
        print(f"Window '{title}' not found")
    return hwnd

hwnd_python = find_window(python_win_title)
hwnd_unity = find_window(unity_win_title)

if hwnd_python != 0 and hwnd_unity != 0:
    uw_style = win32gui.GetWindowLong(hwnd_unity, win32con.GWL_STYLE)
    uw_style |= win32con.WS_CLIPCHILDREN
    win32gui.SetWindowLong(hwnd_unity, win32con.GWL_STYLE, uw_style)
    
    # force Unity to reapply its styles
    win32gui.SetWindowPos(hwnd_unity, None, 0, 0, 0, 0, win32con.SWP_NOMOVE | win32con.SWP_NOSIZE | win32con.SWP_FRAMECHANGED)

    # make Pygame window visible and unminimized
    win32gui.ShowWindow(hwnd_python, win32con.SW_RESTORE)
    win32gui.UpdateWindow(hwnd_python)

    # make unity parent
    win32gui.SetParent(hwnd_python, hwnd_unity)

    # pygame window clipping and visible flags
    child_style = win32gui.GetWindowLong(hwnd_python, win32con.GWL_STYLE)
    child_style &= ~(win32con.WS_CAPTION | win32con.WS_THICKFRAME)
    child_style |= (win32con.WS_CHILD | win32con.WS_VISIBLE | win32con.WS_CLIPSIBLINGS | win32con.WS_CLIPCHILDREN | win32con.WS_TABSTOP)
    win32gui.SetWindowLong(hwnd_python, win32con.GWL_STYLE, child_style)
    win32gui.SetWindowPos(hwnd_python, win32con.HWND_TOP, 2980, 1020, 800, 800, win32con.SWP_SHOWWINDOW | win32con.SWP_NOACTIVATE | win32con.SWP_FRAMECHANGED)
    win32gui.BringWindowToTop(hwnd_python)
else:
    print("Could not find one or both windows")

#append all classes here
objects = []
lines = [{"points": [], "width": 0}]
current_line = []
images = []
polygons = []
rectangles = []
circles = []

user_input = ''
drawColor = [0, 0, 0]
brushSize = 10

drawingEnabled = True
selected_vertex = None
selected_polygon = None

class Button():
    def __init__(self, x, y, width, height, buttonText='Button', onclickFunction=None, onePress=False):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.onclickFunction = onclickFunction
        self.onePress = onePress
        self.fillColors = {'normal': '#ffffff', 'hover': '#666666', 'pressed': '#333333'}
        self.buttonSurface = pygame.Surface((self.width, self.height))
        self.buttonRect = pygame.Rect(self.x, self.y, self.width, self.height)
        self.buttonSurf = font.render(buttonText, True, (20, 20, 20))
        self.alreadyPressed = False
        objects.append(self)

    def process(self):
        mousePos = pygame.mouse.get_pos()
        self.buttonSurface.fill(self.fillColors['normal'])
        if self.buttonRect.collidepoint(mousePos):
            self.buttonSurface.fill(self.fillColors['hover'])
            if pygame.mouse.get_pressed(num_buttons=3)[0]:
                self.buttonSurface.fill(self.fillColors['pressed'])
                if self.onePress:
                    self.onclickFunction()
                elif not self.alreadyPressed:
                    self.onclickFunction()
                    self.alreadyPressed = True
            else:
                self.alreadyPressed = False
        self.buttonSurface.blit(self.buttonSurf, [
            self.buttonRect.width / 2 - self.buttonSurf.get_rect().width / 2,
            self.buttonRect.height / 2 - self.buttonSurf.get_rect().height / 2
        ])
        screen.blit(self.buttonSurface, self.buttonRect)

class InputBox:
    def __init__(self, x, y, w, h, text=''):
        self.rect = pygame.Rect(x, y, w, h)
        self.width = 160
        self.color = pygame.Color("#ffffff")
        self.text = text
        self.txt_surface = font.render(text, True, self.color)
        self.active = False

    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            self.active = self.rect.collidepoint(event.pos)
        if event.type == pygame.KEYDOWN and self.active:
            if event.key == pygame.K_BACKSPACE:
                self.text = self.text[:-1]
            else:
                self.text += event.unicode
            self.txt_surface = font.render(self.text, True, self.color)

    def update(self):
        self.rect.w = self.width

    def draw(self, screen):
        screen.blit(self.txt_surface, (self.rect.x + 5, self.rect.y + 5))
        pygame.draw.rect(screen, self.color, self.rect, 2)

    def get_value(self):
        return self.text

class Slider:
    def __init__(self, position, width=150, height=20, min_val=1, max_val=50, start_val=10, label="Brush Size"):
        self.x, self.y = position
        self.width = width
        self.height = height
        self.min_val = min_val
        self.max_val = max_val
        self.value = start_val
        self.label = label
        self.handle_radius = 8
        self.dragging = False

    def get_value(self):
        return int(self.value)

    def draw(self, screen):
        pygame.draw.rect(screen, (200, 200, 200), (self.x, self.y + self.height // 2 - 2, self.width, 4))
        handle_x = self.x + int((self.value - self.min_val) / (self.max_val - self.min_val) * self.width)
        pygame.draw.circle(screen, '#ffffff', (handle_x, self.y + self.height // 2), self.handle_radius)
        label_surf = font.render(f"{self.label}: {self.get_value()}", True, (255, 255, 255))
        screen.blit(label_surf, (self.x, self.y - 25))

    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            mx, my = event.pos
            handle_x = self.x + int((self.value - self.min_val) / (self.max_val - self.min_val) * self.width)
            if abs(mx - handle_x) <= self.handle_radius and abs(my - (self.y + self.height // 2)) <= self.handle_radius:
                self.dragging = True
        elif event.type == pygame.MOUSEBUTTONUP:
            self.dragging = False
        elif event.type == pygame.MOUSEMOTION and self.dragging:
            mx = max(self.x, min(event.pos[0], self.x + self.width))
            self.value = self.min_val + (mx - self.x) / self.width * (self.max_val - self.min_val)


class Polygon:
    def __init__(self, center, sides, radius):
        self.center = center
        self.sides = sides
        self.radius = radius
        self.points = self.calculate_points()

    def calculate_points(self):
        angle = 2 * math.pi / self.sides
        return [(self.center[0] + self.radius * math.cos(i * angle),
                 self.center[1] + self.radius * math.sin(i * angle)) for i in range(self.sides)]

    def draw(self, surface):
        pygame.draw.polygon(surface, drawColor, self.points, 0)

    def get_vertex_at_pos(self, pos, radius=10):
        for i, (x, y) in enumerate(self.points):
            if math.hypot(pos[0] - x, pos[1] - y) < radius:
                return i
        return None

    def move_vertex(self, index, new_pos):
        self.points[index] = new_pos

class Images:
    def __init__(self, img_surface, pos=(0, 0)):
        self.orig_image = img_surface
        self.pos = list(pos)
        self.SF = 1
        self.dragging = False
        self.drag_offset = (0, 0)
        self.update_scaled()

    def update_scaled(self):
        w, h = self.orig_image.get_size()
        self.image = pygame.transform.scale(self.orig_image, (int(w * self.SF), int(h * self.SF)))
        self.rect = self.image.get_rect(topleft=self.pos)

    def start_drag(self, mouse_pos):
        if self.rect.collidepoint(mouse_pos):
            self.dragging = True
            self.drag_offset = (mouse_pos[0] - self.pos[0], mouse_pos[1] - self.pos[1])
            return True
        return False

    def drag(self, mouse_pos):
        if self.dragging:
            self.pos = [mouse_pos[0] - self.drag_offset[0], mouse_pos[1] - self.drag_offset[1]]
            self.update_scaled()

    def stop_drag(self):
        self.dragging = False

    def draw(self, surface):
        surface.blit(self.image, self.pos)

class Rectangle:
    def __init__(self, pos, size=(100, 60)):
        self.pos = list(pos)  # Top-left corner
        self.size = size
        self.dragging = False
        self.drag_offset = (0, 0)
        self.rect = pygame.Rect(self.pos, self.size)

    def draw(self, surface):
        self.rect.topleft = self.pos
        pygame.draw.rect(surface, drawColor, self.rect)
        pygame.draw.rect(surface, (0, 0, 0), self.rect, 2)  # Optional black border

    def start_drag(self, mouse_pos):
        if self.rect.collidepoint(mouse_pos):
            self.dragging = True
            self.drag_offset = (mouse_pos[0] - self.pos[0], mouse_pos[1] - self.pos[1])
            return True
        return False

    def drag(self, mouse_pos):
        if self.dragging:
            self.pos = [mouse_pos[0] - self.drag_offset[0], mouse_pos[1] - self.drag_offset[1]]

    def stop_drag(self):
        self.dragging = False

class Circle:
    def __init__(self, pos, radius):
        self.pos = list(pos)  # center of circle
        self.radius = radius
        self.dragging = False
        self.drag_offset = (0, 0)
        self.rect = pygame.Rect(self.pos[0] - radius, self.pos[1] - radius, radius * 2, radius * 2)

    def draw(self, surface):
        pygame.draw.circle(surface, drawColor, self.pos, self.radius)
        self.rect = pygame.Rect(self.pos[0] - self.radius, self.pos[1] - self.radius, self.radius * 2, self.radius * 2)

    def start_drag(self, mouse_pos):
        if self.rect.collidepoint(mouse_pos):
            self.dragging = True
            self.drag_offset = (mouse_pos[0] - self.pos[0], mouse_pos[1] - self.pos[1])
            return True
        return False

    def drag(self, mouse_pos):
        if self.dragging:
            self.pos = [mouse_pos[0] - self.drag_offset[0], mouse_pos[1] - self.drag_offset[1]]

    def stop_drag(self):
        self.dragging = False



def draw_polygon():
    try:
        sides = int(input_box1[0].get_value())
        polygons.append(Polygon((canvasSize[0] // 2, canvasSize[1] // 2), sides, 100))
    except ValueError:
        print("Invalid polygon sides")

def draw_rectangle():
    width = int(input_box3[0].get_value())
    height = int(input_box4[0].get_value())
    rect = Rectangle((canvasSize[0] // 2, canvasSize[1] // 2), (width, height))
    rectangles.append(rect) 

def draw_circle():
    radius = int(input_box2[0].get_value())
    circle = Circle((canvasSize[0] // 2, canvasSize[1] // 2), radius)
    circles.append(circle)

#clear canvas
def clear():
    canvas.fill((255, 255, 255))
    polygons.clear()
    lines.clear()
    images.clear()
    circles.clear()
    rectangles.clear()


MAX_RETRIES = 3
RETRY_DELAY = 2  # seconds

def save():
    file_name_orig = "canvas" + str(int(time.time())) + ".png"
    pygame.image.save(canvas, file_name_orig)

    # Downsize image and convert to binary
    img = Image.open(file_name_orig).convert("L").resize((50, 50), Image.LANCZOS)
    img.save("50x50img.png")

    binary_array = (np.array(img) < 128).astype(np.uint8).flatten()
    packed_bits = np.packbits(binary_array)

    # Store for reference
    file_name_bin = str(int(time.time())) + "_data.bin"
    with open(file_name_bin, "wb") as f:
        f.write(packed_bits.tobytes())

    return packed_bits.tobytes()

def send():
    data = save()  # Get packed image data
    for attempt in range(MAX_RETRIES):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                print(f"Attempt {attempt + 1}/{MAX_RETRIES}: Connecting to {HOST}:{PORT}...")
                s.settimeout(10)
                s.connect((HOST, PORT))
                print("Connection established")

                s.sendall(data)
                print(f"Sent {len(data)} bytes")
                break  # Success
        except socket.timeout:
            print("Connection timed out")
        except ConnectionRefusedError:
            print("Connection refused - is the server running?")
        except Exception as e:
            print(f"Connection error: {e}")
        
        if attempt < MAX_RETRIES - 1:
            print(f"Retrying in {RETRY_DELAY} seconds...")
            time.sleep(RETRY_DELAY)
    else:
        print("Failed to connect after retries")

    return data.tobytes()

def send():
    data = save()  # Get packed image data
    for attempt in range(MAX_RETRIES):
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                print(f"Attempt {attempt + 1}/{MAX_RETRIES}: Connecting to {HOST}:{PORT}...")
                s.settimeout(10)
                s.connect((HOST, PORT))
                print("Connection established")

                s.sendall(data)
                print(f"Sent {len(data)} bytes")
                break  # Success
        except socket.timeout:
            print("Connection timed out")
        except ConnectionRefusedError:
            print("Connection refused - is the server running?")
        except Exception as e:
            print(f"Connection error: {e}")
        
        if attempt < MAX_RETRIES - 1:
            print(f"Retrying in {RETRY_DELAY} seconds...")
            time.sleep(RETRY_DELAY)
    else:
        print("Failed to connect after retries")



Button(25, 25, 160, 35, 'Polygon', draw_polygon)
screen_label = font.render("Insert no of sides", True, (255, 255, 255))
input_box1 = [InputBox(25, 100, 50, 25)]

Button(25, 140, 160, 35, 'Circle', draw_circle)
screen_label2 = font.render("Radius", True, (255, 255, 255))
input_box2 = [InputBox(25, 210, 10, 25)]

for i, (btn_name, func) in enumerate([('Save', send), ('Clear', clear)]):
    Button(25, 250 + i * 60, 160, 35, btn_name, func)

Button(25, 370, 160, 35, 'Rectangle', draw_rectangle)
screen_label3 = font.render("Width", True, (255, 255, 255))
input_box3 = [InputBox(25, 440, 10, 25)]

screen_label4 = font.render("Height", True, (255, 255, 255))
input_box4 = [InputBox(25, 510, 10, 25)]

slider = Slider((25, 580))
canvas = pygame.Surface(canvasSize)
canvas.fill((255, 255, 255))

while True:
    screen.fill((30, 30, 30))
    for obj in objects: obj.process()

    canvas.fill((255, 255, 255))
    for poly in polygons: poly.draw(canvas)
    for line in lines:
        if len(line["points"]) >= 2:
            pygame.draw.lines(canvas, drawColor, False, line["points"], line["width"])
    if len(current_line) >= 2:
        pygame.draw.lines(canvas, drawColor, False, current_line, brushSize)
    for img in images:
        img.draw(canvas)
    for rect in rectangles:
        rect.draw(canvas)
    for circle in circles:
        circle.draw(canvas)

    screen.blit(canvas, (buttonAreaWidth, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit(); sys.exit()
        for box in input_box1: box.handle_event(event)
        for box in input_box2: box.handle_event(event)
        for box in input_box3: box.handle_event(event)
        for box in input_box4: box.handle_event(event)
        slider.handle_event(event)

        if event.type == pygame.MOUSEBUTTONDOWN and pygame.mouse.get_pressed()[0]:
            mx, my = pygame.mouse.get_pos()
            if mx > buttonAreaWidth:
                pos = (mx - buttonAreaWidth, my)
                for poly in polygons:
                    idx = poly.get_vertex_at_pos(pos)
                    if idx is not None:
                        selected_vertex, selected_polygon = idx, poly
                        break
                for img in reversed(images):
                    if img.start_drag((mx - buttonAreaWidth, my)):
                        break
                for rect in rectangles:
                    if rect.start_drag((mx - buttonAreaWidth, my)):
                        break
                for circle in circles:
                    if circle.start_drag((mx - buttonAreaWidth, my)):
                        break

        if event.type == pygame.MOUSEBUTTONUP:
            if len(current_line) > 1: lines.append({"points": current_line[:], "width": brushSize})
            
            current_line, selected_vertex, selected_polygon = [], None, None
            for img in images: img.stop_drag()
            for rect in rectangles: rect.stop_drag()
            for circle in circles: circle.stop_drag()

        if event.type == pygame.MOUSEMOTION:
            mx, my = pygame.mouse.get_pos()
            if mx > buttonAreaWidth:
                for img in images:
                    img.drag((mx - buttonAreaWidth, my))
                for rect in rectangles:
                    rect.drag((mx - buttonAreaWidth, my))
                for circle in circles:
                    circle.drag((mx - buttonAreaWidth, my))

        if event.type == pygame.DROPFILE:
            try:
                img_surface = pygame.image.load(event.file).convert_alpha()
                images.append(Images(img_surface, (0, 0)))
            except Exception as e:
                print(f"Could not load image: {e}")

    for box in input_box1:
        box.update()
        box.draw(screen)
    screen.blit(screen_label, (25, 70))

    for box in input_box2:
        box.update()
        box.draw(screen)
    screen.blit(screen_label2, (25, 190))

    for box in input_box3:
        box.update()
        box.draw(screen)
    screen.blit(screen_label3, (25, 420))

    for box in input_box4:
        box.update()
        box.draw(screen)
    screen.blit(screen_label4, (25, 490))


    slider.draw(screen)
    brushSize = slider.get_value()

    drawingEnabled = not any(rect.dragging for rect in rectangles) and not any(img.dragging for img in images) and not any(circle.dragging for circle in circles)


    if drawingEnabled and pygame.mouse.get_pressed()[0]:
        mx, my = pygame.mouse.get_pos()
        if mx > buttonAreaWidth and selected_vertex is None:
            dx, dy = mx - buttonAreaWidth, my
            if not current_line or math.hypot(dx - current_line[-1][0], dy - current_line[-1][1]) > brushSize / 2:
                current_line.append((dx, dy))
                circles.append(Circle((dx, dy), (brushSize * 0.95)//2))

    if selected_polygon and selected_vertex is not None:
        mx, my = pygame.mouse.get_pos()
        selected_polygon.move_vertex(selected_vertex, (mx - buttonAreaWidth, my))

    pygame.display.flip()
    fpsClock.tick(fps)