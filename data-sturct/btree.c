#include <define.h>
//二叉树的基本操作

/*lchild为树的左孩子域
  rchild为树的右孩子域
  为了方便理解，树的算法大都由递归实现*/

//先序遍历
int preorder(Btree *t){
    if(t==null) return null;
    printf("%d",t->data);
    preorder(t->lchild);
    preorder(t->rchild);
    return 1;
}

//中序遍历
int midorder(Btree *t){
    if (t==null) return null;
    midorder(t->lchild);
    printf("%d",t->data);
    midorder(t->rchild);
    return 1;
}

//后续遍历
int latorder(Btree *t){
    if (t==null) return null;
    latorder(t->lchild);
    latorder(t->rchild);
    printf("%d",t->data);
    return 1;
}

//层次遍历
void levelordel(Btree *t){
    typedef struct 
    {
      Btree *vec[Maxsize];
      int *front,*rear;
    }bqu;//自定义一个存储树结点的队列；
    bqu q; Btree *p;
    q.front=q.rear=null;
    if (t)
    {
      printf("%d",t->data);//输出结点值
      q.vec[q.rear++]=t;
      while (q.front<q.rear)
      {
        p=q.vec[q.front++];//出队
        if(p->lchild!=null)
        {
          printf("%d",p->lchild->data);
          q.vec[q.rear++]=p->lchild;//左孩子入队
        }
        if (p->rchild!=null)
        {
          printf("%d",p->rchild->data);
          q.vec[q.rear++]=p->rchild;//右孩子入队
        }
      }
    }  
}

//求叶子结点个数
int leafnod(Btree *t){
  if(t==null) return 0;
  else if(t->lchild==null&&t->rchild==null) return 1;
  else return leafnod(t->lchild)+leafnod(t->rchild);
}

//求度为1的结点个数
int degree1(Btree *t){
  if(t==null) return 0;
  else if((t->lchild==null&&t->rchild!=null)||(t->lchild!=null&&t->rchild==null))
      return 1+degree1(t->lchild)+degree1(t->rchild);
  else return degree1(t->lchild)+degree1(t->rchild);
}

//求树的高度
int hight(Btree *t){
  if (t==null) return 0;
  else {
    int lhig=hight(t->lchild),rhig=hight(t->rchild);
    return 1+(lhig>rhig)?lhig:rhig;
  }
}

//统计二叉树的结点个数
int Tcount(Btree *t){
  if(t==null) return null;
  else if(t->lchild==null&&t->rchild==null) return 1;
  else return Tcount(t->lchild)+Tcount(t->rchild);
}

//计算二叉树所有结点之和
int Tsum(Btree *t){
  if(t==null) return 0;
  else return t->data+Tsum(t->lchild)+Tsum(t->rchild);
}

//求两棵树是否相同
int same(Btree *t1,Btree *t2){
  if(t1==null&&t2==null) return 1;
  else if(t1==null||t2==null) return 0;
  else
  {
    int same1=same(t1->lchild,t2->lchild);
    int same2=same(t1->rchild,t2->rchild);
    return (same1&&same2);
  }
}

//交换所有结点的左右子树
void exchange(Btree *t){
  if (t==null) return ;
  else if(t->lchild==null&&t->rchild==null) return ;
  else
  {
    Btree *p;
    p=t->lchild;
    t->lchild=t->rchild;
    t->rchild=p;
  }
  exchange(t->lchild);
  exchange(t->rchild);  
}

