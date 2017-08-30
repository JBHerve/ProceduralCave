#include "Automata.h"
#include <ctime>

Automata::Automata(int _size)
{
	srand(time(0));
	m_size = _size;
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
				int count = 9 - (tmp[i][j].getState() ? 1 : 0);
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
					count += 8;
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

std::vector<Cell> Automata::GetCellsInRange(int _range, int _column, int _line)
{
	std::vector<Cell> closeCellular = std::vector<Cell>();

	
	if (_column > _range - 1)
	{
		closeCellular.push_back(m_cells[_column - _range][_line]);

		if (_line > _range - 1)
		{
			closeCellular.push_back(m_cells[_column - _range][_line - _range]);
		}
		if (_line + _range < m_size)
		{
			closeCellular.push_back(m_cells[_column - _range][_line + _range]);
		}
	}

	if (_line > _range - 1)
	{
		closeCellular.push_back(m_cells[_column][_line - _range]);

		if (_column + 2 < m_size)
		{
			closeCellular.push_back(m_cells[_column + _range][_line - _range]);
		}
	}

	if (_column + _range < m_size)
	{
		closeCellular.push_back(m_cells[_column + _range][_line]);

		if (_line + _range < m_size)
		{
			closeCellular.push_back(m_cells[_column + _range][_line + _range]);
		}
	}
	if (_line + _range < m_size)
	{
		closeCellular.push_back(m_cells[_column][_line + _range]);
	}

	return closeCellular;
}
