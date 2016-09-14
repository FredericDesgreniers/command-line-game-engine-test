#include "Renderer.h"
#include "Buffer.h"
#include "iostream"
#include "stdlib.h"


#include <string>

using namespace std;
using namespace FredRender;

Renderer::Renderer()
{
	
}

void Renderer::render(Buffer* buffer)
{
	string s = "";

	for (int i = 0; i < buffer->content.size(); i++)
	{
		for (int j = 0; j < buffer->content[i].size(); j++)
		{
			s += buffer->content[i][j];
		}
		s += "\n";
	}
	system("cls");
	cout << s;
}


