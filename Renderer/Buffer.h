#pragma once
#include <vector>
#include "string"
using std::vector;
namespace FredRender{
	class Buffer
	{
	public:
		Buffer(int, int);
		vector<vector<char>> content;
		void drawString(std::string, int, int);
		void drawLine(int x1, int y1, int x2, int y2);
		void drawVerticalLine(int x1, int y1, int y2);
		void drawHorizontalLine(int x1, int x2, int y1);
		void drawRectangle(int x1, int y1, int width, int height);
		void setContent(int x, int y, char c);

		void clear();
		void moveCursor(int, int);
		void resetCursor();
		void setRestricted(int width, int height);
		void resetRestricted();
	private:
		int width, height;
		int xLoc, yLoc;
		int resWidth, resHeight;
	};
}