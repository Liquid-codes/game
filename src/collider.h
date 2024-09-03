#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "player.h"
#include "background.h"

class Collider
{
private:
    sf::RectangleShape barrier;
    std::vector<sf::RectangleShape> collider_layout;
    
    std::vector<int> collider_map;
    std::vector<int> collider_map_2D;


    void initVariables();
    void initBarrier();
    void initCollider_Layout();

public:
    Collider();

    const std::vector<sf::RectangleShape>& returnShape() const;
    void update(Player& player, bool& move);
    void render(sf::RenderWindow* window);
};
