#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* func(ListNode* l1,ListNode* l2){
    ListNode* dum =new ListNode(0);
    ListNode* cur = dum;
    int carry =0;
    while(l1||l2||carry){
        if(l1){
            carry+=l1->val;
            l1 = l1->next;
        }
        if(l2){
            carry+=l2->val;
            l2 = l2->next;
        }
        cur->next = new ListNode(carry%10);
        cur = cur->next;
        carry = carry/10;
        return dum->next;
    }
}

void printlist(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head1 =new ListNode(2);
    ListNode* list1_1 = new ListNode(4);
    ListNode* list1_2 = new ListNode(3);

    head1->next = list1_1;
    list1_1->next = list1_2;
    printlist(head1);

    ListNode* head2 =new ListNode(5);
    ListNode* list2_1 = new ListNode(6);
    ListNode* list2_2 = new ListNode(4);

    head2->next = list2_1;
    list2_1->next = list2_2;
    printlist(head2);

    printlist(func(head1,head2));
    return 0;

 }