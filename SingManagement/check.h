#pragma once
#ifndef _CHECK_H
#define _CHECK_H

#include"head.h"


/*
*身份验证功能函数，在addInfo() inputGrade()  writeDoc()  inquireGrade()函数开头使用
*验证失败返回false，成功返回true
*/
extern int check(void);
#endif