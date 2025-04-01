#version 330 core

// Vertex position
layout (location = 0) in vec3 aPos;

// Vertex color
layout (location = 1) in vec3 aColor;

out vec3 vertexColor; // Pass color to fragment shader

void main()
{
  gl_Position = vec4(aPos, 1.0);
  vertexColor = aColor;
}
