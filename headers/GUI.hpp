#ifndef __GUI_H__
#define __GUI_H__

#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>

class Canvas {
  private:
    bool visible;
  public:
    Canvas();
    ~Canvas();
    void setVisible();
    void setInvisible();
    void addElement();
    void draw(sf::RenderWindow* target);
};

#endif