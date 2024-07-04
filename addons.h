
#include <SFML/Graphics.hpp>
#include<string.h>

using namespace std;
using namespace sf;
class Addons
{
public:
    Sprite sprite;
    Texture LiveAdd;    //2
    Texture LiveRemove; //3
    Texture Fire2x;     //4
    Texture FireHalf;   //5      

    int PowerUpState;
    Addons()
    {
        PowerUpState=0;
        LiveAdd.loadFromFile("img/power/liveadd.png");
        LiveRemove.loadFromFile("img/power/liveremove.png");
        Fire2x.loadFromFile("img/power/fire2x.png");
        FireHalf.loadFromFile("img/power/fire0_5.png");
        sprite.setTexture(LiveAdd);
        sprite.setScale(1.5,1.5);
        sprite.setPosition(100,100);
    }
    ~Addons(){}
    int RandomPower()//to be updatesd the size of powerups
    {   
        int t=rand()%4+1;
        PowerUpState=t;
        if(t==1)
        {
            sprite.setTexture(LiveAdd);
        }
        else if(t==2)
        {
            sprite.setTexture(LiveRemove);
        }
        else if(t==3)
        {
            sprite.setTexture(Fire2x);
        }
        else if(t==4)
        {
            sprite.setTexture(FireHalf);
        }
        return PowerUpState;
    }
    void SpawnPower()
    {
        sprite.setPosition(100+rand()%1000+1,0);
    }
    void Update()
    {
        sprite.move(0,1.f);
    }
    void Draw(RenderWindow& window)
    {
        window.draw(sprite);
    }
    bool IsOFFscreen()
    {
        return sprite.getPosition().y>900;
    }
};