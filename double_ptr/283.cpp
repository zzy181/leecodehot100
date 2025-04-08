#include<iostream>
#include<vector>

using namespace std;

void move0(vector<int> &nums){
    int n = nums.size();
    int f_ptr,s_ptr = 0;
    for(f_ptr;f_ptr<n;f_ptr++){
        if(nums[f_ptr]!=0){
            nums[s_ptr] = nums[f_ptr];
            s_ptr++;
        }
    }

    for(s_ptr;s_ptr<n;s_ptr++){
        nums[s_ptr]=0;
    }
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
    cout<<endl;

    move0(nums);
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

}