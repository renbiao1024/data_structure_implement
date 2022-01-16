#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
//rb-tree
enum Color
{
	RED,
	BLACK
};

template<class ValueType>
struct RBTreeNode
{
	RBTreeNode<ValueType>*_left;
	RBTreeNode<ValueType>*_right;
	RBTreeNode<ValueType>*_parent;
	ValueType _valueField;
	Color _col;
	RBTreeNode(const ValueType&v):_left(NULL),_right(NULL),_parent(NULL),_valueField(v),_col(RED){}
};

template<class ValueType>
class RBTreeIterator
{
public:
	typedef RBTreeNode<ValueType> Node;
	typedef RBTreeIterator<ValueType> Self;
	Node *_node;
	RBTreeIterator(Node*node):_node(node){}
	ValueType& operator*(){ return _node->_valueField;}
	ValueType* operator->() {return &(operator*());}
	Self& operator++()
	{
		if (_node->_right)
		{
			Node*leftLeft = _node->_right;
			while(leftLeft->_left) leftLeft = leftLeft->_left;
			_node = leftLeft;
		}
		else
		{
			Node*cur = _node;
			Node*parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		++(*this);
		return tmp;
	}
	Self operator--()
	{
		if (_node->_left)
		{
			Node* rightRight = _node->_left;
			while (rightRight->_right)
			{
				rightRight = rightRight->_right;
			}
			_node = rightRight;
		}
		else
		{
			Node* cur = _node;
			Node*parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Self operator--(int)
	{
		Self tmp(*this);
		--(*this);
		return tmp;
	}
	bool operator==(const Self&s)
	{
		return _node == s._node;
	}
	bool operator!=(const Self&s)
	{
		return _node!=s._node;
	}
};

template <class K,class ValueType,class KeyOfValue>
class RBTree
{
public:
	typedef RBTreeNode<ValueType> Node;
	typedef RBTreeIterator<ValueType> Iterator;
	RBTree():_root(NULL){}
	Iterator Begin()
	{
		Node*left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return Iterator(left);
	}
	Iterator End()
	{
		return Iterator(NULL);
	}

	Iterator rBegin()
	{
		Node*right = _root;
		while (right&&right->_right)
		{
			right = right->_right;
		}
		return right;
	}
	Iterator rEnd()
	{
		return NULL;
	}

	pair<Iterator, bool>Insert(const ValueType&v)
	{
		if (_root = NULL)
		{
			_root = new Node(v);
			_root->_col = BLACK;
			return make_pair(Iterator(_root),true);
		}
		KeyOfValue keyOfValue;
		Node*parent = NULL;
		Node*cur = _root;
		while (cur)
		{
			if (keyOfValue(cur->_valueField) > keyOfValue(v))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (keyOfValue(cur->_valueField)<keyOfValue(v))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(Iterator(cur),false);
			}
		}
		cur = new Node(v);
		Node* newNode = cur;
		if (keyOfValue(parent->_valueField) < keyOfValue(v))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		while (parent && parent->_col == RED)
		{
			Node*grandparent = parent->_parent;
			if (parent == grandparent->_left)
			{
				Node*uncle = grandparent->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col =BLACK;
					uncle->_col = BLACK;
					grandparent->_col = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent,cur);
					}
					RotateR(grandparent);
					parent->_col = BLACK;
					grandparent->_col = RED;
					break;
				}
			}
			else
			{
				Node*uncle = grandparent->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandparent->_col = RED;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent,cur);
					}
					RotateL(grandparent);
					parent->_col = BLACK;
					grandparent->_col = RED;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(Iterator(newNode), true);
	}

	Iterator Find(const K& key)
	{
		KeyOfValue keyOfValue;
		Node*cur = _root;
		while (cur)
		{
			if (keyOfValue(cur->_valueField) > key)
			{
				cur = cur->_left;
			}
			else if (keyOfValue(cur->_valueField) < key)
			{
				cur = cur->_right;
			}
			else
			{
				return Iterator(cur);
			}
		}
		return Iterator(NULL);
	}

	void RotateL(Node* parent)
	{
		Node*subR = parent->_right;
		Node*subRL = subR->_left;
		parent->_right = subRL;
		if(subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node*grandparent = parent->_parent;
		parent->_parent = subRL;
		if (grandparent == NULL)
		{
			_root = subRL;
			subR->_parent = NULL;
		}
		else
		{
			if (parent == grandparent->_left)
			{
				grandparent->_left = subR;
				subR->_parent = grandparent;
			}
			else
			{
				grandparent->_right = subR;
				subR->_parent = grandparent;
			}
		}
	}

	void RotateR(Node*parent)
	{
		Node* subL = parent->_left;
		Node*subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* grandparent = parent->_parent;
		parent->_parent = subL;
		if (grandparent == NULL)
		{
			_root = subL;
			_root->_parent = NULL;
		}
		else
		{
			if (parent == parent->_left)
			{
				grandparent->_left = subL;
				subL->_parent = grandparent;
			}
			else
			{
				grandparent->_right = subL;
				subL->_parent = grandparent;
			}
		}
	}
private:
	Node* _root;
};