#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int func(string s){
    unordered_set<char> win;
    int ans;
    for(int left,right=0;right<s.size();right++){
        while(win.count(s[right])){
            win.erase(s[left]);
            left++;
        }
        win.insert(s[right]);
        ans = max(ans,right-left+1);
    }
    return ans;
}
int main(){
    string s;
    getline(cin,s);
    cout<<s;

}