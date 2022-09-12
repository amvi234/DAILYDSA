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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
     }
          temp=head; 
        cout<<len<<endl;
        int a=len/2;
        cout<<a;
        
        ListNode* ans=head;
        if(len%2==0){
             while(len--){
              if(len==a){
                  ans=temp->next;
              }
         temp=temp->next;
        }
        }
        else{
            a=a+1;
            while(len--){
              if(len==a){
                  ans=temp->next;
              }
         temp=temp->next;
        }
        }
       
        return ans;
        // ListNode* f;
        // ListNode* s;
        // while(f!=NULL && f->next!=NULL){
        //     s=s->next;
        //     f=f->next->next;
        // }
        // return s;
    }
};