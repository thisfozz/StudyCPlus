#include <iostream>

void fillArrayAuto(int* array, const size_t SIZE) {
	srand(time(NULL));
	for (size_t i = 0; i < SIZE; ++i) {
		array[i] = 1 + rand() % 10;
	}
}

void fillArrayManually(int* array, const size_t SIZE) {
	int tmp{ 0 };
	for (size_t i = 0; i < SIZE; ++i) {
		std::cout << "Enter prifit " << i << " Mounth: ";
		std::cin >> tmp;
		array[i] = tmp;
	}
}

void searchMinAndMaxElementInArray(int* array, const size_t SIZE) {
	int minElement = array[0];
	int maxElement = array[0];
	for (size_t i = 0; i < SIZE; ++i) {
		if (minElement < array[i]) {
			minElement = array[i];
		}
		if (maxElement > array[i]) {
			maxElement = array[i];
		}
	}

	std::cout << "\nMin Element: " << minElement << "\nMax Element: " << maxElement;
}

void searchMinAndMaxProfit(int* array, const size_t SIZE, const int beginRange, const int endRange) {
	int minElement = array[0];
	int maxElement = array[0];
	for (size_t i = beginRange; i < endRange; ++i) {
		if (minElement < array[i]) {
			minElement = array[i];
		}
		if (maxElement > array[i]) {
			maxElement = array[i];
		}
	}
	std::cout << "\nMin Profit Company: " << minElement << "\nMax Profit Company: " << maxElement;
}

void print(int* array, const size_t SIZE) {
	for (size_t i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
}

int sumElement(int* array, const size_t SIZE, const int beginRange, const int endRange, const int value) {
	int sumElement{ 0 };
	for (size_t i = beginRange; i <= endRange; ++i) {
		if (array[i] < value) {
			sumElement += array[i];
		}
	}
	return sumElement;
}

int main()
{
	// Task1: В одномерном массиве, заполненном случайными числами, определить минимальный и максимальный элементы.

	const int SIZE = 30;
	int mArrayTask1[SIZE]{};
	int value{0};

	//fillArrayAuto(mArrayTask1, SIZE);
	//print(mArrayTask1, SIZE);
	//searchMinAndMaxElementInArray(mArrayTask1, SIZE);

	// Task2: В одномерном массиве, заполненном случайными числами в заданном пользователем диапазоне, найти сумму элементов, значения которых меньше указанного пользователем.

	int mArrayTask2[SIZE]{};
	int beginRange{0}, endRange{0}, sum{0};

	fillArrayAuto(mArrayTask2, SIZE);
	print(mArrayTask2, SIZE);

	std::cout << "\nEnter the value of the beginning of the range: ";
	std::cin >> beginRange;
	std::cout << "Enter the value of the ending of the range: ";
	std::cin >> endRange;
	std::cout << "Enter value: ";
	std::cin >> value;

	if (beginRange < endRange) {
		std::cout << "\nSum Element: " << sumElement(mArrayTask2, SIZE, beginRange, endRange, value);
	}

	// Task 3: Пользователь вводит прибыль фирмы за год (12 месяцев). Затем пользователь вводит диапазон(например, 3 и 6 — поиск между 3 - м и 6 - м месяцем).
	//Необходимо определить месяц, в котором прибыль была максимальна и месяц, в котором  была минимальна с учетом выбранного диапазона.

	const int MOUNTH{ 12 };
	int mArrayTask3[MOUNTH]{};

	std::cout << "\nEnter the value of the beginning of the range: ";
	std::cin >> beginRange;
	std::cout << "Enter the value of the ending of the range: ";
	std::cin >> endRange;
	fillArrayManually(mArrayTask3, MOUNTH);
	if (beginRange < endRange) {
		searchMinAndMaxProfit(mArrayTask3, MOUNTH, beginRange, endRange);
	}
}