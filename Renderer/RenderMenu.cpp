#include "RenderItem.h"

using namespace FredRender;

RenderMenu::RenderMenu(int x, int y) : RenderItem(x, y)
{

	selectedOption = 0;
	options.push_back("new game");
	options.push_back("load game");
	options.push_back("options");
	options.push_back("exit");
}

void RenderMenu::draw(Buffer* buffer)
{
	for (int i = 0; i < options.size(); i++)
	{
		bool selected = i == selectedOption;
		buffer->drawString((selected ?"-> ":"   ")+options[i]+(selected?" <-":""), 0, i);
	}
}

void RenderMenu::inputUp()
{
	if (selectedOption > 0)
	{
		selectedOption--;
	}
}

void RenderMenu::inputDown()
{
	if (options.size() > selectedOption + 1)
	{
		selectedOption++;
	}
	
}



