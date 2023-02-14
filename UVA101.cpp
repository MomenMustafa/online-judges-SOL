#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second

using namespace std;

class BlocksWorld
{
    int n;
    vector<int>arr;       /// current position for each block
    vector<stack<int>> world;

public:
    BlocksWorld(){};
    BlocksWorld(int n)
    {
        this->n=n;
        arr.resize(n);
        world.resize(n);

        for(int i=0;i<n;i++)
        {
            arr[i]=i;           /// initialize positions
            world[i].push(i);
        }
    }

    void MoveOnto(int a, int b)
    {
//       cout<<"this is b: "<<arr[a]<<endl;
       RemoveUntilA(arr[a], a);
       RemoveUntilA(arr[b], b);

       Place(a, b);
    }
    void MoveOver(int a, int b)
    {
        RemoveUntilA(arr[a], a);
        Place(a, b);
    }
    void PileOnto(int a, int b)
    {
        RemoveUntilA(arr[b], b);
        Place(RemovePileA(arr[a], a), b);
    }
    void PileOver(int a, int b)
    {
        Place(RemovePileA(arr[a], a), b);
    }
    void RemoveUntilA(int posA ,int a)
    {
        while(world[posA].top()!=a)
        {
            int top=world[posA].top();
//            cout<<"top: "<<top<<endl;
            world[posA].pop();
            world[top].push(top);
            arr[top]=top;
        }
    }
    stack<int>RemovePileA(int posA, int a)
    {
        stack<int>tmp;
        while(world[posA].top()!=a)
        {
            int top=world[posA].top();
            world[posA].pop();
            tmp.push(top);
        }
            world[posA].pop();
            tmp.push(a);
        return tmp;
    }
    void Place(int from ,int to)
    {
        int posA=arr[from], posB=arr[to];
        arr[from]=posB;
        world[posB].push(from);
        world[posA].pop();
    }
    void Place(stack<int>from, int to)
    {
        int posB=arr[to];
        while(!from.empty())
        {
            int top=from.top();
            from.pop();
            world[posB].push(top);
            arr[top]=posB;
        }
    }
    bool UpDown(int p) /// pile
    {
        if( world[p].empty()) return false;

        stack<int>tmp;
        while(!world[p].empty())
        {
            int top=world[p].top();
            tmp.push(top);
            world[p].pop();
        }
        world[p]=tmp;
        return true;
    }
    stack<int>Get(int pos)
    {
        return world[pos];
    }
    int GetPos(int pos)
    {
        return arr[pos];
    }
    void viewArr()
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<' ';
        puts("");
    }
};

class Robot
{
    BlocksWorld bw;
public:
    Robot(BlocksWorld bw)
    {
        this->bw = bw;
    }
    void tst()
    {
        bw.viewArr();
    }
    void ExecuteCommand(string command)
    {
        stringstream ss(command);
        string type, place;
        int a, b;

        ss>>type;
        ss>>a;
        ss>>place;
        ss>>b;

        if(a == b || bw.GetPos(a)== bw.GetPos(b))return;

        if(type=="move"&&place=="onto") bw.MoveOnto(a,b);
        else if(type=="move"&&place=="over")bw.MoveOver(a,b);
        else if(type=="pile"&&place=="onto")bw.PileOnto(a,b);
        else if(type=="pile"&&place=="over")bw.PileOver(a,b);
    }
    bool UpsideDown(int pile)
    {
        return bw.UpDown(pile);
    }
    stack<int>GetStack(int pos)
    {
        return bw.Get(pos);
    }
};

int main()
{
    freopen("tst.txt", "w", stdout);
    int n;
    cin>>n;
    cin.ignore();
    BlocksWorld bw(n);
    Robot robot(bw);

    while(true)
    {
        string cmd;
        getline(cin,cmd);
        if(cmd=="quit")
        {
            break;
        }
        robot.ExecuteCommand(cmd);
    }

   for(int i=0;i<n;i++)         /// output
   {
      cout<<i<<":";
        if(robot.UpsideDown(i))
        {
            stack<int> pile=robot.GetStack(i);
            while(pile.size()>1)
            {
                cout<<" "<<pile.top();
                pile.pop();
            }
            cout<<" "<<pile.top();
        }
        puts("");
   }

    return 0;
}
