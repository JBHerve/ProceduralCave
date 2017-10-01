#pragma once

#include <vector>
#include "Cell.h"

class Automata
{
public:
	Automata(int _width, int _height);

	void update();


	const std::vector<std::vector<Cell>>* getCells() const { return &m_cells; };
	void setCells(std::vector<std::vector<Cell>>& _cells) { m_cells = _cells; }

	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }

	bool isProcessRunning() const { return m_nbIterr < 16; }

private:

	int GetCellsInRangeState(int _range, int _column, int _line) const;

	std::vector<std::vector<Cell>> m_cells;
	int m_width;
	int m_height;

	int m_nbIterr;
};

