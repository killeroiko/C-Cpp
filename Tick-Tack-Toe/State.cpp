#include "State.h"
#include <iostream>

State::State()
{
}
State::State(int X, int Y, bool lights)
{
    robX=X;
    robY=Y;
    this->lights = lights;
    lights=true;

    for (int i=0;i<WIDTH;i++)
        for (int j=0;j<HEIGHT;j++)
            free[i][j]=true;
}
string State::getPath()
{
    unsigned i;
    string s;
    if (path.size()>0)
    {
        for (i=0;i<path.size()-1;i++)
            s+=path.at(i)+", ";
        s+=path.at(i)+ "\n";
    }
    return s;
}
void State::setFree(int i, int j, bool f)
{
    free[i][j]=f;
}
int State::getY()
{
    return robY;
}
int State::getX()
{
    return robX;
}
bool State::isFree(int x,int y)
{
    return free[x][y];
}
void State::setX(int x)
{
    robX=x;
}
void State::setY(int y)
{
    robY=y;
}
bool State::operator==(const State& s) const
{
    return (robX==s.robX && robY==s.robY && lights==s.lights);
}
State State::operator= (State o)
{
    lights = o.lights;
    robX = o.robX;
    robY = o.robY;
    path = o.path;
    return *this;
}
string State::toString () const
{
    stringstream ot;
    ot << robX<<"-"<<robY<<"-";
    if (lights)
        ot<<"true";
    else
        ot<<"false";
    return ot.str();
}
bool operator< (const State& a,const State& o)
{
    return (a.toString() < o.toString());
}

bool State::turnOn(State &n)
{
    if (!lights)
    {
        n=*this;
        n.lights=true;
        n.path.push_back("SwitchOn");
        return true;
    }
    return false;
}

bool State::turnOff (State &n)
{
    if (lights)
    {
        n=*this;
        n.lights=false;
        n.path.push_back("SwitchOff");
        return true;
    }
    return false;
}
bool State::goUp(State &n)
{
    if (getY()>1 && isFree(getX(),getY()-1))
    {
        n=*this;
        n.setY(n.getY()-1);
        n.path.push_back("Up");
        return true;
    }
    return false;
}

bool State::goDown(State &n)
{
    if (getY()<HEIGHT-1 && isFree(getX(),getY()+1))
    {
        n=*this;
        n.setY(n.getY()+1);
        n.path.push_back("Down");
        return true;
    }
    return false;
}
bool State::goLeft(State &n)
{
    if (getX()>1 && isFree(getX()-1,getY()))
    {
        n=*this;
        n.setX(n.getX()-1);
        n.path.push_back("Left");

        return true;
    }
    return false;
}
bool State::goRight(State &n)
{
    if (getX()<WIDTH-1 && isFree(getX()+1,getY()))
    {
        n=*this;
        n.setX(n.getX()+1);
        n.path.push_back("Right");
        return true;
    }
    return false;
}

vector <State> State::expand()
{
    vector <State> children;
    State child;

    if (goUp(child))
        children.push_back(child);
    if (goDown(child))
        children.push_back(child);
    if (goLeft(child))
        children.push_back(child);
    if (goRight(child))
        children.push_back(child);
    if (turnOn(child))
        children.push_back(child);
    if (turnOff(child))
        children.push_back(child);

    return children;
}

