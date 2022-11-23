#include <bits/stdc++.h>

class finite_machine{
public:
	finite_machine():status(0){};
	bool input(char c, int *nums, int &nums_length, int &k, int &t)
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
		else if(c == 't')
		{
			status = 3;
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
		else if(status == 3)
		{
			if(c == ' ' || c == '=' || c == ',')
				return true;
			else if(c >= '0' && c <= '9')
				t = t * 10 + c - '0';
			else if(c == '\0')
				return false;
			return true;
		}
	}
private:
	int status;
};

struct data{
	int data;
	int mark;
};

data getData(int d, int m)
{
	data tmp;
	tmp.data = d;
	tmp.mark = m;
	return tmp;
}
bool cmp(data &a, data &b)
{
	return a.mark < b.mark;
}
class bucket{
private:
	std::vector<data> *b;
	int t;
	int k;
	int size;
public:
	bucket(){}
	bucket(int size_, int t_, int k_):t(t_),k(k_),size(size_){b = new std::vector<data>[size_/t_+2];}
	void con(int size_, int t_, int k_){t=t_;k=k_;size=size_;b = new std::vector<data>[size_/t_+2];}
	bool judge(data num)
	{
		b[num.data/t].push_back(num);
		std::sort(b[num.data/t].begin(),b[num.data/t].end(),cmp);
		for(int i = 1; i < b[num.data/t].size(); i++)
			if(abs(b[num.data/t][i].mark-b[num.data/t][i-1].mark)<=k)
				return true;
		if(num.data/t+1<size/t+1)
			if(!b[num.data/t+1].empty())
			{
				for(auto i = b[num.data/t+1].begin(); abs(i->mark-num.mark)<=k&&i!=b[num.data/t+1].end(); i++)
					if(abs(i->data-num.data)<=t)
						return true;
			}
		if(num.data/t-1>=0)
			if(!b[num.data/t-1].empty())
			{
				for(auto i = b[num.data/t-1].end(); abs(i->mark-num.mark)<=k&&i!=b[num.data/t-1].begin(); i--)
					if(abs(i->data-num.data)<=t)
						return true;
			}
		return false;
	}
};

int main()
{
	/*Input*/
	finite_machine input;
	std::string tmp;
	std::getline(std::cin, tmp);
	int nums[20005] = {0};
	int nums_length=0, k=0, t=0;
	for(auto &i:tmp)input.input(i,nums,nums_length,k,t);
	
	// Data:
	// nums = [1,2,3,1], k = 3, t = 0
	// nums = [1,5,9,1,5,9], k = 2, t = 3
	bucket solve;
	if(t==0)
		solve.con(nums_length, t+1, k);
	else
		solve.con(nums_length, t, k);
	for(int i = 0; i < nums_length; i++)
	{
		if(solve.judge(getData(nums[i],i)))
		{
			std::cout << "True";
			return 0;
		}
	}
	std::cout << "False";
	return 0;
}
