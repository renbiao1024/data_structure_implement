//#include "Linked_list.h"
//#include "Vector.h"
//#include "Stack.h"
#include "Set.h"
#include "Map.h"
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

//Õ»
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

/*set
	Set<int>S;
	S.Insert(1);
	S.Insert(2);
	S.Insert(3);
	S.Find(3);

	Set<int>::Iterator it = S.Begin();
	while (it != S.End())
	{
		cout<<*it<< " ";
		++it;
	}
	cout<<endl;
*/
/*Map
	Map<int,int> m;
	m.Insert(make_pair(1,2));
	m.Insert(make_pair(2,3));
	m.Insert(make_pair(3,4));
	m.Insert(make_pair(4,5));
	m[5] = 6;
	auto i = m.Begin();
	while (i != m.End())
	{
		cout<<i->first<<" "<<i->second;
	}
	cout<<endl;
*/
	return 0;
}