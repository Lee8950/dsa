#include <bits/stdc++.h>

class finite_machine{
public:
	finite_machine():status(0){};
	bool input(char c, int *nums, int &nums_length)
	{
		if(c == '[')
		{
			status = 1;
			return true;
		}
		if(status == 0)
			return true;
		else if(status == 1)
		{
			if(c != ',' && c != ' ' && c != ']')
				nums[nums_length] = nums[nums_length] * 10 + c - '0';
			else if(c == ']' || c == ',')
				nums_length++;
			else
				return true;
			return true;
		}
	}
private:
	int status;
};

class Solution{
public:
	static int Solve(int *nums, int nums_length){
		bool *bucket = new bool[1000000005];
		memset(bucket,0,sizeof(bool)*1000000005);
		int max = 0;
		int last_not_zero = -1;
		int max_num = -1;
		for(int i = 0; i < nums_length; i++){
			bucket[nums[i]] = true;
			max_num = nums[i] > max_num ? nums[i] : max_num;
		}
		for(int i = 0; i <= max_num+1; i++)
		{
			if(last_not_zero==-1&&bucket[i])
				last_not_zero = i;
			else if(bucket[i]){
				max = (i - last_not_zero) > max ? (i - last_not_zero) : max;
				last_not_zero = i;
			}
		}
		delete[] bucket;
		return max;
	}
};

int main()
{
	/*Input*/
	finite_machine input;
	std::string tmp;
	std::getline(std::cin, tmp);
	int nums[10005] = {0};
	int nums_length=0;
	for(auto &i:tmp)input.input(i,nums,nums_length);
	
	if(nums_length<2)std::cout << 0;
	else
	{//process start
		std::cout << Solution::Solve(nums,nums_length);
	}
	return 0;
}
