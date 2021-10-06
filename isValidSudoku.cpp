//leetcode 36有效的数独
#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
    int set1[9][9]{};
    int set2[9][9]{};
    int set3[9][9]{};
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
                continue;
            if(set1[i][board[i][j] - '1'])
                return false;
            else 
                set1[i][board[i][j] - '1']++;
            if(set2[j][board[i][j] - '1'])
                return false;
            else 
                set2[j][board[i][j] - '1']++;
            if(set3[j/3 + (i/3)*3][board[i][j] - '1'])
                return false;
            else 
                set3[j/3 + (i/3)*3][board[i][j] - '1']++;
        }
    }
    return true;
}
