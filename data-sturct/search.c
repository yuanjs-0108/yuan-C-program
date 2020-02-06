#include <define.h>
//基础的查找算法


/*顺序查找
使用顺序表或链表实现。
从头到尾依次查找
*/
//顺序表的查找
int search(sqList l,elemtype x){
    for (int i = 0; i < l.len-1; i++)
        if(l.data[i]==x)
            return i;
    return -1;    
}
//链表的查找
int search(snode *head,elemtype x){
    snode *p=head;
    int cnt=0;
    while (p)
    {
        cnt++;
        if(p->data==x) break;
        p=p->next;
    }
    return cnt;    
}

/*二分查找
给定数据必须有序
首先与中间元素进行比较
大-->移动左边界=mid+1
小-->移动右边界=mid-1
继续以上操作
*/

int binaryser(sqList l,elemtype x){
    int left=0,right=l.len-1,mid;
    while (left<right)
    {
        mid=(left+right)/2;
        if(l.data[mid]<x) left=mid+1;
        else if(l.data[mid]>x) right=mid-1;
        else return mid;
    }
    return -1;
    
}