#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//存放坐标
struct node
{
    int _x;
    int _y;
    node(int x,int y)
    
        :_x(x)
        ,_y(y)
    {}
};
int nextP[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

//迷宫
bool BFS(vector<vector<int>>& grid,int startX,int startY,
         int destX,int destY)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> visited(row,vector<int>(col,0));//标记已访问
    queue<node> q; //建立队列，里面存放node类型数据
    //存放起点
    q.push(node(startX,startY));
    visited[startX][startY] = 1;
    //队列不为空
    while(!q.empty())
    {
        //获取头元素
        node curPos = q.front();
        q.pop();
        //判断是否终点
        if(curPos._x == destX && curPos._y == destY)
        {
            return true;
        }
        //继续判断剩下的位置,将当前位置的上下左右入队列
        for(int i = 0;i < 4;i++)
        {
            int nx = curPos._x + nextP[i][0];
            int ny = curPos._y + nextP[i][1];

            if(nx >= row || nx < 0
            || ny >= col || ny < 0)
                continue;
            //为1，且没访问过，存入队列
            if(grid[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                q.push(node(nx,ny));
                visited[nx][ny] = 1;
            }
        }
    }
    return false;
}

void testBFS()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 1},
                                {0, 1, 0, 1, 0},
                                {0, 0, 1, 0, 0},
                                {1, 0, 0, 1, 1},
                                {0, 1, 0, 0, 0},};
    int sx,sy,dx,dy;
    while(1)
    {
        cout << "请输入起点：" << endl;
        cin >> sx >> sy;
        cout << "请输入终点：" << endl;
        cin >> dx >> dy;
        cout << BFS(grid,sx,sy,dx,dy) << endl;
    }
}
int main()
{
    testBFS();
    return 0;
}