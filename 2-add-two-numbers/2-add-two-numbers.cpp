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
        // creat a dummy linked list to store the addition
        ListNode *dummy = new ListNode();
        // creat a temp node to indicate dummy
        ListNode *temp = dummy; 
        int carry = 0;
      
        // run a loop while l1 != NULL or l2 != NULL or carry != 0
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
          
            // if l1! = NULL, add l1 to sum and move to next
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1 -> next;
            }
            
            // if l2! = NULL, add l2 to sum and move to next
            if(l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            
            // always add carry to the sum
            sum += carry; 
          
            // always update the carry like carry = sum/10 , like 10/10=1 to carried next node 
            carry = sum / 10; 
          
            // make a new node with sum%10 , 10%10=0, add the node
            ListNode *node = new ListNode(sum % 10); 
          
            // move temp to node (0)
            temp -> next = node; 
            // then move the temp again
            temp = temp -> next;
        }
        // sum is starting from 0, 0807, so return dummt->next
        return dummy -> next;
    }
};