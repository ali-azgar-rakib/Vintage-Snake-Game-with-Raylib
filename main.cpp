#include "src/header/game.h"
#include "src/header/global.h"
#include <raylib.h>

bool eventTrigger(double interval);

int main() {

  InitWindow(2 * offset + cellSize * cellCount,
             2 * offset + cellSize * cellCount, "Snanke Game");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    game.KeyEvent();
    BeginDrawing();
    game.Draw();
    ClearBackground(green);
    DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5,
                                   (float)cellCount * cellSize + 10,
                                   (float)cellSize * cellCount + 10},
                         5.f, WHITE);
    DrawText("Snake", offset, 20, 36, WHITE);
    if (eventTrigger(0.2)) {
      game.Update();
    }

    EndDrawing();
  }
  CloseWindow();
  return 1;
}

bool eventTrigger(double interval) {
  if (GetTime() - lastUpdateTime >= interval) {
    lastUpdateTime = GetTime();
    return true;
  }
  return false;
}
