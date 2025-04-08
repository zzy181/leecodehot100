//三数之和
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> func(vector<int> &nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    if(nums[0]>0) return ans;
    for(int i = 0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1]) continue;
        int left = i+1,right = nums.size()-1;
        while(left<right){
            int sum = nums[i]+nums[left]+nums[right];
            if(sum>0) right--;
            else if(sum<0) left++;
            else{
                ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                while(left<right&&nums[right]==nums[right-1]) right--;
                while(left<right&&nums[left]==nums[left+1]) left++;
                right--;
                left++;
            }
        }
    }
    return ans;

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

    /*
    &（引用）的作用
    在 C++ 里，引用相当于变量的别名，它和所引用的变量指向同一块内存地址。在基于范围的 for 循环里使用引用 & 有以下好处：
    避免拷贝：要是不使用引用，循环变量就会是容器元素的一份拷贝，这在处理大型对象（像长字符串、复杂结构体等）时，会带来额外的内存开销与时间开销。使用引用可以直接操作容器中的元素，避免了拷贝的成本。
    修改元素：当使用非 const 引用时，还能够在循环里修改容器中的元素。不过在你提供的代码里，使用的是 const 引用，所以不能修改元素。
    const 是一个类型修饰符，用于表明变量是常量，也就是在其生命周期内，值不能被修改。在基于范围的 for 循环中使用 const 有以下好处：
    防止意外修改：当你不想在循环里修改容器元素的值时，使用 const 可以防止意外修改。如果尝试修改 const 引用的元素，编译器会报错。
    增强代码可读性：const 能够让代码的意图更加清晰，表明在循环中不会对元素进行修改。
    */
    vector<vector<int>> result = func(nums);
    for(const auto& group:result){
        for(const auto& str:group){
            cout<<str<<" ";
        }
        cout<<endl;
    }

    return 0;
}