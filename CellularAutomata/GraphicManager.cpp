#include "GraphicManager.h"

#include "Manager.h"
#include "InputManager.h"



GraphicManager::GraphicManager()
{
	m_window.create(sf::VideoMode(500, 500), "Procedural cave");
	m_window.setFramerateLimit(30);
}

void GraphicManager::closeWindow()
{
	m_window.close();
}

void GraphicManager::update()
{
	int size = Manager::getAutomata().getSize();

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		InputManager::update(event);
	}

	if (Manager::getAutomata().isProcessRunning())
	{
		m_window.clear(sf::Color::White);

		int i = 0;
		for (std::vector<Cell> vector : *Manager::getAutomata().getCells())
		{
			int j = 0;
			for (Cell cell : vector)
			{
				if (!cell.getState())
				{
					sf::RectangleShape shape(sf::Vector2f(m_window.getSize().x / size, m_window.getSize().y / size));
					shape.setPosition(sf::Vector2f(i * m_window.getSize().x / size, j * m_window.getSize().y / size));
					shape.setFillColor(sf::Color::Black);
					m_window.draw(shape);
				}
				++j;
			}
			++i;
		}

		m_window.display();
	}

}
