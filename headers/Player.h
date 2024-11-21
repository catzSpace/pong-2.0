#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player{
  public:
    Player(int x, int y);

    int score;
    RectangleShape playerRec;
 

  public:
    void renderPlayer(RenderWindow& app);
    void movePlayer(int p, int alto, int ancho);
    int getPositionX();
    int getPositionY();
    

    

};

#endif // !PLAYER_H
