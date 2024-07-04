#include <SFML/Graphics.hpp>
#include <string.h>
#include "bomb.h"
#include "laser.h"
#include "kamehameha.h"

using namespace std;
using namespace sf;

class Enemy
{
protected:
    Texture texture;
    Sprite* sprite;
    int HP;
    int MaxHP;
    float dirX,dirY;
    int Total;
    Bomb B[100];
    int numBomb;
    int maxBomb;
    float Speed=0.5;

public:
    Enemy(int hp,int max,float x,float y,int total):HP(hp),MaxHP(max),dirX(x),dirY(y),Total(total){ sprite=new Sprite[Total];}
    ~Enemy(){   delete[] sprite;}
    void SetSpeed(float n){Speed=n;}
    virtual void Move(){}
    virtual void MoveA(){}   
    virtual void ShapeLevel7(){} 
    virtual void Shape1Alpha(){}
    virtual void Shape2Alpha(){}
    virtual void Shape3Alpha(){}
    virtual void Shape1Beta(){}
    virtual void Shape2Beta(){}
    virtual void Shape3Beta(){}
    virtual void Shape1Gamma(){}
    virtual void Shape2Gamma(){}
    virtual void Shape3Gamma(){}
    virtual void Shape1Monster(){}
    virtual void EnemyRemoval(int n){}
    virtual void Fire(){}

    virtual void GokuFire(){}
    virtual void SetDirectiion(float x,float y,int temp){}
    virtual void UpdateBeam(){}
    virtual void GokuBeamDraw(RenderWindow& window){}

    virtual void BombUpdate(){}
    virtual void SetTexture(Texture &temp){}
    virtual void draw(RenderWindow &window){}
    virtual void LaserDraw(RenderWindow &window){}
    virtual void BulletDraw(RenderWindow *window){}
    virtual int getBombNum(){return 1;}
    virtual int getEnemySize(){ return Total;}
    virtual int getHP(){return 1;}
    virtual Sprite getLaser(){  return sprite[0];}
    virtual Sprite getSprite(int n){   return sprite[n];}
    virtual Sprite getBombSprite(int n){ return sprite[n];}
};

class Alpha:public Enemy
{
protected:
    int maxBomb;
    int numBomb;
    Bomb* B;
    float MovementdirectionX;
    float MovementdirectionY;
public:  
    Alpha(int total):Enemy(1,1,100,100,total)
    {
        texture.loadFromFile("img/enemy/enemyBlack1.png");
        for(int n=0;n<Total;n++)
        {
            sprite[n].setTexture(texture);
            sprite[n].setPosition(100,100);
            sprite[n].setScale(0.7,0.7);
        }
        maxBomb=50;
        numBomb=0;
        MovementdirectionX=1;
        MovementdirectionY=0;
        B=new Bomb[maxBomb];

    }
    ~Alpha()
    {   delete[] B;
    }
    void EnemyRemoval(int index)
    {
       sprite[index]=sprite[Total-1];
       Total--;
    }
    void MoveA()
    {
        for(int n=0;n<Total;n++)
            sprite[n].move(Speed*MovementdirectionX,MovementdirectionY);
        if(sprite[0].getPosition().x>320)
            MovementdirectionX=-1;
        else if(sprite[0].getPosition().x<80)
            MovementdirectionX=1;

    }
    void draw(RenderWindow &window)
    {
        for(int n=0;n<Total;n++)
            window.draw(sprite[n]);
    }
    void Shape1Alpha()
    {
        int n;

        for(n=0;n<10;n++)
            sprite[n].setPosition(80+n*80,80);

        sprite[10].setPosition(80,160);
        sprite[11].setPosition(80,240);
        sprite[12].setPosition(80+9*80,160);
        sprite[13].setPosition(80+9*80,240);
        
        n+=4;
        int temp=n;
        for(int m=0;m<Total-temp;m++,n++)
            sprite[n].setPosition(80+m*80,320);

    }
    void Shape2Alpha()
    {
        int n;

        for(n=0;n<10;n++)
            sprite[n].setPosition(80+n*80,80);

        sprite[10].setPosition(80,160);
        sprite[11].setPosition(80,240);
        sprite[12].setPosition(80+9*80,160);
        sprite[13].setPosition(80+9*80,240);
        sprite[14].setPosition(320,160);
        sprite[15].setPosition(320,240);
        sprite[16].setPosition(560,160);
        sprite[17].setPosition(560,240);
        
        n+=8;
        int temp=n;
        for(int m=0;m<Total-temp;m++,n++)
            sprite[n].setPosition(80+m*80,320);

    }
    void Shape3Alpha()
    {
        int n;

        for(n=0;n<10;n++)
            sprite[n].setPosition(80+n*80,80);
        for(int m=0;m<10;m++,n++)
            sprite[n].setPosition(80+m*80,160);
        for(int m=0;m<10;m++,n++)
            sprite[n].setPosition(80+m*80,240);        
        for(int m=0;m<10;m++,n++)
            sprite[n].setPosition(80+m*80,320);

    }
    void Fire()
    {
        int n=rand()%Total;
        B[numBomb].SetPosition(sprite[n].getPosition().x+sprite[n].getGlobalBounds().width/2.f,sprite[n].getPosition().y);
        numBomb++;
    }
    void BombUpdate()
	{
		for(int n=0;n<numBomb;n++)
		{
			B[n].UpdateBomb();
			if(B[n].IsOFFscreen())
			{
				B[n]=B[numBomb-1];
				numBomb--;
			}
		}
	}
    void BulletDraw(RenderWindow* window)
    {
        for(int n=0;n<numBomb;n++)
            window->draw(B[n].sprite);
    }
    int getBombNum()
    {
        return numBomb;
    }
    Sprite getBombSprite(int n)
    {
        return B[n].sprite;
    }

};

class Beta:public Enemy
{
protected:
    int maxBomb;
    int numBomb;
    float MovementdirectionX;
    float MovementdirectionY;
    int level;
public:  
    Beta(int total):Enemy(1,1,100,100,total)
    {
        texture.loadFromFile("img/enemy/enemyBlack2.png");
        for(int n=0;n<Total;n++)
        {
            sprite[n].setTexture(texture);
            sprite[n].setPosition(100,100);
            sprite[n].setScale(0.7,0.7);
        }
        maxBomb=10;
        numBomb=0;
        MovementdirectionX=1;
        MovementdirectionY=0;
        
        if(Total==15)
            level=1;
        if(Total==30)
            level=2;
        if(Total==35)
            level=3;

    }
    ~Beta()
    {
    }
    void EnemyRemoval(int index)
    {
       sprite[index]=sprite[Total-1];
       Total--;
    }
    void MoveA()
    {
        if(level==1)
        {
        for(int n=0;n<Total;n++)
            sprite[n].move(Speed*MovementdirectionX,MovementdirectionY);
        if(sprite[0].getPosition().x>720)
            MovementdirectionX=-1;
        else if(sprite[0].getPosition().x<80)
            MovementdirectionX=1;
        }
        else if(level==2)
        {
        for(int n=0;n<Total;n++)
            sprite[n].move(Speed*MovementdirectionX,MovementdirectionY);
        if(sprite[0].getPosition().x>240)
            MovementdirectionX=-1;
        else if(sprite[0].getPosition().x<80)
            MovementdirectionX=1;
        }
        else if(level==3)
        {
        for(int n=0;n<Total;n++)
            sprite[n].move(Speed*MovementdirectionX,MovementdirectionY);
        if(sprite[0].getPosition().x>640)
            MovementdirectionX=-1;
        else if(sprite[0].getPosition().x<480)
            MovementdirectionX=1;
        }


    }
    void draw(RenderWindow &window)
    {
        for(int n=0;n<Total;n++)
            window.draw(sprite[n]);
    }
    void Shape1Beta()
    {
        int n;
        for(n=0;n<5;n++)
            sprite[n].setPosition(80+80*n,80);
        for(int m=0;m<4;m++,n++)
            sprite[n].setPosition(120+80*m,160);
        for(int m=0;m<3;m++,n++)
            sprite[n].setPosition(160+80*m,240);
        for(int m=0;m<2;m++,n++)
            sprite[n].setPosition(200+80*m,320);
        for(int m=0;m<1;m++,n++)
            sprite[n].setPosition(240+80*m,400);
    }
    void Shape2Beta()
    {
        int n;
        for(n=0;n<5;n++)
            sprite[n].setPosition(80+80*n,80);
        for(int m=0;m<4;m++,n++)
            sprite[n].setPosition(120+80*m,160);
        for(int m=0;m<3;m++,n++)
            sprite[n].setPosition(160+80*m,240);
        for(int m=0;m<2;m++,n++)
            sprite[n].setPosition(200+80*m,320);
        for(int m=0;m<1;m++,n++)
            sprite[n].setPosition(240+80*m,400);
        for(int m=0;m<5;m++,n++)
            sprite[n].setPosition(480+80+80*m,80);
        for(int m=0;m<4;m++,n++)
            sprite[n].setPosition(480+120+80*m,160);
        for(int m=0;m<3;m++,n++)
            sprite[n].setPosition(480+160+80*m,240);
        for(int m=0;m<2;m++,n++)
            sprite[n].setPosition(480+200+80*m,320);
        for(int m=0;m<1;m++,n++)
            sprite[n].setPosition(480+240+80*m,400);

    }
    void Shape3Beta()
    {
        int m=0;
        sprite[m].setPosition(480,80);
        m++;
        sprite[m].setPosition(240,80);
        m++;
        sprite[m].setPosition(720,80);
        m++;
        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(160+80*n,160);
        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(640+80*n,160);
        for(int n=0;n<5;n++,m++)
            sprite[m].setPosition(80+80*n,240);
        for(int n=0;n<5;n++,m++)
            sprite[m].setPosition(560+80*n,240);
        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(160+80*n,320);
        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(640+80*n,320);
        for(int n=0;n<5;n++,m++)
            sprite[m].setPosition(80+80*n,400);
        for(int n=0;n<5;n++,m++)
            sprite[m].setPosition(560+80*n,400);    
    }
    void Fire()
    {
        int n=rand()%Total;
        B[numBomb].SetPosition(sprite[n].getPosition().x+sprite[n].getGlobalBounds().width/2.f,sprite[n].getPosition().y);
        numBomb++;
    }
    void BombUpdate()
	{
		for(int n=0;n<numBomb;n++)
		{
			B[n].UpdateBomb();
			if(B[n].IsOFFscreen())
			{
				B[n]=B[numBomb-1];
				numBomb--;
			}
		}
	}
    void BulletDraw(RenderWindow* window)
    {
        for(int n=0;n<numBomb;n++)
            window->draw(B[n].sprite);
    }
    int getBombNum()
    {
        return numBomb;
    }
    Sprite getBombSprite(int n)
    {
        return B[n].sprite;
    }
};

class Gamma:public Enemy
{
protected:
    int maxBomb;
    int numBomb;
    float MovementdirectionX;
    float MovementdirectionY;
    int level;
public:  
    Gamma(int total):Enemy(1,1,100,100,total)
    {
        texture.loadFromFile("img/enemy/enemyBlack3.png");
        for(int n=0;n<Total;n++)
        {
            sprite[n].setTexture(texture);
            sprite[n].setPosition(100,100);
            sprite[n].setScale(0.7,0.7);
        }
        maxBomb=10;
        numBomb=0;
        MovementdirectionX=1;
        MovementdirectionY=0;
        if(Total>40)
            level=3;
        else
            level=1;

    }
    ~Gamma()
    {
    }
    void EnemyRemoval(int index)
    {
       sprite[index]=sprite[Total-1];
       Total--;
    }
    void MoveA()
    {
        if(level==1)
        {
            for(int n=0;n<Total;n++)
                sprite[n].move(Speed*MovementdirectionX,MovementdirectionY);
            if(sprite[0].getPosition().x>800)
                MovementdirectionX=-1;
            else if(sprite[0].getPosition().x<320)
                 MovementdirectionX=1;
        }
        else if(level==3)
        {
            for(int n=0;n<Total;n++)
                sprite[n].move(Speed*MovementdirectionX,MovementdirectionY);
            if(sprite[0].getPosition().x>240)
                MovementdirectionX=-1;
            else if(sprite[0].getPosition().x<80)
                MovementdirectionX=1;
                
        }

    }
    void draw(RenderWindow &window)
    {
        for(int n=0;n<Total;n++)
            window.draw(sprite[n]);
    }
    void Shape1Gamma()
    {
        sprite[0].setPosition(320,80);  //top
        sprite[1].setPosition(320,440); //bottom

        sprite[2].setPosition(80,260);  //left
        sprite[3].setPosition(560,260); //right

        sprite[4].setPosition(240,140); 
        sprite[5].setPosition(400,140); 

        sprite[6].setPosition(160,200);
        sprite[7].setPosition(480,200);

        sprite[8].setPosition(240,380); 
        sprite[9].setPosition(400,380); 

        sprite[10].setPosition(160,320);
        sprite[11].setPosition(480,320);

    }
    void Shape2Gamma()
    {
        sprite[0].setPosition(320,80);  //top
        sprite[1].setPosition(320,440); //bottom

        sprite[2].setPosition(80,260);  //left
        sprite[3].setPosition(560,260); //right

        sprite[4].setPosition(240,140); 
        sprite[5].setPosition(400,140); 

        sprite[6].setPosition(160,200);
        sprite[7].setPosition(480,200);

        sprite[8].setPosition(240,380); 
        sprite[9].setPosition(400,380); 

        sprite[10].setPosition(160,320);
        sprite[11].setPosition(480,320);

        sprite[12].setPosition(320,200);
        sprite[13].setPosition(320,320);

        sprite[14].setPosition(240,260);
        sprite[15].setPosition(400,260);

    }
    void Shape3Gamma()
    {
        int m=0;
        sprite[m].setPosition(80,80);
        m++;
        sprite[m].setPosition(880,80);
        m++;

        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(240+80*n,80);
        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(240+80*n,400);
        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(560+80*n,80);
        for(int n=0;n<3;n++,m++)
            sprite[m].setPosition(560+80*n,400);


        for(int n=0;n<9;n++,m++)
            sprite[m].setPosition(160+80*n,160);

        sprite[m].setPosition(0,160);
        m++;
        sprite[m].setPosition(960,160);
        m++;

        for(int n=0;n<11;n++,m++)
            sprite[m].setPosition(80+80*n,240);

        sprite[m].setPosition(0,320);
        m++;
        sprite[m].setPosition(960,320);
        m++;

        for(int n=0;n<9;n++,m++)
            sprite[m].setPosition(160+80*n,320);
        
        sprite[m].setPosition(80,400);
        m++;
        sprite[m].setPosition(880,400);
        m++;
    }
    void Fire()
    {
        int n=rand()%Total;
        B[numBomb].SetPosition(sprite[n].getPosition().x+sprite[n].getGlobalBounds().width/2.f,sprite[n].getPosition().y);
        numBomb++;
    }
    void BombUpdate()
	{
		for(int n=0;n<numBomb;n++)
		{
			B[n].UpdateBomb();
			if(B[n].IsOFFscreen())
			{
				B[n]=B[numBomb-1];
				numBomb--;
			}
		}
	}
    void BulletDraw(RenderWindow* window)
    {
        for(int n=0;n<numBomb;n++)
            window->draw(B[n].sprite);
    }
    int getBombNum()
    {
        return numBomb;
    }
    Sprite getBombSprite(int n)
    {
        return B[n].sprite;
    }
    void SetSpeed(float m)
    {   
        Speed=m;
    }


};

class Monster:public Enemy
{
protected:
    int LaserTime;
    int LaserDelay;
    float MovementdirectionX;
    float MovementdirectionY;
    Laser L;
public:
    Monster():Enemy(1,1,100,100,1)
    {
        HP=100;
        sprite=new Sprite;
        texture.loadFromFile("img/boss/monster.png");
        sprite->setTexture(texture);
        sprite->setScale(0.25,0.25);
        sprite->setPosition(100,100);
        MovementdirectionX=1;
        MovementdirectionY=0;
        L.sprite.setPosition(sprite[0].getPosition().x+121,sprite[0].getPosition().y+100);
    }
    ~Monster(){}
    void EnemyRemoval(int index)
    {
       Total--;
    }
    void Shape1Monster()
    {
        sprite[0].setPosition(100,100);
    }
    void draw(RenderWindow &window)
    {
        for(int n=0;n<Total;n++)
            window.draw(sprite[n]);
    }
    void LaserDraw(RenderWindow &window)
    {
        window.draw(L.sprite);
    }
    void Move()
    {
        sprite[0].move(Speed*MovementdirectionX,MovementdirectionY);
        L.sprite.move(Speed*MovementdirectionX,MovementdirectionY);
        if(sprite[0].getPosition().x>1100-sprite[0].getGlobalBounds().width)
            MovementdirectionX=-1;
        else if(sprite[0].getPosition().x<100)
            MovementdirectionX=1;

    }
    int getHP(){    return HP;}
    Sprite getLaser(){  return L.sprite;}

};

class Dragon:public Enemy
{
protected:
    int LaserTime;
    int LaserDelay;
    float Speed;
    float MovementdirectionX;
    float MovementdirectionY;
    int MaxBomb;
    int NumBomb;
    Texture Goku;
    Texture GokuLeft;
    Texture GokuRight;
    GokuBeam* L;
public:
    Dragon():Enemy(1,1,100,100,1),Speed(0.5)
    {
        HP=100;
        NumBomb=0;
        MaxBomb=100;
        L=new GokuBeam[MaxBomb];
        Goku.loadFromFile("img/boss/explosion.png");
        GokuLeft.loadFromFile("img/boss/gokuleft.png");
        GokuRight.loadFromFile("img/boss/gokuright.png");
        sprite->setTexture(Goku);
        sprite->setScale(0.7,0.7);
        sprite->setPosition(100,50);
        MovementdirectionX=1;
        MovementdirectionY=0;
    }
    ~Dragon(){}
    void EnemyRemoval(int index)
    {
       Total--;
    }
    void Shape1Monster()
    {
        sprite[0].setPosition(100,100);
    }
    void Move()
    {
        sprite[0].move(1*MovementdirectionX,MovementdirectionY);
        if(sprite[0].getPosition().x>1000-sprite[0].getGlobalBounds().width)
            MovementdirectionX=-1;
        else if(sprite[0].getPosition().x<200)
            MovementdirectionX=1;

    }
    void GokuFire()
    {
        L[NumBomb].SetPosition(sprite[0].getPosition().x+100,sprite[0].getPosition().y+100);
        NumBomb++;
    }
    void UpdateBeam()
    {
        for(int n=0;n<NumBomb;n++)
        {
            L[n].Updatebullet();
            if(L[n].IsOFFscreen())
			{
				B[n]=B[NumBomb-1];
				NumBomb--;
			}
        }
    }
    void SetDirectiion(float x,float y,int temp)
    {
        if(temp==0)
            sprite->setTexture(Goku);
        else if(temp==30)
            sprite->setTexture(GokuRight);
        else if(temp==-30)
            sprite->setTexture(GokuLeft);
        L[NumBomb].SetTexture(temp);
        L[NumBomb].setDirection(x,y);
    }
    int getHP()
    {    return HP;}
    void draw(RenderWindow& window)
    {
        window.draw(sprite[0]);
    }
    void GokuBeamDraw(RenderWindow& window)
    {
        for(int n=0;n<NumBomb;n++)
            window.draw(L[n].sprite);
    }
    int getBombNum()
    {
        return NumBomb;
    }
    Sprite getBombSprite(int n)
    { 
        return L[n].sprite;
    }
    
};