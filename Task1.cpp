#include <bits/stdc++.h>

int main()
{
	int n;
	std::cin >> n;
	int tmp;
	int a[51] = {0};
	for(int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		a[tmp]++;
	}
	for(int i = 0; i < 51; i++)
		if(a[i]!=0)
			std::cout << i << ':' << a[i] << std::endl;
	return 0;
}
