#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\sprite.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	
	
	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);
	//idle

	animated_sprite.addFrame(sf::IntRect(0, 0, 170, 170));
	animated_sprite.addFrame(sf::IntRect(170, 0, 170, 170));
	animated_sprite.addFrame(sf::IntRect(340, 0, 170, 170));

	//jump
	animated_sprite.addFrame(sf::IntRect(510, 0, 170, 170));
	animated_sprite.addFrame(sf::IntRect(680, 0, 170, 170));

	//attacking
	animated_sprite.addFrame(sf::IntRect(850, 0, 170, 170));

	animated_sprite.addFrame(sf::IntRect(0, 170, 170, 170));
	animated_sprite.addFrame(sf::IntRect(170, 170, 170, 170));
	animated_sprite.addFrame(sf::IntRect(340, 170, 170, 170));
	animated_sprite.addFrame(sf::IntRect(510, 170, 170, 170));
	//running

	animated_sprite.addFrame(sf::IntRect(850, 340, 170, 170));

	animated_sprite.addFrame(sf::IntRect(0, 510, 170, 170));
	animated_sprite.addFrame(sf::IntRect(170, 510, 170, 170));
	animated_sprite.addFrame(sf::IntRect(340, 510, 170, 170));
	animated_sprite.addFrame(sf::IntRect(510, 510, 170, 170));


	//defending
	animated_sprite.addFrame(sf::IntRect(340, 170, 170, 170));

	//taunting

	animated_sprite.addFrame(sf::IntRect(0, 1020, 170, 170));
	animated_sprite.addFrame(sf::IntRect(170, 1020, 170, 170));
	animated_sprite.addFrame(sf::IntRect(340, 1020, 170, 170));
	animated_sprite.addFrame(sf::IntRect(510, 1020, 170, 170));
	//climbing
	animated_sprite.addFrame(sf::IntRect(510, 850, 170, 170));
	animated_sprite.addFrame(sf::IntRect(850, 850, 170, 170));
	

	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		player.i++;
		// Process events
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Left)
				{
					input.setCurrent(Input::Action::LEFT);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					input.setCurrent(Input::Action::RIGHT);

				}
				else if (event.key.code == sf::Keyboard::Up)
				{
					input.setCurrent(Input::Action::UP);
				}
				else if (event.key.code == sf::Keyboard::Space)
				{
					input.setCurrent(Input::Action::SPACE);
				}
				else if (event.key.code == sf::Keyboard::Num1)
				{
					input.setCurrent(Input::Action::ONE);
				}
				else if (event.key.code == sf::Keyboard::Num2)
				{
					input.setCurrent(Input::Action::TWO);
				}
				else if (event.key.code == sf::Keyboard::Num3)
				{
					input.setCurrent(Input::Action::THREE);
				}


				break;
			case sf::Event::KeyReleased:

				if (event.key.code == sf::Keyboard::Right)
				{
					input.setCurrent(Input::Action::IDLE);
				}
				if (event.key.code == sf::Keyboard::Num2)
				{
					input.setCurrent(Input::Action::IDLE);
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					input.setCurrent(Input::Action::IDLE);
				}
				break;
			}
			
			
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};