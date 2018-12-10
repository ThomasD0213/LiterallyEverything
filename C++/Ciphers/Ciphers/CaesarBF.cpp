#include "CaesarBruteForce.h"
#include <algorithm>
#include <iostream>
#include <string>

std::string CaesarBF::bruteForce() 
{
	thing.tableInit();
	std::vector<char> alpha = thing.getTable()[0];
	int symbolIndex;
	int translatedIndex;
	std::vector<std::string> keys(alpha.size(), NULL);

	for (int i = 0; i < alpha.size(); i++) 
	{
		for (char symbol : alpha) 
		{
			if (std::binary_search(alpha.begin(), alpha.end(), symbol)) 
			{
				symbolIndex = std::distance(alpha.begin(), std::find(alpha.begin(), alpha.end(), symbol));
				translatedIndex = symbolIndex - i;

				if (translatedIndex < 0) 
				{
					translatedIndex = translatedIndex + alpha.size();
					keys[i] += alpha[translatedIndex];
				}

			}
			else 
			{
				keys[i] += symbol;
			}
		}
		std::cout << keys[i] << std::endl;
	}
	return translated;
}
