#include "BSTMap.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using std::map;
using std::make_pair;
using std::cout;
using std::vector;
using std::random_shuffle;
using std::pair;

void testone() {
	BSTMap<int,int> test; 
	pair<int,int> fst;
	fst = make_pair(1,1); 
	pair<int,int> snd;
	snd = make_pair(2,2);
	pair<int,int> thrd;
	thrd = make_pair(3,3);
	test.insert(fst);
	cout << test[1];
	test.insert(snd);
	cout << test[2];
	test.insert(thrd);
	cout << test[3];
}

void runTests(){
	int test_size = 10;
	cout << "\n--BSTMAP<INT,INT> TESTS BEGIN-------------------------------------\n\n";
    BSTMap<int, int> shark;
	map<int,int> dolphin;
	
	vector<int> randoms;
	for(int i = 0; i<test_size; ++i){
		randoms.push_back(i);
	}
	//cout << randoms[0] << "\n";
    random_shuffle(randoms.begin(), randoms.end());
	//cout << randoms[0] << "\n";
	for(int i=0; i<test_size; ++i){
		cout << "inserting " << i << "\n";
	    shark.insert(make_pair(randoms[i],randoms[i]));
		cout << "after insert of BST MAP "<< i << "\n";
		dolphin.insert(make_pair(randoms[i],randoms[i]));
		cout << "after insert of MAP "<< i << "\n";
	}

	cout << "After loop\n";
	
	random_shuffle(randoms.begin(), randoms.end()--);
	cout << "after shuffle\n";
	for(int i=0; i<test_size; ++i){
		cout << "\n" << i;
		if(shark[randoms[i]]!=dolphin[randoms[i]]){
			//cout << "insert failure: shark " << shark[randoms[i]] << " should be dolphin " << dolphin[randoms[i]] << "\n";
		}
	}	
	
	/*
	//shark.callInOrd();
	random_shuffle(randoms.begin(), randoms.end());
	for(int i = 0; i<test_size; ++i){
		//cout << "randoms " << randoms[i] << "\n";
		//shark.erase(randoms[i]);		
	}
	//shark.erase(0);
	
	*/
	cout << "\n--TESTS COMPLETE--------------------------------------------------\n";

}
int main(){
	testone();
	runTests();
	return 0; 	
}

