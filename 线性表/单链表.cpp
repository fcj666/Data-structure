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
	//InitList(myList);   //��ʼ�����Ա�
    //CreateListHead(myList,a,n);  //ͷ�巨
	CreateListTail(myList,a,n);
	dispList(myList);
	int len;
	len = LengthList(myList);
	printf("���Ա�ĳ���Ϊlen = %d\n", len);
	ElemType  resdata;
	GetElem(myList, 2, resdata);
	printf("ĳ��Ԫ�ص�ֵΪ = %d\n", resdata);
	int loc;
	loc = LocateElem(myList, 8);
	printf("8 �����Ա����߼����loc=%d\n", loc);

	ListInsert(myList,3,4);
	dispList(myList);

	ElemType x;
	ListDelete(myList,3, x);
	printf("�h��x=%d\n", x);
	dispList(myList);  

	DestoryList(myList);
	return 0;
}
/*
*  ����:��ʼ�������� ��Ϊͷ��������ڴ�ռ�
* �������ƣ�InitList
* ������;
* --list :������ ָ�����ͣ����÷�ʽ���ݲ���
* �������� ��void
*/
void InitList(LinkNode*& list)
{
	list = (LinkNode*)malloc(sizeof(LinkNode));
	list->next = NULL;
}

/*
* ��������ͷ�巨������Ԫ�ش���������
* ��������CreateListHead
* ����:
* ---list :������ָ������,���÷�ʽ���ݲ���
* a:�����׵�ַ
* n������Ԫ�صĸ���
* �������� void 
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
*   ���ܣ�Ӧ��β�巨��������Ԫ�ش���������
* �������� CreateListTail;
* ������
* list : ������ָ�����ͣ����÷�ʽ���ݲ���
* ----a:�����׵�ַ
* n:����Ԫ�صĸ���
* �������� void
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
* ������Ա�
* �������� dispList
* ����
* list��˫����ָ������
* �������ͣ�void
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
* ���ܣ��ж����Ա��Ƿ�Ϊ��
* �������� ListEmpty
* ���� 
* list  �� ������ָ������
* �������� bool
*/
bool ListEmpty(LinkNode* list)
{
	return (list->next == NULL);

}
/*
* �������Ա�ĳ���
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
* �������Ա�
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
* �����Ա���ĳ��Ԫ�ص�����Ԫ��ֵ
*
*/

bool GetElem(LinkNode* list, int i, ElemType& e)
{
	int j = 0;
	if (i < 1) return false;
	LinkNode * p = list; //pָ��ͷ��㣬J��Ϊ0
	while (j < i && p != NULL)//(ͷ�������Ϊ0)
	{
		j++;
		p=p->next;//��pָ����һ��Ԫ��
	}
	if (p == NULL)  //�����ڵ�i����� ����false
		return false;
	else   //���ڵ�i����㷵�� true
	{
		e = p->data;
		return true;
	}
}
/*
* ����Ԫ��ֵ����
* ��ʼ�������� i =0��
* ����ָ����� P,��ʼ��Ϊlist -> next;
* �� p�����ڿ� ��p->data������e ʱ�ͱ���������pָ������ƶ���ָ����һ������ۼ�+1
* �ж��Ƿ���ҳɹ������p���ڿգ���û���ҵ�����e������0�����򷵻�i+1
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
* ���������
* ˼· 1.��ʼ��  K=1;
* 2.����ָ����� P ,��ʼ��Ϊ list->next;
* 3����λҪ�����ǰһ��λ�� i-1��
* �� ��< i-1��p�ĺ�̽��ǿ�ʱ�ͱ�������  �� k+1  
* p����ƶ�
* 4.����λ�ú󣬹����½��S��������ֵX
* 5.��S���뵽p֮��
* s->next - p->next;
* p->next = s;
*/
bool ListInsert(LinkNode *& list, int i, ElemType e)  //�ı�����&
{
	if (i < 1) return false;
	LinkNode* m,*p;  //pָ���һ�����ݽ��
	//s����ָ��Ҫ��������ݽ��   p����ɨ�赥����
	//ȷ��Ҫ����λ�õ�ǰһ��λ��
	p = list->next;
	int k = 1;
	while (p != NULL && k < i - 1)//k����Ҫ������ĺ�һλ��
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
/*sɾ���ڵ��ʵ��
* ֻ���޸���ؽ���ָ���򣬲���Ҫ�ƶ����
*1�� ��ʼ��λ��  K =1
* 2������ڵ�ָ�� p��ʼ��Ϊ list->next
* 3����λ��Ҫɾ����Ԫ��ǰһ��λ��i-1��
* �� k < i-1��p�ĺ�̽��ǿ��� �ͱ����������� k+1
* p ָ������ƶ�
* 4������λ��֮����sָ��Ҫɾ���Ľ�� ,s������ֵ��e
* 5��ɾ������
* 
*/
bool ListDelete(LinkNode*& list, int i, ElemType& e)

{
	if (i < 1) return false;
	int k = 1;
	LinkNode * s,* p;
	p = list->next;
	//ȷ��Ҫɾ����λ��
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
