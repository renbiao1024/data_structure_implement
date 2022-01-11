#include "Linked_list.h"
#include <iostream>


My_LinkedList::My_LinkedList()
{
	m_head = new Node(0);
	m_size = 0;
}

int My_LinkedList::get(int index)
{
	if(index>=m_size||index<0)return -1;
	Node*tmp = m_head->next;
	while (index--)tmp = tmp->next;
	return tmp->val;
}

void My_LinkedList::AddAtHead(int n)
{
	auto newNode = new Node(n);
	newNode->next = m_head->next;
	m_head->next = newNode;
	++m_size;
}

void My_LinkedList::AddAtTail(int n)
{
	auto newNode = new Node(n);
	auto curNode = m_head;
	while(curNode->next!=nullptr)
		curNode = curNode->next;
	curNode->next = newNode;
	++m_size;

}

void My_LinkedList::AddBeforeIndex(int index,int n)
{
	if(index>m_size || index < 0)return;
	auto curNode = m_head;
	auto newNode  = new Node(n);
	while (index--)
	{
		curNode = curNode->next;
	}
	newNode->next = curNode->next;
	curNode->next = newNode;
	++m_size;
}

void My_LinkedList::DeleteAtIndex(int index)
{
	if(index>m_size||index<0)return;
	auto curNode = m_head;
	while (index--)
	{
		curNode = curNode->next;
	}
	auto deleteNode = curNode->next;
	curNode->next = deleteNode->next->next;
	delete deleteNode;
	--m_size;
}

void My_LinkedList::PrintList()
{
	Node* curNode = m_head;
	while (curNode->next != nullptr)
	{
		curNode = curNode->next;
		std::cout<<curNode->val<<' ';
	}
	std::cout<<std::endl;
}