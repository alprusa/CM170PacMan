#include <SFML/Graphics.hpp>
#include "Ghosts.h"

using namespace std;

Ghosts::Ghosts(bool ghost, sf::Texture& ghostsT, float xPos, float yPos):notGhost(ghost), x(xPos), y(yPos){
    ghostEnemy = sf::Sprite(ghostsT);
    ghostEnemy.setTextureRect(sf::IntRect(197,70,120,115));
    ghostEnemy.setPosition(sf::Vector2f(x,y));
}

void Ghosts::ghostAi(){
    cout << "we are ghosts" << endl;
}

void Ghosts::moveAnimation(int amount){
    ghostEnemy.setTextureRect(sf::IntRect(197+amount,70,120,115));
}
