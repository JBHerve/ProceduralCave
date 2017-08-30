#pragma once

#include <vector>
#include "Cell.h"

class Automata
{
public:
	Automata(int _size);

	void update();


	const std::vector<std::vector<Cell>>* getCells() const { return &m_cells; };
	void setCells(std::vector<std::vector<Cell>>& _cells) { m_cells = _cells; }

	int getSize() const { return m_size; }

private:

	std::vector<Cell> GetCellsInRange( int _range, int _column, int _line);

	std::vector<std::vector<Cell>> m_cells;
	int m_size;
};

