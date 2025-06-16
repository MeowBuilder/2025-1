//-----------------------------------------------------------
// 2025.1 �б�		 STL 6�� 16�� ������				(15�� 1��)
// 6/19 ����� 15�� 2�� - �⸻����
//-----------------------------------------------------------
// �� �б� ��
//-----------------------------------------------------------

#include <iostream>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

int main(){
	// special functions 
	// default ctor, dtor,
	// copy ctor, copy assignment op,
	// move ctor, move assignment op
	// 
	// RAII - ��ü�� ����� �޸��� ������ ��ġ��Ű�� ���
	// instancing - ��ü�� ������ �����Ͽ� �޸𸮿� �����ϴ� ��
	// STACK, DATA, free store, CODE - �����Ͱ� ����Ǵ� ���� ����
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
	// * ������ ������(dereference), ++, == (<=>) - ��� �����ؾ� Iterator�� ���� ����
	// 
	// Algorithms
	// 1. Non-modifying sequence
	// 2. Modifying sequence
	// 3. Sorting and related
	// 
	// �ݺ��� ������ ���� ���� -	function dispatch (tag dispatch)
	//							C++20 concept -> if constexpr (compile-time�� ����)
	// 
	// concept + ranges ->	ranges::algorithm (constrained_algorithm)
	//						views�� ���� -> functional programing language
	// 
	
	//save("����.cpp");
	//save("STRING.cpp");
	//save("STRING.h");
}