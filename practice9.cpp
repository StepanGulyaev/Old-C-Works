// Sortirovka_pyzirkom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int SortOtbor(int[], int);//прототип функции Сортировка выбором
int PSort(int[], int);    //прототип функции пузырьковой сортировки
int sort_min(int[], int);

int main()
	{

	setlocale(LC_ALL, "rus");

	const int size=10000;  //размер массива
	int array[size];
	int array2[size];
	int array3[size];//создаем еще один массив, чтобы обе функции сортировок, использовали идентичные масивы(копия массива array)

	int timeOfSortArray = 0;
	int timeOfSortArray2 = 0;
	int timeOfSortArray3 = 0;

	//заполним массивы случайными числами от 1-го до 800-та
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		{
		array[i] = 1 + rand() % 800;
		array2[i] = array[i];
		array3[i] = array[i]; //копируем значения первого массива во второй, чтобы использовать его в функции шейкерной сортировки
		}

	//выводим исходный (неотсортированный) массив на экран
	printf("Неотсортированный массив: \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array[i]);
			printf("\n\n");
	
	timeOfSortArray = SortOtbor(array, size);

	//выводим отсортированный массив (выбором) на экран
	printf("Отсортированный массив (выбором): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array[i]);
	printf("\n\n");
	
	timeOfSortArray2 = PSort(array2, size);

	//выводим отсортированный массив ("Пузырек") на экран
	printf("Отсортированный массив (\"Пузырек\"): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array2[i]);
	printf("\n\n");

    timeOfSortArray3 = sort_min(array3, size);

	printf("Отсортированный массив (\"Своим способом\"): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array3[i]);
	printf("\n\n");

	
	printf("На сортировку массива методом отбором потрачено: %4d временных тактов процессора!\n\n", timeOfSortArray);
	printf("На сортировку массива методом \"Пузырек\" потрачено: %4d временных тактов процессора!\n\n", timeOfSortArray2); 
	printf("На сортировку массива методом \"Своим способом\" потрачено: %4d временных тактов процессора!\n\n", timeOfSortArray3); 



	if ((timeOfSortArray < timeOfSortArray2) && (timeOfSortArray < timeOfSortArray3))
	    {
		printf("Более эффективным оказался метод сортировки выбором!\n\n");
	    }
	else if ((timeOfSortArray2 < timeOfSortArray3) && (timeOfSortArray2 < timeOfSortArray))
	    {
		printf("Более эффективным оказался метод сортировки \"Пузырек\"!\n\n");
	    }
    else if ((timeOfSortArray3 < timeOfSortArray) && (timeOfSortArray3 < timeOfSortArray2))
        {
        printf("Более эффективным оказался метод сортировки \"Своим способом\"!\n\n");
        }
	else printf("Эффективность методов сортировки в данном случае равна!\n\n");

	return 0;
	}


	int sort_min(int array3[], int size)
		{
		int startTime = 0; // начальное время работы функции сортировки
		int endTime = 0; // конечное время работы функции сортировки
		int searchTime = 0;

    	int min;
    	int min_index;
    

		startTime = clock();
		for (int i = 0; i < size - 1; i++)
			{
        	min = array3[i];
			for (int j = i+1; j < size; j++)
				{
				if (array3[j] <= min){min = array3[j]; min_index = j;}
				}
        	array3[min_index] = array3[i];
        	array3[i] = min;
			}
		endTime = clock();
		return searchTime = (endTime - startTime);
		}


	int SortOtbor(int Array[], int Size)
		{
		int startTime = 0; // начальное время работы функции сортировки
		int endTime = 0; // конечное время работы функции сортировки
		int searchTime = 0; //продолжительность работы функции сортировки

		int min; //минимальный элемент в массиве
		int index;
		int temp; // временная переменная для хранения минимального значения элемента

		startTime = clock(); //начинаем отсчет продолжительности сортировки
		for (int i = Size - 1; i >= 1; i--)
			{
			//задаем начальные значения
			min = Array[i];
			index = i;

			//цикл перебора элементов массива
			for (int j = i - 1; j >= 0; j--)
				{
				//находим минимальный элемент
					if (min > Array[j])
					{
					//запоминаем минимальный элемент и его индекс
					min = Array[j];
					index = j;
					}
				}

			//запоминаем минимум
			temp = Array[index];

			for (int x = index; x < i; x++)//сдвигаем элементы влево
				{
				Array[x] = Array[x + 1];
				}

			Array[i] = temp;
			}
		endTime = clock(); // конечное время работы функции сортировки
		return searchTime = (endTime - startTime); //искомое время работы функции ;
		}

	int PSort(int Array2[], int Size)
		{
		int startTime = 0; // начальное время работы функции сортировки
		int endTime = 0; // конечное время работы функции сортировки
		int searchTime = 0; //продолжительность работы функции сортировки

		int temp; //буфер
		int i,j;
	

		startTime = clock(); //начинаем отсчет продолжительности сортировки
	
		for (i = Size - 1; i > 0; i--)
			for (j = 0; j < i; j++)
				if (Array2[j] > Array2[j + 1])
					{
					temp = Array2[j];
					Array2[j] = Array2[j + 1];
					Array2[j + 1] = temp;
					}
		endTime = clock(); // конечное время работы функции сортировки

		return searchTime = (endTime - startTime); //искомое время работы функции ;
		}