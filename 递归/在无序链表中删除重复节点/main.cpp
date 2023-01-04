// @Func: 递归删除无序链表中的重复节点
// @Example: 1->3->1->5->3->5->7  ==>  1->3->5->7

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class WorkList {
public:
    WorkList(const ListNode& l) : m_list(l) {}
    WorkList() = default;

    void rmDup() {
        rmDup(m_list.next);
    }

    void insert(const int a[], int len) {
        ListNode* cur = &m_list;

        for(int i = 0; i < len; i++) {
            ListNode* lNode = new ListNode();
            lNode->val = a[i];
            lNode->next = nullptr;
            cur->next = lNode;
            cur = cur->next;
        }
    }

    void print() {
        ListNode* cur = m_list.next;

        while(cur != nullptr) {
            cout << cur->val << endl;
            cur = cur->next;
        }
    }

private:
    void rmDup(ListNode* head) {
        if(head) {
            rmDup(head->next);  // 删除子链表重复节点
            // 两种实现方式都可以
            //rmDup(head->next, head->val); // 删除与head重复的其他节点
            rmDupRecursive(head->next, head->val);
        }
    }

    void rmDup(ListNode*& head, int v) { // 循环遍历的方式
        if( head ) {
            ListNode* pre = nullptr;
            ListNode* slider = head;

            while( slider ) {
                if( slider->val == v ) {
                    if( slider == head ) {
                        head = slider->next;

                        delete slider;

                        slider = head;
                    } else {
                        ListNode* toDel = slider;

                        slider = slider->next;
                        pre->next = slider;

                        delete toDel;
                    }
                } else {
                    pre = slider;
                    slider = slider->next;
                }
            }
        }
    }

    void rmDupRecursive(ListNode*& head, int v) {  // 递归方式的实现
        if(head) {
            if(head->val == v) {
                ListNode* toDel = head;

                head = head->next;

                delete toDel;

                rmDupRecursive(head, v);
            } else {
                rmDupRecursive(head->next, v);
            }
        }
    }

private:
    ListNode m_list;
};

int main() {
    int a[] = {1,2,3,5,6,4,5,4,5,3,6};
    int len = sizeof(a) / sizeof(*a);

    WorkList workList{};

    workList.insert(a, len);

    workList.rmDup();

    workList.print();
}