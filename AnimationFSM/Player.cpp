#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::IDLE:
		//std::cout << "Player Idling" << std::endl;
		m_state.idle();
		
		
		if (j < 2  && j >= 0)
		{
			m_animated_sprite.setCurrentFrame(j);
		}
		else
		{
			m_animated_sprite.setCurrentFrame(0);
		}
	
		break;
	case Input::Action::UP:
		//std::cout << "Player Up" << std::endl;
		m_state.climbing();
	
		if (j < 22 && j > 19)
		{
			m_animated_sprite.setCurrentFrame(j);
		}
		else
		{
			m_animated_sprite.setCurrentFrame(19);
		}
		
		
		break;
	case Input::Action::LEFT:
		//std::cout << "Player Left" << std::endl;
		m_state.jumping();
	
		if (j < 5 && j > 2)
		{
			m_animated_sprite.setCurrentFrame(j);
		}
		else
		{
			m_animated_sprite.setCurrentFrame(3);
		}
		break;
	case Input::Action::RIGHT:
		//std::cout << "Player Idling" << std::endl;
		
		m_state.jumping();
		if (j < 5 && j > 2)
		{
			m_animated_sprite.setCurrentFrame(j);
		}
		else
		{
			m_animated_sprite.setCurrentFrame(3);
		}
	
			break;
	case Input::Action::SPACE:
		//std::cout << "Player Idling" << std::endl;
		m_state.attacking();
		if (j < 9 && j > 4)
		{
			m_animated_sprite.setCurrentFrame(j);
		}
		else
		{
			m_animated_sprite.setCurrentFrame(5);
		}
	
		break;
	case Input::Action::ONE:
		//std::cout << "Player Idling" << std::endl;
		m_state.running();
		
		if (j < 15 && j > 9)
		{
			m_animated_sprite.setCurrentFrame(j);
		}
		else
		{
			m_animated_sprite.setCurrentFrame(10);
		}
		break;
	case Input::Action::TWO:
		//std::cout << "Player Idling" << std::endl;
		m_state.taunting();
		if(in.getCurrent() == Input::Action::TWO)
		if (j > 16 && j < 20)
		{
			m_animated_sprite.setCurrentFrame(j);
		}
		else
		{
			m_animated_sprite.setCurrentFrame(16);
		}
	
		break;
	case Input::Action::THREE:
		//std::cout << "Player Idling" << std::endl;
		m_state.defending();

		m_animated_sprite.setCurrentFrame(15);
		break;
	default:
	
		break;
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
	j = m_animated_sprite.getCurrentFrame();
}