#include <SFML/Graphics.hpp>
#include<string.h>

using namespace std;
using namespace sf;
class Laser
{
public:
    Sprite sprite;
    Texture text;

    Laser()
    {
        text.loadFromFile("img/bullets/laser.png");
        sprite.setTexture(text);
        sprite.setScale(3.f,30.f);
    }

    ~Laser(){}
    void SetPosition(float x,float y)
    {
        sprite.setPosition(x-5,y);
    }
};
