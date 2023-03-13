#include <iostream>
#include "HomeworkOne.h"

constexpr unsigned int SIZE{ 30 };
constexpr unsigned int MOUNTH{ 12 };

//Автоматическая генерация псевдослучайными значениями массива
void fillArrayAuto(int* array, const size_t& SIZE) {
	srand(time(NULL));

	for (size_t i = 0; i < SIZE; ++i) {
		array[i] = 1 + rand() % 10;
	}
}

//Ручное заполнение элементов в массив
void fillArrayManually(int* array, const size_t& SIZE) {
	int tmp{ 0 };

	for (size_t i = 0; i < SIZE; ++i) {
		std::cout << "Enter value: "; week(i);
		std::cin >> tmp;
		array[i] = tmp;
	}
}

// Заполнение массива с отрицательными элементами
void fillArray(int* array, const size_t& SIZE) {
	srand((int)time(NULL));

	for (size_t i = 0; i < SIZE; ++i) {
		array[i] = 100 - rand() % 100;
	}
}

//Поиск минимального элемента в массиве
int min(int* array, const int& SIZE) {
	int minElement{ array[0] };

	for (size_t i = 0; i < SIZE; ++i) {
		if (minElement < array[i]) {
			minElement = array[i];
		}
	}

	return minElement;
}

//Поиск максимального элемента в массиве
int max(int* array, const int& SIZE) {
	int maxElement{ array[0] };

	for (size_t i = 0; i < SIZE; ++i) {
		if (maxElement > array[i]) {
			maxElement = array[i];
		}
	}

	return maxElement;
}

//Поиск минимальной прибыли компании в заданном диапазоне
int searchMinProfit(int* array, const size_t& beginRange, const size_t& endRange) {
	int minElement{ array[0] };

	for (size_t i = beginRange; i < endRange; ++i) {
		if (minElement < array[i]) {
			minElement = array[i];
		}
	}

	return minElement;
}

//Поиск максимальной приыбли компании в заданном диапазоне
int searchMaxProfit(int* array, const size_t& beginRange, const size_t& endRange) {
	int maxElement{ array[0] };

	for (size_t i = beginRange; i < endRange; ++i) {
		if (maxElement > array[i]) {
			maxElement = array[i];
		}
	}

	return maxElement;
}

//Вывод массива
void print(const int* array, const size_t& SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
}

//Сумма элементов в заданном диапазоне
int sumElem(int* array, const size_t& beginRange, const size_t& endRange, const size_t& value) {
	int sumElement{ 0 };

	for (size_t i = beginRange; i <= endRange; ++i) {
		if (array[i] < value) {
			sumElement += array[i];
		}
	}

	return sumElement;
}

//Сумма отрицательных элементов
int sumNegativeElem(int* array, const size_t& SIZE) {
	int sum{ 0 };

	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] < 0) {
			sum += array[i];
		}
		else {
			std::cout << "Negative elements are missing.";
		}
	}

	return sum;
}

// Поиск индекса минимального элемента
int searchIdxMinElem(int* array, const size_t& SIZE) {
	size_t indexMin{ 0 };
	int minElenent{ array[0] };

	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] < minElenent) {
			minElenent = array[i];
			indexMin = i;
		}
	}

	return static_cast<int>(indexMin);
}

// Поиск индекса максимального элемента
int searchIdxMaxElem(int* array, const size_t& SIZE) {
	size_t indexMax{ 0 };
	int maxElement{ array[0] };

	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] > maxElement) {
			maxElement = array[i];
			indexMax = i;
		}
	}

	return static_cast<int>(indexMax);
}

//Произведение элементов, находящихся между min и max элементами.
int multElem(int* array, const size_t& SIZE) {
	int minIndexElement{ searchIdxMinElem(array, SIZE) }, maxIndexElement{ searchIdxMaxElem(array, SIZE) }, multiplication{ 0 };

	for (size_t i = minIndexElement; i < maxIndexElement; ++i) {
		multiplication *= array[i];
	}

	return multiplication;
}

//Произведение элементов с четными номерами
int  multEvenElem(int* array, const size_t& SIZE) {
	int multiplicationEven{ 0 };

	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] % 2 == 0) {
			multiplicationEven *= array[i];
		}
	}

	return multiplicationEven;
}

//Нахождение первого индекса отрицательного элемента
int firstIdxEvenElem(int* array, const size_t& SIZE) {
	size_t firstIndexEven{ 0 };

	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] < 0) {
			firstIndexEven = i;
			break;
		}
	}

	return static_cast<int>(firstIndexEven);
}

//Нахождение последнего индекса отрицательного элемента
int endIdxEvenElem(int* array, const size_t& SIZE) {
	size_t endIndexEven{ 0 };

	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] < 0) {
			endIndexEven = i;
		}
	}

	return static_cast<int>(endIndexEven);
}

// Сумму элементов, находящихся между первым и последним отрицательными элементами.
int sumElemFirstEvenAndEndEven(int* array, const size_t& SIZE) {
	int firstIndexEven{ firstIdxEvenElem(array, SIZE) }, endIndexEven{ endIdxEvenElem(array, SIZE) }, sum{ 0 };

	for (size_t i = firstIndexEven; i < endIndexEven; ++i) {
		sum += array[i];
	}

	return sum;
}

void Homework() {
	uint8_t choice{ 0 };
	int value{ 0 };
	int mArrayTask1[SIZE]{}, mArrayTask2[SIZE]{}, mArrayTask3[MOUNTH]{}, beginRange{ 0 }, endRange{ 0 }, sum{ 0 }, sizeArrayDynamic{ 0 };

	std::cout << "\t\t\t\t=============== MENU TASK ===============\n\n";
	std::cout
		<< "1. In a one-dimensional array filled with random numbers, determine the minimum and maximum elements."
		<< "\n\n2. In a one-dimensional array filled with random numbers in a user - defined range, find the sum of elements whose values are less than the user - specified."
		<< "\n\n3. The user enters the company's profit for the year (12 months). Then the user enters a range(for example, 3 and 6 — search between the 3rd and 6th month).It is necessary to determine the month"
		<< "in which the profit was maximumand the month in which the profit was minimum, taking into account the selected range."
		<< "\n\n4. In a one-dimensional array consisting of N real numbers, calculate:";

	std::cout << "\n\nSelect a task: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		system("cls");
		std::cout << "============== TASK 1 ==============\n";

		fillArrayAuto(mArrayTask1, SIZE);
		print(mArrayTask1, SIZE);

		std::cout << "\nMin Element in Array: " << min(mArrayTask1, SIZE);
		std::cout << "\nMax Element in Array: " << max(mArrayTask1, SIZE);

		break;
	case 2:
		system("cls");
		std::cout << "============== TASK 2 ==============\n";

		fillArrayAuto(mArrayTask2, SIZE);
		print(mArrayTask2, SIZE);

		std::cout << "\nEnter the value of the beginning of the range: ";
		std::cin >> beginRange;
		std::cout << "Enter the value of the ending of the range: ";
		std::cin >> endRange;
		std::cout << "Enter value: ";
		std::cin >> value;

		if (beginRange < endRange && beginRange > 0 && endRange > 0) {
			std::cout << "\nSum Element: " << sumElem(mArrayTask2, beginRange, endRange, value);
		}

		break;
	case 3:
		system("cls");
		std::cout << "============== TASK 3 ==============\n";;

		std::cout << "\nEnter the value of the beginning of the range: ";
		std::cin >> beginRange;
		std::cout << "Enter the value of the ending of the range: ";
		std::cin >> endRange;
		system("cls");

		fillArrayManually(mArrayTask3, MOUNTH);
		print(mArrayTask3, MOUNTH);

		if (beginRange < endRange && beginRange > 0 && endRange > 0) {
			std::cout << "\nMin Profit in Company: " << searchMinProfit(mArrayTask3, beginRange, endRange);
			std::cout << "\nMin Profit in Company: " << searchMaxProfit(mArrayTask3, beginRange, endRange);
		}

		break;
	case 4:
		system("cls");
		std::cout << "============== TASK 4 ==============\n";

		std::cout << "Enter size array: ";
		std::cin >> sizeArrayDynamic;
		int* mArrayTask4 = new int[sizeArrayDynamic];

		fillArray(mArrayTask4, sizeArrayDynamic);

		std::cout << "The sum of negative elements: " << sumNegativeElem(mArrayTask4, sizeArrayDynamic);
		std::cout << "The product of the elements between the min and max elements: " << multElem(mArrayTask4, sizeArrayDynamic);
		std::cout << "The product of elements with even numbers: " << multEvenElem(mArrayTask4, sizeArrayDynamic);
		std::cout << "The sum of the elements between the first and last negative elements: " << sumElemFirstEvenAndEndEven(mArrayTask4, sizeArrayDynamic);

		delete[] mArrayTask4;

		break;
	}
}

/*======================== ВТОРОЕ ДОМАШНЕЕ ЗАДАНИЕ ========================*/
void week(const int& index) {
	if (index == 0)
		std::cout << " \nMonday: ";
	if (index == 1)
		std::cout << " \nTuesday: ";
	if (index == 2)
		std::cout << " \nWednesday: ";
	if (index == 3)
		std::cout << " \nThursday: ";
	if (index == 4)
		std::cout << " \nFriday: ";
	if (index == 5)
		std::cout << " \nSaturday: ";
	if (index == 6)
		std::cout << " \nSunday: ";
}

int sumWeek(const int* array, const int& SIZE) {
	int sum{ 0 };

	for (size_t i = 0; i < SIZE; ++i) {
		sum += array[i];
	}
	return sum;
}

int avgWeek(const int* array, const int& SIZE) {
	return (sumWeek(array, SIZE) / SIZE);
}

void printWeek(std::vector<int> saveIndex) {
	for (int i = 0; i < saveIndex.size(); ++i) {
		week(i);
	}
}

int countDayMore100D(const int* array, const int& SIZE) {
	std::vector<int> saveIndex{};
	int count{ 0 };
	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] > 100) {
			saveIndex.push_back(i);
			count++;
		}
	}
	printWeek(saveIndex);
	return count;
}

void task1() {
	/*
	* Написать программу, копирующую последовательно элементы одного массива размером 10 элементов в 2 массива размером 5 элементов каждый.
	*/

	const int SIZE = 10;
	const int SIZEANOTHER = 5;
	int arrayOne[SIZE];
	int arrayTwo[SIZEANOTHER];
	int arrayThree[SIZEANOTHER];

	fillArrayAuto(arrayOne, SIZE);

	for (size_t i = 0; i < 5; ++i) {
		arrayTwo[i] = arrayOne[i];
	}

	for (size_t i = 0; i < 5; ++i) {
		arrayThree[i] = arrayOne[5+i];
	}

	std::cout << "Array 1: "; print(arrayOne, SIZE);
	std::cout << "\n";
	std::cout << "Array 2: "; print(arrayTwo, SIZEANOTHER);
	std::cout << "\n";
	std::cout << "Array 3: "; print(arrayThree, SIZEANOTHER);
}

void task2() {
	/*
	* Напишите программу, которая выполняет поэлементную сумму двух массивов и результат заносит в третий массив.
	*/

	const int SIZE{ 5 };;
	int arrayOne[SIZE];
	int arrayTwo[SIZE];
	int arrayThree[SIZE];

	fillArrayAuto(arrayOne, SIZE);
	fillArrayAuto(arrayTwo, SIZE);

	print(arrayOne, SIZE);
	std::cout << "\n";
	print(arrayTwo, SIZE);
	std::cout << "\n";

	for (size_t i = 0; i < SIZE; ++i) {
		arrayThree[i] = arrayOne[i] + arrayTwo[i];
	}

	print(arrayThree, SIZE);
}

void task3() {
	/*
	* Пользователь вводит данные о своих расходах в долларах за неделю (каждый день). Написать программу, которая вычисляет:
		■ среднюю (за неделю) потраченную сумму;
		■ общую сумму, потраченную пользователем за неделю;
		■ количество дней и их названия (например, «вторник»), когда сумма расхода (в день) превысила 100 долларов.
	*/

	const int WEEK = 7;
	int array[WEEK]{};
	int count{0};
	std::vector<int>saveIndex{};

	fillArrayManually(array, WEEK);
	print(array, WEEK);

	std::cout << "\nNaverage for week: " << avgWeek(array, WEEK);
	std::cout << "\nSum for Week: " << sumWeek(array, WEEK);
	std::cout << "Count Day: " << countDayMore100D(array, WEEK);
}

void fillArrayRand(int* array, const int& SIZE) {
	srand(time(NULL));

	for (size_t i = 0; i < SIZE; ++i) {
		array[i] = 1 + rand() % 100;
	}
}

void fillArrayLinear(int* array, const int& SIZE) {
	for (size_t i = 1; i <= SIZE; ++i) {
		array[i] = i;
	}
}

int linearSearch(int* array, const int& SIZE, const int& value) {
	for (size_t i = 0; i < SIZE; ++i) {
		if (array[i] == value) {
			return i;
		}
	}
}

int binarySearch(int* array, int min, int max, int value) {

	if (max < min)
		std::cout << "MAX < MIN";
	int mid = (min + max) / 2;
	char choice{};

	std::cout << "Your value: " << " > " << array[mid] << " ? ";
	std::cout << "\nY - YES   :   N - NO   :   =   ";
	std::cin >> choice;
	switch (choice)
	{
	case 'Y':
		if (array[mid] > value)
			binarySearch(array, min, mid - 1, value);
		break;
	case 'N':
		if (array[mid] < value)
			binarySearch(array, min, mid + 1, value);
		break;
	case '=':
		if (array[mid] == value) {
			std::cout << "Value is find: " << array[mid];
			return 1;
		}
		break;
	default:
		break;
	}
}

void print(int* array, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		std::cout << array[i] << " ";
	}
}

/*======================== ТРЕТЬЕ ДОМАШНЕЕ ЗАДАНИЕ ========================*/

float average(const int* array, const int& SIZE) {
	float average{ 0 };

	for (int i = 0; i < SIZE; ++i) {
		average += array[i];
	}
	average = average / SIZE;

	return average;
}

void count(const int* array, const int& SIZE) {
	int positive{ 0 }, negative{ 0 }, nullelement{ 0 };

	for (int i = 0; i < SIZE; ++i) {
		if (array[i] > 0) {
			++positive;
		}
		else if (array[i] < 0) {
			++negative;
		}
		else {
			++nullelement;
		}
	}

	std::cout << "Positive element: " << positive << "\nNegative element: " << negative << "Null element: " << nullelement;
}

int main()
{
	const int SIZE = 10;
	int array[SIZE]{};
	fillArrayRand(array, SIZE);
	print(array, SIZE);
	std::cout << "\n\nAverage = " << average(array, SIZE);

	system("cls");
	fillArrayRand(array, SIZE);
	print(array, SIZE);
}
