#include <stdio.h>
#include <stdlib.h>
#include"OperateList.h"

//创建大乐透号码链表的函数
//参数NodeNumber应该>=1
DatePoint CreatNumberList(int NodeNumber) {
    if (NodeNumber < 1) {
        printf("Erro----------参数不符合规范\n");
        return NULL;
    } 
    DatePoint p = (DatePoint)malloc(sizeof(Date));//创建一个头结点
    if (p == NULL) {

        printf("头节点分配失败\n");
        return NULL;
    }
    DatePoint temp = p;//声明一个指针指向头结点，用于遍历链表

    //生成链表
    for (int i = 0; i < NodeNumber; i++) {
        //创建节点并初始化
        DatePoint a = (DatePoint)malloc(sizeof(Date));
        //创建大乐透号码
       // srand((unsigned)time(NULL));//时间做种子
        //RAND_MAX的最小值是32767（对于整数类型），如果使用unsigned int，则为65535（双字节）或4294967295（四字节）的整数范围
        //srand(i);//_32---------4294967295/_64-------------18,446,744,073,709,551,615
        CreatNumber(a); 
        a->next = NULL;
        //建立新节点与直接前驱节点的逻辑关系
        temp->next = a;
        temp = temp->next;
    }
    //printf("%d---%d", p->next->back_area[0], p->next->back_area[1]);
    return p;
}

//参数p为原链表头指针，遍历并且打印大乐透号码链表
int PrintNumberList(DatePoint p,int color) {
    //新建一个指针t，初始化为头指针 p
    DatePoint t = p;
    int i = 1;
    //设置字体颜色
    Color(color);
    system("cls");
    //由于头节点的存在，因此while中的判断为t->next，遍历链表直到NULL
    while (t->next) {
        t = t->next;
        //打印
        printf("%-2d组------前区:%-2d %-2d %-2d %-2d %-2d   后区:%-2d %-2d\n",
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
    //程序执行至此处，表示遍历失败，只有头节点
    return -1;
}

//释放链表内存
void FreeList(DatePoint p) {
    DatePoint freenode = p;
    while (p->next != NULL) {

        p = p->next;
        free(freenode);
        freenode = p;
        
    }

    //执行完成，freenode与p都指向最后一个节点
    free(freenode);//释放最后一个节点


}
 void test(Date a) {
	for (int i = 0; i < 7; i++) {
		printf("%d ", a.front_area[i]);
	}
	
	printf("\nnext指针--------%d\n", a.next);
}