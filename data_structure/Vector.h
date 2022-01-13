#pragma once

#include<iostream>
#include <assert.h>

using namespace std;
namespace My_vector {

template<class T>
class vector {

public:
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator cbegin()const
	{
		return _start;
	}
	const_iterator cend()const
	{
		return _finish;
	}
	//���캯��
	//vector():_start(nullptr),_finish(nullptr),_endofstorage(nullptr){}
	vector() = default;//����Ĭ�Ϲ���
	//��������
	~vector()
	{
		if (_start)
		{
			delete []_start;
			_start = _finish = _endofstorage = nullptr;
		}
	}

	size_t Size()const
	{
		return _finish - _start;
	}

	size_t Capacity()const
	{
		return _endofstorage - _start;
	}

	void Reverse(size_t n)
	{
		if (n > Capacity())
		{
			size_t size = Size();
			T* tmp = new T[n];
			if (_start)
			{
				for (size_t i = 0; i < size; ++i)
				{
					tmp[i] = _start[i];//����һ���µĵط��洢
				}
			}
			_start = tmp;
			_finish = _start + size;
			_endofstorage = _start + n;
		}
	}

	//��������
	vector(const vector<T>&v):_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
	{
		Reverse(v.Capacity());
		iterator it = begin();
		const_iterator vit  = v.cbegin();
		while(vit!=v.cend()) *it++ = *vit++;
		_finish = _start +v.Size();
		_endofstorage = _start +v.Capacity();
	}

	vector<T>& operator = (vector<T>v)
	{
		this->Swap(v);
		return *this;
	}

	void Swap(vector<T>&v)
	{
		std::swap(_start,v._start);
		std::swap(_finish,v._finish);
		std::swap(_endofstorage,v._endofstorage);
	}

	void Insert(iterator pos,const T&x)
	{
		assert(pos<=_finish);
		size_t posindex = pos - _start;
		if (_finish == _endofstorage)
		{
			size_t newCapacity = Capacity() == 0?2:Capacity()*2;//�������ݣ��ռ任ʱ��
			Reverse(newCapacity);
			pos = _start + posindex;
		}
		iterator end = _finish;
		while (end > pos)//����ĳ�Ա�����ƣ�����vector���ʺϲ���ɾ��
		{
			*end = *(end - 1);
			--end;
		}
		*pos = x;
		++_finish;
	}

	void Push_back(const T&x)
	{
		Insert(end(),x);
	}

	void Pop_back()
	{
		assert(Size()>0);//�жϿ�
		--_finish;
	}

	iterator Eraser(iterator pos)
	{
		iterator begin = pos;
		while (pos != _finish)
		{
			*pos = *(pos+1);
			++pos;
		}
		--_finish;
		return begin;
	}

	void Resize(size_t n , const T& value = T())//T() ���ö�Ӧ���͵Ĺ��캯��
	{
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			if(n>Capacity())
				Reverse(n);
			while (_finish != _start + n)
			{
				*_finish =value;
				++_finish;
			}
		}
	}

	T& operator [](size_t pos)
	{
		assert(pos<Size());
		return _start[pos];
	}
private:
	iterator _start = nullptr;
	iterator _finish = nullptr;
	iterator _endofstorage = nullptr;
};

}
