#include <iostream>
#include "State.h"
#include "Tile.h"

using namespace std;
template <typename myState>
bool BFS(const myState &goal,queue<myState> &agenda, set<myState> &closed,myState &solution)
{
    myState s;
    if (agenda.empty())
        return false;
    s=agenda.front();
    agenda.pop();
    if (s==goal)
    {
        solution = s;
        return true;
    }
    if (closed.size()==0 || (closed.find(s)==closed.end()))
    {
        vector<myState> children;
        children=s.expand();
        closed.insert(s);
        for (unsigned int i=0;i<children.size();i++)
            agenda.push(children.at(i));
    }
    return BFS(goal,agenda,closed,solution);
}
template <typename myState>
bool DFS(const myState &goal,stack<myState> &agenda, set<myState> &closed,myState &solution)
{
    myState s;
    if (agenda.empty())
        return false;
    s=agenda.top();
    agenda.pop();
    if (s==goal)
    {
        solution = s;
        return true;
    }
    if (closed.size()==0 || (closed.find(s)==closed.end()))
    {
        vector<myState> children;
        children=s.expand();
        closed.insert(s);
        for (unsigned int i=0;i<children.size();i++)
            agenda.push(children.at(i));
    }
    return DFS(goal,agenda,closed,solution);
}


int main()
{
    State initial(7,5,false);
    initial.setFree(4,1,false);
    initial.setFree(3,2,false);
    initial.setFree(4,3,false);

    State goal(2,2,true);
    stack <State> agenda;
    queue <State> Qagenda;

    set <State> closed;
    set <State> Qclosed;

    agenda.push(initial);
    Qagenda.push(initial);



    State solution;
    cout<<initial.toString()<<" -> "<<goal.toString()<<endl;
    DFS(goal,agenda,closed,solution);

    cout<<"DFS Solution: "<<endl;
    cout<<solution.getPath();

    BFS(goal,Qagenda,Qclosed,solution);

    cout<<"BFS Solution: "<<endl;
    cout<<solution.getPath();


    return 0;
}
