#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
namespace My_Stack
{ 

template <class T>
class Stack
{
public:
	Stack(unsigned int wMaxTmp = 0):wMax(wMaxTmp){vData.clear();}
	~Stack(){wMax = 0; vData.clear();}

	int init(vector<T>&vElem);
	bool empty();
	bool full();
	int push(T const &tElem);
	int pop(T &tElem);
	int clear();
	int print_elem(T const &Elem);
	int print_elems();

private:
	vector<T>vData;
	unsigned int wMax;
};

}

template <class T>
int My_Stack::Stack<T>::init(vector<T>&vElem)
{
	if (wMax < vElem.size()) return -1;
	for (auto it = vElem.begin(); it != vElem.end(); ++it)
	{
		push(*it);
	}
	return 0;
}

template <class T>
bool My_Stack::Stack<T>::empty()
{
	if (vData.size() == 0)
		return true;
	return false;
}

template <class T>
bool My_Stack::Stack<T>::full()
{
	if (vData.size() > wMax - 1)
		return true;
	return false;
}

template <class T>
int My_Stack::Stack<T>::push(T const &tElem)
{
	if (full())return -1;
	vData.push_back(tElem);
	return 0;
}

template <class T>
int My_Stack::Stack<T>::pop(T &tElem)
{
	if (empty()) return -1;
	tElem = vData.back();
	vData.pop_back();
	return 0;
}

template <class T>
int My_Stack::Stack<T>::print_elems()
{
	if (empty())
	{
		cout << "stack is empty" << " ";
		return 0;
	}
	for (auto it = vData.begin(); it != vData.end(); ++it)
	{
		print_elem(*it);
	}
	return 0;
}

template <class T>
int My_Stack::Stack<T>::print_elem(T const &Elem)
{
	if (empty())
	{
		cout << "stack is empty" << endl;
		return 0;
	}
	cout << "elem:" << Elem << " ";

	return 0;
}

template <class T>
int My_Stack::Stack<T>::clear()
{
	if (empty())
	{
		return 0;
	}
	vData.clear();
	return 0;
}
