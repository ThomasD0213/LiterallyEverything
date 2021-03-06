
#include "palindrome.h"

int main()
{
	Palindrome pal(5);
	Palindrome pal2("This is a string that should return false");
	Palindrome pal3("1001001");
	Palindrome pal4("Step on no pets"); //although this is a palindrome it will not return true because of the capital
	Palindrome pal5("step on no pets");

	pal.solver(1);
	pal2.solver(1);
	pal3.solver(1);
	pal4.solver(1);
	pal5.solver(1);
	return 0;
	
}

bool const Palindrome::solver() 
{
	for (int i = 0; i < vec.size(); i++) 
	{
		if (vec[i] != vec[(vec.size() - 1) - i])
			return false;
	}

	return true;
}

std::string const Palindrome::solver(int arbitrary) 
{
	std::string str = "";
	for (int i = 0; i < vec.size(); i++) 
	{
		if (vec[i] != vec[(vec.size() - 1) - i])
			return "Is not a palindrome";
		else
			str += static_cast<char>(vec[i]);
	}
	std::cout << str << " is a palindrome" << std::endl;
	return str + " is a palindrome";
}


