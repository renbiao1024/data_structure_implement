#pragma once
#include "RBTree.h"

template<class K>
class Set
{
public:
	Set() = default;

	struct KeyOfValue
	{
		K operator()(const K& key) {return key;}
	};

	typedef typename RBTree<K,K,KeyOfValue>::Iterator Iterator;
	Iterator Begin() {return _s.Begin();}
	Iterator End(){return _s.End();}
	Iterator rBegin() {return _s.rBegin();}
	Iterator rEnd() {return _s.rEnd();}
	Iterator Find(const K& key){return _s.Find(key);}
	pair<Iterator,bool>Insert(const K& key) {return _s.Insert(key);}

private:
	RBTree<K,K,KeyOfValue>_s;
};