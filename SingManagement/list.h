#pragma once
#ifndef _LIST_H
#define _LIST_H

/*
*�����������ӿ��ļ�
*����ο�����C Primer Plus(�����)��P495
*/
struct infotag
{
	int num;                        //���
	char name[12];                  //����
	char sex[12];                   //�Ա�
	char phoneNum[10];              //��ϵ��ʽ���绰���룩
	char score[10];                 //�ɼ�
	char totalScore[20];             //�ܷ�
	double averageScore[20];        //ƽ����
};

/*һ�����Ͷ���*/
typedef struct infotag Singer;//Item

typedef struct node
{
	Singer singer;
	struct node * next;
}Node;

typedef Node * List;

/*
*����ԭ��
*��������ʼ��һ���б�
*����ǰ��plistָ��һ���б�
*�����󣺸��б���ʼ��Ϊһ�����б�
*/
void initializeList(List * plist);

/*
*������ȷ���б��Ƿ�Ϊ���б�
*����ǰ��plistָ��һ���б�
*������������б�Ϊ���򷵻�true�����򷵻�false
*/
bool listIsEmpty(const List * plist);

/*
*������ȷ���б��Ƿ�����
*����ǰ��plistָ��һ���Գ�ʼ�����б�
*����������б������򷵻�true�����򷵻�false
*/
bool listIsFull(const List * plist);

/*
*������ȷ���б�����Ŀ�ĸ���
*����ǰ��plistָ��һ���ѳ�ʼ�����б�
*�����󣺷����б�����Ŀ�ĸ���
*/
unsigned int listItemCount(const List * plist);

/*
*���������б�δ���һ����Ŀ
*����ǰ��singer��Ҫ�����ӵ��б����Ŀ
*		plistָ��һ���ѳ�ʼ�����б�
*������������ܵĻ������б�ĩβ���һ������Ŀ����������true
*		���򷵻�false
*/
bool addItem(Singer singer, List * plist);

/*
*��������һ�������������б��е�ÿ����Ŀ
*����ǰ��plistָ��һ���ѳ�ʼ�����б�
		pfunָ��һ���������ú�������һ��Singer���������޷���ֵ
*������pfunָ��ĺ��������õ��б��е�ÿ����Ŀһ��
*/
void traverse(const List * plist, void(*pfun) (Singer singer));

/*�����죬�����롣��������������������
*�������������в�ѯ��Ӧ�����Ϣ
void searchTable(const List * plist, void(*pfun)(int num));
*/


/*
*�������ͷ��ѷ�����ڴ棨����У�
*����ǰ��plistָ��һ���ѳ�ʼ�����б�
*������Ϊ���б������ڴ����ͷŲ��Ҹ��б���Ϊ���б�
*/
void emptyTheList(List * plist);

#endif // !_LIST_H



