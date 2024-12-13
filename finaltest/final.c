#include <stdio.h>

typedef struct Student
{
	char name[12];
	float korean;
	float english;
	float math;
	double avg;
} Student; //person �ڷ������� data������ ������

Student data;

int read_dat() {
	FILE *p_file = open("students.bat", "rb");
	fread(&data, sizeof(Student),1,p_file);
	fclose(p_file);

}

int write_student() {
	printf("�̸���?:\n");
	scanf_s("%s", &data.name,sizeof(data.name));
	printf("���� ������?\n");
	scanf_s("%lf", &data.korean);
	printf("���� ������?:\n");
	scanf_s("%lf", &data.english);
	printf("���� ������?:\n");
	scanf_s("%lf", &data.math);



}

int save_dat() {


}

int look_achievement() {
	printf("�̸�:%s\n", data.name);
	printf("�����:%lf\n", data.korean);
	printf("�����:%lf\n", data.english);
	printf("���м���:%lf\n", data.math);

	printf("���:%d", (data.korean + data.english + data.math) / 3);

		
}

int main(void) {
	int func_num;
	
	FILE* p_file = fopen("students.dat", "rb");

	while (1) {
		printf("[MENU]\n\n");
		printf("1. .dat ���Ͽ��� ������ �б�\n");
		printf("2. �߰� �л� ���� �Է�\n");
		printf("3. .dat���� ����\n");
		printf("4. ���� Ȯ��\n");
		printf("5. ����\n");
		scanf_s("%d", &func_num);

		switch (func_num)
		{
		case 1:
			read_dat();
			break;

		case 2:
			write_student();
			break;

		case 3:
			save_dat();
			break;

		case 4:
			look_achievement();
			break;

		default:
			printf("\nERR! 1~4 �� ����  �Է��ϼ���!!!!\n");
			break;
		}

	}


}

