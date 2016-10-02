#pragma once
#ifndef _FENGMIAN_H
#define _FENGMIAN_H

/*
*显示封面菜单的函数，隐藏了修改密码选项
*包含 显示当前时间函数Ptime() 定位屏幕字符输出位置函数gotoxy()
*使用后：返回各功能编号
*/
extern int fengmian(void);

void Ptime(void);
void gotoxy(int x, int y);
#endif // !_FENGMIAN_H
