#pragma once
#include "FastNoise.h"

struct WorldGenerator
{
	FastNoise myNoise; // Create a FastNoise object

	WorldGenerator() { myNoise.SetNoiseType(FastNoise::Simplex); }
};