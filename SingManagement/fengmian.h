#pragma once
#ifndef _FENGMIAN_H
#define _FENGMIAN_H

#include"head.h"

/*
*��ʾ����˵��ĺ������������޸�����ѡ��
*���� ��ʾ��ǰʱ�亯��Ptime() ��λ��Ļ�ַ����λ�ú���gotoxy()
*ʹ�ú󣺷��ظ����ܱ��
*/
extern int fengmian(void);

/*
*��ʾ��ǰʱ��ĺ���
*/
extern void Ptime(void);

/*
*�ƶ���굽ָ��λ��
*/
void gotoxy(int x, int y);
#endif // !_FENGMIAN_H
