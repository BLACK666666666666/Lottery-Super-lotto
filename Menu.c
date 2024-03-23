#include"Menu.h"
#include"OperateList.h"
#include"KeyEvent.h"
//�����ն�
void SetSize(unsigned uCol, unsigned uLine) {
	char cmd[64];
	fflush(stdout); // ˢ�������������ȷ����ʾ��Ϣ������ʾ,�ù����ʾ��scanf��
	sprintf(cmd, "mode con cols=%d lines=%d", uCol, uLine);
	fflush(stdout); // ˢ�������������ȷ����ʾ��Ϣ������ʾ,�ù����ʾ��scanf��
	system(cmd);
	fflush(stdout); // ˢ�������������ȷ����ʾ��Ϣ������ʾ,�ù����ʾ��scanf��
}
//ָ�����λ�ã����ַ�Ϊ��λ
void SetPos(int x, int y) {
	COORD point = { x, y };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, point);
}
//����������ɫ
/*color(0);  printf("��ɫ\n");
	color(1);  printf("��ɫ\n");
	color(2);  printf("��ɫ\n");
	color(3);  printf("����ɫ\n");
	color(4);  printf("��ɫ\n");
	color(5);  printf("��ɫ\n");
	color(6);  printf("��ɫ\n");
	color(7);  printf("��ɫ\n");
	color(8);  printf("��ɫ\n");
	color(9);  printf("����ɫ\n");
	color(10); printf("����ɫ\n");
	color(11); printf("��ǳ��ɫ\n");
	color(12); printf("����ɫ\n");
	color(13); printf("����ɫ\n");
	color(14); printf("����ɫ\n");
	color(15); printf("����ɫ\n");*/
void Color(short x) {
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Ĭ�ϰ�ɫ
}
//���ļ��ַ���
int ReadLine(char* path,int color) {
	Color(color);
	FILE* fp;
	int line_num = 0; // �ļ�����
	char buf[LINE_MAX] = { 0 }; // �����ݻ���

	fp = fopen(path, "r");
	if (NULL == fp) {
		printf("open %s failed.\n", path);
		return -1;
	}

	while (fgets(buf, LINE_MAX, fp)) {
		line_num++;
		int line_len = strlen(buf);
		// �ų����з�
		if ('\n' == buf[line_len - 1]) {
			buf[line_len - 1] = '\0';
		}
		// �ų��س����������Windows�ı���
		if ('\r' == buf[line_len - 1]) {
			buf[line_len - 1] = '\0';
		}
		//Color(rand()%16);
		printf("%s\n", buf); // ��ӡÿһ��
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
//��ӭ���������welcome������ɫ
void Welcome(int color) {//������ӭ��
	ReadLine("menu.txt", color);

}
//ѡ�������ѡ���ɫ
void MainMenu(int color) {//ѡ��˵�
	//printf("\n\n\n\n\n\n\n\n\n\n");
	Color(color);
	fflush(stdout); // ˢ�������������ȷ����ʾ��Ϣ������ʾ,�ù����ʾ��scanf��
	printf("\n\n\n***********************************\n              ѡ�\n*---------------^^^---------------*\nѡ��1:   ���ɴ���͸��������\n");
	//fflush(stdout);
	printf("*---------------^^^---------------*\nѡ��2:         exit");
	//fflush(stdout);
	printf("\n***********************************\n������ѡ��:");
	
}
//����1����ѭ������-1����ѭ��
int Choice() {
	int ChoiceNumber=0;
	fflush(stdout); // ˢ�������������ȷ����ʾ��Ϣ������ʾ,�ù����ʾ��scanf��
	fflush(stdin);//ˢ�¼��̻�����
	//scanf���ܳɹ�ʧ�ܣ���Ҫˢ�����뻺����
	if (!scanf("%d", &ChoiceNumber)) {//������ݸ�ʽ�Ƿ���int
		scanf("%*s");//ˢ�¼��̻�����
		printf("Unknown Erro!\n");
		return 1;} 

	switch (ChoiceNumber)
	{
		
	case 1:
	{	//scanf("%*s");//ˢ�¼��̻�����
		int Number = 0;
		printf("������Ҫ���ɵĴ���͸��������");
		fflush(stdout); // ˢ�������������ȷ����ʾ��Ϣ������ʾ,�ù����ʾ��scanf��
		

		//scanf����1�ɹ����룬����0����ʧ��,���ܳɹ�ʧ�ܣ���Ҫˢ�����뻺�������ɹ�������ˢ�»�����
		if (!scanf("%d", &Number)) {//������ݸ�ʽ�Ƿ���int
			scanf("%*s");//ˢ�¼��̻�����
			printf("Unknown Erro!\n");
			return 1;//����ʧ�ܼ���ѭ��
		}
	
		//���Number
		if(Number<1) printf("����С��1!");
		//if (!isdigit(Number)) Number = -8;//��isdigit(Number)��������ʱִ��
		


		//����
		DatePoint p = CreatNumberList(Number);//����ͷ�ڵ�,Number���淶(С��1)����NULL
		//scanf("%*s");//ˢ�¼��̻�����
		if (p == NULL) return 1;//�������淶��ʾ�����ѭ��
		PrintNumberList(p,10);
		//�ͷ������ڴ�
		FreeList(p);
		p = NULL;

		return 1;//����ѭ��
	}
	
		
	case 2:
		
		return 0;//�˳�ѭ��


	default://��������
		
		printf("Unknown Erro!\n");
		return 1;//����ѭ��
	}

}