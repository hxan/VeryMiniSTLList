#include <iostream>
#include"list_function.h"
#include<vector>
using namespace std;
template<class T>

/*
stack list
*/
class stack{
	private:
		list<T> a;
	public:
		T push(T data){
			T temp = a.back();
			a.push_back(data);
			return temp;
		}
		T pop(){
			T temp = a.back();
			a.pop_back();
			return temp;
		}

		bool empty(){
			return a.empty();
		}
		int size(){
			return a.size();
		}
		~stack(){
			a.clear();
			a.~list();
		}
};

template<class T>
class stack_vector
{
	private:
		vector<T> a;
	public:
		stack_vector(){
		}
		~stack_vector(){
		}

		T push(T data){

			T temp = a[a.size()-1];
			a.push_back(data);
			return temp;
		}		
		T pop(){
			T temp = a[a.size()-1];
			a.pop_back();
			return temp;
		}

		int size(){
			return a.size();
		}

	
};


int main(int argc, char** argv) {
	stack<int> s;
	for(int i = 0; i < 10; i++){
		s.push(i);
	}
	cout<<s.pop()<<endl;
	s.push(100);
	cout<<s.pop();


	return 0;
}
