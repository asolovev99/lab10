#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define length_array 10

void insertion_sort(double* numbers);

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

	insertion_sort(numbers);

	printf("\nAfter sort:\n"); // Для наглядности вывод элементов массива после сортировки
	for (int i = 0; i < length_array; i++) // Для наглядности вывод элементов массива до сортировки
	{
		printf("%d: %lf\n", i, numbers[i]);
	}

	return 0;
}

void insertion_sort(double* numbers)
{
	int j = 0;
	double temp = 0;

	for (int i = 1; i < length_array; i++) // Индекс вставляемого элемента
	{
		for (j = i - 1; (j >= 0) && (numbers[i] < numbers[j]); j--); // Индексы отсортированных элементов

		temp = numbers[i];
		for (int k = i - 1; k > j; k--) // Индексы элементов массива, которые нужно сместить на 1 позицию
		{
			numbers[k + 1] = numbers[k];
		}
		numbers[j + 1] = temp;
	}
}