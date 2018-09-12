//Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

//start of program functions
int main() 
{
	//--------------------------
	//Game Setup
	//--------------------------

	//declaring a type called gamewindow for SFML's render window//
	sf::RenderWindow gamewindow;
	gamewindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
		sf::Style::Titlebar | sf::Style::Close);
	

	//Create Button Sprite//
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	//Center the sprite on the screen//
	buttonSprite.setPosition(
		gamewindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gamewindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	//Create Music//
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	gameMusic.play();
	
	//Create Font//
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//Create Title//
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color (255, 165, 0));
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gamewindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);

	//Create Author Text//
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Connor Gallagher");
	authorText.setPosition(gamewindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, gamewindow.getSize().y / 2 - authorText.getLocalBounds().height + 100);

	//Prompt Text
	sf::Text promptText;
	promptText.setFont(gameFont);
	promptText.setString("Click the button to start the game!");
	promptText.setCharacterSize(16);
	titleText.setFillColor(sf::Color(255, 165, 0));
	promptText.setPosition(gamewindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 200);


	int score = 0;

	//Score Text//
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setPosition(30, 30);

	//Timer Text//
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gamewindow.getSize().x - timerText.getLocalBounds().width - 30, 30);

	//Timer Functionality//
	sf::Time timeLimit = sf::seconds(10.0f); //Time is a float
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;

	//Click sound effect
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);

	//Gameover sound effect
	sf::SoundBuffer gameoverBuffer;
	gameoverBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound gameoverSound;
	gameoverSound.setBuffer(gameoverBuffer);

	//Game State//
	bool playing = false;

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
			
			//check if the event is a mouse button pressed event
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					//We clicked the button!!!!
					
					if (playing == true) 
					{
						//Yes - increase score!
						score = score + 1;
					}
					else
					{
						//No - start playing now!
						playing = true;

						//Reset the game data
						score = 0;
						timeRemaining = timeLimit;

						promptText.setString("Click the button as fast as you can!!!!");
					}
					
					//Play the click sound
					clickSound.play();
				}
			}


			//check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//close the game window
				gamewindow.close();
			}
		} 

		// Update game state
		sf::Time frameTime = gameClock.restart();

		if (playing == true)
		{
			timeRemaining = timeRemaining - frameTime;
			
			if (timeRemaining.asSeconds() <= 0.0f)
			{
				timeRemaining = sf::seconds(0.0f);
				playing = false;
				gameoverSound.play();
				promptText.setString("Your final score was " + std::to_string(score) + "!\nClick the button to start a new game!");
			}
		}

		timerText.setString("Time Remaining: " + std::to_string((int)timeRemaining.asSeconds()));
		scoreText.setString("Score: " + std::to_string(score));

		//--------------------------
		//Draw Graphics
		//--------------------------

		//Clear the window to a single colour
		gamewindow.clear(sf::Color::Black);

		//Draw everything 
		gamewindow.draw(buttonSprite);
		gamewindow.draw(titleText);
		gamewindow.draw(authorText);
		gamewindow.draw(scoreText);
		gamewindow.draw(timerText);
		gamewindow.draw(promptText);

		//Display window contents on screen
		gamewindow.display();
	}
	return 0; //Used to end off the program
}