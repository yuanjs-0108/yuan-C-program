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
    node *next;
}snode;
//双链表
typedef struct node
{
    elemtype data;
    node *prior,*next;
}dnode;

//栈

