#include <stddef.h>
#include<cstdlib>
#include<iostream>
#include<cmath>
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

void addTwoNumbers(L* l1, L* l2) {
        reverse(l1);
        reverse(l2);
        int cnt=1;
        int sum1=0,sum2=0;
        Node *n1=l1->Head;
        Node *n2=l2->Head;
        for(int i=cnt;cnt<=3;cnt++){
            sum1 += (pow(10,(3-cnt)) * (n1->val));
            n1=n1->next;
            sum2 += (pow(10,(3-cnt)) * (n2->val));
            n2=n2->next;

        }
        sum1 += sum2;
        L *result=new L();
        for (int i=1;i<=3;i++){
            auto DV=std::div(sum1,(pow(10,(3-i))));
            insert(result,DV.quot);
            sum1=DV.rem;
        }
        show(result);

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

   L *L1=new L();
   insert(L1,2);
   insert(L1,4);
   insert(L1,3);


   L *L2=new L();
   insert(L2,5);
   insert(L2,6);
   insert(L2,4);

    addTwoNumbers(L1,L2);

}
