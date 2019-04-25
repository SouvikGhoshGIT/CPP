#include <stddef.h>
#include<cstdlib>
#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};
struct Node* Head=NULL;
void insert(int val){
    struct Node* n=new Node;
    n->val=val;
    n->next=NULL;

    if(Head != NULL){
        struct Node* curr=Head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=n;
        
    }
    else{
        Head=n;
    }

}
void show(){
Node *n=Head;
while(n->next!=NULL){
    cout << n->val;
    n=n->next;

}cout << n->val;
} 

int main(){
   insert(1); 
      insert(2); 

   insert(3); 

   insert(4); 
   show();

}