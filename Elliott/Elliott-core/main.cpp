#include <GLFW\glfw3.h>
#include <iostream>

#include "src/graphics/window.h"

int main()
{
	using namespace elliott;
	using namespace graphics;

	Window window("Elliott", 800, 600);

	while (!window.closed())
	{
		window.update();
	}

	return 0;
}