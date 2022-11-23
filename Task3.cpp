#include <bits/stdc++.h>

class finite_machine{
public:
	finite_machine():status(0){};
	bool input(char c, int *nums, int &nums_length, int &k)
	{
		if(c == '[')
		{
			status = 1;
			return true;
		}
		else if(c == 'k')
		{
			status = 2;
			return true;
		}
		if(status == 0)
			return true;
		else if(status == 1)
		{
			if(c != ',' && c != ' ' && c != ']')
				nums[nums_length] = nums[nums_length] * 10 + c - '0';
			else if(c == ',')
				nums_length++;
			else
				return true;
			return true;
		}
		else if(status == 2)
		{
			if(c == ' ' || c == '=' || c == ',')
				return true;
			else if(c >= '0' && c <= '9')
				k = k * 10 + c - '0';
			else if(c == '\0')
				return false;
			return true;
		}
	}
private:
	int status;
};
struct data{
	int id;
	int times;
};
data getData(int i, int t)
{
	data tmp;
	tmp.id = i;
	tmp.times = t;
	return tmp;
}
bool cmp(data &a, data &b)
{
	return a.times>b.times;
}

int main()
{
	/*Input*/
	finite_machine input;
	std::string tmp;
	std::getline(std::cin, tmp);
	int nums[10005] = {0};
	int nums_length=0, k=0;
	for(auto &i:tmp)input.input(i,nums,nums_length,k);
	data base[10005];
	memset(base,0,sizeof(base));
	for(int i = 0; i < 10005; i++)
		base[i].id = i;
		
	//Data: nums = [1,1,1,2,2,3], k = 2
	// nums = [1], k = 1
	for(int i = 0; i < nums_length; i++)
	{
		base[nums[i]].times++;
	}
	std::sort(base, base+10005, cmp);
	std::cout << '[';
	for(int i = 0; i < k; i++)
	{
		std::cout << base[i].id;
		if(i!=k-1)
			std::cout << ',';
	}
	std::cout << ']';
	return 0;
}
