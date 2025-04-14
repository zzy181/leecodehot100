#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> func(vector<int> &nums,int& k){
    vector<int> ans;
    deque<int> q;
    for(int i = 0;i<nums.size();i++){
        while(!q.empty()&&nums[q.back()]<=nums[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i-q.front()>k){
            q.pop_front();
        }
        if(i>=k-1){
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int> ans_test;
    int k_test;
    cin>>k_test;
    cout<<endl;
    int an;
    while(cin>>an){
        ans_test.push_back(an);
        if(getchar()=='\n'){
            break;
        }
    }

    vector<int> result = func(ans_test,k_test);
    for(int i :result){
        cout<<i<<" ";
    }

    return 0;
}

