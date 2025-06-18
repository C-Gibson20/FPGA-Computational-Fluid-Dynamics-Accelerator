from .widgets import Button, InputBox, Slider
from .canvas import clear_canvas
from drawing.networking import send

x = 25
button_width = 160
button_height = 35

slider_y = 50
circle_y = 100
rectangle_y = 230
polygon_y = 420
save_y = 700


def setup_ui(canvas, polygons, lines, images, circles, rectangles,
             draw_polygon, draw_circle, draw_rectangle,
            host, port, font):

    labels = {}
    input_boxes = {}

    # Brush Size Slider
    slider = Slider((25, slider_y))

    # Polygon setup
    Button(x, polygon_y, button_width, button_height, 'Polygon', draw_polygon)
    labels["polygon"] = (font.render("No. of sides", True, (255, 255, 255)), (x, polygon_y + 45))
    input_boxes["polygon"] = [InputBox(x, polygon_y + 65, 50, 25, "4")]

    # Circle setup
    Button(x, circle_y, button_width, button_height, 'Circle', draw_circle)
    labels["circle"] = (font.render("Radius", True, (255, 255, 255)), (x, circle_y + 45))
    input_boxes["circle"] = [InputBox(x, circle_y + 65, 50, 25, "50")]

    # Rectangle setup
    Button(x, rectangle_y, button_width, button_height, 'Rectangle', draw_rectangle)
    labels["rect_w"] = (font.render("Width", True, (255, 255, 255)), (x, rectangle_y + 45))
    input_boxes["rect_w"] = [InputBox(x, rectangle_y + 65, 50, 25, "20")]
    labels["rect_h"] = (font.render("Height", True, (255, 255, 255)), (x, rectangle_y + 105)) 
    input_boxes["rect_h"] = [InputBox(x, rectangle_y + 125, 50, 25, "40")] 

    # Labels to state functionality
    labels["images1"] = (font.render("Drag and drop", True, (255, 255, 255)), (x, polygon_y + 115))
    labels["images2"] = (font.render("images to add", True, (255, 255, 255)), (x, polygon_y + 140))
    labels["images3"] = (font.render("as barriers.", True, (255, 255, 255)), (x, polygon_y + 165))

    # Save & Clear
    Button(x, save_y, button_width, button_height, 'Save', lambda: send(canvas, host, port))
    Button(x, save_y + 50, button_width, button_height, 'Clear', lambda: clear_canvas(canvas, polygons, lines, images, circles, rectangles))

    return {
        "labels": labels,
        "input_boxes": input_boxes,
        "slider": slider
    }
