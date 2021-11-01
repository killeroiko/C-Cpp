#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
#define WIDTH  10
#define HEIGHT  10

using namespace std;

class State
{
    int robX,robY;
    bool free[WIDTH][HEIGHT];
    vector <string> path;
     bool lights;

  public:

    State();
    State(int X, int Y, bool lights);
    void setFree(int i, int j, bool f);
    int getY();
    int getX();
    bool isFree(int x,int y);
    void setX(int x);
    void setY(int y);
    State operator= (State o);
    bool operator==(const State& o) const ;
    string toString () const;
    string getPath();
    friend bool operator< (const State& a,const State& o);
    bool turnOn(State &n);
    bool turnOff (State &n);
    bool goUp(State &n);
    bool goDown(State &n);
    bool goLeft(State &n);
    bool goRight(State &n);
    vector <State> expand();
};
