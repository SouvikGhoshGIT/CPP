#include <stddef.h>
#include<cstdlib>
#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};
struct L{
struct Node* Head=NULL;
};
void insert(L *l,int val){
    struct Node* n=new Node;
    n->val=val;
    n->next=NULL;

    if(l->Head != NULL){
        struct Node* curr=l->Head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=n;

    }
    else{
        l->Head=n;
    }

}
void show(L *l){
Node *n=l->Head;
while(n->next!=NULL){
    cout << n->val;
    n=n->next;

}cout << n->val <<endl;
}

L* reverse(L *l){
    Node *current=NULL;
    Node *prev=NULL;
    Node *next=NULL;

    current=l->Head;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    l->Head=prev;

    return l;
}

int main(){
    L *l=new L();
   insert(l,1);
      insert(l,2);

   insert(l,3);

   insert(l,4);
   show(l);
   reverse(l);
   show(l);

}
