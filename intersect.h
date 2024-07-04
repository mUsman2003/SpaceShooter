#include <SFML/Graphics.hpp>
#include <string.h>

using namespace std;
using namespace sf;

bool IntersectPlayerRock(FloatRect A,FloatRect B)
{
    if (A.left+A.width/4 < B.left + B.width &&
        A.left + A.width*0.75 > B.left &&
        A.top < B.top + B.height &&
        A.top + A.height > B.top) 
        {
            return true; // Collision occurred
        }

    return false; // No collision
}

bool IntersectPlayerAddon(FloatRect A,FloatRect B)
{
    if (A.left+A.width/4 < B.left + B.width &&
        A.left + A.width*0.75 > B.left &&
        A.top < B.top + B.height &&
        A.top + A.height > B.top) 
        {
            return true; // Collision occurred
        }

    return false; // No collision
}

bool IntersectPlayerGoku(FloatRect A,FloatRect B)
{
    if (A.left + A.width/4 < B.left + B.width &&
        A.left + A.width*0.75 > B.left &&
        A.top < B.top + B.height &&
        A.top + A.height > B.top) 
        {
            return true; // Collision occurred
        }
    return 0;
}
bool IntersectPlayerGokuBeam(FloatRect A,FloatRect B)
{
    if (A.left+A.width/4 < B.left + B.width &&
        A.left + A.width*0.75 > B.left &&
        A.top < B.top + B.height &&
        A.top + A.height > B.top) 
        {
        return true; // Collision occurred
        }

    return false; // No collision
}
bool IntersectBulletGoku(FloatRect A,FloatRect B)
{
    if (A.left < B.left + B.width*0.8 &&
        A.left*0.9 + A.width > B.left&&
        A.top < B.top + B.height*0.8 &&
        A.top + A.height > B.top) 
        {
            return true; // Collision occurred
        }

    return false; // No collision
}

bool IntersectPlayerMonster(FloatRect A,FloatRect B)    //Done Partially
{
    if (A.left+A.width/4 < B.left + B.width &&
        A.left + A.width/4 > B.left &&
        A.top < B.top + B.height*0.8 &&
        A.top + A.height > B.top*0.8) 
        {
        return true; // Collision occurred
        }

    return false; // No collision
}
bool IntersectPlayerMonsterBeam(FloatRect A,FloatRect B)
{
    if (A.left+A.width/4 < B.left + B.width &&
        A.left + A.width*0.75 > B.left &&
        A.top < B.top + B.height &&
        A.top + A.height > B.top) 
        {
        return true; // Collision occurred
    }

    return false; // No collision
}
bool IntersectBulletMonster(FloatRect A,FloatRect B)    //Done
{
    if (A.left < B.left + B.width &&
        A.left + A.width > B.left &&
        A.top < B.top + B.height/3 &&
        A.top + A.height > B.top) {
        return true; // Collision occurred
    }

    return false; // No collision
}

bool IntersectPlayerEnemy(FloatRect A,FloatRect B)
{
    if (A.left+A.width/4 < B.left + B.width &&
        A.left + A.width*0.75 > B.left &&
        A.top < B.top + B.height &&
        A.top + A.height > B.top) 
        {
            return true; // Collision occurred
        }

    return false; // No collision
}
bool IntersectPlayerEnemyBomb(FloatRect A,FloatRect B)
{
    if (A.left+A.width/4 < B.left + B.width &&
        A.left + A.width*0.75 > B.left &&
        A.top < B.top + B.height &&
        A.top + A.height > B.top) 
        {
            return true; // Collision occurred
        }

    return false; // No collision
}
bool IntersectBulletEnemy(FloatRect A,FloatRect B)
{
    if (A.left < B.left + B.width &&
        A.left + A.width > B.left &&
        A.top < B.top + B.height*0.5 &&
        A.top + A.height > B.top) 
        {
            return true; // Collision occurred
        }

    return false; // No collision
}
