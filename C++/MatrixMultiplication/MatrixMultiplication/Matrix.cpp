#include <iostream>
#include "Matrix.h"


void Matrix::to_string() 
{
	int num = 0;
	for (matricies mat : vec) 
	{
		std::cout << "Matrix: " << num << std::endl;
		num++;
		for (int j = 0; j < mat.vec2d.size(); j++) 
		{
			for (int i = 0; i < mat.vec2d[j].size(); i++) 
			{
				std::cout << mat.vec2d[j][i] << " ";
			}
			std::cout << std::endl;
		}
	}
}

void Matrix::to_string(int matrix)
{
	int num = 0;
		std::cout << "Matrix: " << num << std::endl;
		num++;
		for (int j = 0; j < vec[matrix].vec2d.size(); j++)
		{
			for (int i = 0; i < vec[matrix].vec2d[j].size(); i++)
			{
				std::cout << vec[matrix].vec2d[j][i] << " ";
			}
			std::cout << std::endl;
		}
	
}

void Matrix::multiply() 
{
	//TODO Implement	
}

void Matrix::scale(int scaler) 
{
	for (matricies& mat : vec) 
	{
		for (int j = 0; j < mat.vec2d.size(); j++) 
		{
			for (int i = 0; i < mat.vec2d[j].size(); i++) 
			{
				mat.vec2d[j][i] *= scaler;
			}
		}

	}
}


void Matrix::divide(int matrix1, int matrix2) 
{
	
}

void Matrix::add(int matrix1, int matrix2) //matrix1 and matrix2 must have the same dimensions
{
	for (int j = 0; j < vec[matrix1].vec2d.size(); j++) 
	{
		for (int i = 0; i < vec[matrix1].vec2d[j].size(); i++) 
		{
			vec[matrix2].vec2d[j][i] += vec[matrix1].vec2d[j][i];
		}
	}
}

void Matrix::subtract(int matrix1, int matrix2) //matrix1 and matrix2 must have the same dimensions
{
	for (int j = 0; j < vec[matrix1].vec2d.size(); j++) 
	{
		for (int i = 0; i < vec[matrix1].vec2d[j].size(); i++) 
		{
			vec[matrix1].vec2d[j][i] -= vec[matrix2].vec2d[j][i];
		}
	}
}

void Matrix::setVals(int max) 
{
	//TODO Implement
}

void Matrix::rotateLeft(int matrixIndex) 
{
	std::vector<std::vector<int>>* pvec = &vec[matrixIndex].vec2d;
	std::vector<std::vector<int>> copy = vec[matrixIndex].vec2d;
	pvec->resize(copy[0].size());
	for (int i = 0; i < pvec->size(); i++) { pvec->at(i).resize(copy.size()); }
	
	for (int j = copy[0].size() - 1; j >= 0; j--) 
	{
		int copyindex = copy[0].size() - 1 - j;
		for (int i = 0; i < copy.size(); i++) 
		{
			pvec->at(j).at(i) = copy[i][copyindex];			
		}
	}
	pvec = nullptr;
	delete pvec;	
}

void Matrix::rotateRight(int matrixIndex) 
{
	std::vector<std::vector<int>>* pvec = &vec[matrixIndex].vec2d;
	std::vector<std::vector<int>> copy = vec[matrixIndex].vec2d;
	pvec->resize(copy[0].size());
	for (int i = 0; i < pvec->size(); i++) { pvec->at(i).resize(copy.size()); }

	for (int j = 0; j < copy[0].size(); j++)
	{
		for (int i = copy.size() - 1; i >= 0; i--)
		{
			pvec->at(j).at(i) = copy[copy.size() - 1 - i][j];
		}
	}
	pvec = nullptr;
	delete pvec;
}

int main()
{
	Matrix mat;
	mat.to_string();
	mat.subtract(0, 1);
	mat.to_string();
	std::cin.get();

}