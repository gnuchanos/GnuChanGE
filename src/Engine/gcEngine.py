from enum import Enum
from gcLib import *

class GameScene(Enum):
    LogoScreen = 0
    MenuScreen = 1
    GameScreen = 2
    EndScreen  = 3

class GCEngine:
    def __init__(self, Width: int, Height: int, WindowTitle: str):
        self.window = gcInitWindow(Width, Height, WindowTitle)
        self.CurrentScene = GameScene.LogoScreen



    def RUN(self, GCUpdate: str = "", GCDraw: str = "", GCUnload: str = ""):
        while not gcWindowShouldClose().IsClose():
            if GCUpdate != "":
                GCUpdate()
            gcBeginDrawing().Start()
            if GCDraw != "":
                GCDraw()
            gcEndDrawing().End()

        if GCUnload != "":
            GCUnload()

        gcCloseWindow().Now()
