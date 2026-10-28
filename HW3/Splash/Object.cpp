#include "Object.h"
#include "Splash.h"

bool new_coordinate(int& x, int& y, Direction dir, int size)
{
    switch(dir){
        case LEFT: y -= 1; break;
        case RIGHT: y += 1; break;
        case UP: x -= 1; break;
        case DOWN: x += 1; break;
    }

    if(x < 0 || x >= size || y < 0 || y >= size){
        return false;
    }

    return true;
}

int Water::act(Direction fromwhere, Actor fromwho)
{
    // update size
    if(fromwho == TOXIC)
        size --;
    else
        size ++;

    // check empty
    if(size == 0){
        splash->map[x][y] = new Void(x, y, splash);
        return 0;
    }
    // check split
    if(size > 3)
    {
        splash->map[x][y] = new Void(x, y, splash);

        int score = 1;
        for(Direction dir : {UP, DOWN, LEFT, RIGHT}){
            int nx = x, ny = y;
            if(new_coordinate(nx, ny, dir, splash->size)){
                Object* obj = splash->map[nx][ny];
                score += obj->act(dir, WATER);

                if(obj != splash->map[nx][ny]) delete obj;
            }
        }
        return score;
    }

    return 0;
}

int Toxic::act(Direction fromwhere, Actor fromwho)
{
    // update size
    if(fromwho == WATER)
        size --;
    else
        size ++;

    // check empty
    if(size == 0){
        splash->map[x][y] = new Void(x, y, splash);
        return 0;
    }
    // check split
    if(size > 3)
    {
        splash->map[x][y] = new Void(x, y, splash);

        int score = -1;
        for(Direction dir : {UP, DOWN, LEFT, RIGHT}){
            int nx = x, ny = y;
            if(new_coordinate(nx, ny, dir, splash->size)){
                Object* obj = splash->map[nx][ny];
                score += obj->act(dir, TOXIC);

                if(obj != splash->map[nx][ny]) delete obj;
            }
        }
        return score;
    }

    return 0;
}

int Void::act(Direction fromwhere, Actor fromwho)
{
    if(fromwho == PLAYER){
        cout << "Error: Cannot act a Void." << endl;
        return 0;
    }
    int nx = x, ny = y;

    if(!new_coordinate(nx, ny, fromwhere, splash->size)){
        return 0;
    }

    Object* obj = splash->map[nx][ny];
    int score = obj->act(fromwhere, fromwho);
    if(obj != splash->map[nx][ny]) delete obj;

    return score;
}

int Barrier::act(Direction fromwhere, Actor fromwho)
{
    if(fromwho == PLAYER){
        cout << "Error: Cannot act a Barrier." << endl;
    }

    return 0;
}