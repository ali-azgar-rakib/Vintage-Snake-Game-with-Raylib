#pragma once
#include <raylib.h>

class Food {

private:
  Vector2 position;
  int cellSize{};
  int cellCount{};
  Texture2D texture;

public:
  Food(int cellSize, int cellCount, Image image);
  void Draw(Color color);
  Vector2 randomPosition();
  ~Food();
};
