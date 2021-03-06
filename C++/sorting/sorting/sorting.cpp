
#include "sort.h"
#include <iostream>
#include <ctime>
#include <windows.h>
int count = 0;
std::vector<int> myVec = { 0, 5, 2, 1 }; //used for testing purposes
float const TICKS = CLOCKS_PER_SEC;
Sort thing(1000);


std::string Sort::testQuickSort(int size)
{

	thing.setRandomVector(size);
	clock_t before;
	before = clock();
	thing.quickSort(0, thing.getVecSize() - 1);
	clock_t after = clock();
	float elapsedTime = (after - before) / TICKS;
	
	return "Type: QuickSort     Time Elapsed: " + std::to_string(elapsedTime) + " second(s)";
}

std::string Sort::testBubbleSort(int size)
{

	thing.setRandomVector(size);
	clock_t before;
	before = clock();
	thing.bubbleSort();
	clock_t after = clock();
	float elapsedTime = (after - before) / TICKS;
	return "Type: BubbleSort     Time Elapsed: " + std::to_string(elapsedTime) + " second(s)";
}

std::string Sort::testSelectionSort(int size)
{
	thing.setRandomVector(size);
	clock_t before;
	before = clock();
	thing.selectionSort();
	clock_t after = clock();
	float elapsedTime = (after - before) / TICKS;
	return "Type: SelectionSort     Time Elapsed: " + std::to_string(elapsedTime) + " second(s)";
}

void Sort::bubbleSort()
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int x = 0; x < vec.size(); x++)
		{
			if (vec[i] < vec[x])
				swapElements(vec, x, i);
		}
	}
}

void Sort::quickSort(int leftBound, int rightBound) //Implement a working version of this eventually
{
	if (leftBound >= rightBound)
		return;
	int pivot = vec[(leftBound + rightBound) / 2];
	int index = partition(leftBound, rightBound, pivot);
	quickSort(leftBound, index - 1);
	quickSort(index, rightBound);

	
}

// helper method for quicksort
int const Sort::partition(int leftBound, int rightBound, int pivot) 
{
	while (leftBound <= rightBound) 
	{
		while (vec[leftBound] < pivot)
			leftBound++;
		
		while (vec[rightBound] > pivot)
			rightBound--;
		
		if (leftBound <= rightBound) 
		{
			swapElements(vec, leftBound, rightBound);
			leftBound++;
			rightBound--;
		}

	}
	return leftBound;
}  

void Sort::selectionSort()
{
	int temp = 0;
	for (int i = 0; i < vec.size() - 1; i++) //should always coincide with lowest number within the range ex: i = 1 & arr = {0, 1, 4, 3} at the end arr[i] should equal 1
	{
		int smallestIndex = i;
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[j] < vec[smallestIndex])
			{
				smallestIndex = j;
			}
		}
		swapElements(vec, i, smallestIndex);
	}
}


bool Sort::sorted(std::vector<int> const& vec) 
{
	for (int i = 0; i < vec.size() - 1; i++) 
	{
		if (vec[i] > vec[i + 1])
			return false;
	}
	return true;
}
void Sort::swapElements(std::vector<int>& vec, int const first, int const second) //TODO throw exception with array size less than 2
{
	int temp = vec[first];
	vec[first] = vec[second];
	vec[second] = temp;

}