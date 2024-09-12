#include <deque>
#include <raylib.h>

class Snake {
public:
  std::deque<Vector2> body = {Vector2{2, 5}, Vector2{2, 6}, Vector2{2, 7}};
  int cellSize{};
  Vector2 direction{1, 0};
  bool addSegment = false;
  bool gameRunning = true;
  Snake(int cellSize);

  void Draw(Color color);

  void Update();

  void Reset();
};
