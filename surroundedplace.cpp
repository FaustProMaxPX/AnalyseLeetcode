//leetcode 130.被围绕的区域
//思路：扫描矩阵边界，对其中的每一个O做深度优先搜索，将路径上的O全部修改为-（找到与边界的O直接或间接相邻的所有O，因为这代表他们总有一边不可能是X）
//然后将矩阵中所有的O改为X，-改为O
#include <iostream>
#include <vector>
using namespace std;

const int dt[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vector<vector<char>> & board, int x, int y)
{
    board[x][y] = '-';
    for(int i = 0; i < 4; i++)
    {
        int dx = x + dt[i][0];
        int dy = y + dt[i][1];
        if(dx < 0 || dx >= board.size() || dy < 0 || dy >= board[0].size() || board[dx][dy] != 'O')
            continue;
        else 
            dfs(board, dx, dy);
    }
}

void solve(vector<vector<char>>& board)
{   
    int row = board.size();
    int col = board[0].size();
    for(int i = 0; i < row; i++)
    {
        dfs(board, i, 0);
        dfs(board, i, col - 1);
    }
    for(int j = 0; j < col; j++)
    {
        dfs(board, 0, j);
        dfs(board, row - 1, j);
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == '-')
                board[i][j] = 'O';
        }
    }
}
