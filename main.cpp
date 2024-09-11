#include "src/header/game.h"
#include "src/header/global.h"
#include <raylib.h>

bool eventTrigger(double interval);

int main() {

  InitWindow(cellSize * cellCount, cellSize * cellCount, "Snanke Game");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    game.KeyEvent();
    BeginDrawing();
    game.Draw();
    ClearBackground(green);
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
