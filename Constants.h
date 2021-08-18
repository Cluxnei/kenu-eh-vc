#pragma once
#include <random>
#include <cstdlib>

static class Constants
{
public:
	const static unsigned int _UNIT_SIZE = 40;
	const static unsigned int _RANDOM_POSITION_GENERATION_MAX_ATTEMPS = 5;
public:
	static int randomIntBetween(const int min, const int max) {
		return rand() % (max - min + 1) + min;
	}
};

