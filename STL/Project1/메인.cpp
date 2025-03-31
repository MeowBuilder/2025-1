//-----------------------------------------------------------
// 2025.1 �б�		 STL 3�� 31�� ������				(4�� 2��)
//-----------------------------------------------------------
// Callable types - ȣ�Ⱑ���� Ÿ��
// 1. �Լ�
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

	// STL�� sort�� �������� ����
	// ���Ŀ� �ɸ��� �ð�
	// �����ġ ����
	auto b = std::chrono::high_resolution_clock::now();
	std::sort(randomNumber.begin(), randomNumber.end(), [] (int a, int b) {
		return a > b;
		});
	auto e = std::chrono::high_resolution_clock::now();
	// �����ġ ��

	for ( int num : randomNumber | std::views::take(1000)) {
		std::print("{:8}", num);
	}

	std::cout << std::endl << "���Ŀ� �ɸ� �ð� : " << e - b << std::endl;

	//save("����.cpp");
}