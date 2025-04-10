#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int func(vector<int> &nums,int k){
    unordered_map<int,int> presumCount{{0,1}};
    int ans = 0 ,preSum = 0;
    for(int num :nums){
        preSum+=num;
        if(presumCount.find(preSum-k)!=presumCount.end()){
            ans += presumCount[preSum-k];
        }
        presumCount[preSum-k]++;
    }
    return ans;
}

int main(){
    int k_test = 0;
    cin>>k_test;
    cout<<"k: "<<k_test<<endl;
    vector<int> nums_test;
    int num_test;
    while(cin>>num_test){
        nums_test.push_back(num_test);
        if(getchar()=='\n'){
            break;
        }
    }
    int result = func(nums_test,k_test);
    cout<<"result: "<<result<<endl;
    return 0;
}