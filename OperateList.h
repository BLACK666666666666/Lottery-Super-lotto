#pragma once
#include"DateStruct.h"
#include"CreatNumber.h"
#include"windows.h"
DatePoint CreatNumberList(int NodeNumber);
int PrintNumberList(DatePoint p,int color);
//ÊÍ·ÅÁ´±íÄÚ´æ
void FreeList(DatePoint p);
void test(Date a);