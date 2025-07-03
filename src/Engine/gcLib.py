import gcEngine


# this is i don't know
class TwoNumber:
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.result = gcEngine.TwoNumber(a, b)

    def __repr__(self):
        return f"{self.a} + {self.b} = {self.result}"

# extra functions

class gcRGBA:
    def __init__(self, R: int, G: int, B: int, A: int):
        self.R = R
        self.G = G
        self.B = B
        self.A = A

    @property
    def Get(self):
        return [self.R, self.G, self.B, self.A]

class gcSetTargetFPS:
    def __init__(self, FPS: int):
        self.FPS = FPS
    
    def Set(self):
        gcEngine.gc_SetTargetFPS(self.FPS)

# raylib binding

class gcInitWindow:
    def __init__(self, Width: int, Height: int, Title: str):
        gcEngine.gc_InitWindow(Width, Height, Title)

class gcWindowShouldClose:
    def IsClose(self):
        return gcEngine.gc_WindowShouldClose()

class gcBeginDrawing:
    def Start(self):
        gcEngine.gc_BeginDrawing()

class gcClearBackground:
    def __init__(self, RGBA: gcRGBA):
        self.RGBA = RGBA

    def Get(self):
        gcEngine.gc_ClearBackground(self.RGBA.R, self.RGBA.G, self.RGBA.B, self.RGBA.A)

# 0xFF000000
class gcDrawText:
    def __init__(self, Text: str, X: int, Y: int, Size: int, Color: gcRGBA):
        self.Text  = Text
        self.X     = X
        self.Y     = Y
        self.Size  = Size
        self.Color = [Color.A, Color.G, Color.B, Color.A]

    def Draw(self):
        gcEngine.gc_DrawText(self.Text, self.X, self.Y, self.Size, self.Color)

class gcDrawFPS:
    def __init__(self, X: int, Y: int):
        self.X = X
        self.Y = Y
    
    def Draw(self):
        gcEngine.gc_DrawFPS(self.X, self.Y)





# End Drawing and Close Window
class gcEndDrawing:
    def End(self):
        gcEngine.gc_EndDrawing()

class gcCloseWindow:
    def Now(self):
        gcEngine.gc_CloseWindow()




