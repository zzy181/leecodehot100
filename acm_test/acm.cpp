#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    // 用法1，读入单数据
    // int num;
    // cin>>num;
    // cout<<num<<endl;

    // // 用法2，批量读入多个数据
    // vector<int> nums(5);
    // for(int i = 0;i<nums.size();i++){
    //     cin>>nums[i];
    // }

    // // 输出读入的数组
    // for(int i = 0;i<nums.size();i++){
    //     cout<<nums[i]<<" ";
    // }
    /*
    从cin的注意中，也可以看出，当我们要求读取的字符串中间存在空格的时候，cin会读取不全整个字符串，
    这个时候，可以采用getline()函数来解决。
    注意1：使用getline()函数的时候，需要包含头文件<string>
    注意2：getline()函数会读取一行，读取的字符串包括空格，遇到换行符结束

    */
    // string s;
    // getline(cin,s);
    // cout<<s<<endl;

    // char ch;
    // ch = getchar();
    // // 输出读入的字符
    // cout << ch << endl;
    //固定数目
    // int n;
    // cin >> n; // 读入3，说明数组的大小是3
    // vector<int> nums(n); // 创建大小为3的vector<int>
    // for(int i = 0; i < n; i++) {
    //     cin >> nums[i];
    // }

    // // 验证是否读入成功
    // for(int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    //不固定数目
    vector<int> nums;
    int num;
    while(cin>>num){
        nums.push_back(num);
        if(getchar()=='\n'){
            break;
        }
    }
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;




    

}
