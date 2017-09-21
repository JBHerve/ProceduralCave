#pragma once

#include <SFML/Graphics.hpp>

class GraphicManager
{
public:
	GraphicManager();

	bool windowOpen() const { return m_window.isOpen(); }
	void closeWindow();

	void update();

private:
	sf::RenderWindow m_window;
	std::vector<sf::RectangleShape> m_shapes;
};

