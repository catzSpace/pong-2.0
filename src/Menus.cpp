#include "../headers/Menus.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


Menus::Menus(){}


void Menus::InitMenu(RenderWindow& app, int p1, int p2){


  string scoreComplete = to_string(p1) + "|" + to_string(p2);

  Font font;

  //error (en caso de no encontrar la fuente)
  if(!font.loadFromFile("./assets/slkscr.ttf")){
    cout << "error" <<endl;

    system("pause"); 
  }

  Text score;

  score.setFont(font);
  score.setString(scoreComplete);
  score.setCharacterSize(50);
  score.setPosition(940, 20);
  score.setFillColor(Color::White);

  app.draw(score);
}
