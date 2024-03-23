#include"CreatNumber.h"
int NonBlockingWaitSetClockReturnTure(DWORD start, unsigned int second) {
	double result = ((GetTickCount() - start) - (second * 1000)) / (double)(second * 1000);//得到执行条件0.980，0.998，1.002，2.005，3.020等，因为有抖动所以确定保留三位小数，最大暂且设置为+-0.020误差
	static int BoolReturnTrue = 1;//return 1开关触发，保证满足一定范围的条件后只触发一次而不多次触发
	//处理result
	if (result < 0.8) return 0;
	int n = (int)(result * 1000);//保留三位小数方法，result*1000倍后转int
	int m = round(result);//四舍五入result,得出result有几个1000
	unsigned short tolerance = abs(n - m * 1000);//计算tolerance容错误差---单位千分之一
	if (tolerance < 10 && BoolReturnTrue) {//千分之10容错
		BoolReturnTrue = 0;//开关触发一次后关闭
		return 1;
	} //tolerance为千分之20时(与准点5，10，15s的误差，控制在一定范围)
	else if (tolerance >= 10) {
		BoolReturnTrue = 1;
		return 0;
	}
	else
	{
		return 0;
	}

}
//检查前区是否有相同的数
int CheakEuqalFront(DatePoint p) {
	DatePoint temp = p;
	//重复计数
	//int singn=0;
	//遍历前区
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {

			if (i == j) continue;
			if (temp->front_area[i] == temp->front_area[j]) {
				//singn = singn + 1;
				return -1;
			}
		}

	return 1;

	
}
//检查后区是否有相同的数
int CheakEuqalBack(DatePoint p) {
	DatePoint temp = p;
	if (temp->back_area[0] == temp->back_area[1]) {
		//singn = singn + 1;
		return -1;
	}
	else
	{
		return 1;
	}

}
//初始化全部置为0
void initNumber(DatePoint p) {
	DatePoint temp = p;

	for (int i = 0; i < 5; i++)
	{
		//前区逻辑
		temp->front_area[i] = 0;
		//后区逻辑
		if (i < 2) {
			temp->back_area[i] =0;

		}


	}


}
void bubble_sort(unsigned short arr[], int len) {
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
//对前区后区进行排序
void Sort(DatePoint p) {
	DatePoint temp = p;
	//前区排序逻辑
	bubble_sort(temp->front_area,sizeof(temp->front_area)/ sizeof(temp->front_area)[0]);
	//后区排序逻辑
	if (temp->back_area[0] > temp->back_area[1]) {

		unsigned short a = temp->back_area[0];
		temp->back_area[0] = temp->back_area[1];
		temp->back_area[1] = a;

	}
	

}
/*
* 参数DatePoint p为结构体链表指针
* 随机数生成数字，不可用时间做种子，因为循环很快，会多次出现一样的结果
*/
void CreatNumber(DatePoint p) {
	//srand((unsigned)time(NULL));
	DatePoint temp = p;

	//初始化全部置为0
	initNumber(temp);
	for (int i = 0; i <5; i++)
	{
		//前区逻辑
		temp->front_area[i]=rand()%35+1;
		//Sleep(1);
		//后区逻辑
		if (i < 2) {
			temp->back_area[i] = rand() % 12 + 1;

		}
		

	}
	//检查前区和后区是否有重复数字
	if (CheakEuqalFront(temp) == 1 && 1 == CheakEuqalBack(temp)) {//递归出口条件-没有重复数字
		//对当前号码符合条件后进行冒泡排序
		Sort(temp);
		return;//递归出口
	} 
	else
	{
		//递归直到找到合适的一串大乐透号码
		CreatNumber(temp);
	}
	
	
}