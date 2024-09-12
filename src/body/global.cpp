#include "../header/global.h"
#include <raylib.h>

Color green = {173, 204, 96, 255};
Color darkdGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

double lastUpdateTime = 0;
Image image = LoadImage("../graphics/food.png");

int offset = 75;
