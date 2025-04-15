//环形链表

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) return true;
    }
    return false;
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
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    cout<<hasCycle(node1);
}
