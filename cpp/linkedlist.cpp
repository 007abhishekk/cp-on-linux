#include<iostream>
#include<stdlib.h>
using namespace std;
//node
class node{
public:
int data;
node* next;
};

int count=0;
node *head=NULL;

void insAtEnd(){
node *temp=(node*)malloc(sizeof(node));
node *q=head;
int p;
cout<<"Enter Input"<<endl;
cin>>p;
if(head==NULL){
temp->data=p;
head=temp;
temp->next=NULL;
count++;
}
else {
while(q->next!=NULL){
    q=q->next;
}
temp->data=p;
temp->next=NULL;
q->next=temp;
count++;
}
}

void display(){
node *t=head;
while(t!=NULL){
    cout<<t->data;
    if(t->next!=NULL)
        cout<<"->";
    t=t->next;
}
cout<<endl;
}

void insAtbeg(){
node* temp=(node*)malloc(sizeof(node));
int p;
cout<<"Enter Input"<<endl;
cin>>p;
if(head==NULL){
    temp->data=p;
    temp->next=NULL;
    head=temp;
    count++;
}
else{
    temp->data=p;
    temp->next=head;
    head=temp;
    count++;
}
}

void insAtnode(){
cout<<"1.Before"<<endl<<"2.After"<<endl;
int k;
cin>>k;
    cout<<"Enter value ";
    if(k==1)
        cout<<"before ";
    if(k==2)
        cout<<"after ";
    cout<<"which number is to be added"<<endl;
    int val;
    cin>>val;
    cout<<"Value to be added:"<<endl;

switch(k){
case 1:
 {
     node *temp=(node*)malloc(sizeof(node));
    node *q=head;
    if(val==q->data)
        insAtbeg();
    else{
            int k1;
    cin>>k1;
        while(q->next->data!=val){
        q=q->next;
    }
    temp->data=k1;
    temp->next=q->next;
    q->next=temp;
    count++;
    }
    break;
}
case 2:
       {
           int k1;
    cin>>k1;
     node *temp=(node*)malloc(sizeof(node));
           node* p=head;
        while(p->data!=val){
        p=p->next;
    }
    temp->data=k1;
    temp->next=p->next;
    p->next=temp;
    count++;
    break;
       }
default:
    cout<<"Wrong Input"<<endl;

}
}
void del(){
cout<<"1. By value"<<endl<<"2. By index"<<endl;
int k;
cin>>k;
        node *temp=(node*)malloc(sizeof(node));
switch(k){
case 1:
    {
        cout<<"Enter value"<<endl;
        int val;
        cin>>val;
        node *temp=(node*)malloc(sizeof(node));
        node *q=head;
        node *pre;
        while(q->data!=val)
        {
            pre = q;
            q=q->next;

        }
        if(q==NULL){
            cout<<"value not found!"<<endl;
            break;
        }
        if(q==head){
                temp=head;
                head=head->next;
                free(temp);
                count--;
        }
        else {
            pre->next=q->next;
            free(q);
            count--;
        }
        break;
    }
case 2:
    {
       node* temp=(node*)malloc(sizeof(node));
        cout<<"Enter position"<<endl;
    int index;
    cin>>index;
    node *q=head;
    node *pre;
    for(int i=1;i<index;i++){
        pre=q;
        q=q->next;
    }
    if(index>count){
        cout<<"Underflow!"<<endl;
    }
        if(q==head){
                temp=head;
                head=head->next;
                free(temp);
                count--;
        }
        else {
            pre->next=q->next;
            free(q);
            count--;
        }
break;
    }
default:
    cout<<"Wrong Input"<<endl;
}
}


int main(){
    start:;
	int k;
    while(1){
            cout<<"1.Insert at End"<<endl<<"2.Insert at Beginning."<<endl<<"3. Insert At a given node."<<endl<<"4.Delete at a node."<<endl<<"11.Display."<<endl;
    cout<<"Enter Choice: ";
    cin>>k;
    switch(k){
case 1:
    insAtEnd();
    break;
case 11:
    display();
    break;
case 2:
    insAtbeg();
    break;
case 3:
    insAtnode();
    break;
case 4:
    del();
    break;
default:
    cout<<"Wrong Input"<<endl;
    }
    int p;
    cout<<"1.Continue"<<endl<<"2.Exit"<<endl;
    cin>>p;
    switch(p){
case 1:
    goto start;
    break;
case 2:
    exit(0);
default:
    cout<<"Wrong Input"<<endl;
    }
}
return 0;
}

