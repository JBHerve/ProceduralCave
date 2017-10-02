#include "Automata.h"
#include <ctime>

Automata::Automata(int _width, int _height)
	: m_width(_width), m_height(_height), m_nbIterr(0)
{
	srand(time(0));
	m_buff1 = std::vector<std::vector<Cell>>(_width);
	for (size_t i = 0; i < _width; i++)
	{
		m_buff1[i] = std::vector<Cell>(_height);
	}

	for (size_t i = 0; i < m_width; i++)
	{
		m_buff1[i][0].setState(false);
		m_buff1[i][m_height - 1].setState(false);
	}
	for (size_t i = 0; i < m_height; i++)
	{
		m_buff1[0][i].setState(false);
		m_buff1[m_width - 1][i].setState(false);
	}

	m_buff2 = m_buff1;

	m_currBuff = std::unique_ptr<std::vector<std::vector<Cell>>>(&m_buff1);
}

void Automata::update()
{
	if (isProcessRunning())
	{
		std::unique_ptr<std::vector<std::vector<Cell>>> oldBuff; ;
		if (m_currBuff.get() == &m_buff1)
		{
			oldBuff = std::unique_ptr<std::vector<std::vector<Cell>>>(&m_buff2);
		}
		else
		{
			oldBuff = std::unique_ptr<std::vector<std::vector<Cell>>>(&m_buff1);
		}
		m_currBuff.swap(oldBuff);

		for (int i = 0; i < m_width; i++)
		{
			for (int j = 0; j < m_height; j++)
			{

				//We decrease the max count in order to consider tiles out of bounds like walls.
				int count = 9 - (m_buff1[i][j].getState() ? 1 : 0);
				count -= GetCellsInRangeState(1, i, j, oldBuff.get());

				//Game of life
				/*if (count != 2)
				{
					tmp[i][j].setState(count != 3);
				}*/

				if (m_nbIterr < 4 && count < 5)
				{
					count += 16 - GetCellsInRangeState(2, i, j, oldBuff.get()) ;
					(*m_currBuff)[i][j].setState(count > 2);
				}
				else
				{
					(*m_currBuff)[i][j].setState(count < 5);
				}

			}
		}
		++m_nbIterr;
		oldBuff.release();
	}
}

int Automata::GetCellsInRangeState(int _range, int _column, int _row, std::vector<std::vector<Cell>> *_buff) const
{
	int count = 0;

	int lowerBound = _row - _range;
	int upperBound = _row + _range;
	for (int i = _column - _range; i <= _column + _range; i++)
	{

		if (i >= 0 && i < m_width)
		{
			if (lowerBound >= 0 && lowerBound < m_height && (*_buff)[i][lowerBound].getState())
			{
				++count;
			}

			if (upperBound >= 0 && upperBound < m_height && (*_buff)[i][upperBound].getState())
			{
				++count;
			}
		}
	}

	lowerBound = _column - _range;
	upperBound = _column + _range;
	for (size_t i = _row - _range + 1; i < _row + _range; i++)
	{

		if (i >= 0 && i < m_height)
		{
			if (lowerBound >= 0 && lowerBound < m_width && (*_buff)[lowerBound][i].getState())
			{
				++count;
			}
			if (upperBound >= 0 && upperBound < m_width && (*_buff)[upperBound][i].getState())
			{
				++count;
			}
		}
	}

	return count;
}
