#include "src/header/food.h"
#include <raylib.h>

Color green = {173, 204, 96, 255};
Color darkdGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

int main() {

  InitWindow(cellSize * cellCount, cellSize * cellCount, "Snanke Game");
  SetTargetFPS(60);
  Image image = LoadImage(
      "/mnt/3C14D7F414D7AF60/code/c++/raylib_projects/snake/graphics/food.png");

  Food food = Food(cellSize, cellCount, image);
  if (image.width) {
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(green);
      food.Draw(darkdGreen);
      EndDrawing();
    }
  }
  CloseWindow();
  return 1;
}
