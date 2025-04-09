//找到字符串中所有字母的异位词

#include<iostream>
#include<vector>

using namespace std;

vector<int> func(string s ,string p){
    vector<int> ans;
    int slen = s.size(),plen = p.size();
    vector<int> s_count(26,0),p_count(26,0);
    for(char c:p){
        p_count[c-'a']++;
    }
    for(int left =0,right = 0;right<slen;right++){
        s_count[s[right]-'a']++;
        while(right-left+1>plen){
            s_count[s[left]-'a']--;
            left++;
        }
        if(right-left+1==plen&&s_count==p_count){
            ans.push_back(left);
        }
    }
    return ans;
}

int main(){
    string p_test,s_test;
    getline(cin,p_test);
    cout<<p_test<<endl;
    getline(cin,s_test);
    cout<<s_test<<endl;

    vector<int> ans_test = func(s_test,p_test);
    for(const int & a :ans_test){
        cout<<a<<"";
    }
}