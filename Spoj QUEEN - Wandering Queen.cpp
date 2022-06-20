#include <bits/stdc++.h>

using namespace std;


const int MAX_ROW=1e3, MAX_COL=1e3;
const int INF = 1e3+1;

struct point
{
    int x,y;
    point();
    point(int x, int y)
    {
        this ->x = x;
        this -> y = y;
    }
};
class cell
{
public:
    short cost;
    int8_t visited;
    cell()
    {
        cost = INF;
        visited = 0;
    }
    void setBit(int bitNum)
    {
        visited |= (1<< bitNum);
    }
    bool checkBit(int bitNum)
    {
        return bitNum & (1<<bitNum);
    }

};

class Grid
{
public:
    cell board[100][100];
    int n, m;
    Grid(int n, int m)
    {
        this->n = n;
        this->m = m;
    }
};

int bfs(Grid & board, point & start, point & finish, int &n, int &m)
{
    queue<point>q;
    q.push(start);

    while(!q.empty())
    {
        point p = q.front();
        q.pop();
        int newCost = board.board[p.x][p.y].cost +1;


        if(! board.board[p.x][p.y].checkBit(1))
        {

            /// UP 1
            for(int i=p.x-1, j=p.y; i>=0&& board.board[i][j].cost!=-1;--i){

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                 board.board[i][j].setBit(1);
            }

            /// DOWN 1
            for(int i=p.x+1, j=p.y; i<n&& board.board[i][j].cost!=-1;++i){

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                board.board[i][j].setBit(1);
            }
            board.board[p.x][p.y].setBit(1);
        }

        if(! board.board[p.x][p.y].checkBit(2))
        {

            /// LEFT 2
            for(int i=p.x, j=p.y-1; j>=0&& board.board[i][j].cost!=-1;--j){

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                board.board[i][j].setBit(2);
            }

            /// RIGHT 2
            for(int i=p.x, j=p.y+1; j<m&& board.board[i][j].cost!=-1;++j){

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                board.board[i][j].setBit(2);
            }
            board.board[p.x][p.y].setBit(2);
        }

        if(! board.board[p.x][p.y].checkBit(3))
        {

            /// UP RIGHT 3
            for(int i=p.x-1, j=p.y+1; j<m&&i>=0&& board.board[i][j].cost!=-1;++j, --i){

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                board.board[i][j].setBit(3);
            }

            /// DOWN LEFT 3
            for(int i=p.x+1, j=p.y-1; j>=0&& i<n&& board.board[i][j].cost!=-1;--j, ++i){

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                board.board[i][j].setBit(3);
            }
            board.board[p.x][p.y].setBit(3);
        }

        if(board.board[p.x][p.y].checkBit(4))
        {
            /// UP LEFT 4
            for(int i=p.x-1, j=p.y-1; j>=0&& i>=0&& board.board[i][j].cost!=-1;--j, --i){

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                board.board[i][j].setBit(4);
            }

            /// DOWN RIGHT 4
            for(int i=p.x+1, j=p.y+1; j<m&& i<n&& board.board[i][j].cost!=-1;++j, ++i)
            {

                if(board.board[i][j].cost == INF){
                    board.board[i][j].cost = newCost, q.push(point(i,j));

                    if(i == finish.x && j == finish.y)
                        return board.board[i][j].cost;
                }
                board.board[i][j].setBit(4);
            }
            board.board[p.x][p.y].setBit(4);
        }

        cout<<p.x<<' '<<p.y<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<board.board[i][j].cost<<"     ";
            puts("");
        }
    }

    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        Grid board(n,m);
        point start(0,0), finish(0,0);
        for(int i=0;i<n;i++){
            char c;
            for(int j=0;j<m;j++){
                cin>>c;
                if(c == 'X')
                    board.board[i][j].cost=-1;
                else if(c=='S')
                    board.board[i][j].cost = 0, start.x=i, start.y = j;
                else if(c == 'F')
                    finish.x = i, finish.y = j;
            }

        }
        int ans = bfs(board, start, finish, n, m);
        printf("%d\n", ans);

    }
    return 0;
}
