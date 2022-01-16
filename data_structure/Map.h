#pragma once
#include "RBTree.h"

template<class K,class V>
struct MapKeyOfValue
{
	K operator()(const V&kv){return kv.first;}
};

template <class K,class V,class KeyOfValue = MapKeyOfValue<K,pair<K,V>>>
class Map {
public:
	typedef typename RBTree<K,pair<K,V>,KeyOfValue>::Iterator Iterator;
	Iterator Begin() { return _s.Begin(); }
	Iterator End() { return _s.End() ;}
	Iterator rBegin() { return _s.rBegin(); }
	Iterator rEnd() { return _s.rEnd(); }
	pair<Iterator, bool> Insert(const pair<K,V>& value) { return _s.Insert(value); }
	V&operator[](const K& key)
	{
		pair<Iterator,bool>ret = _s.Insert(make_pair(key,V()));
		return ret.first->second;
	}
private:
	RBTree<K,pair<K,V>,KeyOfValue> _s;
};