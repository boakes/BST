#include "BSTMap.h"
#include <iostream>

#include <map>

using std::cout;

using std::make_pair;
using std::pair;
void testone() {
	BSTMap<int,int> test; 
	pair<int,int> fst;
	fst = make_pair(1,1); 
	test.insert(fst);
	
}

int main(){
	testone();
	return 0; 	
}

