
#include "Buffer.h"

using namespace FredRender;

Buffer::Buffer(int width, int height)
{
	this->height = height;
	this->width = width;
	xLoc = 0;
	yLoc = 0;
	resWidth = width;
	resHeight = height;
	content.resize(height);
	for (int i = 0; i < content.size(); i++)
	{
		content[i].resize(width);
	}
}
void Buffer::drawString(std::string str, int x, int y)
{
	for (int i = 0; i < str.length(); i++)
	{
		content[y+yLoc][x + xLoc + i] = str[i];
	}
}

void Buffer::drawLine(int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
		drawVerticalLine(x1, y1, y2);
	else if (y1 == y2)
		drawHorizontalLine(x1, x2, y1);
	else
	{
		
	}

}

void Buffer::drawHorizontalLine(int x1, int x2, int y1)
{
	if(x1>x2)
	{
		int t = x1;
		x1 = x2;
		x2 = t;
	}

	for (int x = x1; x <= x2; x++)
	{
		setContent(x,y1, '-');
	}
}

void Buffer::drawVerticalLine(int x1, int y1, int y2)
{
	if (y1>y2)
	{
		int t = y1;
		y1 = y2;
		y2 = t;
	}

	for (int y = y1; y <= y2; y++)
	{
		setContent(x1, y, '|');
	}
}

void Buffer::drawRectangle(int x1, int y1, int width, int height)
{
	drawVerticalLine(x1, y1, y1 + height);
	drawVerticalLine(x1 + width, y1, y1 + height);
	drawHorizontalLine(x1, x1 + width, y1);
	drawHorizontalLine(x1, x1 + width, y1 + height);
}


void Buffer::setContent(int x, int y, char c)
{
	if(!(x>=resWidth || y>=resHeight))
	{
		content[y+yLoc][x+xLoc] = c;
	}
}


void Buffer::clear()
{
	content.clear();
	content.resize(height);
	for (int i = 0; i < content.size(); i++)
	{
		content[i].clear();
		content[i].resize(width);
	}

}

void Buffer::moveCursor(int x, int y)
{
	xLoc += x;
	yLoc += y;
	resWidth = width - xLoc;
	resHeight = height - yLoc;
}

void Buffer::resetCursor()
{
	xLoc = 0;
	yLoc = 0;
	resetRestricted();
}

void Buffer::setRestricted(int width, int height)
{
	resWidth = width;
	resHeight = height;
}
void Buffer::resetRestricted()
{
	resWidth = width;
	resHeight = height;
}

