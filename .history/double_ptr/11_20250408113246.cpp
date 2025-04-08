#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxArea(vector<int>& height) {
        int curl,maxl = 0;
        int left = 0,right = height.size()-1;
        while(left<right){
            int h = min(height[left],height[right]);
            curl = h*(right-left);
            maxl = max(curl,maxl);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxl;
        
    }

int main(){
    vector<int> highs;
    int high;
    while(cin>>high){
        highs.push_back(high);
        if(getchar()=='\n'){
            break;
        }
    }
    cout<<endl;
    int l = maxArea(highs);
    cout<<l;
}
