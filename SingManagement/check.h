#pragma once
#ifndef _CHEEK_H
#define _CHEEK_H

#include"head.h"


/*
*身份验证功能函数，在addInfo() inputGrade()  writeDoc()  inquireGrade()函数开头使用
*验证失败返回0，成功返回1
*/
extern int cheek(void);
#endif