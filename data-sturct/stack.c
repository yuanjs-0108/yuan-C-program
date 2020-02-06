#include <define.h>
//栈的基本操作

/*栈顶top为插入和删除数据的端点
栈底是对应栈顶的一端
栈的特点为：先进后出，后进先出*/

//入栈操作
//顺序栈
int push(stack *s,elemtype x){
    if(s->top==Maxsize) return -1;
    s->top++;
    s->data[s->top]=x;
    return 1;
}
//链栈
void lpush(lstack *top,elemtype x){
    lstack *q;
    q=(lstack*)malloc(sizeof(lstack));
    q->data=x;
    q->next=top;
    top=q;
}

//出栈操作
//顺序栈
elemtype pop(stack *s){
    if (s->top==-1) return -1;
    else return s->data[s->top--];
}
//链栈
elemtype lpop(lstack *top){
    if (top==null) return -1;
    lstack p=top;
    elemtype x=p->data;
    top=top->next;
    free(q);
    return x;
}