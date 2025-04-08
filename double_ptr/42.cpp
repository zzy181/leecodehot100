//接雨水
#include<iostream>
#include<vector>

using namespace std;

int func(vector<int> & height){
    int ans = 0;
    int left =0 ,right = height.size()-1;
    int leftmax,rightmax=0;
    while(left<right){
        leftmax = max(leftmax,height[left]);
        rightmax = max(rightmax,height[right]);
        if(height[left]<height[right]){
            ans+=leftmax-height[left];
            left++;
        }
        else{
            ans+=rightmax-height[right];
            right--;
        }
    }
    return ans;
}

int main(){
    vector<int> heights;
    int high;
    while(cin>>high){
        heights.push_back(high);
        if(getchar()=='\n'){
            break;
        }
    }

    int result = func(heights);
    cout<<endl;
    cout<<result;
}
