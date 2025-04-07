#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 查找两数之和等于目标值的函数
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashmap;
    for (int i = 0; i < nums.size(); i++) {
        int it = target - nums[i];
        if (hashmap.count(it)) {
            return {hashmap[it], i};
        }
        hashmap[nums[i]] = i;
    }
    return {};
}

int main() {
    int target;
    cin >> target;
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') {
            break;
        }
    }

    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}    