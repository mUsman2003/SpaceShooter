#include <SFML/Graphics.hpp>
#include<string.h>

using namespace std;
using namespace sf;
class Rock
{
public:
    Sprite sprite;
    Texture T4;
    Rock()
    {
        T4.loadFromFile("img/meteors/4.png");
        sprite.setTexture(T4);

    }
    ~Rock(){}    
    void SetPosition(float x,float y)
    {
        sprite.setPosition(x,y);
    }
    void UpdateRock()
    {
        sprite.move(0,1.5);
    }
    bool IsOFFscreen()
    {
        return sprite.getPosition().y>900;
    }
};