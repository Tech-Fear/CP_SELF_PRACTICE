// #include<bits/stdc++.h>
// using namespace std;
// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };
// */

// class Solution {
// private:
//   unordered_map<Node*,Node*>mp;

// public:
//     void trav(Node *head){
//       while(trav){
//         Node *temp=new Node(head->val);
//         mp[head]=temp;
//         head=head->temp;
//       }
//     }
//     Node* copyRandomList(Node* head) 
//     {   if(!head) return nullptr;
//         Node *temp=head;
//         trav(temp);
//         Node *curr=head;
//         while(curr){
//           mp[curr]->next=mp[curr->next]
//           mp[curr]->random=mp[cur->random];
//           curr=curr->next;
//         }
//         return mp[head];
//     }
// };


class solution{
  public:
    void insert(Node *head){
      while(head){
        Node *temp=new Node(head->val);
        temp->next=head->next;
        head->next=temp;
        head=temp->next;
      }
    }
    void connectRandom(Node *head){
      while(head){
        if(head->random){
          head->next->random=head->random->next;
        }
        head=head->next;
      }
    }
    Node *createCopy(Node *head){
      Node *temp=new Node(0);
      Node *cur=temp;
      while(head){
        curr->next=head->next;
        curr=cur->next;
        head->next=head->next->next;
        head=head->next;
      }
      return temp->next;
    }
   Node* clone(Node *head){
    if(!head) return nullptr;
      insert(head);
      connectRandom(head);
      return createCopy(head);

   }

};