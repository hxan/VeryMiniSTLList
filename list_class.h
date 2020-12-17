#include<iostream>
using namespace std;
template <class T>
struct Node{
	T val;
	//iterator 
	struct Node *front;
	struct Node *next;
};

class Iterator{
	public:
	Iterator(){}

	Node<int> *p;//p为链表指针
	//auto operator*() -> decltype((p->val)){return (p->val);}
	//operator*()
	void operator ++(int f){p=p->next;}
	void operator --(int f){p=p->front;}
	
	bool operator !=(Node<int> *t)
	{
		if(p!=t)
		{
			return 1;
		}
		return 0;
	}
	
	void operator ++(){p=p->next;}
	void operator --(){p=p->front;}
	void operator=(Node<int> *b){p=b;}
};	
template <class T>
class list{//构建list类 
	public:
		Node<T> *a;
		Node<T> *head;//头 
		Node<T> *tail;//尾
		int size = 0;	 
	void assign(int n,T );
	void merge(list<T> &b);
	void swap(list<T>&,list<T>&);
	void insert(Iterator it,T);//在IT后面插入
	 
	void erase(Iterator it);
	void erase(Iterator first,Iterator last);
	
	int front();
	int back();
	int Create_Link(int n,T v);
	
	void resize(int);
	void push_back(T );
	void print(int );
	void push_front(T );
	void reverse();//链表反转 
	void pop_front();//头部删除元素
	void pop_back();//尾部删除元素
	void clear(); 
	list(int n=0,T v=0)
	{
		Create_Link(n,v); 
	}
	Node<T>* begin()
	{
		return head;
	}
	Node<T>* end()
	{
		return tail;
	}
	bool empty()
	{
		return size==0?1:0;	
	}	 
};



