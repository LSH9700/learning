#include "chapter01.h"



void example_11() {

	
}




//2차원 배열
void example_10() {
	// 배열선언
	int iArr[3][4] = { {1,2,3,4},
		               {5,6,7,8},
		               {9,10,11,12}};

	// 2x3행렬
	int iArr2[2][3] = { 
		{10,20,30},
	    {40,50,60} 
	};
	int num_col = (int)sizeof(iArr2[0]) / (int)sizeof(iArr[0][0]);
	int num_row= (int)sizeof(iArr2) / (int)sizeof(iArr[0][0])/ num_col;
	printf("sizeof(iArr2) : %d\n", 
		(int)sizeof(iArr2)/(int)sizeof(iArr[0][0]));
	printf("sizeof(iArr2) : %d\n",
		(int)sizeof(iArr2[0]) / (int)sizeof(iArr[0][0]));
	printf("row : %d col : %d\n", num_row, num_col);
		
	
}




void example_09() {
	int list[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int num1;
	printf("[10 20 30 40 50 60 70 80 90 100]\n");
	printf("탐색하실 값을 입력하세요 >");
	scanf("%d", &num1);
	for (size_t i = 0; i < 10; i++){
		if (list[i] == num1) {
			printf("탐색 성공 인덱스 %d", i);
		}
	}


}
//배열복사
void example_08() {
	int iArr_src[5] = { 1, 2, 3, 4, 5 };
	int iArr_dst[5];
	char country[10] = "Korea";
	char nation[10];

	// 정수형 배열 복사
	int length = sizeof(iArr_src) / sizeof(iArr_src[0]);
	array_copy(iArr_src, iArr_dst, length);
	//결과값 출력
	for (size_t i = 0; i < length; i++) {
		printf("%d ", iArr_src[i]);
	}
	printf("\n");
	length = sizeof(iArr_dst) / sizeof(iArr_dst[0]);
	for (size_t i = 0; i < length; i++) {
		printf("%d ", iArr_dst[i]);
	}
	printf("\n");

	string_copy(country, nation);
	printf("src : %s\n", country);
	printf("dst : %s\n", nation);
}

void array_copy(int src_arr[], int dst_arr[], int length) {
	for (size_t i = 0; i < length; i++) {
		dst_arr[i] = src_arr[i];
	}
}

void string_copy(char src_arr[], char dst_arr[]) {
	int count = 0;
	while (src_arr[count] != '\0') {
		dst_arr[count] = src_arr[count];
		count++;
	}
	dst_arr[count] = '\0';
}


void example_07() {
	char my_str[20], your_str[20];
	printf("첫번쨰 문장을 입력 >");
	gets(my_str);
	printf("두번쨰 문장을 입력 >");
	gets(your_str);
	printf("첫번째문장의 길이 : %d\n", strlen(my_str));
	printf("두번째문장의 길이 : %d\n", strlen(your_str));
	//문자열 비교
	if (strcmp(my_str, your_str) == 0) {
		printf("두문장 일치\n");
	}
	else {
		printf("두문장 불일치\n");
	}
}

void example_06() {
	char input_str[20];
	printf("문자열을 입력하세요 :");
	scanf("%s",input_str);
	int len = 0;
	while (input_str[len] != '\0') {
		len++;
	}
	printf("%s의 길이는 %d\n", input_str, len);
	printf("%s의 길이는 %d\n", input_str, strlen(input_str));
}

void example_05() {
	char codes[26];
	int length = sizeof(codes) / sizeof(codes[0]);
	codes[length-1] = '\0';
	for (size_t i = 0; i < length-1; i++){
		codes[i] = 'a'+i;
		printf("%c ", codes[i]);
	}
	printf("\n");

	printf("%s", codes);
	
}


void example_04() {
	int testArr[100];
	int length = sizeof(testArr) / sizeof(testArr[0]);
	for (size_t i = 0; i < length; i++) {
		testArr[i] = 2 + i;
		printf("%d ", testArr[i]);
	}
	for (size_t i = 0; i < length-1; i++){
		testArr[i] = 2 * i - 1;
	}
}

void example_03(){
	// 주사위를 1만번 던져서 나온 숫자
	//주사위의 경우의 수 :1~6
	int counts[6] = { 0, }; //1~6 ->0~5
	//주사위는 랜덤하게 나와야하기 때문에 rand()
	//rand() -> srand((unsigned)time(NULL));
	srand((unsigned)time(NULL));

	for (size_t i = 0; i < 10000; i++) {
		int roll = rand() % 6 ; //0~5
		counts[roll]++;
	}
	printf("===============\n");
	printf("면  빈도\n");
	printf("===============\n");

	int length = sizeof(counts) / sizeof(counts[0]);
	for (size_t i = 0; i <length; i++) {
		printf("%d: %4d\n", i + 1, counts[i]);
	}

}

void example_02() {
	int testArr[5] = {1};
	for (int i = 0; i < sizeof(testArr)/sizeof(testArr[5]); i++){
		printf("%d",testArr[i]);
	}
}



void example_01() {
	/*숫자 4개를 입력받아서 그수의 합을 구하는 프로그램*/
	 int nums[10] = {0,0,0,0};
	 int sum = 0;
	 int length = sizeof(nums) / sizeof(nums[0]);
	 for (size_t i = 0; i < length; i++){
		 printf("%d번쨰 숫자 입력 >", i + 1);
		 scanf("%d",&nums[i]);
		 sum += nums[i];

	 }
	 printf("숫자 %d개의 합은 %d\n",length, sum);

	/*********변수 대신 단순 배열 사용***** */
	/*int nums[4] = {0,};
	int	 sum = 0;
	printf("첫번째 숫자 입력 : \n");
	scanf("%d", &nums[0]);
	printf("두번째 숫자 입력 : \n");
	scanf("%d", &nums[1]);
	printf("세번쨰 숫자 입력 : \n");
	scanf("%d", &nums[2]);
	printf("네번째 숫자 입력 : \n");
	scanf("%d", &nums[3]);
	sum = nums[0] + nums[1] + nums[2] + nums[3];
	printf("숫자 4개의 합은 %d\n", sum);*/

	/******변수 사용*********
	//     000000
	int sum = 0;
	printf("첫번째 숫자 입력 : \n");
	scanf("%d", &num1);
	printf("두번째 숫자 입력 : \n");
	scanf("%d", &num2);
	printf("세번쨰 숫자 입력 : \n");
	scanf("%d", &num3);
	printf("네번째 숫자 입력 : \n");
	scanf("%d", &num4);
	sum = num1 + num2 + num3 + num4;
	printf("숫자 4개의 합은 %d\n", sum);*/
}
