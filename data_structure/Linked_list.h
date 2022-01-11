#pragma once
class My_LinkedList
{
private:
	struct Node  
	{
		int val;
		Node*next;
		Node(int x):val(x),next(nullptr){}
	};
	int m_size;
	Node* m_head;
public:
	My_LinkedList();

	//获取列表index节点的数值
	int get(int index);
	//链表前插
	void AddAtHead(int n);
	//链表后插
	void AddAtTail(int n);
	//在index前插入
	void AddBeforeIndex(int index,int n);
	//删除index节点
	void DeleteAtIndex(int index);
	//打印链表
	void PrintList();
};



