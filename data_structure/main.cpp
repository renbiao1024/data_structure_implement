//#include "Linked_list.h"
//#include "Vector.h"
#include "Stack.h"

int main()
{	
//µ¥Á´±í
/*
	My_LinkedList * l1 = new My_LinkedList();
	l1->PrintList();
	l1->AddAtHead(2);
	l1->PrintList();
	l1->AddAtTail(4);
	l1->PrintList();
	l1->AddAtHead(1);
	l1->PrintList();
	l1->AddAtTail(5);
	l1->PrintList();
	l1->AddBeforeIndex(2,3);//1,2,3,4,5
	l1->PrintList();
	std::cout<<l1->get(3);
*/

//vector
/*
using namespace My_vector;
	vector<int>v;
	v.Push_back(1);
	v.Push_back(2);
	v.Push_back(3);//123
	vector<int>::iterator pos = find(v.begin(),v.end(),3);//pos = 2
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	v.Insert(pos,4);//1243
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	pos = find(v.begin(),v.end(),4);
	vector<int>::iterator ret = v.Eraser(pos-1);//143
	vector<int>::const_iterator cit = v.cbegin();
	while (cit != v.cend())
	{
		cout<<*cit<<" ";
		++cit;
	}
	cout<<endl;
*/

//Stack
/*
	using namespace My_Stack;
	std::vector<int> arr = {1,2,3,4};
	Stack<int>tStack(12);
	tStack.init(arr);
	tStack.print_elems();
	cout << endl;
	tStack.push(5);
	tStack.print_elems();
	cout << endl;
	int x;
	tStack.pop(x);
	tStack.print_elems();
	cout << endl;
	tStack.print_elem(2);
	std::cout<<"isFull?:"<<tStack.full()<<" isEmpty? :"<<tStack.empty()<<endl;
	tStack.clear();
	tStack.print_elems();
	cout << endl;
*/
	return 0;
}