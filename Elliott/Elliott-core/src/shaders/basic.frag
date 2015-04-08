#version 330 core

layout (location = 0) out vec4 col;

uniform vec2 light_pos;
uniform vec4 color;

in vec4 pos;

void main()
{
	float intensity = 1.0f / length(pos.xy - light_pos);
	col = color * intensity;
}