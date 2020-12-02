#include<iostream>
using namespace std;
template <class T>
struct Node{
	T val;
	//iterator 
	struct Node *front;
	struct Node *next;
};

template <class T>
class iter{
	public:
		iter(){}
	Node<T> *p;//pΪ����ָ��
	T operator*(){return (p -> val);};
	void operator ++(int f){p = p -> next;}
	void operator --(int f){p = p -> front;}
	
	bool operator !=(iter<T> t){
		if(p != t.p){
			return 1;
		}
		return 0;
	}
	
	void operator ++(){
		p = p -> next;
	}
	void operator --(){p = p -> front;}
	void operator=(Node<T> *b){p = b;}
};	
template <class T>
class list{//����list�� 
	public:
		Node<T> *a = 0;
		Node<T> *head = 0;//ͷ 
		Node<T> *tail = 0;//β
		int size = 0;	 
	void assign(int n,T );
	void merge(list<T> &b);
	void swap(list<T>&,list<T>&);
	void insert(iter<T> it,T);//��IT�������
	 
	void erase(iter<T> it);
	void erase(iter<T> first,iter<T> last);
	
	int front();
	int back();
	int Create_Link(int n,T v);
	
	void resize(int);
	void push_back(T );
	void print(int );
	void push_front(T );
	void reverse();//����ת 
	void pop_front();//ͷ��ɾ��Ԫ��
	void pop_back();//β��ɾ��Ԫ��
	void clear(); 
	list(int n = 0,T v = 0){
		Create_Link(n,v);
	}
	Node<T>* begin(){
		return head;
	}
	Node<T>* end(){
		return tail;
	}
	bool empty(){
		return (size == 0)?1:0;	
	}	 
};



