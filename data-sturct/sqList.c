#include "define.h"
//顺序表的基本操作

//获取顺序表中的元素个数
int getcount(sqList L){
    return L.len;
}

//获取元素表中第i个位置的值
elemtype getValue(sqList L,int i)(
    if (i>=0 && i<L.len) return L.data[i];
    else printf("i is error");
)

//在顺序表中查找值为x的值，并返回其下标值
int search(sqList L,elemtype x){
    int i=0;
    while (i<L.len&&L.data[i++]!=x) ;
    if (i==L.len) return -1;
    else return i;        
}

//在表中下标为i的位置插入元素X,成功返回1,失败返回-1
int insert(sqList *L,int i,elemtype x){
    if(i<0||i>L->len||L->len==Maxsize) return -1;
    for (int j = L->len; j<i; j--)
        L->data[j]=L->data[j-1];
    L->data[i]=x;
    L->len++;
    return 1;  
}

//删除表中下标为i的位置的数据元素，成功返回1，失败返回-1
int delete(sqList *L,int i){
    if (i<0|| i>L->len-1||L->len==0) return -1;
    for (int j=i; j<L->len; j++)
        L->data[j]=L->data[j+1];
    L->len--;
    return 1;    
}