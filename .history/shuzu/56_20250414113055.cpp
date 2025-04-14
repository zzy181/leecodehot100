
//合并区间
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans.back()[1] >= intervals[i][0])
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<vector<int>> inter(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> inter[i][0] >> inter[i][1];
    }
    vector<vector<int>> res = merge(inter);
    for (const auto &path : res)
    {
        cout << path[0] << " " << path[1] << endl;
    }
    return 0;
}