#include "cipher.h"
#include <string>
#include <iostream>

char Cipher::shift(std::vector<char> const& alpha, int element, int shift)
{
	return alpha[(element + shift) % alpha.size()];
}

void Cipher::tableInit()
{
	for (int row = 0; row < rows; row++) 
	{
		for (int col = 0; col < cols; col++) 
		{
			alphabet_table[row][col] = shift(upper_alphabet, col, row);
		}
	}
}

int Cipher::indexOf(char element) 
{
	for (int i = 0; i < upper_alphabet.size(); i++) 
	{
		if (upper_alphabet[i] == element)
			return i;
	}

	return -1;
}

std::string Cipher::encipher(std::string clear_text, std::string keyword) //message has to be in all caps
{
	std::string message = "";
	char key;
	char clear;
	int keyIndex = 0;
	for (int i = 0; i < clear_text.length(); i++) //row = keyword col = clear_text
	{
		key = keyword[keyIndex % keyword.length()];
		clear = (clear_text[i]);
		if (clear_text[i] == ' ') 
		{
			message += ' ';
			 //to counter act inserting a space
		}
		else 
		{
			message += alphabet_table[map[key]][map[clear]];
			keyIndex++;
		}


	}
	return message; 
}

std::string Cipher::decipher(std::string cipher_text, std::string keyword) 
{
	int keyIndex = 0;
	int firstcipher = 0;
	int firstkey = 0;
	int index = 0;
	std::string clear_text;
	for (char character : cipher_text) 
	{
		if (character != ' ')
		{

			firstcipher = this->indexOf(character);
			firstkey = this->indexOf(keyword[keyIndex % keyword.length()]);
			index = (firstcipher - firstkey < 0)? (firstcipher - firstkey) + 26 : firstcipher - firstkey;
			clear_text += upper_alphabet[index];
			keyIndex++;
		}
		else 
		{
			clear_text += " ";
		}
	}
	
	return clear_text;
}

void Cipher::tablePrintString(std::vector<std::vector<char>> const& alphabet_table) 
{
	for (int row = 0; row < alphabet_table.size(); row++) 
	{
		std::cout << "row: " << row << " [" << alphabet_table[row][0] << ", ";
		for (int col = 1; col < alphabet_table[row].size() - 1; col++) 
		{
			std::cout << alphabet_table[row][col] << ", "; 
		}
		std::cout << alphabet_table[row][alphabet_table[row].size() - 1] << "]" << std::endl;
	}
}

int main()
{
	Cipher thing;
	Cipher::tablePrintString(thing.getTable());
	std::string message = "THE MESSAGE IS ALSO THE KEY";
	std::string key = "THEMESSAGEISALSOTHEKEY";
	std::string enciphered = thing.encipher(message, key);
	std::cout << thing.encipher(message, key) << std::endl;
	std::cout << thing.decipher(enciphered, key) << std::endl;
}



