#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball{
  public:
    Ball(int x, int y);

    CircleShape ballCir;


  public:
    void renderBall(RenderWindow& app);
    int movex(int x);
    int movey(int y);
    void m(int x, int y);
    int pointsp1(int s1);
    int pointsp2(int s2);
    void PlayerColision(int p1x, int p1y, int p2x, int p2y, int& x);

};

#endif // !BALL_H
