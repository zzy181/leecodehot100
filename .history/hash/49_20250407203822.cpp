//字母异位词分组
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<string>> group(vector<string>& strs){
    unordered_map<string, vector<string>> map;
    for(string& str :strs){
        string key = str;
        sort(key.begin(),key.end());
        map[key].emplace_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = map.begin(); it != map.end(); it++) {
        ans.emplace_back(it->second);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i = 0;i<n;i++){
        cin>>strs[i];
    }
    vector<vector<string>> result = group(strs);

    for(const auto& group :result){
        for(const auto& str:group){
            cout<<str<<" ";
        }
        cout<<endl;

    }
    return 0;
}