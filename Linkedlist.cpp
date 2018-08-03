#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;
};


node * insert(node * head, int d){ //insert at the end

    node * q=head;
    
    node * p=new node;
    p->data=d;
    p->next=NULL;
    
    if(head==NULL){
        head=p;
    }
    else{
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }
    return head;
}

node * insertpos(node* head, int d, int pn){   //insert at specific position
    int cnt=1;
    node *q=head;
    node *p=new node;
    p->data=d;
    p->next=NULL;
    
    if(pn==1){
        p->next=head;
        head=p;
    }
    else{
        while(q->next!=NULL && cnt<pn-1){
            q=q->next;
            cnt++;
        }
        p->next=q->next;
        q->next=p;
        
    }
    return head;
}

node *deletefrnt(node *head){
    node *p=head;
    head=head->next;
    return head;
}

void print (node* head){
    node * q=head;
    while(q!=NULL){
        cout<<q->data<<"\t";
        q=q->next;
    }
    cout<<endl;
}

int main() {
	
	node * head=NULL;
	
	for(int i=0;i<10;i++){
	    head=insert(head ,i);
	}
	
	cout<<"insert at end "<<endl;
	print(head);
	
	cout<<"insert at specific positon after head "<<endl;
	head=insertpos(head, 13, 5);
	print(head);
	
	cout<<"insert at positions greater than length "<<endl;
	head=insertpos(head, 45, 13);
	print(head);
	
	cout<<"insert at before head "<<endl;
	head=insertpos(head, 11, 1);
	print(head);
	
	cout<<"delete first "<<endl;
	head=deletefrnt(head);
	print(head);
	return 0;
}
