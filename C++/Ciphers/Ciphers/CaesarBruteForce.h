#pragma once
#include "cipher.h"
class CaesarBF 
{
private:
	Cipher thing;
	std::string translated;
	std::string message;
public:
	CaesarBF(std::string _message) 
	{
		translated = "";
		message = _message;
	}
	std::string bruteForce();
	std::string smartForce(); 
};