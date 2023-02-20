#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
/*************/
struct node *start;
/*************/
struct node *GetNode()
{
    struct node *p;
    p =(struct node*)malloc(sizeof(struct node));
    return p;
}
/*************/
void InsEnd(struct node **start,int x)
{
    struct node *q,*p;
    q=*start;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    p=GetNode();
    p->info=x;
    p->next=NULL;
    q->next=p;
}
/*************/
void InsBeg(struct node **start,int x)
{
    struct node *p;
    p=GetNode();
    p->info=x;
    p->next=*start;
    *start=p;
}
/*************/
void Traverse(struct node *start)
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
/*************/
void InsAft(struct node **q,int x)
{
    struct node *r;
    struct node *p;
    p=GetNode();
    p->info=x;
    r = (*q)->next;
    p->next=r;
    (*q)->next=p;
}
/*************/
void splitLL(struct node **start)
{
    struct node*t,*r,*start2;
    t=*start;
    r=(*start)->next;
    while(r!=NULL&&r->next!=NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
    }
    start2=t->next;
    t->next=NULL;
    Traverse(*start);
    printf("\n");
    Traverse(start2);
}
/*************/
int main()
{
    struct node *start2;
    InsBeg(&start,1);
    InsBeg(&start,1);
    InsBeg(&start,2);
    InsBeg(&start,2);
    InsBeg(&start,2);
    InsBeg(&start,3);
    InsBeg(&start,4);
    InsEnd(&start,4);
    InsEnd(&start,4);
    InsEnd(&start,5);
    Traverse(start);
    printf("\n");
    DelDupli(&start);
    return 0;

}