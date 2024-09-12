#include "../header/snake.h"
#include "../header/global.h"
#include <raylib.h>
#include <raymath.h>

Snake::Snake(int cellSize) : cellSize(cellSize) {}
void Snake::Draw(Color color) {
  for (auto i : body) {

    float x = i.x;
    float y = i.y;

    Rectangle rectangle{offset + x * cellSize, offset + y * cellSize,
                        (float)cellSize, (float)cellSize};

    DrawRectangleRounded(rectangle, 10.f, 7, color);
  }
}

void Snake::Update() {
  if (gameRunning) {
    body.push_front(Vector2Add(body.at(0), direction));
    if (addSegment) {
      addSegment = false;
    } else {
      body.pop_back();
    }
  }
}

void Snake::Reset() {
  gameRunning = false;
  body = {Vector2{2, 5}, Vector2{2, 6}, Vector2{2, 7}};
  direction = {1, 0};
}
