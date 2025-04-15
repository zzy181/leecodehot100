//回文链表

#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* rever(ListNode* head){
    ListNode*temp;
    ListNode*cur = head;
    ListNode* pre = nullptr;
    while(cur){
        temp = cur->next;
        cur->next = pre;
        pre =cur;
        cur = temp;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    if(head==nullptr||head->next==nullptr) return true;

    ListNode* pre = head;
    ListNode* slow = head;
    ListNode* fast =head;
    while(fast!=nullptr&&fast->next!=nullptr){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    ListNode* cur1 = head;
    ListNode* cur2 = rever(slow);
    while(cur1){
        if(cur1->val!=cur2->val) return false;
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return true;
}

void printList(ListNode *head){
    while(head){
        cout<<head->val;
        if(head->next!=nullptr) cout<<"->";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    printList(node1);
    cout<<isPalindrome(node1);
    return 0;
}