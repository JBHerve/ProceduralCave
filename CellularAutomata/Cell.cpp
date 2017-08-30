#include "Cell.h"
#include <random>



Cell::Cell()
{
	m_state = ((std::rand() % (100 + 1)) > 45);
}
