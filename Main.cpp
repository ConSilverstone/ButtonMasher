//Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//start of program functions
int main() 
{
	//--------------------------
	//Game Setup
	//--------------------------

	//declaring a type called gamewindow for SFML's render window 
	sf::RenderWindow gamewindow;
	gamewindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
		sf::Style::Titlebar | sf::Style::Close);
	

	//Create Button Sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	// Center the sprite on the screen
	buttonSprite.setPosition(
		gamewindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gamewindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	//Create Music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	gameMusic.play();
	
	// Create Font 
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	// Create Title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color (255, 165, 0));
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gamewindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);


	// Create Title
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Connor Gallagher");
	authorText.setPosition(gamewindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, gamewindow.getSize().y / 2 - authorText.getLocalBounds().height + 100);

	//--------------------------
	//Game Loop
	//--------------------------

	//Runs every frame until the game window is closed
	while (gamewindow.isOpen())
	{
		//Check for input
		sf::Event gameEvent;

		while (gamewindow.pollEvent(gameEvent))
		{
			// Process Events

			//check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//close the game window
				gamewindow.close();
			}
		} 

		//TODO: Update game state

		//--------------------------
		//Draw Graphics
		//--------------------------

		//Clear the window to a single colour
		gamewindow.clear(sf::Color::Black);

		//Draw everything 
		gamewindow.draw(buttonSprite);
		gamewindow.draw(titleText);
		gamewindow.draw(authorText);

		//Display window contents on screen
		gamewindow.display();
	}
	return 0; //Used to end off the program
}