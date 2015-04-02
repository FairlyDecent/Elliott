#include "src/graphics/window.h"

//TODO: Episode 2 Sparky game engine

int main()
{
	using namespace elliott;
	using namespace graphics;

	Window window("Elliott", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();

#if 1
		glBegin(GL_QUADS);
		glVertex2d(-0.5f, -0.5f);
		glVertex2d(-0.5f, 0.5f);
		glVertex2d(0.5f, 0.5f);
		glVertex2d(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		window.update();
	}

	return 0;
}