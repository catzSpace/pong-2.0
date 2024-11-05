#ifndef MENUS_H
#define MENUS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Menus{

  public:
    Menus();

  public:
    void InitMenu(RenderWindow& app, int p1, int p2);
    void Score(RenderWindow& app);


};



#endif // !MENUS_H
