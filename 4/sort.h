#pragma once

#include <vector>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>

class SortAlgorithm
{
	public:

		void bubbleSort(std::vector<int> &unsortedVector);

		void insertionSort(std::vector<int>& unsortedVector);

		void quickSort(std::vector<int>& unsortedVector, int leftElement, int rightElement);

		void selectionSort(std::vector<int>& unsortedVector);

		void stdSort(std::vector<int>& unsortedVector);
		
		void print(std::vector<int>& unsortedVector);

	private:

		int partition(std::vector<int>& unsortedVector, int leftElement, int rightElement);

};

