import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from gcLib import *
from enum import Enum


class GameScene(Enum):
    LogoScreen = 0
    MenuScreen = 1
    GameScreen = 2
    EndScreen  = 3


class Game:
    def __init__(self, Width: int, Height: int, WindowTitle: str):
        self.window = gcInitWindow(Width, Height, WindowTitle)

        self.CurrentScene = GameScene.LogoScreen


        gcSetTargetFPS(60).Set()
        while not gcWindowShouldClose().IsClose():
            self.Update()
            gcBeginDrawing().Start()
            gcClearBackground(gcRGBA(255, 255, 0, 255)).Get()
            self.DrawUI()
            gcEndDrawing().End()

        # not finish yet


        gcCloseWindow().Now()

    def Update(self):
        if self.CurrentScene == GameScene.LogoScreen:
            pass
        elif self.CurrentScene == GameScene.MenuScreen:
            pass
        elif self.CurrentScene == GameScene.GameScreen:
            pass
        elif self.CurrentScene == GameScene.EndScreen:
            pass
        


    def DrawUI(self):
        gcDrawText("Merhaba", 100, 100, 20, gcRGBA(255, 0, 0, 255)).Draw()
        gcDrawFPS(10, 10).Draw()

        if self.CurrentScene == GameScene.LogoScreen:
            pass
        elif self.CurrentScene == GameScene.MenuScreen:
            pass
        elif self.CurrentScene == GameScene.GameScreen:
            pass
        elif self.CurrentScene == GameScene.EndScreen:
            pass



if __name__ == "__main__":
    gc = Game(1600, 900, "uWu")

print(TwoNumber(10, 20))
import sys
print("Python executable:", sys.executable)
print("Python sys.path:", sys.path)
