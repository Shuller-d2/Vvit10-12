#pragma once
#pragma once
#include<initializer_list>
using namespace std;

template<typename LT>
class tlist
{
public:
	tlist();
	tlist(const tlist& tl);
	tlist(tlist&& tl);
	~tlist();
	//realizaciy spiskom
	tlist(initializer_list<LT> init) {
		init();
		for (const auto& item : init) {
			push_back(item);
		}
	}
	//constuction realizôcii masiom
	tlist(const LT* arr, int size) {
		init();
		for (int i = 0; i < size; ++i) {
			push_back(arr[i]);
		}
	}
	//operator prisvaivaniy s ispolyzovaniem copy
	tlist& operator=(const tlist& item) {
		if (this != &item) {
			copy(item);
		}
		return *this;
	}
	//operator prisvaivaniy s ispolyzovaniem move
	tlist& operator=(tlist&& item) {
		if (this != &item) {
			move(item);
		}
		return *this;
	}
	//Function print(vivod)
	void print() {
		titem* p = m_pFirst;
		cout << "Num:" << size() << " Data:";

		while (p) {
			cout << p->m_value << " ";
			p = p->m_pNext;
		}
		cout << endl;
	}

protected:
	struct titem
	{
		LT m_value;
		titem* m_pNext;
		titem()
		{
			m_value = LT(0);
			m_pNext = nullptr;
		};
	};
protected:
	titem* m_pFirst;
protected:
	void init();
	void destroy(titem* pi);
public:
	int push_back(LT val);
	int size(void);
	int copy(const tlist& tl);
	int move(tlist& tl);

	//lr11----------------------------------------
	class iterator
	{
		friend class tlist; 
	protected:
		titem* m_pItem;
	public:
		iterator() 
		{
			m_pItem = nullptr; 
		};
		iterator(const iterator& it) 
		{
			m_pItem = it.m_pItem;
		}
	protected:
		iterator(titem* p) 
		{
			m_pItem = p;
		};
	public:
		LT& operator*() 
		{
			return m_pItem->m_value;
		}
		iterator& operator++() 
		{
			m_pItem = m_pItem->m_pNext;
			return *this;
		}
		iterator operator++(int) 
		{
			iterator it(*this);
			m_pItem = m_pItem->m_pNext;
			return it;
		}
		iterator& operator=(const iterator& it) 
		{
			m_pItem = it.m_pItem;
			return *this;
		}
		bool operator==(const iterator& it) 
		{
			return (m_pItem == it.m_pItem ? true : false);
		}
		bool operator!=(const iterator& it) 
		{
			return (m_pItem != it.m_pItem ? true : false);

		};
	};
public:
	//ykazately na nachalo
	iterator begin() {
		return iterator(m_pFirst);
	}
	//ykazately na konec
	iterator end() {
		return iterator();
	}
	double operator()();
	double norma();
	//----------------------------------------
};
//Constryctor move
template <typename LT>
int tlist<LT>::move(tlist& tl) {
	if (this != &tl) {
		destroy(m_pFirst);
		m_pFirst = tl.m_pFirst;
		tl.init();
	}return size();
}

template<typename LT>
tlist<LT>::tlist()
{
	init();
}
template<typename LT>
tlist<LT>::tlist(const tlist<LT>& tl)
{
	init(); copy(tl);
}
template<typename LT>
tlist<LT>::tlist(tlist<LT>&& tl)
{
	init();
	move(tl);
}
template<typename LT>
tlist<LT>::~tlist()
{
	destroy(m_pFirst);
}
template<typename LT>
void tlist<LT>::init()
{
	m_pFirst = nullptr;
}
template<typename LT>
void tlist<LT>::destroy(titem* pi)
{
	titem* p;
	while (pi)
	{
		p = pi->m_pNext;
		delete pi;
		pi = p;
	}
}
template<typename LT>
int tlist<LT>::push_back(LT val)
{
	titem* pLast, * pNew;
	pNew = new titem;
	if (pNew)
	{
		if (m_pFirst)
		{
			pLast = m_pFirst;
			while (pLast->m_pNext)
			{
				pLast = pLast->m_pNext;
			}
			pLast->m_pNext = pNew;
		}
		else
		{
			m_pFirst = pNew;
		}
		pNew->m_value = val;
		return size() - 1;
	}
	return -1;
}
template<typename LT>
int tlist<LT>::size(void)
{
	titem* p; int s = 0;
	p = m_pFirst;
	while (p)
	{
		p = p->m_pNext;
		s++;
	}
	return s;
}
template<typename LT>
int tlist<LT>::copy(const tlist<LT>& lt)
{
	if (this == &lt)return size();
	titem* p;
	tlist nl;
	p = lt.m_pFirst;
	while (p)
	{
		if (nl.push_back(p->m_value) < 0)return 0;

		p = p->m_pNext;
	}
	return move(nl);
}


//lr11-------------------------------------------
template<typename LT>
double operator*(tlist<LT>& vec1, tlist<LT>& vec2) {
	return scalar_product(vec1, vec2);
}

template<typename LT>
double tlist<LT>::operator()() {
	return this->norma();
}

template <typename LT>
double scalar_product(tlist<LT>& vec1, tlist<LT>& vec2) {
	double res = 0;
	auto it_vec1 = vec1.begin();
	auto it_vec2 = vec2.begin();
	while (it_vec1 != vec1.end() && it_vec2 != vec2.end()) {
		res += (*it_vec1) * (*it_vec2);
		++it_vec1;
		++it_vec2;
	}
	return res;
}

template<typename LT>
double tlist<LT>::norma() {
	return sqrt(scalar_product(*this, *this));
}
//lr11-----------------------------------------------------