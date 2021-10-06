//leetcode 1091二进制矩阵中的最短路径
//层序遍历次数相当于对应的最短路
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int steps = INT_MAX;
    const int dt[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int path = 1;
        int flag = 1;
        queue<pair<int,int>> q;
        if(grid.size() == 0 || grid[0][0] == 1 || grid[grid.size() - 1][grid.size() - 1] == 1)
            return -1;
        q.push({0,0});
        grid[0][0] = 1; //必须在入队的同时标记阻塞，否则可能到这某个结点被多次入队
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                auto [x,y] = q.front();
                q.pop();
                if(x == grid.size() - 1 && y == grid[0].size() - 1)
                {
                    flag = 0;
                    break;
                }
                int dx, dy;
                for(int j = 0; j < 8; j++)
                {
                    dx = x + dt[j][0];
                    dy = y + dt[j][1];
                    if(dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size() && grid[dx][dy] == 0)
                    {
                        q.push({dx,dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
            if(!flag)
                break;
            path++;
        }
        return path;
    }
