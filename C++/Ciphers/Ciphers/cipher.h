#pragma once
#include <vector>
#include <map>
class Cipher {
private:
	int cols; //cols in alphabet_table
	int rows; //rows in alphabet_table
	std::vector<char> upper_alphabet; //this MUST be the same as lower_alphabet just different case. it's size is equal to cols
	std::vector<char> lower_alphabet; //this MUST be the same as upper_alphabet just different case. it's size is equal to cols
	std::vector<std::vector<char>> alphabet_table; //vigenere table, can be different tables depending on how the values are set
	std::map<char, int> map;
public:
	Cipher() 
	{
		cols = 26;
		rows = 26;
		char car;
		for (int i = 0; i < cols; i++)
		{
			upper_alphabet.push_back(i + 65); //65 is the ascii value of A
			lower_alphabet.push_back(i + 97); //97 is the ascii value of a
			car = i + 65;
			map.insert(std::pair<char, int>(car, i)); //throws error, fix this
		}
		
		
		for (int i = 0; i < rows; i++) 
		{
			alphabet_table.push_back(std::vector<char>(cols));
		}
		
		
		tableInit();
	}
	~Cipher() { };
	std::vector<std::vector<char>> getTable() { return alphabet_table; } //returns alphabet_table
	void tableInit(); //initializes alphabet_table based off of your upper_alphabet and shift
	std::string encipher(std::string clear_text, std::string keyword); //enciphers the message clear_text
	std::string decipher(std::string cipher_text, std::string keyword); //deciphers the cipher_text
	char shift(std::vector<char> const& alpha, int element, int shift); //returns shifted value of specified alphabet
	static void tablePrintString(std::vector<std::vector<char>> const& alphabet_table); //takes alphabet_table by const referance then prints out its contents 
	int indexOf(char element); //returns index of element in upper_alphabet  
};