#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/
Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp = head;
        while(temp){
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp = head;
        while(temp){
            mp[temp]->next=mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp= temp->next;
        }
        return mp[head];
    }
int main(){
    return 0;
}