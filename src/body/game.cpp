#include "../header/game.h"
#include <raylib.h>

void Game::Draw() {
  snake.Draw(darkdGreen);
  food.Draw(darkdGreen);
}

void Game::Update() { snake.Update(); }

void Game::KeyEvent() {
  if (IsKeyPressed(KEY_UP) && snake.direction.y != 1) {
    snake.direction = Vector2{0, -1};
  }

  if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1) {
    snake.direction = Vector2{0, 1};
  }

  if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1) {
    snake.direction = Vector2{-1, 0};
  }
  if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1) {
    snake.direction = Vector2{1, 0};
  }
}
