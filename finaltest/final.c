#include <stdio.h>

typedef struct Student
{
	char name[12];
	float korean;
	float english;
	float math;
	double avg;
} Student; //person 자료형으로 data변수를 선언함

Student data;

int read_dat() {
	FILE *p_file = open("students.bat", "rb");
	fread(&data, sizeof(Student),1,p_file);
	fclose(p_file);

}

int write_student() {
	printf("이름은?:\n");
	scanf_s("%s", &data.name,sizeof(data.name));
	printf("국어 성적은?\n");
	scanf_s("%lf", &data.korean);
	printf("영어 성적은?:\n");
	scanf_s("%lf", &data.english);
	printf("수학 성적은?:\n");
	scanf_s("%lf", &data.math);



}

int save_dat() {


}

int look_achievement() {
	printf("이름:%s\n", data.name);
	printf("국어성적:%lf\n", data.korean);
	printf("영어성적:%lf\n", data.english);
	printf("수학성적:%lf\n", data.math);

	printf("평균:%d", (data.korean + data.english + data.math) / 3);

		
}

int main(void) {
	int func_num;
	
	FILE* p_file = fopen("students.dat", "rb");

	while (1) {
		printf("[MENU]\n\n");
		printf("1. .dat 파일에서 데이터 읽기\n");
		printf("2. 추가 학생 정보 입력\n");
		printf("3. .dat파일 저장\n");
		printf("4. 성적 확인\n");
		printf("5. 종료\n");
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
			printf("\nERR! 1~4 중 숫자  입력하세요!!!!\n");
			break;
		}

	}


}

