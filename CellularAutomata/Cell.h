#pragma once
class Cell
{
public:
	Cell();

	bool getState() const {return m_state;}
	void setState(bool _state) { m_state = _state; }

private:
	bool m_state;
};

