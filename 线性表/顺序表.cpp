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
	int n = sizeof(a) / sizeof(a[0]);//��ռ�ֽ���
	CreateList(mylist,a, n);
	displist(mylist);
	int length = ListLength(mylist);
	printf("length of list is %d\n",length);

	int value;
	GetElem(mylist, 3, value);
	printf("%d", value);

	value = LocateElem(mylist, 8);
	printf("\n8��˳����е��߼�λ��value=%d\n",value);

	ListInsert(mylist, 3, 12);
	displist(mylist);

	DeleteList(mylist,3,value);
	printf("\nvalue=%d\n", value);
	displist(mylist);

	DestoryList(mylist);
	return 0;

}
/*��ʼ��˳���Ϊͷ��������ڴ�ռ�
�������� InitList ���� list��˳���ָ�����ͣ�
���÷�ʽ���ݲ���
�������� void
*/
void InitList(SqList* &list)  //list�����洢����Sqlist�ĵ�ַ������Sqlist�������Ϣ
{
	list = (SqList*)malloc(sizeof(SqList));
	list->length = 0;
}
/*list ˳���ָ������,���÷�ʽ���ݲ���
---a:�����׵�ַ
---n����Ԫ�صĸ���
�������� void */
void CreateList(SqList* &list, ElemType a[], int n)//&list ��ı�
{
	int i;
	for (i = 0; i < n && i < Maxsize; i++) //���ܳ���n��maxsize��
		list->data[i] = a[i];
	list->length = i;//���n<maxsize  i����n �������n>maxsize i���� maxsize

}
/*˳����п�
�������� ListEmpty
���� ��--list:˳���ָ������
�������� bool
*/
bool ListEmpty(SqList* list)
{
	return(list->length == 0);
}
/*
��ʾ�����е�Ԫ�ص�ֵ
�������� displist
������ --list��˫����ָ������
�������� void
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
/*����:����������Ԫ�صĸ���
* �������ƣ�ListLength 
* ���� list��˳����ָ������
* �������� int
*/
int ListLength(SqList* list)
{
	return (list->length);
}
/*���ܻ�ȡ���Ա��е�i��Ԫ�ص�ֵ
* GetElem
* ���� list��˳���ָ������
* --iҪ���а�Ԫ�ص�λ��
* e:ElemType���� �������m��������
*/
bool GetElem(SqList* list, int i, ElemType & e)
{
	if (i<1 || i>list->length)return false;
		e = list->data[i - 1];
	return true;
}
/*���ܣ������Ա��в���Ԫ��e
* ��������LocateElem
* ������
* list������ָ������
* e:ElemTypeҪ���ҵ�����
* �������� int��ʾ���ݵ��߼�λ��
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
* ��˳����еĲ����i��λ�����Ԫ��e
* �������� InsertList
* ���� list������ָ������ ����������
* i Ҫ�����λ��
* e Ҫ����Ԫ�ص�λ��
* �������� BOOL
*/
bool ListInsert(SqList*  &list,int i, ElemType e)
{
	int j;
	if (i<1 || i>list->length + 1)
		return false; //��������fanhuifalse
	i--;//���߼�λ��תΪ����λ��
	for (j = list->length; j > i; j--)//��data[i...n]Ԫ�غ���һ��λ��
		list->data[j] = list->data[j - 1];
	list->data[i] = e;
	list->length++;
	return true;
}
/*
* ���� ��˳�����ɾ��Ԫ��
* �������ƣ�DeleteList
* ����
* --list������ָ������
* --i:Ҫɾ����Ϊλ��
* --e�����ر�ɾ����Ԫ��λ��
* �������� bool
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
* ���� list :˳���ָ������ ���÷�ʽ���ݲ���
* ����������Ϊ��
*/
void DestoryList(SqList*& list)
{
	free(list);
	list = NULL; // ����

}





