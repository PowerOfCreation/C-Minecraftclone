#pragma once
#include "World.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "shader.h"
#include "texture.h"
#include "bufferdata.h"
#include <iostream>

World* activeWorld;

glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)4 / (float)3, 0.1f, 4000.0f);
glm::mat4 View;

GLuint vertexbuffer;
GLuint uvbuffer;
GLuint programID;
GLuint MatrixIDInShader;
GLuint Texture;
GLuint TextureID;

#include "Chunk.h"

struct DrawManager
{
	void Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		for (const auto& element : activeWorld->chunks)
		{
			element->Draw();			
		}
	}

	void Init()
	{
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glClearColor(0.9f, 0.9f, 1.0f, 0.0f);

		GLuint VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

		programID = LoadShaders("vertex.glsl", "fragment.glsl");

		MatrixIDInShader = glGetUniformLocation(programID, "MVP");

		Texture = loadBMP_custom("dirt.bmp");
		//GLuint Texture = loadDDS("uvtemplate.DDS");
		TextureID = glGetUniformLocation(programID, "myTextureSampler");

		View = glm::lookAt(
			glm::vec3(-15, 15, -15), // Camera is at (4,3,3), in World Space
			glm::vec3(32, 0, 32), // and looks at the origin
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		glGenBuffers(1, &uvbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

		activeWorld = new World{ 5656765 }; //213213 5656765
		//std::cout << "asd" << sizeof(activeWorld->chunks);
		for (int i = 0; i < 400; i++)
		{
			activeWorld->chunks[i] = new Chunk{ glm::vec2{ i % 20, (int) i/20 }, activeWorld };
		}
		return;
	}

} drawManager;