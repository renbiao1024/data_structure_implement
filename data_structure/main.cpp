#include "Linked_list.h"
#include <iostream>
int main()
{	
//µ¥Á´±í
	//****************************************
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
	//******************************************/


}