#include <iostream>
#include <array>

constexpr unsigned int SIZE{ 30 };
constexpr unsigned int MOUNTH{ 12 };

//Автоматическая генерация псевдослучайными значениями массива
void fillArrayAuto(int* array, const size_t SIZE) {
	srand(time(NULL));

	for (int i = 0; i < SIZE; ++i) {
		array[i] = 1 + rand() % 10;
	}
}


//Ручное заполнение элементов в массив
void fillArrayManually(int* array, const size_t SIZE) {
	int tmp{ 0 };

	for (int i = 0; i < SIZE; ++i) {
		std::cout << "Enter prifit " << i << " Mounth: ";
		std::cin >> tmp;
		array[i] = tmp;
	}
}


// Заполнение массива с отрицательными элементами
void fillArray(int* array, const size_t SIZE) {
	srand(time(NULL));

	for (int i = 0; i < SIZE; ++i) {
		array[i] = 100 - rand() % 100;
	}
}


//Поиск минимального и максимального элементов в массиве
void searchMinAndMaxElementInArray(int* array, const int SIZE) {
	int minElement{ array[0] }, maxElement{ array[0] };

	for (int i = 0; i < SIZE; ++i) {
		if (minElement < array[i]) {
			minElement = array[i];
		}
		if (maxElement > array[i]) {
			maxElement = array[i];
		}
	}

	std::cout << "\nMin Element: " << minElement << "\nMax Element: " << maxElement;
}


//Поиск минимальной и максимальной прибыли компании в заданном диапазоне
void searchMinAndMaxProfit(int* array, const size_t beginRange, const size_t endRange) {
	int minElement{ array[0] },maxElement{ array[0] };

	for (int i = beginRange; i < endRange; ++i) {
		if (minElement < array[i]) {
			minElement = array[i];
		}
		if (maxElement > array[i]) {
			maxElement = array[i];
		}
	}

	std::cout << "\nMin Profit Company: " << minElement << "\nMax Profit Company: " << maxElement;
}


//Вывод массива
void print(const int* array, const size_t SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
}


//Сумма элементов в заданном диапазоне
int sumElement(int* array, const size_t beginRange, const size_t endRange, const size_t value) {
	int sumElement{ 0 };
	for (int i = beginRange; i <= endRange; ++i) {
		if (array[i] < value) {
			sumElement += array[i];
		}
	}
	return sumElement;
}


//Сумма отрицательных элементов
int SumNegativeElement(int* array, const size_t SIZE) {
	int sum{ 0 };
	for (int i = 0; i < SIZE; ++i) {
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
int seatchIndexMinElement(int* array, const size_t SIZE) {
	int indexMin{ 0 }, minElenent{ array[0] };
	for (int i = 0; i < SIZE; ++i) {
		if (array[i] < minElenent) {
			minElenent = array[i];
			indexMin = i;
		}
	}

	return indexMin;
}


// Поиск индекса максимального элемента
int seatchIndexMaxElement(int* array, const size_t SIZE) {
	int indexMax{ 0 }, maxElement{ array[0] };
	for (int i = 0; i < SIZE; ++i) {
		if (array[i] > maxElement) {
			maxElement = array[i];
			indexMax = i;
		}
	}

	return indexMax;
}


//Произведение элементов, находящихся между min и max элементами.
int multiplicationElement(int* array, const size_t SIZE) {
	int minIndexElement{ seatchIndexMinElement(array, SIZE) }, maxIndexElement{ seatchIndexMaxElement(array, SIZE) }, multiplication{ 0 };
	for (int i = minIndexElement; i < maxIndexElement; ++i) {
		multiplication *= array[i];
	}

	return multiplication;
}


//Произведение элементов с четными номерами
int  multiplicationEvenElement(int* array, const size_t SIZE) {
	int multiplicationEven{ 0 };
	for (int i = 0; i < SIZE; ++i) {
		if (array[i] % 2 == 0) {
			multiplicationEven *= array[i];
		}
	}

	return multiplicationEven;
}


//Нахождение первого индекса отрицательного элемента
int firstIndexEvenElement(int* array, const size_t SIZE) {
	int firstIndexEven{ 0 };
	for (int i = 0; i < SIZE; ++i) {
		if (array[i] < 0) {
			firstIndexEven = i;
			break;
		}
	}
	return firstIndexEven;
}


//Нахождение последнего индекса отрицательного элемента
int endIndexEvenElement(int* array, const size_t SIZE) {
	int endIndexEven{ 0 };
	for (int i = 0; i < SIZE; ++i) {
		if (array[i] < 0) {
			endIndexEven = i;
		}
	}
	return endIndexEven;
}


// Сумму элементов, находящихся между первым и последним отрицательными элементами.
int sumnElementFirstEvenAndEndEven(int* array, const size_t SIZE) {
	int firstIndexEven{ firstIndexEvenElement(array, SIZE) }, endIndexEven{ endIndexEvenElement(array, SIZE) }, sum{ 0 };

	for (int i = firstIndexEven; i < endIndexEven; ++i) {
		sum += array[i];
	}

	return sum;
}


int main()
{
	int choice{ 0 };
	std::cout << "\t\t\t\t=============== MENU TASK ===============\n\n";
	std::cout
		<< "1. In a one-dimensional array filled with random numbers, determine the minimum and maximum elements."
		<< "\n\n2. In a one-dimensional array filled with random numbers in a user - defined range, find the sum of elements whose values are less than the user - specified."
		<< "\n\n3. The user enters the company's profit for the year (12 months). Then the user enters a range(for example, 3 and 6 — search between the 3rd and 6th month).It is necessary to determine the month"
		<< "in which the profit was maximumand the month in which the profit was minimum, taking into account the selected range."
		<< "\n\n4. In a one-dimensional array consisting of N real numbers, calculate:";

	std::cout << "\n\nSelect a task: ";
	std::cin >> choice;

	int mArrayTask1[SIZE]{}, mArrayTask2[SIZE]{}, mArrayTask3[MOUNTH]{}, beginRange{ 0 }, endRange{ 0 }, sum{ 0 }, sizeArrayDynamic{ 0 };
	int value{ 0 };

	switch (choice)
	{
	case 1:
		system("cls");
		std::cout << "============== TASK 1 ==============\n";

		fillArrayAuto(mArrayTask1, SIZE);
		print(mArrayTask1, SIZE);
		searchMinAndMaxElementInArray(mArrayTask1, SIZE);
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
			std::cout << "\nSum Element: " << sumElement(mArrayTask2, beginRange, endRange, value);
		}
		break;
	case 3:
		system("cls");
		std::cout << "============== TASK 3 ==============\n";;

		std::cout << "\nEnter the value of the beginning of the range: ";
		std::cin >> beginRange;
		std::cout << "Enter the value of the ending of the range: ";
		std::cin >> endRange;
		fillArrayManually(mArrayTask3, MOUNTH);
		if (beginRange < endRange && beginRange > 0 && endRange > 0) {
			searchMinAndMaxProfit(mArrayTask3, beginRange, endRange);
		}
		break;
	case 4:
		system("cls");
		std::cout << "============== TASK 4 ==============\n";

		std::cout << "Enter size array: ";
		std::cin >> sizeArrayDynamic;
		int* mArrayTask4 = new int[sizeArrayDynamic];

		fillArray(mArrayTask4, sizeArrayDynamic);

		std::cout << "The sum of negative elements: " << SumNegativeElement(mArrayTask4, sizeArrayDynamic);
		std::cout << "The product of the elements between the min and max elements: " << multiplicationElement(mArrayTask4, sizeArrayDynamic);
		std::cout << "The product of elements with even numbers: " << multiplicationEvenElement(mArrayTask4, sizeArrayDynamic);
		std::cout << "The sum of the elements between the first and last negative elements: " << sumnElementFirstEvenAndEndEven(mArrayTask4, sizeArrayDynamic);
		break;
	}
}