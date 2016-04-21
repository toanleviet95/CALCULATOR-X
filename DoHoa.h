#pragma once
#include "CalculatorX.h"

// Các hàm đồ họa cho chương trình
void resizeBuffer(int width, int height);
void gotoxy(int x, int y);
void textcolor(WORD color);
void multiPut(int x, int y, char c, int color);
void Logo();
void ClearAt(int x, int y);
void ClearMenuAt(int x, int y);
