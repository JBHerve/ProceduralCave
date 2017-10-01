#pragma once

#include "GraphicManager.h"
#include "Automata.h"

class Manager
{
public:

	static void init(int _width, int _height) { m_automata = new Automata(_width, _height); }

	static const Automata& getAutomata() { return *m_automata; }
	static const GraphicManager& getGraphicManager() { if (!m_graphic) { m_graphic = new GraphicManager(); } return *m_graphic; }

	static void updateGraphic() { m_graphic->update(); }
	static void updateAutomata() { m_automata->update(); }

	static void closeWindow() { m_graphic->closeWindow(); }

private:
	static GraphicManager  *m_graphic;
	static Automata *m_automata;
};
