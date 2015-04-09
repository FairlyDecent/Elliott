#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"

#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include "src\graphics\renderer2D.h"
#include "src\graphics\simple2DRenderer.h"

int main()
{
	using namespace elliott;
	using namespace graphics;
	using namespace maths;

	std::cout << "Elliot Game Engine" << std::endl;

	Window window("Elliott", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("color", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 0, 1), shader);
	Renderable2D sprite2(maths::vec3(7, 1, 0), maths::vec2(2, 3), maths::vec4(0, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	double x, y;
	while (!window.closed())
	{
		window.clear();

		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2(x * 16.0f / 960.0f, 9.0f - y * 9.0f / 540.0f));

		renderer.submit(&sprite);
		renderer.submit(&sprite2);
		renderer.flush();

		window.update();
	}

	return 0;
}