import pygame
import math

# A global variable `drawColor` will be injected or passed in; for now we assume black
DEFAULT_COLOR = (0, 0, 0)

class Polygon:
    def __init__(self, center, sides, radius, color=DEFAULT_COLOR):
        self.center = center
        self.sides = sides
        self.radius = radius
        self.color = color
        self.points = self.calculate_points()

    def calculate_points(self):
        angle = 2 * math.pi / self.sides
        return [(self.center[0] + self.radius * math.cos(i * angle),
                 self.center[1] + self.radius * math.sin(i * angle)) for i in range(self.sides)]

    def draw(self, surface):
        pygame.draw.polygon(surface, self.color, self.points, 0)

    def get_vertex_at_pos(self, pos, radius=10):
        for i, (x, y) in enumerate(self.points):
            if math.hypot(pos[0] - x, pos[1] - y) < radius:
                return i
        return None

    def move_vertex(self, index, new_pos):
        self.points[index] = new_pos

class Rectangle:
    def __init__(self, pos, size=(100, 60), color=DEFAULT_COLOR):
        self.pos = list(pos)
        self.size = size
        self.color = color
        self.dragging = False
        self.drag_offset = (0, 0)
        self.rect = pygame.Rect(self.pos, self.size)

    def draw(self, surface):
        self.rect.topleft = self.pos
        pygame.draw.rect(surface, self.color, self.rect)
        pygame.draw.rect(surface, (0, 0, 0), self.rect, 2)

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
    def __init__(self, pos, radius, color=DEFAULT_COLOR):
        self.pos = list(pos)
        self.radius = radius
        self.color = color
        self.dragging = False
        self.drag_offset = (0, 0)
        self.rect = pygame.Rect(self.pos[0] - radius, self.pos[1] - radius, radius * 2, radius * 2)

    def draw(self, surface):
        pygame.draw.circle(surface, self.color, self.pos, self.radius)
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
