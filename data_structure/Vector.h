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
	//构造函数
	//vector():_start(nullptr),_finish(nullptr),_endofstorage(nullptr){}
	vector() = default;//生成默认构造
	//析构函数
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
					tmp[i] = _start[i];//开辟一块新的地方存储
				}
			}
			_start = tmp;
			_finish = _start + size;
			_endofstorage = _start + n;
		}
	}

	//拷贝构造
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
			size_t newCapacity = Capacity() == 0?2:Capacity()*2;//翻倍扩容，空间换时间
			Reverse(newCapacity);
			pos = _start + posindex;
		}
		iterator end = _finish;
		while (end > pos)//后面的成员都后移，所以vector不适合插入删除
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
		assert(Size()>0);//判断空
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

	void Resize(size_t n , const T& value = T())//T() 调用对应类型的构造函数
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
