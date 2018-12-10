#include <vector>
#include <string>
#include <random>
#pragma once
class Matrix 
{
private:
	struct matricies
	{
		std::vector<std::vector<int>> vec2d;
	};
	
	std::vector<matricies> vec;
public:
	Matrix() //Default constructor creates two 2 x 3 matricies with random values between 1 and 100 as the elements 
	{
		matricies m1;
		matricies m2;
		m1.vec2d.resize(2);
		m2.vec2d.resize(2);						
		for (int i = 0; i < m1.vec2d.size(); i++) 
		{
			m1.vec2d[i].resize(3);
			m2.vec2d[i].resize(3);
		}
												
		std::cout << "m1 size: " << m1.vec2d.size() << std::endl;
		std::cout << "m2 size: " << m2.vec2d.size() << std::endl;
		std::cout << "m1.vec2d size: " << m1.vec2d.size() << std::endl;
		std::cout << "m2.vec2d size: " << m2.vec2d.size() << std::endl;

		for (int j = 0; j < m1.vec2d.size(); j++) 
		{
			for (int i = 0; i < m1.vec2d[j].size(); i++) 
			{
				m1.vec2d[j][i] = rand() % 100 + 1;
				m2.vec2d[j][i] = rand() % 100 + 1;
			}
		}
		vec.push_back(m1);
		vec.push_back(m2);
		std::cout << vec.size() << std::endl;
	}
	

	~Matrix() {};
	void setVals(int max);
	void multiply();
	void divide(int matrix1, int matrix2);
	void add(int matrix1, int matrix2);
	void subtract(int matrix1, int matrix2); //subtracts matrix2 from matrix1
	void rotateRight(int matrixIndex); //rotates a matrix by 90 degrees right
	void rotateLeft(int matrixIndex); //rotates a matrix by 90 degrees left
	void scale(int scaler);
	void to_string(); //should probably return a string but whatever it just prints it out 
	void to_string(int matrix); //does the same as above but you can choose which matrix to print out

};