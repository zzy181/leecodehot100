#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dum = new ListNode(0);
    ListNode* cur = dum;
    while(list1!=nullptr&&list2!=nullptr){
        if(list1->val<list2->val){
            cur->next = list1;
            list1 = list1->next;
        }
        else{
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    cur->next = list1!=nullptr?list1:list2;
    return dum->next;
    
}

void printListNode(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next!=nullptr) cout<<"->";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* list1_2 = new ListNode(2);
    ListNode* list1_3 = new ListNode(4);

    head1->next = list1_2;
    list1_2->next=list1_3;

    ListNode* head2 = new ListNode(1);
    ListNode* list2_2 = new ListNode(3);
    ListNode* list2_3 = new ListNode(4);

    head2->next = list2_2;
    list2_2->next = list2_3;

    ListNode* list3 = mergeTwoLists(head1,head2);
    printListNode(list3);
    return 0;


}
