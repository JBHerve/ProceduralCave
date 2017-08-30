#include "GraphicManager.h"
#include "Manager.h"



GraphicManager::GraphicManager()
{
	m_window.create(sf::VideoMode(500, 500), "Procedural cave");
	m_window.setFramerateLimit(2);

	int size = Manager::getAutomata().getSize();

	m_shapes = std::vector<sf::RectangleShape>(size * size);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{

			sf::RectangleShape shape(sf::Vector2f(m_window.getSize().x / size, m_window.getSize().y / size));
			shape.setPosition(sf::Vector2f(i * m_window.getSize().x / size, j * m_window.getSize().y / size));
			m_shapes[i * size + j] = shape;
		}
	}
}

void GraphicManager::update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
		}*/
	}

	m_window.clear();

	int size = Manager::getAutomata().getSize();

	int i = 0;
	for (std::vector<Cell> vector : *Manager::getAutomata().getCells())
	{
		int j = 0;
		for (Cell cell : vector)
		{
			if (cell.getState())
			{
				m_shapes[i * size + j].setFillColor(sf::Color::White);
			}
			else
			{
				m_shapes[i * size + j].setFillColor(sf::Color::Black);
			}
			++j;
		}
		++i;
	}


	for (sf::RectangleShape shape : m_shapes)
	{
		m_window.draw(shape);
	}

	m_window.display();

}
