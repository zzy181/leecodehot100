//最长连续序列

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
using namespace std;

int func(vector<int> &nums)
    {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end()); // 把 nums 转成哈希集合
        for (int x : st) { // 遍历哈希集合
            if (st.count(x - 1)) {
                continue;
            }
            // x 是序列的起点
            int y = x + 1;
            while (st.count(y)) { // 不断查找下一个数是否在哈希集合中
                y++;
            }
            // 循环结束后，y-1 是最后一个在哈希集合中的数
            ans = max(ans, y - x); // 从 x 到 y-1 一共 y-x 个数
        }
        return ans;
    }
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << func(nums) << endl;
    return 0;
}