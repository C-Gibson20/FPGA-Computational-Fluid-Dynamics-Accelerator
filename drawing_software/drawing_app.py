import sys
import pygame
import ctypes
import math
from PIL import Image
import numpy as np
import time

ctypes.windll.shcore.SetProcessDpiAwareness(True)

# Pygame Configuration
pygame.init()
fps = 60
fpsClock = pygame.time.Clock()

canvasSize = [800, 800]

# Window size 
buttonAreaWidth = canvasSize[0]/4  # Space for buttons
width, height = canvasSize[0] + buttonAreaWidth, canvasSize[1]
screen = pygame.display.set_mode((width, height), pygame.RESIZABLE | pygame.DROPFILE | pygame.HWSURFACE | pygame.DOUBLEBUF)

font = pygame.font.SysFont('Lato', 30)


# Our Buttons will append themselves to this list
objects = []

#store lines here
lines = []

# Store all drawn points here
points = []

#store moved polygons here
dragging_poly = []

#store cirlces here
circles = set()

#store objects being moved here
active_object = []

# Initial color
drawColor = [0, 0, 0]

# Initial brush size
brushSize = 10

# Store drawn polygons
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

        self.fillColors = {
            'normal': '#ffffff',
            'hover': '#666666',
            'pressed': '#333333',
        }

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
        if event.type == pygame.KEYDOWN:
            if self.active:
                if event.key == pygame.K_RETURN:
                    pass
                elif event.key == pygame.K_BACKSPACE:
                    self.text = self.text[:-1]
                else:
                    self.text += event.unicode
                self.txt_surface = font.render(self.text, True, self.color)

    def update(self):
        width = max(200, self.txt_surface.get_width() + 10)
        self.rect.w = width

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
            mx = event.pos[0]
            mx = max(self.x, min(mx, self.x + self.width))
            self.value = self.min_val + (mx - self.x) / self.width * (self.max_val - self.min_val)

class Polygon:
    def __init__(self, center, sides, radius):
        self.center = center
        self.sides = sides
        self.radius = radius
        self.points = self.calculate_points()

    def calculate_points(self):
        angle = 2 * math.pi / self.sides
        return [
            (
                self.center[0] + self.radius * math.cos(i * angle),
                self.center[1] + self.radius * math.sin(i * angle)
            ) for i in range(self.sides)
        ]

    def draw(self, surface):
        pygame.draw.polygon(surface, drawColor, self.points, 0)

    def get_vertex_at_pos(self, pos, radius=10):
        for i, (x, y) in enumerate(self.points):
            if math.hypot(pos[0] - x, pos[1] - y) < radius:
                return i
        return None
    
    def move_polygon(self, dx, dy):
        self.center[0] += dx
        self.center[1] += dy
        self.points = self.calculate_points()

    def move_vertex(self, index, new_pos):
        self.points[index] = new_pos

    #def expand(self, )

def draw_polygon():
    try:
        sides = int(input_box1[0].get_value())
        poly = Polygon((canvasSize[0] // 2, canvasSize[1] // 2), sides, 100)
        polygons.append(poly)
    except ValueError:
        print("Invalid input for polygon sides")

def draw_circle():
    circle_point = (400, 400)
    circles.add(circle_point)

def save():
    file_name_orig = "canvas" + str(int(time.time())) + ".png"
    pygame.image.save(canvas, file_name_orig)

    img = Image.open(file_name_orig).convert("L")
    img_resized = img.resize((50, 50), Image.LANCZOS)
    img_resized.save("50x50img.png")

    img_array = np.array(img_resized)
    binary_array = (img_array < 128).astype(np.uint8)

    flat_arr = binary_array.flatten()
    packed_bits = np.packbits(flat_arr)  

    file_name_bin = str(int(time.time())) + "_data.bin"
    with open(file_name_bin, "wb") as f:
        f.write(packed_bits.tobytes())

def clear():
    canvas.fill((255, 255, 255))
    polygons.clear()
    points.clear()
    circles.clear()

# Setup buttons
buttonWidth = 160
buttonHeight = 35
buttonMargin = 25

buttons = [
    ['Polygon', draw_polygon],
    ['Circle', draw_circle],
    ['Save', save],
    ['Clear', clear]
]

for index, buttonName in enumerate(buttons):
    Button(buttonMargin, buttonMargin + index * (buttonHeight + buttonMargin), buttonWidth, buttonHeight, buttonName[0], buttonName[1])

num_buttons = len(buttons)
input_box_y = buttonMargin + num_buttons * (buttonHeight + buttonMargin)
input_box1 = [InputBox(buttonMargin, input_box_y, buttonWidth, 25)]

slider_y = input_box_y + 60
slider = Slider((buttonMargin, slider_y))

canvas = pygame.Surface(canvasSize)
canvas.fill((255, 255, 255))

drawingEnabled = True

# Game loop
while True:
    screen.fill((30, 30, 30))

    for obj in objects:
        obj.process()

    #canvas.fill((255, 255, 255))
    for poly in polygons:
        poly.draw(canvas)

    for line in lines:
        if(len(points) >= 2):
            pygame.draw.lines(canvas,drawColor,False,points,brushSize)

    # for point in points:
    #     pygame.draw.circle(canvas, drawColor, point, brushSize)


    for circle_point in circles:
        pygame.draw.circle(canvas, drawColor, circle_point, 50)


    screen.blit(canvas, (buttonAreaWidth, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        for box in input_box1:
            box.handle_event(event)

        slider.handle_event(event)

        #draw or move polygon vertex when pressed
        if event.type == pygame.MOUSEBUTTONDOWN:
            if pygame.mouse.get_pressed()[0]:
                mx, my = pygame.mouse.get_pos()
                if mx > buttonAreaWidth:
                    pos = (mx - buttonAreaWidth, my)
                    for poly in polygons:
                        idx = poly.get_vertex_at_pos(pos)
                        if idx is not None:
                            selected_vertex = idx
                            selected_polygon = poly
                            break
                        elif math.hypot(pos[0] - mx, pos[1] - my) < poly.radius:
                            dragging_poly = poly
                            start_point = pos
                            break


        if event.type == pygame.MOUSEMOTION:
            if dragging_poly and start_point:
                mx, my = pygame.mouse.get_pos()
                new_pos = (mx - buttonAreaWidth, my)
                dx = new_pos[0] - start_point[0]
                dy = new_pos[1] - start_point[1]
                dragging_poly.move_polygon(dx, dy)
                start_point = new_pos 


        if event.type == pygame.MOUSEBUTTONUP:
            selected_vertex = None
            selected_polygon = None
            dragging_poly = None
            start_point = None
            if len(points) > 1:
                lines.append(points[:])
            points.clear()

        #drag and drop image into canvas
        if event.type == pygame.DROPFILE:
            path = event.file
            img = pygame.image.load(path)
            img = pygame.transform.scale(img, canvasSize)
            canvas.blit(img, (0, 0))


    for box in input_box1:
        box.update()
        box.draw(screen)

    slider.draw(screen)
    brushSize = slider.get_value()

#draw
    if pygame.mouse.get_pressed()[0]:
        mx, my = pygame.mouse.get_pos()
        if mx > buttonAreaWidth and selected_vertex is None:
            dx = mx - buttonAreaWidth
            dy = my
            points.append((dx, dy))
            if len(points) == 0 or math.hypot(dx - points[-1][0], dy - points[-1][1]) > brushSize/2:
                points.append((dx, dy))

#change location of polygon vertex
    if selected_polygon is not None and selected_vertex is not None:
        mx, my = pygame.mouse.get_pos()
        pos = (mx - buttonAreaWidth, my)
        selected_polygon.move_vertex(selected_vertex, pos)

    pygame.display.flip()
    fpsClock.tick(fps)
