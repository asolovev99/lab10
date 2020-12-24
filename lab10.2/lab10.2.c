#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define length_array 10

void quicksort(double numbers[length_array], int left_border, int right_border);

int main()
{
	double numbers[length_array];

	srand(time(0));
	printf("Before sort:\n"); // Для наглядности вывод элементов массива до сортировки
	for (int i = 0; i < length_array; i++)
	{
		numbers[i] = (double)rand() + (double)rand() / 10e5;
		printf("%d: %lf\n", i, numbers[i]); // Для наглядности вывод элементов массива до сортировки
	}

	quicksort(numbers, 0, length_array - 1);

	printf("\nAfter sort:\n"); // Для наглядности вывод элементов массива после сортировки
	for (int i = 0; i < length_array; i++) // Для наглядности вывод элементов массива до сортировки
	{
		printf("%d: %lf\n", i, numbers[i]);
	}

	return 0;
}

void quicksort(double numbers[length_array], int left_border, int right_border)
{
	double middle = numbers[(left_border + right_border) / 2];
	int i = left_border;
	int j = right_border;
	char was_changed = 0;

	while (i < j)
	{
		was_changed = 0;

		while (numbers[i] < middle)
		{
			i++;
		}
		while (middle < numbers[j])
		{
			j--;
		}

		if (i < j)
		{
			was_changed = 1;
			double temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}

		i++;
		j--;
	}

	printf("\nWorking...\nleft_border = %d, right_border = %d, middle = %lf\n", left_border, right_border, middle);
	for (int i = 0; i < length_array; i++)
	{
		printf("%d: %lf\n", i, numbers[i]);
	}
	//system("pause");

	if (right_border - left_border > 1)
	{
		quicksort(numbers, left_border, j + was_changed);
		quicksort(numbers, j + 1 + was_changed, right_border);
	}
}