#include <stdio.h>
#include <stdlib.h>
#include"OperateList.h"
#include"CreatNumber.h"
#include"Menu.h"
#include"KeyEvent.h"
int main(int argc, char* argv[])//.exe运行参数
{
	if (argc == 1) {//默认无参启动模式
		//设置终端放缩合适大小
		//SetSize(500,500);
		int TrueFalse = 1;
		fflush(stdout);
		Welcome(1);
		//主线程以系统时钟播种一次
		srand(GetTickCount() % 4294967294);
		DWORD start=GetTickCount();
		while (TrueFalse)
		{
			//fflush(stdout);
			//主线程非阻塞每5s定时重新播种一次
			if (NonBlockingWaitSetClockReturnTure(start, 5)) {
				srand(GetTickCount() % 4294967294);
			}
			
			MainMenu(3);
			TrueFalse = Choice();
			fflush(stdout);
		}

	}
	else if (argc == 2) {//有一个字符串参数
		
		
		//主线程播种一次
		srand(GetTickCount() % 4294967294);

		//string to int
		int number=atol(argv[1]);
		//检查Number
		if (number < 1) printf("组数小于1!");
		else
		{
			printf("Number数----------%d", number);
		}
		DWORD start = GetTickCount();
		//生成
		DatePoint p = CreatNumberList(number);//返回头节点
		if (p == NULL) return 1;//参数不规范提示后继续循环
		//printf("%d---%d", p->next->back_area[0], p->next->back_area[1]);
		PrintNumberList(p, 10);
		//释放链表内存
		FreeList(p);
		p = NULL;
		DWORD end = GetTickCount();
		printf("----耗费时间---%.2lf s", (double)(end - start) / 1000);
		return 2;
	}
	else
	{
		printf("exe 参数错误！\n");
		return -1;
	}


	system("pause");
	return 1;
}

