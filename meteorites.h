#include <SFML/Graphics.hpp>
#include <string.h>
#include "rock.h"

using namespace std;
using namespace sf;

class Meteorites
{
public:
    Rock* R;
    int MaxRocks;
    int NumRocks;
    Meteorites()
    {
        
        MaxRocks=100;
        NumRocks=0;
        R=new Rock[MaxRocks];
    }
    ~Meteorites()
    {
        delete[] R;
    }
    Sprite GetSprite(int n)
    {
        return R[n].sprite;
    }
    void RockSpawn()
    {
        R[NumRocks].SetPosition(100+rand()%1000+1,0);
        NumRocks++;
    }
    void draw(RenderWindow& window)
    {
        for(int n=0;n<NumRocks;n++)
            window.draw(R[n].sprite);
    }
    void RockUpdate()
    {
        for(int n=0;n<NumRocks;n++)
		{
            R[n].UpdateRock();
            if(R[n].IsOFFscreen())
            {
                R[n]=R[NumRocks-1];
                NumRocks--;
            }
		}
    }

};