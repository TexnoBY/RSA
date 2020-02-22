#include <iostream>
#include "Key.h"
#include <vector>
#include <string>
namespace RSA
{
	int mod(int number, int power, int base);
	const std::vector<int> code(std::string& line, Key& key);
	const std::string uncode(std::vector<int>& coded, Key& key);

	const std::vector<int> code(std::string &line,  Key &key)
	{
		std::vector<int> coded;
		int temp;
		for (auto var : line)
		{
			temp = mod(var, key.get_e(), key.get_n());
			coded.push_back(temp);

		}

		return coded;
	}

	const std::string uncode(std::vector<int>& coded, Key& key)
	{
		std::string line;
		

		for (auto var : coded)
		{
			line += char(mod(var, key.get_e(), key.get_n()));
		}
		return line;
	}

	int mod(int number,  int power, int base)
	{
		std::vector<int> multipliers;
		
		
		while (power != 1)
		{
			if (number == 0 || number == 1) break;
			if(number < base) 
				if (power % 2 == 0)
				{
					number *= number;
					power /= 2;
				}
				else
				{
					multipliers.push_back(number);
					number *= number;
					power /= 2;
				}
			number %= base;
		}
		int answer = number;
		for (size_t i = 0; i < multipliers.size(); i++)
		{
			answer *= multipliers[i];
			answer %= base;
		}
		return answer;
	}
}
int main()
{
	Key k1(37, 73);
	std::string example;
	std::getline(std::cin, example);
	
	
	std::cout << "e = " << k1.get_e() << " d = " << k1.get_d() << " n = " <<k1.get_n()<< std::endl;
	for (auto var : example)
	{
		std::cout << int(var) << " ";
	}
	std::cout << std::endl;
	auto code = RSA::code(example, k1);
	for (auto var : code)
	{
		std::cout << var << " ";

	}
	std::cout << std::endl;
	auto line = RSA::uncode(code, k1);
	for (auto var : line)
	{
		std::cout << var << " ";

	}
	std::cout << std::endl;
	std::cout << line;
	return 0;
}