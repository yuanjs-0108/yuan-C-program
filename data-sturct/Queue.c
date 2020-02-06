#include <define.h>
//队列的基本操作

/*front为队头指针，用于数据的删除操作，
  rear为队尾指针，用于数据的插入操作，
  队列的特性为：先进先出，后进后出
  为了防止假溢出现象，以下操作会用到循环队列*/

//入队操作
//顺序队列
int insert(queue *qu,elemtype x){
    if ((qu->rear+1)%Maxsize==qu->front) return -1;
    qu->data[qu->rear]=x;
    qu->rear=(qu->rear+1)%Maxsize;
    return 1;
}
//链队列
void linsert(lqueue *qu,elemtype x){
    snode *p=(snode*)malloc(sizeof(snode));
    p->data=x;
    p->next=null;
    if (qu->rear==null)
    {
        qu->rear=p;
        qu->front=p;
    }else
    {
        qu->rear->next=p;
        qu->rear=p;
    }
}

//出队操作
//顺序队列
elemtype delete(queue *qu){
    if (qu->front==qu->rear) return ;
    elemtype x=qu->data[qu->front];
    qu->front=(qu->front+1)%Maxsize;
    return x;
}
//链队列
elemtype ldelete(lqueue *qu){
    if(qu->front==null) return ;
    else if(qu->rear==qu->front){
       elemtype x;
       snode *p=qu->front;
       x=p->data;
       qu->rear=null;
       qu->front=null;
       free(p);
       return x;
    }else
    {
        elemtype x;
        snode *p=qu->front;
        x=p->data;
        qu->front=p->next;
        free(p);
        return x;
    }
    
}