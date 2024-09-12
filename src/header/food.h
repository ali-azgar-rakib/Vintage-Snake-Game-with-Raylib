#pragma once
#include <deque>
#include <raylib.h>

class Food {

private:
  Vector2 position;
  int cellSize{};
  int cellCount{};
  Texture2D texture;

public:
  Food(int cellSize, int cellCount, Image image, std::deque<Vector2> body);
  void Draw(Color color);
  Vector2 RandomPosition(std::deque<Vector2> body);
  Vector2 RandomPoint();
  bool ElementinDeque(std::deque<Vector2> body, Vector2 position);
  inline Vector2 GetPosition() { return position; }
  inline void SetPosition(Vector2 vec) { position = vec; }
  ~Food();
};
