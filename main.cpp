#include "src/header/food.h"
#include "src/header/snake.h"
#include <raylib.h>

Color green = {173, 204, 96, 255};
Color darkdGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

double lastUpdateTime = 0;

bool eventTrigger(double interval);

int main() {

  InitWindow(cellSize * cellCount, cellSize * cellCount, "Snanke Game");
  SetTargetFPS(60);
  Image image = LoadImage("../graphics/food.png");

  Food food = Food(cellSize, cellCount, image);
  Snake snake = Snake(cellSize);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(green);
    food.Draw(darkdGreen);
    snake.Draw(darkdGreen);
    if (eventTrigger(0.2)) {
      snake.Update();
    }

    EndDrawing();
  }
  CloseWindow();
  return 1;
}

bool eventTrigger(double interval) {
  if (GetTime() - lastUpdateTime >= interval) {
    lastUpdateTime = GetTime();
    return true;
  }
  return false;
}
