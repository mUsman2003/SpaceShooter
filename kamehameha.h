#include <SFML/Graphics.hpp>
#include<string.h>

using namespace std;
using namespace sf;
class GokuBeam
{
public:
    Sprite sprite;
    Texture BulletMiddle;
    Texture Bullet30Left;
    Texture Bullet30Right;
    int MaxBullets;
    float speed;
    float DirY,DirX;

    GokuBeam()
    {
        BulletMiddle.loadFromFile("img/boss/gokubeam0.png");
        Bullet30Left.loadFromFile("img/boss/gokubeam-30.png");
        Bullet30Right.loadFromFile("img/boss/gokubeam30.png");
        sprite.setTexture(Bullet30Right);
        sprite.scale(0.7,0.7);
        speed=7.0f;
    }

    ~GokuBeam(){}

    void setDirection(float x,float y)
    {
        DirX=x;
        DirY=y;
    }
    void SetTexture(int n)
    {
        if(n==0)
            sprite.setTexture(BulletMiddle);
        else if(n==30)
            sprite.setTexture(Bullet30Right);
        else if(n==-30)
            sprite.setTexture(Bullet30Left);
    }
    
    void SetPosition(float x,float y)
    {
        sprite.setPosition(x-20,y+60);
    }
    void Updatebullet()
    {
        sprite.move(DirX*speed,DirY*speed);
    }
    bool IsOFFscreen()
    {
        return sprite.getPosition().y>900;
    }
};