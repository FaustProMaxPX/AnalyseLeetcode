//leetcode 78子集（二分掩码做法）
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
    int n = nums.size();
    int total = (1 << n) - 1;
    vector<int> temp;
    vector<vector<int>> ans;
    for(int i = 1; i <= total; i++)
    {
        int b = 0;
        temp.clear();
        for(int j = 0; j < n; j++)
        {
            if((i >> b) & 1)
            {
                temp.push_back(nums[j]);
            }
            b++;
        }
        ans.push_back(temp);
    }
    ans.push_back({});
    return ans;
}

int main()
{
    vector<int> nums{1,2,3};
    subsets(nums);
    return 0;
}
