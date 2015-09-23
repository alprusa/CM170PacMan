#include <SFML/Graphics.hpp>
#include "PacManSprite.h"

using namespace std;

PacMan::PacMan(float xPos, float yPos):x(xPos), y(yPos){
    textureMove = 0;

     //load the pacman texture
    if (!pacManImage.loadFromFile("PacManSheet.png"))
        return;

    pacMan = sf::Sprite(pacManImage);
    pacMan.setTextureRect(sf::IntRect(1,105,64,64));
    pacMan.setScale(sf::Vector2f(0.7,0.7));
    pacMan.setPosition(sf::Vector2f(x,y));
}

void PacMan::PacManAnimate(){
    pacMan.setTextureRect(sf::IntRect(3 + textureMove,105,64,64));

    textureMove += 64;
    if(textureMove > 128) textureMove = 0;
}

void PacMan::movePac(int speed, string direction){
    if(pacMan.getPosition().x > 0 && direction == "left") {
        pacMan.setRotation(0);
        pacMan.move(-speed,0);
    }
    if(pacMan.getPosition().x < 700 && direction == "right") {
        pacMan.setRotation(180);
        pacMan.move(speed,0);
    }
    if(pacMan.getPosition().y > 0 && direction == "up") {
        pacMan.setRotation(90);
        pacMan.move(0,-speed);
    }
    if(pacMan.getPosition().y < 800 && direction == "down") {
        pacMan.setRotation(-90);
        pacMan.move(0,speed);
    }
    PacManAnimate();
}
