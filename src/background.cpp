#include "background.h"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

void Background::initVariables()
{
    this->image_location = "../assets/map/map.png";
}

void Background::initBackground()
{
    this->image.loadFromFile(this->image_location, sf::IntRect(0, 0, 1120, 960));
    this->background.setTexture(this->image);
    this->background.scale(3.f, 3.f);
    this->background.setPosition(0, 0);
}

Background::Background()
{
    this->initVariables();
    this->initBackground();
}

sf::Sprite& Background::attributes() 
{
    return this->background;
}

void Background::update(Player& player)
{
    
    if ((player.getShape().getPosition().x > 380.f && player.getShape().getPosition().x < 1440.f) && (player.getShape().getPosition().y > 352.f && player.getShape().getPosition().y < 955.f))
    {
        move = true;
        this->background.move(player.returnSpeed().x, player.returnSpeed().y);
    }
    else 
    {
        move = false;
    }
    
}

void Background::render(sf::RenderWindow* window)
{
    window->draw(this->background);
}
