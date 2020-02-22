#include "Key.h"


Key::Key(long int p, long int q)
{
	n = p * q;
	long long int phi = (p - 1) * (q - 1);
	
	std::vector<char> prime(phi + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= phi; ++i)
		if (prime[i])
			if (i * 1ll * i <= phi)
				for (int j = i * i; j <= phi; j += i)
					prime[j] = false;

	for (auto i = prime.size() - 1; i > 0; i--)
	{
		if (prime[i]) 
		{
			e = i;
			break;
		}
	}

	int temp = 1;
	while (1)
	{
		if (((temp * phi + 1) % e == 0) && (temp * phi + 1 != e * e))
		{
			d = (temp * phi + 1) / e;
			break;
		}
		temp++;
	}
	
	d = (temp * phi + 1) / e;
}

long int Key::get_e()
{
	return e;
}

long long int Key::get_n()
{
	return n;
}

long int Key::get_d()
{
	return d;
}
