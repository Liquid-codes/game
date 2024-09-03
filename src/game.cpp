#include "game.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

// Initalizing variables
void Game::initVariables()
{

}

// Initalizing the window
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Game", sf::Style::Fullscreen | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

// Calls on run
Game::Game() : player(), collider(), background_image()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

// Checks for events such as keypress
void Game::pollEvents()
{
    while(this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                {
                    this->window->close();
                    break;
                }
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                    break;
                }
        }
    }
}

// Returns wether the window is open or closed
const bool Game::isRunning() const
{
    return this->window->isOpen();
}

// Constantly updates all functions
void Game::update()
{
    this->pollEvents();
    this->player.update(*this->window, this->background_image.attributes());
    this->background_image.update(this->player);
    this->collider.update(this->player, this->background_image.move);
    this->ani_control.update(this->player.state, this->player.direction, this->player.getShape());
}

// Renders everything
void Game::render()
{
    this->window->clear();
    this->background_image.render(this->window);
    this->collider.render(this->window);
    this->player.render(this->window);
    this->window->display();
}
