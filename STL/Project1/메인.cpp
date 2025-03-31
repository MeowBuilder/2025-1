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
#include <algorithm>
#include <chrono>
#include "save.h"

std::mt19937_64 dre(std::random_device{}());
std::uniform_int_distribution<int> uid(0, 1000'0000 - 1);

std::array<int, 1000'0000> randomNumber;

int main()
{
	for (int& num : randomNumber) {
		num = uid(dre);
	}

	// STL의 sort로 내림차순 정렬
	// 정렬에 걸리는 시간
	// 스톱워치 시작
	auto b = std::chrono::high_resolution_clock::now();
	std::sort(randomNumber.begin(), randomNumber.end(), [] (int a, int b) {
		return a > b;
		});
	auto e = std::chrono::high_resolution_clock::now();
	// 스톱워치 끝

	for ( int num : randomNumber | std::views::take(1000)) {
		std::print("{:8}", num);
	}

	std::cout << std::endl << "정렬에 걸린 시간 : " << e - b << std::endl;

	//save("메인.cpp");
}