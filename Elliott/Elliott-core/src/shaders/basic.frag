#version 330 core

layout (location = 0) out vec4 col;

uniform vec2 light_pos;
uniform vec4 color;

in DATA
{
	vec4 color;
	vec4 position;
} fs_in;

in vec4 pos;

void main()
{
	float intensity = 1.0f / length(fs_in.position.xy - light_pos);
	//col = color * intensity;
	col = fs_in.color * intensity;
}