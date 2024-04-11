#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // check is list is empty or has only one element
        if(head == nullptr || head->next == nullptr){
            return true; 
            // we return true because if list is empty or has only one element then it is palindrome
        }

        // we make a stack to store the values of the first half of the list
        stack<int> values;
        ListNode* slow = head;
        ListNode* fast = head;

        // we use slow and fast method to find the middle of the list while simultaniusly pushing the values of the first half of the list into the stack
        while(fast != nullptr && fast->next!=nullptr){
            values.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // is list has odd number of elements then we move the slow pointer to the next element
        if(fast != nullptr){
            slow = slow->next;
        }

        // now we go from the middle of the list to the end of the list and compare the values of the stack with the values of the list 
        while(slow!=nullptr){
            int top = values.top();
            values.pop();

            if(top != slow->val){
                return false;
            }
            
            slow = slow->next;
        }

        // we return ture if the list is palindrome as all the checks have passed

        return true;
}
};

int main(){
    Solution s;
    vector<int> values = {1,2,2,1};
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for(int i=1; i<values.size(); i++){
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    if(s.isPalindrome(head)){
        cout << "Yes it is Palindrome";
    }else{
        cout << "No it is not palindrome";
    }

    return 0;
}