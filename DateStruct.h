#pragma once
typedef struct date {
	unsigned short front_area[5];//1-35
	unsigned short back_area[2];//1-12
	struct date* next;//struct dateָ��������typedef����ȡ����ʱ��ǧ�򲻿�����DatePoint next����Date*next����Ϊ��δ�����ʹ�ã����벻ͨ��

}Date, * DatePoint;/*
typedef struct Date a; //����Date���൱��struct date����һ���Զ������ݵ����ͣ�����int short��
typedef struct date * DatePoint; //����DatePoint���൱��struct date*,��һ���Զ������ݵ�ָ�����ͣ�����int short��
*/
