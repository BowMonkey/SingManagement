#pragma once
#ifndef _PASSWORD_H
#define _PASSWORD_H

#include"head.h"

/*
*管理员密码函数
*第一次使用密码预置为123456
*修改密码需要验证当前密码
*/
extern void password();

/*
*修改密码功能函数
*/
extern void changeWord();


#endif