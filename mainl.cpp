#include <iostream>
#include"list_function.h"
using namespace std;
int main(int argc, char** argv) {
	list<int> a;
	list<int> b;
	iter<int> it;
	
	for(int i = 0 ; i < 10; i++){
		a.push_back(i);
	}
	for(int i = 10 ; i < 20; i++){
		b.push_back(i);
	}
	a.merge(b);
	a.print(1);
	return 0;
}
