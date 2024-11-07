#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>


//game elements

#include "./headers/Player.h"
#include "./headers/Ball.h"
#include "./headers/Menus.h"


using namespace sf;

void renderInicio(RenderWindow& App, Text tittle[4], const string str[4], const int medidas[4][3]){
  Font font;

  //error (en caso de no encontrar la fuente)
  if(!font.loadFromFile("./assets/slkscrb.ttf")){
    std::cout << "error \n";

    system("pause"); 
  }


  for (int i = 0; i < 4; i++){
    tittle[i].setFont(font);
    tittle[i].setString(str[i]);


    tittle[i].setCharacterSize(medidas[i][0]);
    tittle[i].setPosition(medidas[i][1], medidas[i][2]);
    tittle[i].setFillColor(Color::White);

    App.draw(tittle[i]);
  }

}

void pantallaInicio(RenderWindow& App){

  Text titulo, enter, autor, version;
  const std::string componentes[4] = {"PonG!", "-Press Enter-", "catzspace", "2.0"};
  Text nombres[4] = {titulo, enter, autor, version};
  const int medidas[4][3] = {
    {130, 690, 380},
    {27, 810, 520},
    {27, 20, 17},
    {27, 1850, 17}
  };

  
  renderInicio(App, nombres, componentes, medidas);

}


/* MAIN FUNCTION */


int main(){

  RenderWindow App(VideoMode::getDesktopMode(), "Pong!", Style::Fullscreen);
  //system("bspc node -t floating>2");
  App.setActive();

  bool status = false;
  
  // posicion inicial en y
  int yp1 = 400;
  int yp2 = 400;

  // velocidad de la pelota
  int x = 3, y = 3; 

  // score 
  int s1 = 0, s2 = 0; 

  // instancias de los elementos del juego

  Ball ballcir(900, 500);

  Player player1(80, yp1);
  Player player2(1800, yp2);
  
  Menus menu;


  while (App.isOpen())
  {
      // Eventos
      Event event;
      while (App.pollEvent(event))
      {
            // Cerrar ventana
          if (event.type == Event::Closed){
            App.close();
          } 
          if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
          {
            status = true;
          }
          if (Keyboard::isKeyPressed(Keyboard::Key::Escape)){
            status = false;
          }
      }

      // Clear the screen (fill it with black color)
      App.clear(Color::Black);


      if (status){
      
        // jugadores
        player1.renderPlayer(App);
        player2.renderPlayer(App);

        player1.movePlayer(1);
        player2.movePlayer(2);

        // posiciones x, y de ambos jugadores
        int p1x = player1.getPositionX();
        int p2x = player2.getPositionX();
        int p1y = player1.getPositionY();
        int p2y = player2.getPositionY();

        //std::cout << p1x << "\n\n";
        //std::cout << p1y <<",";


        // pelota
        ballcir.renderBall(App);
        x = ballcir.movex(x);
        y = ballcir.movey(y);
        ballcir.m(x, y);
        ballcir.PlayerColision(p1x, p1y, p2x, p2y, x);
        s2 = ballcir.pointsp1(s2);
        s1 = ballcir.pointsp2(s1);
        menu.InitMenu(App, s1, s2);

      } else {
        pantallaInicio(App);
      }
      // Display window contents on screen
      App.display();
      
  }
  return 0;
}
