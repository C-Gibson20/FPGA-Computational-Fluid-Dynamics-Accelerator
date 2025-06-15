import pygame

def create_canvas(size):
    canvas = pygame.Surface(size)
    canvas.fill((255, 255, 255))
    return canvas

def clear_canvas(canvas, polygons, lines, images, circles, rectangles):
    canvas.fill((255, 255, 255))
    polygons.clear()
    lines.clear()
    images.clear()
    circles.clear()
    rectangles.clear()

def draw_canvas(canvas, drawColor, brushSize, current_line, lines, polygons, rectangles, circles, images):
    canvas.fill((255, 255, 255))

    for poly in polygons:
        poly.draw(canvas)

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
