#pragma once
typedef struct date {
	unsigned short front_area[5];//1-35
	unsigned short back_area[2];//1-12
	struct date* next;//struct date指针域，这里typedef定义取别名时，千万不可以用DatePoint next或者Date*next，因为还未定义就使用，编译不通过

}Date, * DatePoint;/*
typedef struct Date a; //这里Date就相当于struct date，是一种自定义数据的类型（类似int short）
typedef struct date * DatePoint; //这里DatePoint就相当于struct date*,是一种自定义数据的指针类型（类似int short）
*/
