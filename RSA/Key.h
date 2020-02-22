#pragma once

#include <vector>

class Key
{
private: 
	unsigned long int e;
	unsigned long long int n;
	unsigned long int d;
public:
	Key(long int p, long int q);
	long int get_e();
	long long int get_n();
	long int get_d();
};

