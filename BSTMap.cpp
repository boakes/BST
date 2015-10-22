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
	auto itrfrst = test.insert(fst);
	auto itrfrstfail = test.insert(fst);
	cout << test[1] << "\n";
	test.insert(snd);
	cout << test[2] << "\n";
	test.insert(thrd);
	cout << test[3] << "\n";
	cout << test.count(1) << "\n";
	cout << test.count(0) << "\n";
	cout << "This should be a 1: " << (itrfrst.first == itrfrstfail.first);
	cout << "\nThis should be a 0: " << (itrfrst.second == itrfrstfail.second);
	
	test.erase(2);
	cout << "\n"<< test.count(2) << "\n";


	for(auto x:test){
		cout << "\n" << "Ranged loop";
		cout << x.first << "\n";
	}


	
}

void runTests(){
	int test_size = 100;
    BSTMap<int, int> firstbst;
	map<int,int> firstmap;
	
	vector<int> randoms;
	for(int i = 0; i<test_size; ++i){
		randoms.push_back(i);
	}
	//cout << randoms[0] << "\n";
    random_shuffle(randoms.begin(), randoms.end());
	//cout << randoms[0] << "\n";
	for(int i=0; i<test_size; ++i){
	    firstbst.insert(make_pair(randoms[i],randoms[i]));
		firstmap.insert(make_pair(randoms[i],randoms[i]));
	}
	
	random_shuffle(randoms.begin(), randoms.end()--);
	for(int i=0; i<test_size; ++i){
		if(firstbst[randoms[i]]!=firstmap[randoms[i]]){
			cout << "insert failure: firstbst " << firstbst[randoms[i]] << " should be firstmap " << firstmap[randoms[i]] << "\n";
		}
	}	
	
	BSTMap<int, int> tsbtsrif(firstbst);
	

	/*
	//firstbst.callInOrd();
	random_shuffle(randoms.begin(), randoms.end());
	for(int i = 0; i<test_size; ++i){
		//cout << "randoms " << randoms[i] << "\n";
		//firstbst.erase(randoms[i]);		
	}
	//firstbst.erase(0);
	
	*/


	cout << firstmap[(firstbst.maxNode(firstbst.getroot()))->nodepr.first];
	cout << " ";
	cout << firstbst[(firstbst.maxNode(firstbst.getroot()))->nodepr.first];
	cout << "\n";
	cout << firstmap[(firstbst.minNode(firstbst.getroot()))->nodepr.first];
	cout << " ";
	cout << firstbst[(firstbst.minNode(firstbst.getroot()))->nodepr.first];
	cout << "\n";
	
}

bool equalitytest(){
	int test_size = 1000;
	bool testbool = true;
	BSTMap<int,int> test;
	map<int,int> testmap;
	vector<int> RandomThing;
	for(int i = 0; i<test_size; ++i){
		RandomThing.push_back(i);
	}
    random_shuffle(RandomThing.begin(), RandomThing.end());

    for(int i=0;i<test_size;++i){
    	test.insert(make_pair(RandomThing[i],RandomThing[i]));
    	testmap.insert(make_pair(RandomThing[i],RandomThing[i]));
    }

    auto ths = test.begin()++++++++++++;
    auto thsafter = ths;
    thsafter++;
    auto ers = test.erase(ths);
    if(ers != thsafter){
    	testbool = false;
    }
	for(auto bgn = test.begin();bgn != test.end(); ++bgn){
		if((*bgn).second != testmap[(*bgn).first]){
			testbool = false;
		}	
	}

	return testbool;
}
int main(){
	testone();
	cout << "\n---------Testone passed---------\n";
	runTests();
	cout << "\n---------RunTests passed---------\n";
	if(equalitytest()) {cout << "\n---------Equality Test Passed---------\n";}
	else cout << "\n---------Equality Test Failed---------\n";
	return 0; 	
}

