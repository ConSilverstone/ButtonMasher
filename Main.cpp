//Included Libraries
#include <SFML/Graphics.hpp>


//start of program functions
int main() 
{
	//declaring a type called gamewindow for SFML's render window 
	sf::RenderWindow gamewindow;
	gamewindow.create(sf::VideoMode(800, 600), "Button Masher");

	while (gamewindow.isOpen()) //Game Loop
	{
		//Check for input
		sf::Event gameEvent;

		while (gamewindow.pollEvent(gameEvent))
		{
			//TODO: Process Events
			//check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//close the game window
				gamewindow.close();
			}
		}

		//TODO: Update game state

		//TODO: Draw Graphics
	}
	return 0; //Used to end off the program
}