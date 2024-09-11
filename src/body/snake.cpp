#include "../header/snake.h"
#include <raylib.h>
#include <raymath.h>

Snake::Snake(int cellSize) : cellSize(cellSize) {}
void Snake::Draw(Color color) {
  for (auto i : body) {

    float x = i.x;
    float y = i.y;

    Rectangle rectangle{x * cellSize, y * cellSize, (float)cellSize,
                        (float)cellSize};

    DrawRectangleRounded(rectangle, 10.f, 7, color);
  }
}

void Snake::Update() {
  body.pop_back();
  body.push_front(Vector2Add(body.at(0), direction));
}
