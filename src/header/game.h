#include "../header/global.h"
#include "./food.h"
#include "./snake.h"
#include <raylib.h>

class Game {
public:
  Snake snake = Snake(cellSize);
  Food food = Food(cellSize, cellCount, image);

  void Draw();

  void Update();

  void KeyEvent();
};
