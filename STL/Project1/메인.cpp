//-----------------------------------------------------------
// 2025.1 학기		 STL 3월 31일 월요일				(4주 2일)
//-----------------------------------------------------------
// Callable types - 호출가능한 타입
// 1. 함수
//-----------------------------------------------------------

#include <iostream>
#include <random>
#include <array>
#include <print>
#include <ranges>
#include "save.h"

// [문제] 값의 범위가 [0,1000'0000) 까지인 랜덤 int값 1000만개를 저장할 메모리를 확보하고 값을 채워라
// (시작) qsort로 오름차순 정렬하라
// 정렬한 결과 중에서 앞에서부터 1000개만 화면에 출력하라


std::random_device rd;
std::mt19937_64 dre(rd());
std::uniform_int_distribution<int> uid(0, 1000'0000 - 1);

std::array<int, 1000'0000> randomNumber;

int 오름차순(const void* a, const void * b) {
	return *(int*)a - *(int*)b;
}

int 내림차순(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main()
{
	for (int& num : randomNumber) {
		num = uid(dre);
	}

	// qsort로 정렬
	//정렬방법 = 오름차순;
	//정렬방법 = 내림차순;
	std::qsort(randomNumber.data(), randomNumber.size(), sizeof(int), 오름차순);

	for ( int num : randomNumber | std::views::take(1000)) {
		std::print("{:8}", num);
	}

	//save("메인.cpp");
}