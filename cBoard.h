#pragma once
#include "CalculatorX.h"

// Lớp cBoard để vẽ khung bảng hình chữ nhật
class cBoard
{
public:
	int x1, y1, x2, y2, width, height;
	inline void drawBoard(int x1, int y1, int x2, int y2, float DivPos, int color = 14, char *title = NULL, int ttColor = 15)
	{
		int i;
		multiPut(x1, y1, (char)218, color); //top-left
		multiPut(x2, y1, (char)191, color); //top-right
		multiPut(x1, y2, (char)192, color); //bottom-left
		multiPut(x2, y2, (char)217, color); //bottom-right
		textcolor(color);
		for (i = x1; i<x2 - 1; i++) //top border */
			multiPut(i + 1, y1, (char)196, color);
		for (i = x1; i<x2 - 1; i++) //bottom border */
			multiPut(i + 1, y2, (char)196, color);
		for (i = 0; i<y2 - y1 - 1; i++) /* left border */
			multiPut(x1, y1 + i + 1, (char)179, color);
		for (i = 0; i<y2 - y1 - 1; i++) /* right border */
			multiPut(x2, y1 + i + 1, (char)179, color);
		if (title != NULL&&strlen(title)<(x2 - x1))
		for (i = 0; i<strlen(title); i++)
			multiPut(i + (x2 + x1) / DivPos - strlen(title) / 2, y1, *(title + i), ttColor);
	}
};