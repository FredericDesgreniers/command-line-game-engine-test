#include "Renderer.h"
#include "iostream"
#include "Keys.h"
#include "conio.h"
#include "RenderItem.h"
#include <chrono>
#include <thread>
using namespace std;

int main()
{
	FredRender::Renderer renderer;
	FredRender::Buffer* buffer = new FredRender::Buffer(100,20);

	FredRender::RenderMenu menu(0,10);

	int key = 0;
		
	for (int i = 0; i < 10; i++)
	{
		buffer->drawRectangle(50-i*2, 10-i, 0+i*4, 0+i*2);
		if (i > 5)
			buffer->drawString("Fred's Renderer v1.0",40,10);
		renderer.render(buffer);
		buffer->clear();
		this_thread::sleep_for(100ms);
	}
	this_thread::sleep_for(2s);
		while(1){
			key = 0;
			buffer->drawString("Rendered using Fred's Renderer", 0, 0);
			
			buffer->moveCursor(0,10);
			buffer->drawHorizontalLine(0,100,-1);
			menu.draw(buffer);
			buffer->resetCursor();
			renderer.render(buffer);
			buffer->clear();
			switch((key=_getch()))
			{
			case KEY_UP:
				menu.inputUp();
				break;
			case KEY_DOWN:
				menu.inputDown();
				break;
			case KEY_LEFT:
				string s;
				cin >> s;
				break;
			}
		}
}