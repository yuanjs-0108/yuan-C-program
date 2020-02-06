#ifndef _define_H_
#define _define_H_
#include <stdio.h>
#define Maxsize 50
#define elemtype int
#define null 0
//线性表

//顺序表
typedef struct 
{
    elemtype data[Maxsize];
    int len;   
}sqList;

//链表
//单链表
typedef struct node
{
    elemtype data;
    struct node *next;
}snode;
//双链表
typedef struct node
{
    elemtype data;
    struct node *prior,*next;
}dnode;

//栈
//顺序栈
typedef struct 
{
    elemtype data[Maxsize];
    int top;//栈顶指针->下标值
}stack;
//链栈
typedef struct lnode
{
    elemtype data;
    struct lnode *next;
}lstack;

//队列
//顺序队列
typedef struct 
{
    elemtype data[Maxsize];
    int front,rear;
}queue;
//链栈
typedef struct 
{
    snode *front,*rear;
}lqueue;


//二叉树
typedef struct tnode
{
    elemtype data;
    struct tnode *lchild,*rchild;
}Btree;



