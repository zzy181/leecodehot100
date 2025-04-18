#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

void printl(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout<<endl;
}

ListNode* func(ListNode* head){
    ListNode* dum = new ListNode(0);
    dum->next = head;
    ListNode* pre = dum;
    ListNode* cur = head;
    while(cur&&cur->next){
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = cur;
        pre = cur;
        cur = cur->next;
    }
    return dum->next;
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
    printl(func(head));
    return 0;
}
