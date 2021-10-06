//leetcode 73 矩阵置0
#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    //将矩阵第一行和第一列作为标记，记录该行/列有无0
    int flag_r = 1, flag_c = 1; //用于标记第一行或第一列有没有0，避免后续修改时影响数据
    for(int i = 0; i < row; i++) //搜索第一列有没有0
        if(!matrix[i][0])
            flag_c = 0;
    for(int j = 0; j < col; j++)
        if(!matrix[0][j])
            flag_r = 0;
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            if(!matrix[i][j])
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
        }
    }
    if(!flag_r)
        for(int j = 0; j < col; j++)
            matrix[0][j] = 0;
    if(!flag_c)
        for(int i = 0; i < row; i++)
            matrix[i][0] = 0;
}
