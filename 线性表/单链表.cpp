#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
struct  LNode
{
	ElemType data;
	struct LNode* next;
};
typedef struct LNode LinkNode;
void InitList(LinkNode*& list);
void CreateListHead(LinkNode*& list, int a[], int n);
void CreateListTail(LinkNode*& list, int a[], int n);
void dispList(LinkNode* L);
int LengthList(LinkNode* list);
void DestoryList(LinkNode*& list);
bool GetElem(LinkNode* list, int i, ElemType& e);
int LocateElem(LinkNode* list,ElemType e);
bool ListInsert(LinkNode*& list, int i, ElemType e);
bool ListDelete(LinkNode*& list, int i, ElemType& e);
int main()
{
	int a[] = { 5,1,3,8,2 };
	int n = sizeof(a) / sizeof(a[0]);

	LinkNode * myList;
	//InitList(myList);   //初始化线性表
    //CreateListHead(myList,a,n);  //头插法
	CreateListTail(myList,a,n);
	dispList(myList);
	int len;
	len = LengthList(myList);
	printf("线性表的长度为len = %d\n", len);
	ElemType  resdata;
	GetElem(myList, 2, resdata);
	printf("某个元素的值为 = %d\n", resdata);
	int loc;
	loc = LocateElem(myList, 8);
	printf("8 在线性表中逻辑序号loc=%d\n", loc);

	ListInsert(myList,3,4);
	dispList(myList);

	ElemType x;
	ListDelete(myList,3, x);
	printf("刪除x=%d\n", x);
	dispList(myList);  

	DestoryList(myList);
	return 0;
}
/*
*  功能:初始化单链表 ，为头结点申请内存空间
* 函数名称：InitList
* 参数‘;
* --list :单链表 指针类型，引用方式传递参数
* 返回类型 ：void
*/
void InitList(LinkNode*& list)
{
	list = (LinkNode*)malloc(sizeof(LinkNode));
	list->next = NULL;
}

/*
* 功能运用头插法以数组元素创建单链表
* 函数名称CreateListHead
* 参数:
* ---list :单链表指针类型,引用方式传递参数
* a:数组首地址
* n：数组元素的个数
* 返回类型 void 
*/
void CreateListHead(LinkNode * &list, int a[], int n)
{
	LinkNode* s;
	int i;
	list = (LinkNode*)malloc(sizeof(LinkNode));
	for (i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s -> data =  a[i];
		s -> next = list -> next;
		list->next = s;
	}
}
/*
*   功能：应用尾插法，以数组元素创建单链表
* 函数名称 CreateListTail;
* 参数：
* list : 单链表指针类型，引用方式传递参数
* ----a:数组首地址
* n:数组元素的个数
* 返回类型 void
*/
void CreateListTail(LinkNode * &list ,int a[],int n)
{
	LinkNode* s, * tail;
	list = (LinkNode*)malloc(sizeof(LinkNode));
	list -> next = NULL;
	tail = list;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = NULL;
		tail->next = s;
		tail = s;
	}
}
/*
* 输出线性表
* 函数名称 dispList
* 参数
* list：双链表指针类型
* 返回类型：void
*/
void dispList(LinkNode * list)
{
	LinkNode* p;
	p = list->next;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}
/*
* 功能：判断线性表是否为空
* 函数名称 ListEmpty
* 参数 
* list  ： 但链表指针类型
* 返回类型 bool
*/
bool ListEmpty(LinkNode* list)
{
	return (list->next == NULL);

}
/*
* 求线线性表的长度
* 
*/
int LengthList(LinkNode* list)
{
	int length = 0;
	LinkNode* p = list->next;
	while (p != NULL)
	{
		length++;
		p = p->next;

	}
	return length;
}
/*
* 销毁线性表
*/
void DestoryList(LinkNode *& list)
{
	LinkNode* pre = list;
	LinkNode* p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	list = NULL;
}
/*
* 求线性表中某个元素的数据元素值
*
*/

bool GetElem(LinkNode* list, int i, ElemType& e)
{
	int j = 0;
	if (i < 1) return false;
	LinkNode * p = list; //p指向头结点，J置为0
	while (j < i && p != NULL)//(头结点的序号为0)
	{
		j++;
		p=p->next;//让p指向下一个元素
	}
	if (p == NULL)  //不存在第i个结点 返回false
		return false;
	else   //存在第i个结点返回 true
	{
		e = p->data;
		return true;
	}
}
/*
* ；按元素值查找
* 初始化计数器 i =0；
* 定义指针变量 P,初始化为list -> next;
* 当 p不等于空 且p->data不等于e 时就遍历链表让p指针向后移动，指向下一个结点累加+1
* 判断是否查找成功，如果p等于空，则没有找到数据e，返回0，否则返回i+1
*/
int LocateElem(LinkNode * list,ElemType e)
{
	int i = 0;
	LinkNode * p = list -> next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i + 1;
}
/*
* 插入操作的
* 思路 1.初始化  K=1;
* 2.定义指针变量 P ,初始化为 list->next;
* 3、定位要插入的前一个位置 i-1；
* 当 看< i-1且p的后继结点非空时就遍历链表  让 k+1  
* p向后移动
* 4.定好位置后，构造新结点S，数据域赋值X
* 5.将S插入到p之后
* s->next - p->next;
* p->next = s;
*/
bool ListInsert(LinkNode *& list, int i, ElemType e)  //改变链表&
{
	if (i < 1) return false;
	LinkNode* m,*p;  //p指向第一个数据结点
	//s用于指向要构造的数据结点   p用来扫描单链表
	//确定要插入位置的前一个位置
	p = list->next;
	int k = 1;
	while (p != NULL && k < i - 1)//k不是要插入结点的后一位置
	{
		k++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	m = (LinkNode*)malloc(sizeof(LinkNode));
	m->data = e;
	m ->next = p->next;
	p ->next = m;
	return true;
}
/*s删除节点的实现
* 只需修改相关结点的指针域，不需要移动结点
*1、 初始化位置  K =1
* 2、定义节点指针 p初始化为 list->next
* 3、定位到要删除的元素前一个位置i-1；
* 当 k < i-1且p的后继结点非空是 就遍历连链表让 k+1
* p 指针向后移动
* 4，定好位置之后，让s指向要删除的结点 ,s数据域赋值给e
* 5、删除操作
* 
*/
bool ListDelete(LinkNode*& list, int i, ElemType& e)

{
	if (i < 1) return false;
	int k = 1;
	LinkNode * s,* p;
	p = list->next;
	//确定要删除的位置
	while (p != NULL && k < i - 1)
	{
		k++;
		p = p->next;
	}
	if ( p->next == NULL) return false;
	s = p -> next;
	e = s -> data;
	p->next = s->next; 
	free(s);
	return true;
}
