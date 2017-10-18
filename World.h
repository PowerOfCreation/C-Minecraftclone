#pragma once
#include "WorldGenerator.h"
#include <iostream>

struct Chunk;

struct World
{
	unsigned long seed = 1;

	Chunk* chunks[400];

	WorldGenerator worldGenerator;

	World(unsigned long _seed) : seed(_seed) { worldGenerator.myNoise.SetSeed(_seed);}
};

