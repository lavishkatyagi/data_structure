#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 1
struct node{
    int info;
    struct node *next;
};


struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}


void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}


void insertbeggining(struct node**start,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}


void insertend(struct node**start,int x){
    struct node*p,*q;
    q=*start;
    if(q==NULL){
        insertbeggining(start,x);
    }

    else{
        while(q->next!=NULL){
        q=q->next;
    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;
    }
    
}


void insertafter(struct node **q, int x){
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*q)->next;  
    p->next=r;    
    (*q)->next=p;
}


int middleelement(struct node **start)
{
    struct node *t,*r;
    t=start;
    r=(*start)->next;
    while(r!=NULL && r->next != NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t->info;
}
struct node* binarysearch(struct node**start,int x){
    struct node*mid;
    while((*start)->next!=NULL){
        mid=middleelement(start);
        if(mid->info==x){
        return mid;
    }
    else{
        if(x<mid->info){
            mid->next=NULL;
        }
        else{
            (*start)=mid->next;
        }
        }
    }
    if((*start)->info==x){
        return start;
    }
    else{
        return NULL;
    }
    

}
int main(){
    struct node *start1,*start2;
    start1 = NULL;
    start2 = NULL;
    
    struct node*p,*q;

    insertbeggining(&start1,1);
    insertbeggining(&start1,2);
    insertbeggining(&start1,3);
    insertbeggining(&start1,9);
    insertbeggining(&start1,5);
    insertbeggining(&start1,6);
    insertbeggining(&start1,7);
    insertbeggining(&start1,4);
    insertbeggining(&start1,8);
    insertbeggining(&start1,10);
    insertbeggining(&start1,0);
    traverse(start1);
    int x;
    scanf("%d",&x);
    int m = binarysearch(&start1,x);
    printf("%d",m);
    
}