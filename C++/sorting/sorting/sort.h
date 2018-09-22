#pragma once
#include <vector>
#include <string>

class Sort 
{
private:
	std::vector<int> vec;
	
public:
	Sort(int size) 
	{
		vec = std::vector<int>(size);
		for (int i = 0; i < vec.size(); i++)
			vec[i] = rand() % vec.size() + 1;
	}
	Sort()
	{
		vec = std::vector<int>(0);
	}
	
	//GETTERS
	std::vector<int> const getVector(void) { return vec; }		
	int const getElement(int i) { return vec[i]; }	
	std::string getVecToString(void)
	{
		std::string str = "[";
		for (int i = 0; i < vec.size(); i++)
		{
			str += std::to_string(vec[i]) + ", ";
		}
		return str + "]";
	}
	int const getVecSize(void) { return vec.size(); }
	//SETTERS
	void setVector(std::vector<int> newvec) { vec = newvec; }
	void setRandomVector(int size) 
	{
		std::vector<int> temp(size);
		for (int i = 0; i < size; i++) 
		{
			temp[i] = rand();

		}
		vec = temp;
	}
	
	
	
	

	//SORTING ALGORITHMS
	void bubbleSort(void);
	void selectionSort(void);
	void quickSort(int leftBound, int rightBound); //because of it's recursive nature quickSort has to take parameters for the left bound and right bound.

	//HELPERS
	bool sorted(std::vector<int> const& vec); //checks to see if the provided vector is sorted or not
    void swapElements(std::vector<int>& nums, int const small, int const large); //swaps 2 elements within a vector
	int const partition(int leftBound, int rightBound, int pivot); //helper method for quicksort, partitions the vector into 2 sides.
	
	//TESTERS
	/*
		these methods are purely for convienience measuring the time in seconds 
		it takes for an array to be sorted
	*/
	static std::string testBubbleSort(int size);
	static std::string testQuickSort(int size);
	static std::string testSelectionSort(int size);
};
