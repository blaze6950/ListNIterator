#include <iostream>
#include <list>
#include <string>


using namespace std;



template<typename T>
void print(list<T>& l)
{
	for (auto el : l)
	{
		cout << el << "\t";
	}
	cout << endl;
}
//void print(list<string> l)
//{
//	list<string>::iterator it = l.begin();
//	for (; it != l.end(); it++)
//	{
//		cout <<  << endl;
//	}
//}

bool men_fiveHundred(const int& value) { return (value>500); }
bool same_integral_part(string first, string second){	return (first == second);}

int srednee(list<int>& l)
{
	int res = 0;
	auto it_list = l.begin();
	for (; it_list != l.end(); it_list++)
	{
		res += *it_list;
	}
	return (res / 10);
}
int last_otr(list<int>& l)
{
	auto it = l.rbegin();
	for (; it != l.rend(); it++)
	{
		if (*it < 0)
		{
			return *it;
		}
	}
}
int max_num(list<int>& l)
{
	int buf = 0;
	auto it = l.begin();
	for (; it != l.end(); it++)
	{
		if (*it > buf)
		{
			buf = *it;
		}
	}
	return buf;
}
int min_num(list<int>& l)
{
	auto it = l.begin();
	int buf = *it;
	for (; it != l.end(); it++)
	{
		if (*it < buf)
		{
			buf = *it;
		}
	}
	return buf;
}

void first_ex()
{

	list<int> l(20);
	list<int>::iterator it = l.begin();
	for (; it != l.end(); it++)
	{
		*it = rand() % 1000;
	}
	print(l);
	l.remove_if(men_fiveHundred);
	cout << "===============================================================================\n";
	print(l);
}

void second_ex()
{
	list<string> lb1 = { "asasa", "adfasfsda", "asdfasdfdsf", "asdfdsgbfbsw" };
	list<string> lb2 = { "asasa", "adfasfsda", "asdfasdfdsf", "asdfdsgbfbsw", "zxcvczxvxzv", "mfgmnfgmfdngf" };
	list<string> lb3;
	lb3.assign(lb1.begin(), lb1.end());
	lb3.insert(lb3.end(), lb2.begin(), lb2.end());
	lb3.sort();
	lb3.unique(same_integral_part);
	print(lb3);
	/*list<char>::iterator it1 = lb1.begin();
	list<char>::iterator it2 = lb2.begin();
	for (; it1 != lb1.end(); it1++)
	{
	*it1 = rand() % 1000;
	}
	for (; it2 != lb2.end(); it2++)
	{
	*it2 = rand() % 1000;
	}*/
}

void third_ex()
{
	list<int> list1(10);
	list<int>::iterator it_list = list1.begin();
	for (; it_list != list1.end(); it_list++)
	{
		*it_list = -50 + rand() % 101;
	}


	for (; it_list != list1.end(); it_list++)
	{
		if (*it_list == 0)
		{
			*it_list = srednee(list1);
		}
	}


	for (; it_list != list1.end(); it_list++)
	{
		*it_list += last_otr(list1);
	}


	for (; it_list != list1.end(); it_list++)
	{
		if (*it_list > 0)
		{
			*it_list = max_num(list1);
		}
	}

	int flag = 0;
	for (; it_list != list1.end(); it_list++)
	{
		if (*it_list > 0)
		{
			if (flag == 1)
			{
				*it_list = (min_num(list1) / 2);
				flag = 0;
			}
			else{
				flag++;
			}
		}
	}


	for (auto it = list1.begin(); it != list1.end(); it++)
	{
		if (*it % 2 == 0)
		{
			*it = max_num(list1) - min_num(list1);
		}
	}
}

void main()
{
	//first_ex();
	//second_ex();
	third_ex();
}