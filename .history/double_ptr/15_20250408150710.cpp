//三数之和
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> func(vector<int> &nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    if(nums[0]>0) return ans;

    for(int i = 0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1]) continue;
        int left = i+1,right = nums.size()-1;
        while(left<right){
            int sum = nums[i]+nums[left]+nums[right];
            if(sum>0) right--;
            else if(sum<0) left++;
            else{
                ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                while(left<right&&nums[right]==nums[right-1]) right--;
                while(left<right&&nums[left]==nums[left+1]) left++;
                right--;
                left++;
            }
        }
    }
    return ans;

}

int main(){
    vector<int> nums;
    int num;
    while(cin>>num){
        nums.push_back(num);
        if(getchar()=='\n'){
            break;
        }
    }
    vector<vector<int>> result = func(nums);
    for(const auto& group:result){
        for(const auto& str:group){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}