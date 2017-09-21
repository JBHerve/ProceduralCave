#include "Cell.h"
#include <random>



Cell::Cell()
{
	//Rand with range : min + (rand() % (max - min + 1))
	m_state = std::rand() % 101 > 45;
}
