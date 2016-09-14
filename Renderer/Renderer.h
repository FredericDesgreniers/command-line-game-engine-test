#pragma once
#include "Buffer.h"

namespace FredRender{
	class Renderer
	{
	public:
		Renderer();
		void render(Buffer*);
	};
}