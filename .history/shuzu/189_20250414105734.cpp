#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

int main(){
    vector<int> nums_test;
    int k = 0;
    cin>>k;
    cout<<"k "<<k<<endl;
    int num_test = 0;
    while(cin>>num_test){
        nums_test.push_back(num_test);
        if(getchar()=='\n'){
            break;
        }
    }
    cout<<endl;
    rotate(nums_test,k);
    for(int i :nums_test){
        cout<<i<<" ";
    }
}


