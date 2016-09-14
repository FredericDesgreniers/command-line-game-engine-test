#pragma once
#include "Buffer.h"

namespace FredRender
{
	

	class RenderItem
	{
	public:
		RenderItem(int, int);
		virtual void draw(Buffer* buffer);
	protected:
		int x;
		int y;
	};

	class RenderMenu : public RenderItem
	{
	public:
		RenderMenu(int, int);
		void draw(Buffer* buffer);
		vector<std::string> options;
		void inputUp();
		void inputDown();
	private:
		int selectedOption;
	};
}