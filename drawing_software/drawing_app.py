import sys
import pygame
import ctypes
import math

from drawing.shapes import Polygon, Rectangle, Circle
from drawing.widgets import Button, InputBox, Slider, Images, set_font, set_screen, objects
from drawing.canvas import create_canvas, clear_canvas, draw_canvas
from drawing.networking import send
from drawing.layout import setup_ui
from drawing.embed import embed_pygame_into_unity

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
set_font(font)
set_screen(screen)

pygame.display.set_caption(python_win_title)
pygame.display.flip() # force window creation

embed_pygame_into_unity(python_win_title, unity_win_title)

#append all classes here
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


MAX_RETRIES = 3
RETRY_DELAY = 2  # seconds

canvas = create_canvas(canvasSize)

layout = setup_ui(
    canvas, polygons, lines, images, circles, rectangles,
    draw_polygon, draw_circle, draw_rectangle,
    send, HOST, PORT, font
)

input_box1 = layout["input_boxes"]["polygon"]
input_box2 = layout["input_boxes"]["circle"]
input_box3 = layout["input_boxes"]["rect_w"]
input_box4 = layout["input_boxes"]["rect_h"]
labels = layout["labels"]
slider = layout["slider"]


while True:
    screen.fill((30, 30, 30))
    for obj in objects: obj.process()

    draw_canvas(canvas, drawColor, brushSize, current_line, lines, polygons, rectangles, circles, images)

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

    for _, (label_surf, pos) in labels.items():
        screen.blit(label_surf, pos)

    for box in input_box1 + input_box2 + input_box3 + input_box4:
        box.update()
        box.draw(screen)

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