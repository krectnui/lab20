#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

void main()
{
	setlocale(LC_ALL, "RUS");
	// 1
	char fname[20] = "aaa.txt";
	FILE* in;
	in = fopen(fname, "r");
	if (in == NULL)
	{
		printf("Ошибка открытия файла");
		return 0;
	}
	int sum = 0;
	while (!feof(in)) {
		int a;
		fscanf(in, "%d", &a);
		printf("%d\n", a);
		sum += a;
	}
	fclose(in);

	// 2
	FILE* in1;
	FILE* in2;
	char fileName[24];
	printf("Введите название файла: ");
	scanf("%24s", fileName);
	char newFileName[24] = "new";
	strcat(newFileName, fileName);
	in1 = fopen(fileName, "r");
	if (in1 == NULL)
	{
		printf("Ошибка открытия файла 1 ");
		return 0;
	}
	if ((in2 = fopen(newFileName, "wt")) == NULL) {
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	int counter = 0;
	while (!feof(in1)) {
		int a;
		fscanf(in1, "%d", &a);
		if (counter % 2 == 0) {
			fprintf(in2, "%d\n", 0);
		}
		else {
			fprintf(in2, "%d\n", a);
		}
		counter++;
	}
	fclose(in1);
	fclose(in2);
	// 3
	puts("\n\n\n");
	FILE* in3;
	char fileName2[24] = "stroke.txt";
	in3 = fopen(fileName2, "r");
	if (in3 == NULL)
	{
		printf("Ошибка открытия файла 3 ");
		return 0;
	}
	char str[100];
	int counter2 = 0;
	while (!feof(in3)) {
		if (fgets(str, sizeof(str), in3) != NULL) {
			char* pch = strtok(str, " ");
			while (pch != NULL)
			{
				printf("\n%s - %d", pch, counter2);
				pch = strtok(NULL, " ");
				counter2++;
			}
		}
	}
}