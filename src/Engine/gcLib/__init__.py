from . import gcLib_GnuLinux as gcLib



PI = 3.14159265358979323846
DEG2RAD = (PI/180.0)
RAD2DEG = (180.0/PI)

class gcVector2:
    def __init__(self, X: float, Y: float):
        self.X = X
        self.Y = Y

class gcVector3:
    def __init__(self, X: float, Y: float, Z: float):
        self.X = X
        self.Y = Y
        self.Z = Z

class gcVector4:
    def __init__(self, X: float, Y: float, Z: float, W: float):
        self.X = X
        self.Y = Y
        self.Z = Z
        self.W = W

class gcRGBA:
    def __init__(self, R: int, G: int, B: int, A: int):
        self.R = R
        self.G = G
        self.B = B
        self.A = A

    @property
    def Get(self):
        return [self.R, self.G, self.B, self.A]






# this is i don't know
class TwoNumber:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    @property
    def Get(self):
        return gcLib.TwoNumber(self.a, self.b)

class gcRandomNumber_Int:
    def __init__(self, Min: int, Max: int):
        self.Min = Min
        self.Max = Max
    
    @property
    def Get(self):
        return gcLib.gc_GetRandomValue_int(self.Min, self.Max)

class gcRandomNumber_Float:
    def __init__(self, Min: int, Max: int):
        self.Min = Min
        self.Max = Max
    
    @property
    def Get(self):
        return gcLib.gc_GetRandomValue_float(self.Min, self.Max)

# extra functions



class gcSetTargetFPS:
    def __init__(self, FPS: int):
        self.FPS = FPS
    
    def Set(self):
        gcLib.gc_SetTargetFPS(self.FPS)



# raylib binding

class gcInitWindow:
    def __init__(self, Width: int, Height: int, Title: str):
        gcLib.gc_InitWindow(Width, Height, Title)

class gcWindowShouldClose:
    def IsClose(self):
        return gcLib.gc_WindowShouldClose()

class gcBeginDrawing:
    def Start(self):
        gcLib.gc_BeginDrawing()

class gcClearBackground:
    def __init__(self, RGBA: gcRGBA):
        self.RGBA = RGBA

    def Get(self):
        gcLib.gc_ClearBackground(self.RGBA.R, self.RGBA.G, self.RGBA.B, self.RGBA.A)

# 0xFF000000
class gcDrawText:
    def __init__(self, Text: str, X: int, Y: int, Size: int, Color: gcRGBA):
        self.Text  = Text
        self.X     = X
        self.Y     = Y
        self.Size  = Size
        self.Color = [Color.A, Color.G, Color.B, Color.A]

    def Draw(self):
        gcLib.gc_DrawText(self.Text, self.X, self.Y, self.Size, self.Color)

class gcDrawFPS:
    def __init__(self, X: int, Y: int):
        self.X = X
        self.Y = Y
    
    def Draw(self):
        gcLib.gc_DrawFPS(self.X, self.Y)





# End Drawing and Close Window
class gcEndDrawing:
    def End(self):
        gcLib.gc_EndDrawing()

class gcCloseWindow:
    def Now(self):
        gcLib.gc_CloseWindow()




