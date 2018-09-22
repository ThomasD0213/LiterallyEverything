#pragma once
#include <iostream>
#include <vector>
#include <string>

class Palindrome 
{
private:
	std::vector<int> vec;
public:
	Palindrome(int size) { vec = std::vector<int>(size); }
	Palindrome(std::string str) 
	{ 
		vec = std::vector<int>(str.length());
		for (int i = 0; i < str.length(); i++)
		{
			vec[i] = static_cast<int>(str[i]);
		}
	}
	~Palindrome() {};
	std::vector<int> const getVec() { return vec; }
	void setVec(std::vector<int> _vec) { vec = _vec; }
	bool const solver(void);

	std::string const solver(int arbitrary);

};