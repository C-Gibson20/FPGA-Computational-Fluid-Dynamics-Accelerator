import pygame

# This list will hold all button objects created
objects = []

# Font and screen need to be set externally
font = None
screen = None

def set_font(pygame_font):
    global font
    font = pygame_font

def set_screen(pygame_screen):
    global screen
    screen = pygame_screen

class Button:
    def __init__(self, x, y, width, height, buttonText='Button', onclickFunction=None, onePress=False):
        global font, screen
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

        # Blinking cursor
        self.cursor_visible = True
        self.last_cursor_switch = pygame.time.get_ticks()
        self.cursor_interval = 500  # ms

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
        # Blinking cursor logic
        current_time = pygame.time.get_ticks()
        if current_time - self.last_cursor_switch >= self.cursor_interval:
            self.cursor_visible = not self.cursor_visible
            self.last_cursor_switch = current_time

    def draw(self, screen):
        # Draw text
        screen.blit(self.txt_surface, (self.rect.x + 5, self.rect.y + 5))
        pygame.draw.rect(screen, self.color, self.rect, 2)

        # Draw blinking cursor
        if self.active and self.cursor_visible:
            cursor_x = self.rect.x + 5 + self.txt_surface.get_width()
            cursor_y = self.rect.y + 5
            cursor_height = self.txt_surface.get_height() * .95
            pygame.draw.line(screen, self.color, (cursor_x, cursor_y), (cursor_x, cursor_y + cursor_height), 2)

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