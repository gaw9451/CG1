#include <SFML/System.hpp>
#include <iostream>

int main() {
	sf::Clock clock;
	while(clock.GetElapsedTime() < 5.f) {
		std::cout << clock.GetElapsedTime() << std::endl;
		sf::Sleep(0.5f);
	}
	return 0;
}
