//环形链表2

#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            ListNode* cur1=head;
            ListNode* cur2 = slow;
            while(cur1!=cur2){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1->val;
        }
    }
    return nullptr;
}

int main(){
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    cout<<detectCycle(node1);
}
