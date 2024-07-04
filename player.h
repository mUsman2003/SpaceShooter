#include <SFML/Graphics.hpp>
#include <string.h>
#include "bullet.h"
#include "addons.h"

using namespace std;
using namespace sf;
class Player
{
public:
	Sprite sprite;
	int HP,MaxHP;
	float speed;
	Bullet* B;
	int MaxBullets;
    int NumBullets;
	Addons Power;
	bool Numpowers;

	Player(Texture *temp)
	{
		MaxHP=3;
		HP=MaxHP;
		speed=5.f;
		sprite.setTexture(*temp);
		sprite.setScale(0.1,0.09);
		sprite.setPosition(600-sprite.getGlobalBounds().width/2.f,700);

		//Bullet
        MaxBullets=500;
        NumBullets=0;
        B=new Bullet[MaxBullets];

		//Addon
		Numpowers=false;


	}
	~Player(){	delete[] B;}
	void SetDirection(float x,float y,int n)
	{
		B[NumBullets].SetTexture(n);
		B[NumBullets].setDirection(x,y);
	}
	void SetTexture(Texture *temp)
	{
		sprite.setTexture(*temp);
	}
	void Fire()
	{
		B[NumBullets].SetPosition(sprite.getPosition().x+sprite.getGlobalBounds().width/2.f,sprite.getPosition().y);
        NumBullets++;
	}
	void BulletUpdate()
	{
		for(int n=0;n<NumBullets;n++)
		{
			B[n].Updatebullet();
			if(B[n].IsOFFscreen())
			{
				B[n]=B[NumBullets-1];
				NumBullets--;
			}
		}
	}
	void draw(RenderWindow *window)
	{
		for(int n=0;n<NumBullets;n++)
			window->draw(B[n].sprite);
	}
	void move(float X,float Y)
	{
		float delta_x=X,delta_y=Y;			
		delta_x*=speed;
		delta_y*=speed;
		sprite.move(sf::Vector2f(delta_x, delta_y));		
	}

};
