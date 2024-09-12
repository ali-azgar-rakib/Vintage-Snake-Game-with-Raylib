#include "../header/food.h"
#include "../header/global.h"
#include <deque>
#include <raylib.h>
#include <raymath.h>

Food::Food(int cellSize, int cellCount, Image image, std::deque<Vector2> body)
    : cellSize(cellSize), cellCount(cellCount) {
  position = RandomPosition(body);
  ImageResize(&image, 25, 25);
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
}

void Food::Draw(Color color) {

  if (texture.width) {
    DrawTexture(texture, offset + position.x * cellSize,
                offset + position.y * cellSize, WHITE);
  }
}

Vector2 Food::RandomPoint() {
  return Vector2{(float)GetRandomValue(0, cellCount - 1),
                 (float)GetRandomValue(0, cellCount - 1)};
}

bool Food::ElementinDeque(std::deque<Vector2> body, Vector2 position) {
  for (auto i : body) {
    if (Vector2Equals(i, position)) {
      return true;
    }
  }
  return false;
}
Vector2 Food::RandomPosition(std::deque<Vector2> body) {
  Vector2 position = RandomPoint();
  while (ElementinDeque(body, position)) {
    position = RandomPoint();
  }
  return position;
}

Food::~Food() { UnloadTexture(texture); }
