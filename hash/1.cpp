#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

    unordered_map<int, int> hashmap;
    bool found = false;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (hashmap.count(complement)) {
            cout << hashmap[complement] << " " << i << endl;
            found = true;
            break;
        }
        hashmap[nums[i]] = i;
    }

    if (!found) {
        cout << "null" << endl;
    }

    return 0;
} 