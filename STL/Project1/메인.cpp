//-----------------------------------------------------------
// 2025.1 학기		 STL 6월 16일 월요일				(15주 1일)
// 6/19 목요일 15주 2일 - 기말시험
//-----------------------------------------------------------
// 한 학기 끝
//-----------------------------------------------------------

#include <iostream>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

int main(){
	// special functions 
	// default ctor, dtor,
	// copy ctor, copy assignment op,
	// move ctor, move assignment op
	// 
	// RAII - 객체의 수명과 메모리의 수명을 일치시키는 기법
	// instancing - 객체를 실제로 생성하여 메모리에 저장하는 것
	// STACK, DATA, free store, CODE - 데이터가 저장되는 곳의 종류
	// 
	// Containers
	// 1. sequence				( O(N) )		- array<T,N>, vector<T>, deque<T>, list<T>, forward_list<T>
	// 2. associative			( O(log N) )	- set<T>, multiset<T>, map<k,v>, multimap<k,v>
	// 3. unordered associative ( O(1) )		- unordered_set<T>, unordered_map<k,v>
	// 
	// Iterators
	// - Category (Hierarchy) 
	//		input_iterator_tag
	//		output_iterator_tag
	//		forward_iterator_tag
	//		bidirectional_iterator_tag
	//		random_access_iterator_tag
	//		contiguous_iterator_tag
	// * 역참조 연산자(dereference), ++, == (<=>) - 등등 지원해야 Iterator로 수행 가능
	// 
	// Algorithms
	// 1. Non-modifying sequence
	// 2. Modifying sequence
	// 3. Sorting and related
	// 
	// 반복자 종류에 따른 구현 -	function dispatch (tag dispatch)
	//							C++20 concept -> if constexpr (compile-time에 결정)
	// 
	// concept + ranges ->	ranges::algorithm (constrained_algorithm)
	//						views와 결합 -> functional programing language
	// 
	
	//save("메인.cpp");
	//save("STRING.cpp");
	//save("STRING.h");
}