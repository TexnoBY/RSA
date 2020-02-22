#include <iostream>
#include "Key.h"
#include <vector>
#include <string>
namespace RSA
{
	const std::vector<int> code(const std::string &line, const Key &key)
	{
		std::vector<int> coded;
		for (size_t i = 0; i < line.size(); i++)
		{

		}
	}

	int mod(int number, const Key &key)
	{

	}
}
int main()
{
	Key k1(3, 7);
	std::cout << k1.get_e() << " " << k1.get_n() << std::endl;
	std::cout << k1.get_d() << " " << k1.get_n() << std::endl;

	return 0;
}