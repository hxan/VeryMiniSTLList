#include"list_class.h"
template <class T>
void list<T>::merge(list<T> &b)
{
	while(b.empty()==0)
	{
		push_back(b.front());
		b.pop_front();
	}
	return ;
}
template <class T>
void list<T>::swap(list<T> &m,list<T> &q)
{
	Node<T> *t=m.head;
	m.head=q.head;
	q.head=t;//头指针交换 
	
	t=m.tail;
	m.tail=q.tail;
	q.tail=t;//尾指针交换
	
	t=m.a;
	m.a=q.a;
	q.a=t;//a指针交换 
	
	int tsize=m.size;
	m.size=q.size;
	q.size=tsize; //size变量交换 
	return ;
}
template <class T>
void list<T>::assign(int n,T x)
{
	for(int i=0;i<n;i++)
	{
		push_back(x);
	}
	return ;
}
template <class T>
void list<T>::insert(iter<T> it,T v)////这个还没写 
{
	if(size==0)
		return ;
	else if(size==1)
	{
		tail->next=new Node<T> [1];//下一个节点分配 
		tail=tail->next;//转移到下一个节点 
		tail->val=v;//下一个节点赋值 
		head->next=tail;//
		tail->front=head;
		tail->next=0;
		size++;
		return ;
	}
	Node<T> *b=it.p->next;//第一步 
	it.p->next=0;//第二步 
	it.p->next=new Node<T>[1];//第三
	b->front=it.p->next;//   4
	it.p->next->front=it.p;//5
	it.p->next->next=b;
	it.p->next->val=v;
	size++;
	return ;
}
template <class T>
void list<T>::erase(iter<T> it)
{
	if(size==0) 
		return;
	else if(size==1) 
	{
		clear();
		return ;
	}
	if(it.p==begin())//表示第一个元素
	{
		it.p->next->front=0;
		head=head->next;
		delete it.p;
		size--;
		return ;
	 } 
	else if(it.p==end())//代表最后一个元素
	{
	 	it.p->front->next=0;
	 	tail=tail->front;
	 	delete it.p;
	 	size--;
	 	return ;
	 } 
	it.p->front->next=it.p->next;
	it.p->next->front=it.p->front;
	delete it.p;
	return ;
}
template <class T>
int list<T>::front()
{
	return head->val;
}
template <class T>
int list<T>::back()
{
	return tail->val;
}
template <class T>
void list<T>::resize(int n)
{
	int t=size;
	if(n==0) 
	{
		clear();
		return ;
	}
	
	if(t<n)
	{
		for(int i=0;i<n-t;i++)
		{
			push_back(0);
		}
	}
	else if(t>n)
	{
		for(int i=0;i<t-n;i++)
		{
			pop_back();
		}
	}
	return ;
}
template <class T>
void list<T>::clear()
{
	while(size!=0)
	{
		pop_back();
		cout<<size<<" ";
	}
	return ;
}
template <class T>
void list<T>::pop_back()
{
	if(size==0)
		return ;//如果大小为零 
	else if(size==1)
	{
		delete head;
		head=0;
		tail=0;
		size--;
		return ;
	}
	tail=tail->front;
	delete tail->next;
	tail->next=0;
	size--;
	return ;
}
template <class T>
void list<T>::pop_front()
{
	if(size==0)
		return ;//如果大小为零 
	else if(size==1)
	{
		delete head;
		head=0;
		tail=0;
		size--;
		return ;
	}
	head=head->next;
	delete head->front;
	head->front=0;
	size--;
	return ;
}
template <class T>
void list<T>::reverse()
{
	if(size==0)
		return ;
	Node<T> *temphead=head;//头
	Node<T> *temptail=tail;
	while(1)
	{
		if(temphead->next==temptail)
		{
			//双数的节点数
			int t=temphead->val;
			temphead->val=temptail->val;
			temptail->val=t; //交换 
			return ;
		}
		else if(temphead==temptail)
		{
			return ;//单数 两个指针会遇到 
		}
		
		int t=temphead->val;
		temphead->val=temptail->val;
		temptail->val=t;
		
		temphead=temphead->next;//往后移 
		temptail=temptail->front;//往前移 
		
	 } 
}
template <class T>
void list<T>::push_back(T v)
{
	if(size==0)
	{
		a=new Node<T>[1];
		a->val=v;
		
		a->next=0;
		a->front=0;
		head=a;
		tail=a;
		size++;
		return ;
	}
	tail->next=new Node<T>[1];
	tail->next->front=tail;
	tail=tail->next;
	tail->val=v;
	tail->next=0;
	size++;
	return ;
}
template <class T>
void list<T>::push_front(T v)
{
	if(size==0)
	{
		a=new Node<T>[1];
		a->val=v;
		head=a;
		tail=a;
		a->next=0;
		a->front=0;
		size++;
		return ;
	}
	head->front=new Node<T> [1];
	head->front->next=head;
	head=head->front;
	head->val=v;
	head->front=0;
	size++;
	return ;
}
template <class T>
void list<T>::print(int sign)//0为顺序输出 1为逆序 
{
	if(sign==1)
	{
		Node<T> *temp=tail;
		while(temp!=0)
		{
			cout<<temp->val<<" "<<endl;
			temp=temp->front;
		}
	}
	else
	{
		Node<T> *temp=head;
		while(temp!=0)
		{
			cout<<temp<<" "<<temp->val<<" "<<endl;
			temp=temp->next;
		}
	}
}
template <class T>
int list<T>::Create_Link(int n,T v)//测试完成 
{
	if(n==0)
		return 0;
	a=new Node<T> [1];
	a->val=v;
	a->front=0;
	a->next=0;
	head=a;
	tail=a;
	size++;
	for(int i=0;i<n-1;i++)//     
	{
		a->next=new Node<T>[1];
		a->next->front=a;
		a=a->next;
		a->val=v;
		a->next=0;
		size++;
	}
	tail=a; 
	return 0;
}
