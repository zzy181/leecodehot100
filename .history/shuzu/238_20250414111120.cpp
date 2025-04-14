#include<iostream>
#include<vector>

using namespace std;

vector<int> func(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    int pre = 1;
    for(int i = 0;i<n;i++){
        ans[i] = pre;
        pre = pre * nums[i];
    }

    int bac = 1;
    for(int i = n-1;i>=0;i--){
        ans[i]=ans[i]*bac;
        bac = bac*nums[i];
    }
    return ans;
}

int main(){
    vector<int> nums_test;
    int num_test=0;
    while(cin>>num_test){
        nums_test.push_back(num_test);
        if(getchar()=='\n'){
            break;
        }
    }

    vector<int> ans = func(nums_test);
    for(const int &i : ans ){
        cout<<i<<" ";
    }
    return 0;
}