import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from gcEngine import *

class Game(GCEngine):
    def __init__(self, Width, Height, WindowTitle):
        super().__init__(Width, Height, WindowTitle)
        # Variables


        print(gcRandomNumber_Int(10, 30).Get)
        print(type(gcRandomNumber_Float(123, 33123120).Get))



        # Variables
        # Load Somethings




        # Load Somethings
        gcSetTargetFPS(60).Set()
        self.RUN(GCUpdate=self.Update, GCDraw=self.Draw, GCUnload=self.Unload)

    def Update(self):
        pass

    def Draw(self):
        # Background
        gcClearBackground(gcRGBA(34, 3, 54, 255)).Get()

        # 2D
        gcDrawText("This Is Long Text", 100, 100, 20, gcRGBA(197, 107, 255, 255)).Draw()
        gcDrawFPS(10, 10).Draw()


    def Unload(self):
        pass


if __name__ == "__main__":
    gc = Game(1600, 900, "uWu")

print(TwoNumber(10, 20).Get)
import sys
print("Python executable:", sys.executable)
print("Python sys.path:", sys.path)
