#include "../headers/Player.h"
#include <iostream>

// caracteristicas del jugador
Player::Player(int x, int y) : playerRec(Vector2f(40, 300)){
  playerRec.setPosition(x, y);
  playerRec.setFillColor(Color::White);
}

// dibujar jugador
void Player::renderPlayer(RenderWindow& app){
  app.draw(Player::playerRec);
}


// movimiento del jugador
void Player::movePlayer( int p ){

  // p = numero del jugador 1 o 2
  // TODO colision con el escenario

  if (p == 1){
    if (Keyboard::isKeyPressed(Keyboard::Key::E)){
      playerRec.move(0, -1.5);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D)){
      playerRec.move(0, 1.5);
    }
  }

  if (p == 2) {
    if (Keyboard::isKeyPressed(Keyboard::Key::U)){
      playerRec.move(0, -1.5);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::J)){
      playerRec.move(0, 1.5);
    }

  }

}


// posicion en tiempo real de ambos jugadores
int Player::getPositionX(){
  float px = playerRec.getPosition().x;
  return px;
}

int Player::getPositionY(){
  float py = playerRec.getPosition().y;
  return py;
}
