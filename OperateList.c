#include <stdio.h>
#include <stdlib.h>
#include"OperateList.h"

//��������͸��������ĺ���
//����NodeNumberӦ��>=1
DatePoint CreatNumberList(int NodeNumber) {
    if (NodeNumber < 1) {
        printf("Erro----------���������Ϲ淶\n");
        return NULL;
    } 
    DatePoint p = (DatePoint)malloc(sizeof(Date));//����һ��ͷ���
    if (p == NULL) {

        printf("ͷ�ڵ����ʧ��\n");
        return NULL;
    }
    DatePoint temp = p;//����һ��ָ��ָ��ͷ��㣬���ڱ�������

    //��������
    for (int i = 0; i < NodeNumber; i++) {
        //�����ڵ㲢��ʼ��
        DatePoint a = (DatePoint)malloc(sizeof(Date));
        //��������͸����
       // srand((unsigned)time(NULL));//ʱ��������
        //RAND_MAX����Сֵ��32767�������������ͣ������ʹ��unsigned int����Ϊ65535��˫�ֽڣ���4294967295�����ֽڣ���������Χ
        //srand(i);//_32---------4294967295/_64-------------18,446,744,073,709,551,615
        CreatNumber(a); 
        a->next = NULL;
        //�����½ڵ���ֱ��ǰ���ڵ���߼���ϵ
        temp->next = a;
        temp = temp->next;
    }
    //printf("%d---%d", p->next->back_area[0], p->next->back_area[1]);
    return p;
}

//����pΪԭ����ͷָ�룬�������Ҵ�ӡ����͸��������
int PrintNumberList(DatePoint p,int color) {
    //�½�һ��ָ��t����ʼ��Ϊͷָ�� p
    DatePoint t = p;
    int i = 1;
    //����������ɫ
    Color(color);
    system("cls");
    //����ͷ�ڵ�Ĵ��ڣ����while�е��ж�Ϊt->next����������ֱ��NULL
    while (t->next) {
        t = t->next;
        //��ӡ
        printf("%-2d��------ǰ��:%-2d %-2d %-2d %-2d %-2d   ����:%-2d %-2d\n",
            i,
            t->front_area[0],
            t->front_area[1],
            t->front_area[2],
            t->front_area[3],
            t->front_area[4],
            t->back_area[0],
            t->back_area[1]
        );
       

        i++;
    }
    //����ִ�����˴�����ʾ����ʧ�ܣ�ֻ��ͷ�ڵ�
    return -1;
}

//�ͷ������ڴ�
void FreeList(DatePoint p) {
    DatePoint freenode = p;
    while (p->next != NULL) {

        p = p->next;
        free(freenode);
        freenode = p;
        
    }

    //ִ����ɣ�freenode��p��ָ�����һ���ڵ�
    free(freenode);//�ͷ����һ���ڵ�


}
 void test(Date a) {
	for (int i = 0; i < 7; i++) {
		printf("%d ", a.front_area[i]);
	}
	
	printf("\nnextָ��--------%d\n", a.next);
}