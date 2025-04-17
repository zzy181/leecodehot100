#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* func(ListNode* head,int n){
    ListNode* dum = new ListNode(0);
    dum->next = head;
    ListNode* fast = dum;
    ListNode* slow = dum;
    for(int i = 0;i<n+1;i++){
        fast =fast->next;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dum->next;
}

void printl(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head =new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printl(head);
    int n = 2;
    printl(func(head,n));
    return 0;

}