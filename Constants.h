#pragma once
#include <random>
#include <cstdlib>

class Constants
{
public:
	const static unsigned int _WIDTH = 1000;
	const static unsigned int _HEIGHT = 1000;

	const static unsigned int _NUMBER_OF_MAP_SQUARES = 32;

	const static unsigned int __BASE_UNIT_SIZE = std::min(Constants::_WIDTH, Constants::_HEIGHT) / _NUMBER_OF_MAP_SQUARES;

	const static unsigned int _RANDOM_POSITION_GENERATION_MAX_ATTEMPS = _NUMBER_OF_MAP_SQUARES * _NUMBER_OF_MAP_SQUARES - 1;

public:

	static int randomIntBetween(const int min, const int max) 
	{
		return rand() % (max - min + 1) + min;
	}
	
	static float getMovementFactor() 
	{
		return 0.05f;
	}
};

