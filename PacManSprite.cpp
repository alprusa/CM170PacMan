#include <SFML/Graphics.hpp>
#include "PacManSprite.h"

using namespace std;

PacMan::PacMan(sf::Texture& pacManText, float xPos, float yPos):x(xPos), y(yPos){
    pacMan = sf::Sprite(pacManText);
    pacMan.setTextureRect(sf::IntRect(0,100,100,115));
    //pacMan.setScale(sf::Vector2f(0.5,0.5));
    pacMan.setPosition(sf::Vector2f(x,y));
}
