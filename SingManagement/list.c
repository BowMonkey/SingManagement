
#include "head.h"

/*局部函数原型*/
static void copyToNode(Singer singer, Node * pnode);

/*
*接口函数
*把列表设置为空列表
*/
void initializeList(List * plist)
{
	*plist = NULL;
}

/*如果列表为空则返回真*/
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

/*如果列表已满则返回真*/
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

/*返回节点数*/
unsigned int listItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;//设置到列表的开始处

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;//把1设置为下一个节点
	}
	return count;
}

/*
*创建存放项目的节点，并把它添加到
*由plist指向的列表尾部
*/
bool addItem(Singer singer, List * plist)
{
	Node * pnew;
	Node * scan = *plist;

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		return false;//失败时退出函数
	}

	copyToNode(singer, pnew);
	pnew->next = NULL;
	if (scan == NULL)//空列表因此把pnew放到列表头部
	{
		*plist = pnew;
	}
	else
	{
		//找到列表结尾，把pnew添加到结尾处
		while (scan->next != NULL)
		{
			scan = scan->next;
		}
		scan->next = pnew;
	}
	return true;
}

/*访问每个节点并对他们分别执行由pfun指向的函数*/
void traverse(const List * plist, void(*pfun) (Singer singer))
{
	Node * pnode = *plist;//设置到列表的开始处
	while (pnode != NULL)
	{
		(*pfun)(pnode->singer);//把函数作用于列表中的项目
		pnode = pnode->next;//前进到下一项
	}
}

/*
*释放由malloc()分配的内存
*把列表指针设置为NULL
*/
void emptyTheList(List * plist)
{
	Node * psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next;//保存下一节点的地址
		free(*plist);//释放当前结点
		*plist = psave;//前进到下一节点
	}
}

/*
*局部函数定义
*把一个项目复制到下一个节点
*/
static void copyToNode(Singer singer, Node * pnode)
{
	pnode->singer = singer;//结构复制
}