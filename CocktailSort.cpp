#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	int asize;
	int *arr;											   //Указатель для выделения памяти под массив
	std::cout << "Enter size of array: ";
	std::cin >> asize;
	arr = new int[asize];								   //Выделение памяти под массив
	srand(time(NULL));									   //Установка начальной точки генерирования последовательности

	for (int i = 0; i < asize; i++)						   //Заполнение массива случайными числами
	{
		arr[i] = rand();
		std::cout << arr[i] << " ";
	}
	std::cout << endl;

	int left = 0, right = asize - 1, f = 1, t = 0;
	while ((left < right) && f > 0)						   //CockailSort
	{
		f = 0;
		for (int i = left; i < right; i++)				   //Слева направо
		{
			if (arr[i] > arr[i + 1])
			{
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				f = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)				   //Справо налево
		{
			if (arr[i] < arr[i - 1])
			{
				t = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = t;
				f = 1;
			}
		}
		left++;
	}

	std::cout << "Output sorted array:" << endl;
	for (int i = 0; i < asize; i++)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}
