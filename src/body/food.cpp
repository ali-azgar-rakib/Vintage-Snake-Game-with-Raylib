#include "../header/food.h"
#include <raylib.h>

Food::Food(int cellSize, int cellCount, Image image)
    : cellSize(cellSize), cellCount(cellCount) {
  position = randomPosition();
  ImageResize(&image, 25, 25);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
}

void Food::Draw(Color color) {

  if (texture.width) {
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
  }
}

Vector2 Food::randomPosition() {
  return Vector2{(float)GetRandomValue(0, cellCount - 1),
                 (float)GetRandomValue(0, cellCount - 1)};
}

Food::~Food() { UnloadTexture(texture); }
