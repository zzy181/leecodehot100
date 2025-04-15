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

    std::cout << "原始链表: ";
    ListNode* current = node1;
    while (current) {
        std::cout << current->val;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;

    // 反转链表
    ListNode* reversedHead = reverseList(node1);

    std::cout << "反转后的链表: ";
    current = reversedHead;
    bool allPositive = true;
    while (current) {
        std::cout << current->val;
        if (current->val <= 0) {
            allPositive = false;
        }
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;

    // 判断反转后的链表元素是否都为正数
    if (allPositive) {
        std::cout << "反转后的链表所有元素都为正数。" << std::endl;
    } else {
        std::cout << "反转后的链表存在非正数元素。" << std::endl;
    }

    // 释放链表内存
    current = reversedHead;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}    
