//无重复字符的字串

#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int func(string s){
    unordered_set<char> win;
    int ans=0;
    for(int left=0,right=0;right<s.size();right++){
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
    cout<<s<<endl;

    int result = func(s);
    cout<<result<<endl;

}