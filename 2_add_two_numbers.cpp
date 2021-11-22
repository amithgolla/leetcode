/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;
        int adder = 0;
        while(ptr1 != NULL && ptr2 != NULL){
            int part = ptr1->val + ptr2->val + carry;
            carry = part/10;
            adder = part % 10;
            if(ans == NULL){
                if(ptr1->next == NULL && ptr2->next == NULL && carry != 0){
                    ans = new ListNode(adder);
                    ListNode* temp = new ListNode(carry);
                    ans->next = temp;
                }else{
                    ans = new ListNode(adder);
                    tail = ans;
                }
            }else{
                if(ptr1->next == NULL && ptr2->next == NULL && carry != 0){
                    ListNode* temp = new ListNode(adder);
                    tail->next = temp;
                    tail = temp;
                    ListNode* temp1 = new ListNode(carry);
                    tail->next = temp1;
                    tail = temp;
                }else{
                    ListNode* temp = new ListNode(adder);
                    tail->next = temp;
                    tail = temp;
                }
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr1 != NULL){
            while(ptr1 != NULL){
                int part = carry + ptr1->val;
                carry = part/10;
                adder = part % 10;
                ListNode* temp = new ListNode(adder);
                tail->next = temp;
                tail = temp;
                if(ptr1->next == NULL && carry != 0){
                    ListNode* temp1 = new ListNode(carry);
                    tail->next = temp1;
                    tail = temp1;
                }
                ptr1 = ptr1->next;
            }
            
        }
        if(ptr2 != NULL){
            while(ptr2 != NULL){
                int part = carry + ptr2->val;
                carry = part/10;
                adder = part % 10;
                ListNode* temp = new ListNode(adder);
                tail->next = temp;
                tail = temp;
                if(ptr2->next == NULL && carry != 0){
                    ListNode* temp1 = new ListNode(carry);
                    tail->next = temp1;
                    tail = temp1;
                }
                ptr2 = ptr2->next;
            }
            
        }
        return ans;
        
    }
};