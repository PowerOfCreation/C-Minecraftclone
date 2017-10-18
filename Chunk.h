#pragma once
#include "Block.h"
#include <array>
#include <iostream>
#include "DrawManager.h"

const int CHUNK_WIDTH = 16, CHUNK_HEIGHT = 16;

using namespace glm;

struct World;

struct Chunk
{
	glm::vec2 offset;
	std::array<Block, (CHUNK_WIDTH * 2 * CHUNK_HEIGHT)> blocks {};
	World* world;

	Chunk(const glm::vec2& _offset, World* _world)
	{
		offset = _offset;
		world = _world;
	}

	void Draw()
	{
		int _x, _y;
		for (int x = 0; x < CHUNK_WIDTH; x++)
		{
			for (int y = 0; y < CHUNK_WIDTH; y++)
			{
				_x = (CHUNK_WIDTH * offset.x + x);
				_y = (CHUNK_WIDTH * offset.y + y);
		//		std::cout << _x << " " << _y << std::endl;
				mat4 Model = translate(glm::mat4(1.0f), vec3(_x, (int)(GetBlock(_x,_y)*10), _y));
				glm::mat4 mvp = Projection * View * Model;

				glUniformMatrix4fv(MatrixIDInShader, 1, GL_FALSE, &mvp[0][0]);

				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, Texture);
				// Set our "myTextureSampler" sampler to use Texture Unit 0
				glUniform1i(TextureID, 0);

				glEnableVertexAttribArray(0);

				glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

				glVertexAttribPointer(
					0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
					3,                  // size
					GL_FLOAT,           // type
					GL_FALSE,           // normalized?
					0,                  // stride
					(void*)0            // array buffer offset
				);

				glEnableVertexAttribArray(1);

				glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);

				glVertexAttribPointer(
					1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
					2,                                // size
					GL_FLOAT,                         // type
					GL_FALSE,                         // normalized?
					0,                                // stride
					(void*)0                          // array buffer offset
				);
				glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
			}
		}
	}

	float GetBlock(int x, int y)
	{
		return world->worldGenerator.myNoise.GetNoise(x, y);
	}
};