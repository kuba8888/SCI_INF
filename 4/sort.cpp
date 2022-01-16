#include <vector>
#include "sort.h"

void SortAlgorithm::bubbleSort(std::vector<int>& unsortedVector)
{
	for (int i = 0; i < unsortedVector.size(); ++i)
	{
		for (int j = 0; j < unsortedVector.size() - 1; ++j)
		{
			if (unsortedVector.at(j) > unsortedVector.at(j + 1))
			{
				int temp = unsortedVector.at(j);
				unsortedVector.at(j) = unsortedVector.at(j + 1);
				unsortedVector.at(j + 1) = temp;
			}
		}
	}
}

void SortAlgorithm::insertionSort(std::vector<int>& unsortedVector)
{
	for(int i=1;i<=unsortedVector.size()-1;i++)
	{
		int currentEle = unsortedVector[i];
		int prevEle = i-1;
		while(prevEle>=0 and unsortedVector[prevEle]>currentEle){
			unsortedVector[prevEle+ 1] = unsortedVector[prevEle];
			prevEle = prevEle-1;

		}
		unsortedVector[prevEle+1] = currentEle;
	}
}

void SortAlgorithm::quickSort(std::vector<int>& unsortedVector, int leftElement, int rightElement)
{
	int q;
	if (leftElement < rightElement)
	{
		q = partition(unsortedVector, leftElement, rightElement); 
		quickSort(unsortedVector, leftElement, q); 
		quickSort(unsortedVector, q + 1, rightElement); 
	}
}

int SortAlgorithm::partition(std::vector<int>& unsortedVector, int leftElement, int rightElement)
{
	int x = unsortedVector[leftElement]; 
	int i = leftElement, j = rightElement, w; 
	while (true) 
	{
		while (unsortedVector[j] > x) 
			j--;
		while (unsortedVector[i] < x) 
			i++;
		if (i < j) 
		{
			w = unsortedVector[i];
			unsortedVector[i] = unsortedVector[j];
			unsortedVector[j] = w;
			i++;
			j--;
		}
		else 
			return j;
	}
}

void SortAlgorithm::selectionSort(std::vector<int>& unsortedVector)
{
	int temp;
	for(int i = 0; i < unsortedVector.size() - 1; i++) {
		temp = i;   
		for(int j = i+1; j < unsortedVector.size(); j++)
			if(unsortedVector[j] < unsortedVector[temp])
				temp = j;
		std::swap(unsortedVector[i], unsortedVector[temp]);
	}
}

void SortAlgorithm::print(std::vector<int>& unsortedVector)
{
	std::cout << "Vector elements: \n";

	for(int i = 0; i < unsortedVector.size(); ++i)
	{
		std::cout << unsortedVector.at(i) << " ";
	}
	std::cout << std::endl;
}
