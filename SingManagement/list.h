#pragma once
#ifndef _LIST_H
#define _LIST_H

/*
*创建链表和其接口文件
*程序参考：《C Primer Plus(第五版)》P495
*/
struct infotag
{
	int num;                        //编号
	char name[12];                  //姓名
	char sex[12];                   //性别
	char phoneNum[10];              //联系方式（电话号码）
	char score[10];                 //成绩
	char totalScore[20];             //总分
	double averageScore[20];        //平均分
};

/*一般类型定义*/
typedef struct infotag Singer;//Item

typedef struct node
{
	Singer singer;
	struct node * next;
}Node;

typedef Node * List;

/*
*函数原型
*操作：初始化一个列表
*操作前：plist指向一个列表
*操作后：该列表被初始化为一个空列表
*/
void initializeList(List * plist);

/*
*操作：确定列表是否为空列表
*操作前：plist指向一个列表
*操作后：如果该列表为空则返回true，否则返回false
*/
bool listIsEmpty(const List * plist);

/*
*操作：确定列表是否已满
*操作前：plist指向一个以初始化的列表
*操作后：如果列表已满则返回true，否则返回false
*/
bool listIsFull(const List * plist);

/*
*操作：确定列表中项目的个数
*操作前：plist指向一个已初始化的列表
*操作后：返回列表中项目的个数
*/
unsigned int listItemCount(const List * plist);

/*
*操作：在列表未添加一个项目
*操作前：singer是要被增加到列表的项目
*		plist指向一个已初始化的列表
*操作后：如果可能的话，在列表末尾添加一个新项目，函数返回true
*		否则返回false
*/
bool addItem(Singer singer, List * plist);

/*
*操作：把一个函数作用于列表中的每个项目
*操作前：plist指向一个已初始化的列表
		pfun指向一个函数，该函数接受一个Singer参数并且无返回值
*操作后：pfun指向的函数被作用到列表中的每个项目一次
*/
void traverse(const List * plist, void(*pfun) (Singer singer));

/*不成熟，在想想。。。。。。。。。。。
*操作：从链表中查询相应编号信息
void searchTable(const List * plist, void(*pfun)(int num));
*/


/*
*操作：释放已分配的内存（如果有）
*操作前：plist指向一个已初始化的列表
*操作后：为该列表分配的内存已释放并且该列表被置为空列表
*/
void emptyTheList(List * plist);

#endif // !_LIST_H



