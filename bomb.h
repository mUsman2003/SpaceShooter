#include <SFML/Graphics.hpp>
#include<string.h>

using namespace std;
using namespace sf;
class Bomb
{
public:
    Sprite sprite;
    Texture text;
    int MaxBombs;
    float speed=0.75;

    Bomb()
    {
        text.loadFromFile("img/bullets/bomb.png");
        sprite.setTexture(text);
        sprite.setScale(1.f,1.f);
        speed=2.0f;
    }

    ~Bomb(){}
    void SetPosition(float x,float y)
    {
        sprite.setPosition(x-5,y);
    }
    void UpdateBomb()
    {
        sprite.move(0,1.f*speed);
    }
    bool IsOFFscreen()
    {
        return sprite.getPosition().y>900;
    }
};