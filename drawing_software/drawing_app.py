import sys
import pygame
import ctypes
import math
from PIL import Image
import numpy as np
import time
import subprocess

ctypes.windll.shcore.SetProcessDpiAwareness(True)
pygame.init()
fps = 60
fpsClock = pygame.time.Clock()

canvasSize = [800, 800]
buttonAreaWidth = 200
width, height = canvasSize[0] + buttonAreaWidth, canvasSize[1]
screen = pygame.display.set_mode((width, height), pygame.RESIZABLE)

font = pygame.font.SysFont('Arial', 20)
objects = []
lines = []
current_line = []
images = []

user_input = ''
drawColor = [0, 0, 0]
brushSize = 10

drawingEnabled = True
polygons = []
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
        self.rect.w = max(200, self.txt_surface.get_width() + 10)

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

def save():
    file_name_orig = "canvas" + str(int(time.time())) + ".png"
    pygame.image.save(canvas, file_name_orig)
    img = Image.open(file_name_orig).convert("L").resize((50, 50), Image.LANCZOS)
    img.save("50x50img.png")
    binary_array = (np.array(img) < 128).astype(np.uint8).flatten()
    packed_bits = np.packbits(binary_array)
    file_name_bin = str(int(time.time())) + "_data.bin"
    with open(file_name_bin, "wb") as f:
        f.write(packed_bits.tobytes())

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

def draw_polygon():
    try:
        sides = int(input_box1[0].get_value())
        polygons.append(Polygon((canvasSize[0] // 2, canvasSize[1] // 2), sides, 100))
    except ValueError:
        print("Invalid polygon sides")

def draw_circle():
    pygame.draw.circle(canvas, drawColor, [400, 400], 50)

def clear():
    canvas.fill((255, 255, 255))
    polygons.clear()
    lines.clear()

Button(25, 25, 160, 35, 'Polygon', draw_polygon)
label_y = 60
screen_label = font.render("Insert no of sides", True, (255, 255, 255))
input_box1 = [InputBox(25, label_y + 30, 160, 25)]

for i, (btn_name, func) in enumerate([('Circle', draw_circle), ('Save', save), ('Clear', clear)]):
    Button(25, 120 + i * 60, 160, 35, btn_name, func)

slider = Slider((25, 320))
canvas = pygame.Surface(canvasSize)
canvas.fill((255, 255, 255))

while True:
    screen.fill((30, 30, 30))
    for obj in objects: obj.process()

    canvas.fill((255, 255, 255))
    for poly in polygons: poly.draw(canvas)
    for line in lines:
        if len(line) >= 2:
            pygame.draw.lines(canvas, drawColor, False, line, brushSize)
    if len(current_line) >= 2:
        pygame.draw.lines(canvas, drawColor, False, current_line, brushSize)
    for img in images:
        img.draw(canvas)

    screen.blit(canvas, (buttonAreaWidth, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit(); sys.exit()
        for box in input_box1: box.handle_event(event)
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

        if event.type == pygame.MOUSEBUTTONUP:
            if len(current_line) > 1: lines.append(current_line)
            current_line, selected_vertex, selected_polygon = [], None, None
            for img in images: img.stop_drag()

        if event.type == pygame.MOUSEMOTION:
            mx, my = pygame.mouse.get_pos()
            if mx > buttonAreaWidth:
                for img in images:
                    img.drag((mx - buttonAreaWidth, my))

        if event.type == pygame.DROPFILE:
            try:
                img_surface = pygame.image.load(event.file).convert_alpha()
                images.append(Images(img_surface, (0, 0)))
            except Exception as e:
                print(f"Could not load image: {e}")

    for box in input_box1:
        box.update()
        box.draw(screen)
    screen.blit(screen_label, (25, label_y))

    slider.draw(screen)
    brushSize = slider.get_value()

    if drawingEnabled and pygame.mouse.get_pressed()[0]:
        mx, my = pygame.mouse.get_pos()
        if mx > buttonAreaWidth and selected_vertex is None:
            dx, dy = mx - buttonAreaWidth, my
            if not current_line or math.hypot(dx - current_line[-1][0], dy - current_line[-1][1]) > brushSize / 2:
                current_line.append((dx, dy))

    if selected_polygon and selected_vertex is not None:
        mx, my = pygame.mouse.get_pos()
        selected_polygon.move_vertex(selected_vertex, (mx - buttonAreaWidth, my))

    pygame.display.flip()
    fpsClock.tick(fps)
