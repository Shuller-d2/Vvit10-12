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
