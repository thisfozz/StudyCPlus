#pragma once
#include <iostream>
#include <array>
#include <vector>


void fillArrayAuto(int* array, const size_t& SIZE);
void fillArrayManually(int* array, const size_t& SIZE);
void fillArray(int* array, const size_t& SIZE);


int min(int* array, const int& SIZE);
int max(int* array, const int& SIZE);


int searchMinProfit(int* array, const size_t& beginRange, const size_t& endRange);
int searchMaxProfit(int* array, const size_t& beginRange, const size_t& endRange);


void print(const int* array, const size_t& SIZE);


int sumElem(int* array, const size_t& beginRange, const size_t& endRange, const size_t& value);
int sumNegativeElem(int* array, const size_t& SIZE);
int multElem(int* array, const size_t& SIZE);
int multEvenElem(int* array, const size_t& SIZE);
int sumElemFirstEvenAndEndEven(int* array, const size_t& SIZE);


int searchIdxMinElem(int* array, const size_t& SIZE);
int searchIdxMaxElem(int* array, const size_t& SIZE);
int searchIdxMaxElem(int* array, const size_t& SIZE);
int firstIdxEvenElem(int* array, const size_t& SIZE);
int endIdxEvenElem(int* array, const size_t& SIZE);

void week(const int& index);
int avgWeek(const int* array, const int& SIZE);
int countDayMore100D(const int* array, const int& SIZE);
void Homework();
void task1();
void task2();
void task3();

//void countDayMore100D(const int* array, const int& SIZE) {
//	std::vector<int> saveIndex{};
//	int count{ 0 };
//	for (size_t i = 0; i < SIZE; ++i) {
//		if (array[i] > 100) {
//			saveIndex.push_back(i);
//			//std::cout << week(i);
//			count++;
//		}
//	}
//	for (int i = 0; i < saveIndex.size(); ++i) {
//		weekk(i);
//	}
//	//week(saveIndex);
//	std::cout << "\nCount day > 100: " << count;
//}