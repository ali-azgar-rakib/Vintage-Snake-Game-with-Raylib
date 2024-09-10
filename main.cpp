#include "src/header/food.h"
#include <raylib.h>

Color green = {173, 204, 96, 255};
Color darkdGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

int main() {

  InitWindow(cellSize * cellCount, cellSize * cellCount, "Snanke Game");
  SetTargetFPS(60);
  Image image = LoadImage("../graphics/food.png");

  Food food = Food(cellSize, cellCount, image);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(green);
    food.Draw(darkdGreen);
    EndDrawing();
  }
  CloseWindow();
  return 1;
}
