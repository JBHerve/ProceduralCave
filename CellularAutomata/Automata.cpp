#include "Automata.h"
#include <ctime>

Automata::Automata(int _width, int _height)
	: m_width(_width), m_height(_height), m_nbIterr(0)
{
	srand(time(0));
	m_cells = std::vector<std::vector<Cell>>(_width);
	for (size_t i = 0; i < _width; i++)
	{
		m_cells[i] = std::vector<Cell>(_height);
	}
}

void Automata::update()
{
	if (isProcessRunning())
	{
		std::vector<std::vector<Cell>> tmp = m_cells;
		for (int i = 0; i < m_width; i++)
		{
			for (int j = 0; j < m_height; j++)
			{

				//We decrease the max count in order to consider tiles out of bounds like walls.
				int count = m_cells[i][j].getState() ? 0 : 1;
				count += GetCellsInRangeState(1, i, j);

				//Game of life
				/*if (count != 2)
				{
					tmp[i][j].setState(count != 3);
				}*/

				if (m_nbIterr < 4)
				{
					bool wall = count >= 5 || count + GetCellsInRangeState(2, i, j) <= 1;
					tmp[i][j].setState(!wall);
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

	for (int i = _column - _range; i <= _column + _range; i++)
	{
		int j = _row - _range;
		int k = _row + _range;

		if (i >= 0 && i < m_width)
		{
			if (j < 0 || j >= m_height || !m_cells[i][j].getState())
			{
				++count;
			}

			if (k < 0 || k >= m_height || !m_cells[i][k].getState())
			{
				++count;
			}
		}
		else
		{
			count += 2;
		}
	}

	for (size_t i = _row - _range + 1; i < _row + _range; i++)
	{
		int j = _column - _range;
		int k = _column + _range;

		if (i >= 0 && i < m_height)
		{
			if (j < 0 || j >= m_width || !m_cells[j][i].getState())
			{
				++count;
			}
			if (k < 0 || k >= m_width || !m_cells[k][i].getState())
			{
				++count;
			}
		}
		else
		{
			count += 2;
		}
	}

	return count;
}
