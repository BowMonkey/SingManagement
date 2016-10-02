
#include "head.h"

/*�ֲ�����ԭ��*/
static void copyToNode(Singer singer, Node * pnode);

/*
*�ӿں���
*���б�����Ϊ���б�
*/
void initializeList(List * plist)
{
	*plist = NULL;
}

/*����б�Ϊ���򷵻���*/
bool listIsEmpty(const List * plist)
{
	if (* plist == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*����б������򷵻���*/
bool listIsFull(const List * plist)
{
	Node * pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
	{
		full = true;
	}
	else
	{
		full = false;
	}
	free(pt);
	return full;
}

/*���ؽڵ���*/
unsigned int listItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;//���õ��б�Ŀ�ʼ��

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;//��1����Ϊ��һ���ڵ�
	}
	return count;
}

/*
*���������Ŀ�Ľڵ㣬��������ӵ�
*��plistָ����б�β��
*/
bool addItem(Singer singer, List * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		return false;//ʧ��ʱ�˳�����
	}

	copyToNode(singer, pnew);
	pnew->next = NULL;
	if (scan == NULL)//���б���˰�pnew�ŵ��б�ͷ��
	{
		*plist = pnew;
	}
	else
	{
		//�ҵ��б��β����pnew��ӵ���β��
		while (scan->next != NULL)
		{
			scan = scan->next;
		}
		scan->next = pnew;
	}
	return true;
}

/*����ÿ���ڵ㲢�����Ƿֱ�ִ����pfunָ��ĺ���*/
void traverse(const List * plist, void(*pfun) (Singer singer))
{
	Node * pnode = *plist;//���õ��б�Ŀ�ʼ��
	while (pnode != NULL)
	{
		(*pfun)(pnode->singer);//�Ѻ����������б��е���Ŀ
		pnode = pnode->next;//ǰ������һ��
	}
}

/*
*�ͷ���malloc()������ڴ�
*���б�ָ������ΪNULL
*/
void emptyTheList(List * plist)
{
	Node * psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next;//������һ�ڵ�ĵ�ַ
		free(*plist);//�ͷŵ�ǰ���
		*plist = psave;//ǰ������һ�ڵ�
	}
}

/*
*�ֲ���������
*��һ����Ŀ���Ƶ���һ���ڵ�
*/
static void copyToNode(Singer singer, Node * pnode)
{
	pnode->singer = singer;//�ṹ����
}