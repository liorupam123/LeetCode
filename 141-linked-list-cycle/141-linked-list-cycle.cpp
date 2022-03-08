/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)  return false;
        ListNode *temp = head;
        // take a haspmap of node and its count
        unordered_map<ListNode*,int> map; 
        // traverse still the end
        while(temp!=NULL){ 
            // if any node's count>0 it means ih has already one time 2nd time means cycle
            if(map.count(temp)>0) 
                return true; // return true
            else
                // else mark node count as 1
                map[temp]=1; 
            // move to next
            temp=temp->next; 
        }
        // if the while loop doesn't return true, return false at the end
        return false;
    }
};