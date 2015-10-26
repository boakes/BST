#include "BSTMap.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono>
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

	test.clear();

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


void chartest() {
	BSTMap<int,char> test; 
	pair<int,char> fst;
	fst = make_pair(1,'c'); 
	pair<int,char> snd;
	snd = make_pair(2,'d');
	pair<int,char> thrd;
	thrd = make_pair(3,'e');
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


bool runTests(){
	int test_size = 200000;
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
			cout << "check with map failed\n";
			return false;
		}
	}	
	
/*
	BSTMap<int, int> tsbtsrif(firstbst);
	
	const auto a = tsbtsrif;
	const auto b = firstbst;

	if(a != b){
		cout << "copy construct failed\n";
		return false;
	}

	cout << firstmap[(firstbst.maxNode(firstbst.getroot()))->nodepr.first];
	cout << " ";
	cout << firstbst[(firstbst.maxNode(firstbst.getroot()))->nodepr.first];
	cout << "\n";
	cout << firstmap[(firstbst.minNode(firstbst.getroot()))->nodepr.first];
	cout << " ";
	cout << firstbst[(firstbst.minNode(firstbst.getroot()))->nodepr.first];
	cout << "\n";


	firstbst.clear();
	random_shuffle(randoms.begin(), randoms.end());
	//cout << randoms[0] << "\n";
	for(int i=0; i<test_size; ++i){
	    firstbst.insert(make_pair(randoms[i],randoms[i]));
		//firstmap.insert(make_pair(randoms[i],randoms[i]));
	}

	firstbst.clear();
	random_shuffle(randoms.begin(), randoms.end());
	//cout << randoms[0] << "\n";
	for(int i=0; i<test_size; ++i){
	    firstbst.insert(make_pair(randoms[i],randoms[i]));
		firstmap.insert(make_pair(randoms[i],randoms[i]));
	}
	
	
*/ 

	return true;	
}

int main(){
	testone();
	cout << "\n---------Testone passed---------\n";
	auto t1 = std::chrono::high_resolution_clock::now();
    runTests();
	auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "test function took "
           	  << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()/1000
              << " seconds\n";
/*	

	cout << "\n---------RunTests passed---------\n";
	if(equalitytest()) {cout << "\n---------Equality Test Passed---------\n";}
	else cout << "\n---------Equality Test Failed---------\n";
	chartest();
	cout << "\n---------CharTests ran---------\n";
	return 0; 	

*/
}


