#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* mid(ListNode* head){
    ListNode* pre = head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast&&fast->next){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    return slow;
}

ListNode* mec(ListNode* l1,ListNode* l2){
    ListNode* dum = new ListNode(0);
    ListNode* cur = dum;
    while(l1&&l2){
        if(l1->val<l2->val){
            cur->next = l1;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1!=nullptr?l1:l2;
    return dum->next;
}

ListNode *sortlist(ListNode* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    ListNode* head2 = mid(head);
    head = sortlist(head);
    head2 = sortlist(head2);

    return mec(head,head2);
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

    ListNode* head =new ListNode(5);
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printl(head);
    printl(sortlist(head));
    return 0;

}
