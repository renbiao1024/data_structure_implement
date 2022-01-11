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

	//��ȡ�б�index�ڵ����ֵ
	int get(int index);
	//����ǰ��
	void AddAtHead(int n);
	//������
	void AddAtTail(int n);
	//��indexǰ����
	void AddBeforeIndex(int index,int n);
	//ɾ��index�ڵ�
	void DeleteAtIndex(int index);
	//��ӡ����
	void PrintList();
};



