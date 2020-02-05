#include "define.h"
//单链表的基本操作

//不带头节点的单链表的遍历
void display(snode *head){
    snode *p=head;  //带头节点的单链表见此处改为:p=head->next
    while (p->next!=null)
    {
        printf("%d",p->data);
        p=p->next;
    }
}

//在不带头节点的单链表中查找一个值为X的元素，在其后插入一个数据域为y的结点
int insert(snode *head,elemtype x,elemtype y){
    snode *p=head;
    if (p==null) return -1;
    while (p->data!=x&&p->next!=null)
        p=p->next;
    if (p->data==x){
        snode *q=(snode*)malloc(sizeof(snode));
        q->data=y;
        q->next=p->next;
        p->next=q;
        return 1;
    }
    else return -1;
}
//在不带头节点的单链表中查找一个值为x的元素，并删除他
int delete(snode *head,elemtype x){
    snode *p=head;
    if (p==null) return -1;
    while(p->next!=null&&p->next->data!=x)
        p=p->next;
    if (p->next->data==x){
        snode *q=p->next;
        p=p->next->next;
        free(q);
        return 1;
    }
    else return -1;
}
//不带头节点的单链表的逆置
snode* inversion(snode *head){
    snode *p=head,*q=null,temp;
    while (p)
    {
        temp=p->next;
        p->next=q;
        q=p;
        p=temp;
    }
    return q;
}
//两个有序(升序)单链表的合并,生成一个新的有序单链表 
void merge(snode *head1,snode *head2,snode *head3){//默认head3为空表
    snode *p=head1,*q=head2,*s=head3;
    while (p!=null&&q!=null)
    {
        s=(snode*)malloc(sizeof(snode));
        s->next=null;
        if (p->data<q->data)
        {
           s->data=p->data;
           s=s->next;
           p=p->next;
        }else
        {
            s->data=q->data;
            s=s->next;
            q=q->next;
        }
    }
    while (p)
    {
        s=(snode*)malloc(sizeof(snode));
        s->next=null;
        s->data=p->data;
        p=p->next;
    }
    while (q)
    {
        s=(snode*)malloc(sizeof(snode));
        s->next=null;
        s->data=q->data;
        q=q->next;
    }
    
}