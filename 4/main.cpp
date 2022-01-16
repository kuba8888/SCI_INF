#include <algorithm>
#include <cstdlib>
#include <type_traits>
#include <fstream>
#include "sort.h"

void random(std::vector<int>& unsortedVector)
{
	srand(time(0));

	for(int i = 0; i < unsortedVector.size(); ++i)
	{
		unsortedVector[i]=rand()%1000;
	}
}

int main()
{
	char choice;
	std::vector<int> v(10000);
	SortAlgorithm s;

	random(v);
	s.print(v);

	std::cout << "Choose sort alghoritm: \n"
		"1. bubble sort\n"
		"2. insertion sort\n"
		"3. quick sort\n"
		"4. selecton sort\n"
		"5. std sort\n";
	std::cin >> choice;

	switch(choice)
	{
		case '1':
			{
				auto start = std::chrono::steady_clock::now();
				s.bubbleSort(v);
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_second = end - start;
				std::cout << "elapsed time is " << elapsed_second.count() << "s. \n";
				std::fstream times;
				times.open("times.txt", std::fstream::app);
				times << "bubble: " << elapsed_second.count() << std::endl;
				s.print(v);
				break;
			}

		case '2':
			{
				auto start = std::chrono::steady_clock::now();
				s.insertionSort(v);
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_second = end - start;
				std::cout << "elapsed time is " << elapsed_second.count() << "s. \n";
				std::fstream times;
				times.open("times.txt", std::fstream::app);
				times << "insertion: " << elapsed_second.count()<< std::endl;
				s.print(v);
				break;
			}

		case '3':
			{
				auto start = std::chrono::steady_clock::now();
				s.quickSort(v, 0, v.size()-1);
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_second = end - start;
				std::cout << "elapsed time is " << elapsed_second.count() << "s. \n";
				std::fstream times;
				times.open("times.txt", std::fstream::app);
				times << "quick: " << elapsed_second.count()<< std::endl;
				s.print(v);
				break;
			}

		case '4':
			{
				auto start = std::chrono::steady_clock::now();
				s.selectionSort(v);
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_second = end - start;
				std::cout << "elapsed time is " << elapsed_second.count() << "s. \n";
				std::fstream times;
				times.open("times.txt", std::fstream::app);
				times << "selection: " << elapsed_second.count()<< std::endl;
				s.print(v);
				break;
			}

		case '5':
			{
				auto start = std::chrono::steady_clock::now();
				std::sort(v.begin(), v.end());
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_second = end - start;
				std::cout << "elapsed time is " << elapsed_second.count() << "s. \n";
				std::fstream times;
				times.open("times.txt", std::fstream::app);
				times << "std sort: " << elapsed_second.count()<< std::endl;
				s.print(v);
				break;
			}

		default:
			{
				std::cout << "invalid value\n";
				break;
			}
	}
	return 0;
}
