#include"CreatNumber.h"
int NonBlockingWaitSetClockReturnTure(DWORD start, unsigned int second) {
	double result = ((GetTickCount() - start) - (second * 1000)) / (double)(second * 1000);//�õ�ִ������0.980��0.998��1.002��2.005��3.020�ȣ���Ϊ�ж�������ȷ��������λС���������������Ϊ+-0.020���
	static int BoolReturnTrue = 1;//return 1���ش�������֤����һ����Χ��������ֻ����һ�ζ�����δ���
	//����result
	if (result < 0.8) return 0;
	int n = (int)(result * 1000);//������λС��������result*1000����תint
	int m = round(result);//��������result,�ó�result�м���1000
	unsigned short tolerance = abs(n - m * 1000);//����tolerance�ݴ����---��λǧ��֮һ
	if (tolerance < 10 && BoolReturnTrue) {//ǧ��֮10�ݴ�
		BoolReturnTrue = 0;//���ش���һ�κ�ر�
		return 1;
	} //toleranceΪǧ��֮20ʱ(��׼��5��10��15s����������һ����Χ)
	else if (tolerance >= 10) {
		BoolReturnTrue = 1;
		return 0;
	}
	else
	{
		return 0;
	}

}
//���ǰ���Ƿ�����ͬ����
int CheakEuqalFront(DatePoint p) {
	DatePoint temp = p;
	//�ظ�����
	//int singn=0;
	//����ǰ��
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
//�������Ƿ�����ͬ����
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
//��ʼ��ȫ����Ϊ0
void initNumber(DatePoint p) {
	DatePoint temp = p;

	for (int i = 0; i < 5; i++)
	{
		//ǰ���߼�
		temp->front_area[i] = 0;
		//�����߼�
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
//��ǰ��������������
void Sort(DatePoint p) {
	DatePoint temp = p;
	//ǰ�������߼�
	bubble_sort(temp->front_area,sizeof(temp->front_area)/ sizeof(temp->front_area)[0]);
	//���������߼�
	if (temp->back_area[0] > temp->back_area[1]) {

		unsigned short a = temp->back_area[0];
		temp->back_area[0] = temp->back_area[1];
		temp->back_area[1] = a;

	}
	

}
/*
* ����DatePoint pΪ�ṹ������ָ��
* ������������֣�������ʱ�������ӣ���Ϊѭ���ܿ죬���γ���һ���Ľ��
*/
void CreatNumber(DatePoint p) {
	//srand((unsigned)time(NULL));
	DatePoint temp = p;

	//��ʼ��ȫ����Ϊ0
	initNumber(temp);
	for (int i = 0; i <5; i++)
	{
		//ǰ���߼�
		temp->front_area[i]=rand()%35+1;
		//Sleep(1);
		//�����߼�
		if (i < 2) {
			temp->back_area[i] = rand() % 12 + 1;

		}
		

	}
	//���ǰ���ͺ����Ƿ����ظ�����
	if (CheakEuqalFront(temp) == 1 && 1 == CheakEuqalBack(temp)) {//�ݹ��������-û���ظ�����
		//�Ե�ǰ����������������ð������
		Sort(temp);
		return;//�ݹ����
	} 
	else
	{
		//�ݹ�ֱ���ҵ����ʵ�һ������͸����
		CreatNumber(temp);
	}
	
	
}