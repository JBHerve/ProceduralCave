#include "Automata.h"
#include <ctime>

Automata::Automata(int _size)
	: m_size(_size), m_nbIterr(0)
{
	srand(time(0));
	m_cells = std::vector<std::vector<Cell>>(_size);
	for (size_t i = 0; i < _size; i++)
	{
		m_cells[i] = std::vector<Cell>(_size);
	}
}

void Automata::update()
{
	if (m_nbIterr < 7)
	{
		std::vector<std::vector<Cell>> tmp = m_cells;
		for (int i = 0; i < m_size; i++)
		{
			for (int j = 0; j < m_size; j++)
			{
				//We decrease the max count in order to consider tiles out of bounds like walls.
				int count = 9 - m_cells[i][j].getState() - GetCellsInRangeState(1, i, j);

				//Game of life
				/*if (count != 2)
				{
					tmp[i][j].setState(count != 3);
				}*/

				if (m_nbIterr < 4 && count < 5)
				{
					count += 16 - GetCellsInRangeState(2, i, j);
					tmp[i][j].setState(count > 1);
				}
				else
				{
					tmp[i][j].setState(count < 5);
				}
			}
		}
		++m_nbIterr;
		m_cells = tmp;
	}
}

int Automata::GetCellsInRangeState(int _range, int _column, int _row) const
{
	int count = 0;

	for (size_t i = _column - _range; i <= _column + _range; i++)
	{
		int j = _row - _range;
		int k = _row + _range;

		if (i >= 0 && i < m_size)
		{
			if (j >= 0 && j < m_size && m_cells[i][j].getState())
			{
				++count;
			}
			if (k >= 0 && k < m_size &&  m_cells[i][k].getState())
			{
				++count;
			}
		}
	}

	for (size_t i = _row - _range + 1; i < _row + _range; i++)
	{
		int j = _column - _range;
		int k = _column + _range;

		if (i >= 0 && i < m_size)
		{
			if (j >= 0 && j < m_size && m_cells[j][i].getState())
			{
				++count;
			}
			if (k >= 0 && k < m_size && m_cells[k][i].getState())
			{
				++count;
			}
		}
	}

	return count;
}
