import pygame
import math

DEFAULT_COLOR = (0, 0, 0)

class Shape:
    def __init__(self, pos, color=DEFAULT_COLOR):
        self.pos = list(pos)
        self.color = color
        self.dragging = False
        self.drag_offset = (0, 0)

    def start_drag(self, mouse_pos):
        if hasattr(self, 'rect') and self.rect.collidepoint(mouse_pos):
            self.dragging = True
            self.drag_offset = (mouse_pos[0] - self.pos[0], mouse_pos[1] - self.pos[1])
            return True
        return False

    def drag(self, mouse_pos):
        if self.dragging:
            self.pos = [mouse_pos[0] - self.drag_offset[0], mouse_pos[1] - self.drag_offset[1]]

    def stop_drag(self):
        self.dragging = False

    def draw(self, surface):
        raise NotImplementedError("Each shape must implement its own draw method")


class Polygon(Shape):
    def __init__(self, center, sides, radius, color=DEFAULT_COLOR):
        super().__init__(center, color)
        self.sides = sides
        self.radius = radius
        self.points = self.calculate_points()
        self.update_rect()

    def calculate_points(self):
        angle = 2 * math.pi / self.sides
        return [(self.pos[0] + self.radius * math.cos(i * angle),
                 self.pos[1] + self.radius * math.sin(i * angle)) for i in range(self.sides)]

    def update_rect(self):
        xs, ys = zip(*self.points)
        min_x, max_x = min(xs), max(xs)
        min_y, max_y = min(ys), max(ys)
        self.rect = pygame.Rect(min_x, min_y, max_x - min_x, max_y - min_y)

    def draw(self, surface):
        self.points = self.calculate_points()
        self.update_rect()
        pygame.draw.polygon(surface, self.color, self.points)

    def drag(self, mouse_pos):
        if self.dragging:
            self.pos = [mouse_pos[0] - self.drag_offset[0], mouse_pos[1] - self.drag_offset[1]]
            self.points = self.calculate_points()
            self.update_rect()

    def get_vertex_at_pos(self, pos, radius=10):
        for i, (x, y) in enumerate(self.points):
            if math.hypot(pos[0] - x, pos[1] - y) < radius:
                return i
        return None

    def move_vertex(self, index, new_pos):
        if 0 <= index < len(self.points):
            self.points[index] = new_pos


class Rectangle(Shape):
    def __init__(self, pos, size=(100, 60), color=DEFAULT_COLOR):
        super().__init__(pos, color)
        self.size = size
        self.rect = pygame.Rect(self.pos, self.size)

    def draw(self, surface):
        self.rect.topleft = self.pos
        pygame.draw.rect(surface, self.color, self.rect)
        pygame.draw.rect(surface, (0, 0, 0), self.rect, 2)  # black outline


class Circle(Shape):
    def __init__(self, pos, radius, color=DEFAULT_COLOR):
        super().__init__(pos, color)
        self.radius = radius
        self.rect = pygame.Rect(pos[0] - radius, pos[1] - radius, radius * 2, radius * 2)

    def draw(self, surface):
        pygame.draw.circle(surface, self.color, self.pos, self.radius)
        self.rect = pygame.Rect(self.pos[0] - self.radius, self.pos[1] - self.radius,
                                self.radius * 2, self.radius * 2)
