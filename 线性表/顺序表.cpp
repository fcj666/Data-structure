#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define Maxsize 100

typedef struct SqeuenceList
{
	ElemType data[Maxsize];
	int length;
}SqList;

void InitList(SqList*& list);
void CreateList(SqList*& list, ElemType a[], int n);
bool ListEmpty(SqList* list);
void displist(SqList* list);
int ListLength(SqList * list);
bool GetElem(SqList* list, int i, ElemType& e);
int LocateElem(SqList* list, ElemType e);
bool ListInsert(SqList* &list,int i, ElemType e);
bool DeleteList(SqList * &list, int i, ElemType & e);
void DestoryList(SqList*& list);
int  main()
{
	SqList* mylist;
	InitList(mylist);
	int a[] = { 2, 4, 8, 16 };
	int n = sizeof(a) / sizeof(a[0]);//所占字节数
	CreateList(mylist,a, n);
	displist(mylist);
	int length = ListLength(mylist);
	printf("length of list is %d\n",length);

	int value;
	GetElem(mylist, 3, value);
	printf("%d", value);

	value = LocateElem(mylist, 8);
	printf("\n8在顺序表中的逻辑位序value=%d\n",value);

	ListInsert(mylist, 3, 12);
	displist(mylist);

	DeleteList(mylist,3,value);
	printf("\nvalue=%d\n", value);
	displist(mylist);

	DestoryList(mylist);
	return 0;

}
/*初始化顺序表，为头结点申请内存空间
函数名称 InitList 参数 list：顺序表指针类型，
引用方式传递参数
返回类型 void
*/
void InitList(SqList* &list)  //list变量存储的是Sqlist的地址而不是Sqlist对象的信息
{
	list = (SqList*)malloc(sizeof(SqList));
	list->length = 0;
}
/*list 顺序表指针类型,引用方式传递参数
---a:数组首地址
---n数组元素的个数
返回类型 void */
void CreateList(SqList* &list, ElemType a[], int n)//&list 会改变
{
	int i;
	for (i = 0; i < n && i < Maxsize; i++) //不能超出n和maxsize、
		list->data[i] = a[i];
	list->length = i;//如果n<maxsize  i就是n 如果数组n>maxsize i就是 maxsize

}
/*顺序表判空
函数名称 ListEmpty
参数 ：--list:顺序表指针类型
返回类型 bool
*/
bool ListEmpty(SqList* list)
{
	return(list->length == 0);
}
/*
显示链表中的元素的值
函数名称 displist
参数： --list：双链表指针类型
返回类型 void
*/
void displist(SqList* list)
{
	int i = 0;
	if (ListEmpty(list))
	return;
	for (i = 0; i < list->length; i++)
		printf("%3d", list->data[i]);
	printf("\n");
}
/*功能:计算链表中元素的个数
* 函数名称：ListLength 
* 参数 list：顺序表的指针类型
* 返回类型 int
*/
int ListLength(SqList* list)
{
	return (list->length);
}
/*功能获取线性表中第i个元素的值
* GetElem
* 参数 list：顺序表指针类型
* --i要查中安元素的位置
* e:ElemType类型 输出参数m引用类型
*/
bool GetElem(SqList* list, int i, ElemType & e)
{
	if (i<1 || i>list->length)return false;
		e = list->data[i - 1];
	return true;
}
/*功能：在线性表中查找元素e
* 函数名称LocateElem
* 参数：
* list：链表指针类型
* e:ElemType要查找的数据
* 返回类型 int表示数据的逻辑位序
*/
/*int LocateElem(SqList* list, ElemType e)
{
	for (int i = 0; i < list->length; i++)
		if (list->data[i] == e)
			return i + 1;
	return 0;

}
*/
int LocateElem(SqList* list, ElemType  e)
{
	int i = 0;
	while (i < list->length && list->data[i]!=e)
		i++;
	if (i >= list->length)
		return 0;
	else
		return i + 1;
}
/*
* 想顺序表中的插入第i个位置添加元素e
* 函数名称 InsertList
* 参数 list：链表指针类型 引用类型那
* i 要插入的位置
* e 要查入元素的位置
* 返回类型 BOOL
*/
bool ListInsert(SqList*  &list,int i, ElemType e)
{
	int j;
	if (i<1 || i>list->length + 1)
		return false; //参数错误fanhuifalse
	i--;//将逻辑位序转为数组位序
	for (j = list->length; j > i; j--)//将data[i...n]元素后移一个位置
		list->data[j] = list->data[j - 1];
	list->data[i] = e;
	list->length++;
	return true;
}
/*
* 功能 从顺序表中删除元素
* 函数名称：DeleteList
* 参数
* --list：链表指针类型
* --i:要删除的为位置
* --e：带回被删除的元素位置
* 返回类型 bool
*/
bool DeleteList(SqList*& list, int i, ElemType & e)
{
	if (i<1 || i>list->length)
		return false;
	i--;
	e = list->data[i];
	for (int j = i; j < list->length; j++)
		list->data[j] = list->data[j + 1];
	list->length--;
	return true;
}
/*
* Destorylist
* 参数 list :顺序表指针类型 引用方式传递参数
* 返回类型那为空
*/
void DestoryList(SqList*& list)
{
	free(list);
	list = NULL; // 避免

}





