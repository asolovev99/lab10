#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define length_array 10

void insertion_sort(double* numbers);

int main()
{
	double numbers[length_array];

	srand(time(0));
	printf("Before sort:\n"); // ��� ����������� ����� ��������� ������� �� ����������
	for (int i = 0; i < length_array; i++)
	{
		numbers[i] = (double)rand() + (double)rand() / 10e5;
		printf("%d: %lf\n", i, numbers[i]); // ��� ����������� ����� ��������� ������� �� ����������
	}

	insertion_sort(numbers);

	printf("\nAfter sort:\n"); // ��� ����������� ����� ��������� ������� ����� ����������
	for (int i = 0; i < length_array; i++) // ��� ����������� ����� ��������� ������� �� ����������
	{
		printf("%d: %lf\n", i, numbers[i]);
	}

	return 0;
}

void insertion_sort(double* numbers)
{
	int j = 0;
	double temp = 0;

	for (int i = 1; i < length_array; i++) // ������ ������������ ��������
	{
		for (j = i - 1; (j >= 0) && (numbers[i] < numbers[j]); j--); // ������� ��������������� ���������

		temp = numbers[i];
		for (int k = i - 1; k > j; k--) // ������� ��������� �������, ������� ����� �������� �� 1 �������
		{
			numbers[k + 1] = numbers[k];
		}
		numbers[j + 1] = temp;
	}
}