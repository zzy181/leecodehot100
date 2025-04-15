#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* reverseList(ListNode* head) {
    ListNode* temp;
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while(cur){
        temp = cur ->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
    
}

void printList(ListNode *head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<"->";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    // 手动创建链表
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* current = node1;
    printList(current);

    // 反转链表
    ListNode* reversedHead = reverseList(node1);

    printList(reversedHead);
    
    return 0;
}    
