#pragma once
#include <random>
#include <cstdlib>

class Constants
{
public:
	const static unsigned int __BASE_UNIT_SIZE = 20;
	const static unsigned int _RANDOM_POSITION_GENERATION_MAX_ATTEMPS = 64;
public:
	static int randomIntBetween(const int min, const int max) {
		return rand() % (max - min + 1) + min;
	}
};

