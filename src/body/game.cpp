#include "../header/game.h"
#include <deque>
#include <raylib.h>
#include <raymath.h>

void Game::Draw() {
  snake.Draw(darkdGreen);
  food.Draw(darkdGreen);
}

void Game::Update() {
  snake.Update();
  CheckCollisionWithEdge();
  CheckCollisionTail();
  CheckCollision();
}

void Game::KeyEvent() {
  if (IsKeyPressed(KEY_UP) && snake.direction.y != 1) {
    snake.direction = Vector2{0, -1};
    snake.gameRunning = true;
  }

  if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1) {
    snake.direction = Vector2{0, 1};
    snake.gameRunning = true;
  }

  if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1) {
    snake.direction = Vector2{-1, 0};
    snake.gameRunning = true;
  }
  if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1) {
    snake.direction = Vector2{1, 0};
    snake.gameRunning = true;
  }
}

void Game::CheckCollision() {
  if (Vector2Equals(snake.body.at(0), food.GetPosition())) {
    food.SetPosition(food.RandomPosition(snake.body));
    snake.addSegment = true;
  }
}

void Game::CheckCollisionWithEdge() {
  int x = snake.body.at(0).x;
  int y = snake.body.at(0).y;
  if (x == cellCount || x == -1 || y == -1 || y == cellCount) {
    GameOver();
  }
}

void Game::CheckCollisionTail() {
  std::deque<Vector2> headLessBody = snake.body;
  headLessBody.pop_front();
  if (food.ElementinDeque(headLessBody, snake.body.at(0))) {
    GameOver();
  }
}
void Game::GameOver() { snake.Reset(); }
