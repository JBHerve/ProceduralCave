#include "Automata.h"
#include <ctime>

Automata::Automata(int _size)
	: m_size(_size)
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
	static int call = 0;
	if (call < 7)
	{
		++call;
		std::vector<std::vector<Cell>> tmp = m_cells;
		for (int i = 0; i < m_size; i++)
		{
			for (int j = 0; j < m_size; j++)
			{
				int count = 9;
				for (Cell cell : GetCellsInRange(1, i, j))
				{
					if (cell.getState())
					{
						--count;
					}
				};

				//Game of life
				/*if (count != 2)
				{
					tmp[i][j].setState(count != 3);
				}*/

				if (call < 4 && count < 5)
				{
					count = 25;
					for (Cell cell : GetCellsInRange(2, i, j))
					{
						if (cell.getState())
						{
							--count;
						}
					};
					tmp[i][j].setState(count > 1);
				}
				else
				{
					tmp[i][j].setState(count < 5);
				}
			}
		}
		m_cells = tmp;
	}
}

std::vector<Cell> Automata::GetCellsInRange(int _range, int _column, int _row)
{
	std::vector<Cell> closeCellular = std::vector<Cell>();

	for (size_t i = _column - _range; i <= _column + _range; i++)
	{
		for (size_t j = _row - _range; j <= _row + _range; j++)
		{
			if (i >= 0 && j >= 0 && i < m_size && j < m_size)
			{
				closeCellular.push_back(m_cells[i][j]);
			}
		}
	}

	return closeCellular;
}
