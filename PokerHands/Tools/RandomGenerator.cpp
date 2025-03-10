#include "Tools/RandomGenerator.hpp"

RandomNumber::RandomNumber() : mt(std::random_device{}())
{
	//EMPTY BODY
}
