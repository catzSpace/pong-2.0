#include "../headers/Ball.h"
#include <iostream>


Ball::Ball(int x, int y) : ballCir(30){
  ballCir.setFillColor(Color::White);
  ballCir.setPosition(x, y);
}


void Ball::renderBall(RenderWindow& app){
  app.draw(Ball::ballCir);
}


int Ball::movex(int x){

  int px = Ball::ballCir.getPosition().x;

  if (px >= 1870 || px <= 0) {
    x = -x;
  }

  return x;
}


int Ball::movey(int y){

  int py = Ball::ballCir.getPosition().y;

  if(py >= 1020 || py <= 0) {
    y = -y;
  }
  return y;
}


void Ball::m(int x, int y){
  Ball::ballCir.move(x, y);
}



// colicion con la zona de puntos de cada jugador
int Ball::pointsp1(int s2){

  int px = Ball::ballCir.getPosition().x;
  int py = Ball::ballCir.getPosition().y;

  if (px <= 0 && py <=  1020 && py >= 0) {
    s2 += 1;
  }

  return s2;

}

int Ball::pointsp2(int s1){

  int ballpx = Ball::ballCir.getPosition().x;
  int ballpy = Ball::ballCir.getPosition().y;

  if (ballpx >= 1870 && ballpy <=  1020 && ballpy >= 0) {
    s1 += 1;
  }

  return s1;

}


void Ball::PlayerColision(int p1x, int p1y, int p2x, int p2y, int& x){
  int ballpx = Ball::ballCir.getPosition().x;
  int ballpy = Ball::ballCir.getPosition().y;

  if (ballpx >= 50 && ballpx <= 110 )
    {
      if (ballpy >= p1y && ballpy <= p1y + 300)
      {
        x = -x;
        //std::cout << ballpx << ",";
      }
  }

  if (ballpx >= 1770 && ballpx <= 1850 )
    {
      if (ballpy >= p2y && ballpy <= p2y + 300)
      {
        x = -x;
        //std::cout << ballpx << ",";
      }
  }

}
