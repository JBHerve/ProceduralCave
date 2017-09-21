#include "InputManager.h"

#include "Manager.h"


void InputManager::update(sf::Event _event)
{
		if (_event.type == sf::Event::Closed)
			Manager::closeWindow();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int size = Manager::getAutomata().getSize();
			Manager::init(size);
		}
}
