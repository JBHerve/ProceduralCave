#include <SFML/Graphics.hpp>
#include "Manager.h"

GraphicManager  *Manager::m_graphic;
Automata *Manager::m_automata;

int main()
{
	sf::Clock Clock;

	Manager::Manager::init(100);

	while (Manager::getGraphicManager().windowOpen())
	{


		bool timeUp = false;

		if (Clock.getElapsedTime().asSeconds() > 1)
		{
			timeUp = true;
			Clock.restart();
		}

		Manager::updateGraphic();
		if (timeUp)
		{
			Manager::updateAutomata();
		}
	}

	return 0;
}