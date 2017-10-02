#pragma once

#include <vector>
#include <memory>

#include "Cell.h"

class Automata
{
public:
	Automata(int _width, int _height);

	void update();


	const std::vector<std::vector<Cell>> *getCells() const { return m_currBuff.get(); };

	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }

	bool isProcessRunning() const { return m_nbIterr < 16; }

private:

	int GetCellsInRangeState(int _range, int _column, int _line, std::vector<std::vector<Cell>> *_buff) const;

	std::vector<std::vector<Cell>> m_buff1;
	std::vector<std::vector<Cell>> m_buff2;
	std::unique_ptr<std::vector<std::vector<Cell>>> m_currBuff;

	int m_width;
	int m_height;

	int m_nbIterr;
};

