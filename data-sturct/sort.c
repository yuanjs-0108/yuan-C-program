#include <define.h>
//基础的排序算法

//直接插入排序
void inshort(sqList *l){
    int i,j;
    for ( i = 2; i < l->len; i++)
    {
        l->data[0]=l->data[i];
        j=i-1;
        while (l->data[0]<l->data[j])
        {
            l->data[j+1]=l->data[j];
            j--;
        }
        l->data[j+1]=l->data[0];
    }
    
}

//简单选择排序
void esshort(sqList *l){
    int i,j,k;
    for (i = 0; i < l->len-1; i++)
    {
        k=i;
        for (j = i+1; i < l->len; j++)
            if (l->data[k]>l->data[j])
                k=j;     //找到最小数的下标
        int t=l->data[k];
        l->data[k]=l->data[i];
        l->data[i]=t;
    }
}

//冒泡排序
void bubshort(sqList *l){
    int i,j,flag;
    for ( i = 1; i < l->len; i++)//趟数
    {
        flag=0;//0表示未交换，1表示交换
        for (j = 0; j < l->len-1; j++)
            if(l->data[j]<l->data[j+1]){
                int t=l->data[j];
                l->data[j]=l->data[j+1];
                l->data[j+1]=t;
                flag=1;
            }
        if (flag==0) break;
    }
    
}

