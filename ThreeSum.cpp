//leetcode 15三数之和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //先将数组排序，方便之后用双指针移动来缩小范围
        sort(nums.begin(),nums.end());
        int i = 0, j = n - 1;
        vector<vector<int>> ans;
        vector<int> temp(3);
        for(int first = 0; first < n - 2; first++)
        {
            if(first > 0 && nums[first] == nums[first - 1]) //去重，理由:让同一个数不会多次出现在同一个位置
                continue;
            int third = n - 1; //右指针从后往前遍历
            int second;
            int target = -nums[first];
            //只用一重循环的理由:左指针右移代表总和增大，此时右指针唯有继续左移才可能找到答案，右边的部分没有意义
            for(second = first + 1; second < third; second++)
            {
                //去重
                if(second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                while(second < third && nums[second] + nums[third] > target)
                    third--;
                //两指针重合代表区间内仅剩下一个元素，没有继续比较的意义，直接跳出
                if(second == third)
                    break;
                if(nums[second] + nums[third] == target)
                    ans.push_back({nums[first],nums[second],nums[third]});
            }
        }
        return ans;
    }

int main()
{
    vector<int> nums{-1,0,1};
    //nums[0] = -1, nums[1] = 0, nums[2] = 1, nums[3] = 2, nums[4] = -1, nums[5] = -4;
    //nums[0] = 0, nums[1] = -1, nums[3] = 1, nums[2] = 0;
    vector<vector<int> > ans;
    ans = threeSum(nums);
    return 0;
}
