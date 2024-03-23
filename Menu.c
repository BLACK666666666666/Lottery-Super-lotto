#include"Menu.h"
#include"OperateList.h"
#include"KeyEvent.h"
//放缩终端
void SetSize(unsigned uCol, unsigned uLine) {
	char cmd[64];
	fflush(stdout); // 刷新输出缓冲区，确保提示信息立即显示,让光标显示在scanf旁
	sprintf(cmd, "mode con cols=%d lines=%d", uCol, uLine);
	fflush(stdout); // 刷新输出缓冲区，确保提示信息立即显示,让光标显示在scanf旁
	system(cmd);
	fflush(stdout); // 刷新输出缓冲区，确保提示信息立即显示,让光标显示在scanf旁
}
//指定光标位置，以字符为单位
void SetPos(int x, int y) {
	COORD point = { x, y };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, point);
}
//设置字体颜色
/*color(0);  printf("黑色\n");
	color(1);  printf("蓝色\n");
	color(2);  printf("绿色\n");
	color(3);  printf("湖蓝色\n");
	color(4);  printf("红色\n");
	color(5);  printf("紫色\n");
	color(6);  printf("黄色\n");
	color(7);  printf("白色\n");
	color(8);  printf("灰色\n");
	color(9);  printf("淡蓝色\n");
	color(10); printf("淡绿色\n");
	color(11); printf("淡浅绿色\n");
	color(12); printf("淡红色\n");
	color(13); printf("淡紫色\n");
	color(14); printf("淡黄色\n");
	color(15); printf("亮白色\n");*/
void Color(short x) {
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 默认白色
}
//读文件字符画
int ReadLine(char* path,int color) {
	Color(color);
	FILE* fp;
	int line_num = 0; // 文件行数
	char buf[LINE_MAX] = { 0 }; // 行数据缓存

	fp = fopen(path, "r");
	if (NULL == fp) {
		printf("open %s failed.\n", path);
		return -1;
	}

	while (fgets(buf, LINE_MAX, fp)) {
		line_num++;
		int line_len = strlen(buf);
		// 排除换行符
		if ('\n' == buf[line_len - 1]) {
			buf[line_len - 1] = '\0';
		}
		// 排除回车符（如果是Windows文本）
		if ('\r' == buf[line_len - 1]) {
			buf[line_len - 1] = '\0';
		}
		//Color(rand()%16);
		printf("%s\n", buf); // 打印每一行
		fflush(stdout);
	}

	if (!feof(fp)) {
		printf("fgets error\n");
		fclose(fp);
		return -1;
	}

	fclose(fp);
	return line_num;
}
//欢迎界面参数是welcome字体颜色
void Welcome(int color) {//进来欢迎语
	ReadLine("menu.txt", color);

}
//选项卡参数是选项卡颜色
void MainMenu(int color) {//选择菜单
	//printf("\n\n\n\n\n\n\n\n\n\n");
	Color(color);
	fflush(stdout); // 刷新输出缓冲区，确保提示信息立即显示,让光标显示在scanf旁
	printf("\n\n\n***********************************\n              选项卡\n*---------------^^^---------------*\n选项1:   生成大乐透开奖号码\n");
	//fflush(stdout);
	printf("*---------------^^^---------------*\n选项2:         exit");
	//fflush(stdout);
	printf("\n***********************************\n请输入选项:");
	
}
//返回1继续循环或者-1结束循环
int Choice() {
	int ChoiceNumber=0;
	fflush(stdout); // 刷新输出缓冲区，确保提示信息立即显示,让光标显示在scanf旁
	fflush(stdin);//刷新键盘缓存区
	//scanf不管成功失败，都要刷新输入缓冲区
	if (!scanf("%d", &ChoiceNumber)) {//检查数据格式是否是int
		scanf("%*s");//刷新键盘缓存区
		printf("Unknown Erro!\n");
		return 1;} 

	switch (ChoiceNumber)
	{
		
	case 1:
	{	//scanf("%*s");//刷新键盘缓存区
		int Number = 0;
		printf("请输入要生成的大乐透号码组数");
		fflush(stdout); // 刷新输出缓冲区，确保提示信息立即显示,让光标显示在scanf旁
		

		//scanf返回1成功输入，返回0输入失败,不管成功失败，都要刷新输入缓冲区，成功在用完刷新缓存区
		if (!scanf("%d", &Number)) {//检查数据格式是否是int
			scanf("%*s");//刷新键盘缓存区
			printf("Unknown Erro!\n");
			return 1;//输入失败继续循环
		}
	
		//检查Number
		if(Number<1) printf("组数小于1!");
		//if (!isdigit(Number)) Number = -8;//当isdigit(Number)不是数字时执行
		


		//生成
		DatePoint p = CreatNumberList(Number);//返回头节点,Number不规范(小于1)返回NULL
		//scanf("%*s");//刷新键盘缓存区
		if (p == NULL) return 1;//参数不规范提示后继续循环
		PrintNumberList(p,10);
		//释放链表内存
		FreeList(p);
		p = NULL;

		return 1;//继续循环
	}
	
		
	case 2:
		
		return 0;//退出循环


	default://发生错误
		
		printf("Unknown Erro!\n");
		return 1;//继续循环
	}

}