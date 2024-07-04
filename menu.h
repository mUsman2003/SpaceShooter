#include <SFML/Graphics.hpp>
#include <string.h>
using namespace std;
using namespace sf;

//------------------------------------------------------------------------------------------------------------------------------------//   
//-------------------------------------------------------Menu Class-------------------------------------------------------------------//   
//------------------------------------------------------------------------------------------------------------------------------------//   
    

class Menu
{
public:
    Texture ScoreBoard;
    Sprite sprite,s;
    Texture num0,num1,num2,num3,num4,num5,num6,num7,num8,num9;

    Texture PLT0,PLT1,PLT2,PLT3,PLT4;     //Player Live Texture n(1,2,3)
    Sprite PLS0,PLS1,PLS2,PLS3,PLS4;

    Texture L1a,L1b,L1c,L2a,L2b,L2c,L3a,L3b,L3c,B0,B1,B2;
    Sprite LevelSprite;



//------------------------------------------------------Constructor-----------------------------------------------------------------------//   
    Menu()
    {     
//-----------------------------------------------------Level Transition textures------------------------------------------------------------------//   
        L1a.loadFromFile("img/level/1a.png");
        L1b.loadFromFile("img/level/1b.png");
        L1c.loadFromFile("img/level/1c.png");
        L2a.loadFromFile("img/level/2a.png");
        L2b.loadFromFile("img/level/2b.png");
        L2c.loadFromFile("img/level/2c.png");
        L3a.loadFromFile("img/level/3a.png");
        L3b.loadFromFile("img/level/3b.png");
        L3c.loadFromFile("img/level/3c.png");
        B0.loadFromFile("img/level/boss0.png");
        B1.loadFromFile("img/level/boss1.png");
        B2.loadFromFile("img/level/boss2.png");
//--------------------------------------------------------Score Board + Numbers-----------------------------------------------------------//   
        ScoreBoard.loadFromFile("img/UI/Score.png");
        num0.loadFromFile("img/UI/numeral0.png");
        num1.loadFromFile("img/UI/numeral1.png");
        num2.loadFromFile("img/UI/numeral2.png");
        num3.loadFromFile("img/UI/numeral3.png");
        num4.loadFromFile("img/UI/numeral4.png");
        num5.loadFromFile("img/UI/numeral5.png");
        num6.loadFromFile("img/UI/numeral6.png");
        num7.loadFromFile("img/UI/numeral7.png");
        num8.loadFromFile("img/UI/numeral8.png");
        num9.loadFromFile("img/UI/numeral9.png");
        sprite.setTexture(ScoreBoard);
        sprite.scale(0.7,0.7);
        sprite.setPosition(20,20);
        s.setTexture(num0);
        s.setScale(1.7,1.7);
//---------------------------------------------------------Player Live indicator---------------------------------------------------------------//   
        PLT0.loadFromFile("img/UI/playerLife1_green.png");
        PLS0.setTexture(PLT0);
        PLT1.loadFromFile("img/UI/playerLife1_red.png");
        PLS1.setTexture(PLT1);
        PLT2.loadFromFile("img/UI/playerLife1_blue.png");
        PLS2.setTexture(PLT2);
        PLT3.loadFromFile("img/UI/playerLife1_red.png");
        PLS3.setTexture(PLT3);
        PLT4.loadFromFile("img/UI/playerLife1_green.png");
        PLS4.setTexture(PLT4);
        PLS0.setScale(2,2);
        PLS1.setScale(2,2);
        PLS2.setScale(2,2);
        PLS3.setScale(2,2);
        PLS4.setScale(2,2);
        PLS0.setPosition(20,800);
        PLS1.setPosition(100,800);
        PLS2.setPosition(180,800);
        PLS3.setPosition(260,800);
        PLS4.setPosition(340,800);
    }

    void DisplayLevelTransition(int temp)
    {
        if(temp==1)
            LevelSprite.setTexture(L1a);
        else if(temp==2)
            LevelSprite.setTexture(L1b);
        else if(temp==3)
            LevelSprite.setTexture(L1c);
        else if(temp==4)
            LevelSprite.setTexture(L2a);
        else if(temp==5)
            LevelSprite.setTexture(L2b);
        else if(temp==6)
            LevelSprite.setTexture(L2c);
        else if(temp==7)
            LevelSprite.setTexture(L3a);
        else if(temp==8)
            LevelSprite.setTexture(L3b);
        else if(temp==9)
            LevelSprite.setTexture(L3c);
        else if(temp==10)
            LevelSprite.setTexture(B0);
        else if(temp==11)
            LevelSprite.setTexture(B1);
        else if(temp==12)
            LevelSprite.setTexture(B2);
    }
    void DisplayLive(int live,RenderWindow& window)
    {

        for(int n=0;n<live;n++)        //Lives DisPlayer    
        {
            switch(n)
            {
                case 0: window.draw(PLS0);
                        break;
                case 1: window.draw(PLS1);
                        break;
                case 2: window.draw(PLS2);
                        break;
                case 3: window.draw(PLS3);
                        break;
                case 4: window.draw(PLS4);
                        break;
            }
        }
              
    }
    void DisplayTransition(RenderWindow& window)
    {
        window.draw(LevelSprite);
    }
    void Checker(int temp)
    {
        if(temp==0)
            s.setTexture(num0);
        if(temp==1)
            s.setTexture(num1);
        if(temp==2)
            s.setTexture(num2);
        if(temp==3)
            s.setTexture(num3);
        if(temp==4)
            s.setTexture(num4);
        if(temp==5)
            s.setTexture(num5);
        if(temp==6)
            s.setTexture(num6);
        if(temp==7)
            s.setTexture(num7);
        if(temp==8)
            s.setTexture(num8);
        if(temp==9)
            s.setTexture(num9);

        s.setScale(1.7,1.7);
    }
    void DisplayScore(int temp,RenderWindow& window)
    {
        window.draw(sprite);
        Checker(temp/10000);
        s.setPosition(200,20);
        window.draw(s);
        Checker(temp/1000%10);
        s.setPosition(235,20);
        window.draw(s);
        Checker(temp/100%10);
        s.setPosition(270,20);
        window.draw(s);
        Checker(temp/10%10);
        s.setPosition(305,20);
        window.draw(s);
        Checker(temp%10);
        s.setPosition(340,20);
        window.draw(s);
        
    }
    void DisplayEndScore(int temp,RenderWindow& window)
    {
        Checker(temp/10000);
        s.setPosition(500,455);
        window.draw(s);
        Checker(temp/1000%10);
        s.setPosition(535,455);
        window.draw(s);
        Checker(temp/100%10);
        s.setPosition(570,455);
        window.draw(s);
        Checker(temp/10%10);
        s.setPosition(605,455);
        window.draw(s);
        Checker(temp%10);
        s.setPosition(640,455);
        window.draw(s);
    }
    void AddScoretoFile(RenderWindow& window)
    {
        Event e;
        if (e.type == sf::Event::TextEntered)
        {
            // Append input to text box if it's a valid number
            if (e.text.unicode >= 'a' && e.text.unicode <= 'z')
            {
            }
        }
    }
    
};