from .widgets import Button, InputBox, Slider
import pygame
from .canvas import clear_canvas

def setup_ui(canvas, polygons, lines, images, circles, rectangles,
             draw_polygon, draw_circle, draw_rectangle,
             send_fn, host, port, font):

    labels = {}
    input_boxes = {}

    # Polygon setup
    Button(25, 25, 160, 35, 'Polygon', draw_polygon)
    labels["polygon"] = (font.render("Insert no of sides", True, (255, 255, 255)), (25, 70))
    input_boxes["polygon"] = [InputBox(25, 100, 50, 25)]

    # Circle setup
    Button(25, 140, 160, 35, 'Circle', draw_circle)
    labels["circle"] = (font.render("Radius", True, (255, 255, 255)), (25, 190))
    input_boxes["circle"] = [InputBox(25, 210, 50, 25)]

    # Save & Clear
    Button(25, 250, 160, 35, 'Save', lambda: send_fn(canvas, host, port))
    Button(25, 310, 160, 35, 'Clear', lambda: clear_canvas(canvas, polygons, lines, images, circles, rectangles))

    # Rectangle setup
    Button(25, 370, 160, 35, 'Rectangle', draw_rectangle)
    labels["rect_w"] = (font.render("Width", True, (255, 255, 255)), (25, 420))
    input_boxes["rect_w"] = [InputBox(25, 440, 50, 25)]
    labels["rect_h"] = (font.render("Height", True, (255, 255, 255)), (25, 490))
    input_boxes["rect_h"] = [InputBox(25, 510, 50, 25)]

    # Brush Size Slider
    slider = Slider((25, 580))

    return {
        "labels": labels,
        "input_boxes": input_boxes,
        "slider": slider
    }
