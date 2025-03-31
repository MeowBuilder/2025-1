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
#include "save.h"

// [����] ���� ������ [0,1000'0000) ������ ���� int�� 1000������ ������ �޸𸮸� Ȯ���ϰ� ���� ä����
// (����) qsort�� �������� �����϶�
// ������ ��� �߿��� �տ������� 1000���� ȭ�鿡 ����϶�


std::random_device rd;
std::mt19937_64 dre(rd());
std::uniform_int_distribution<int> uid(0, 1000'0000 - 1);

std::array<int, 1000'0000> randomNumber;

int ��������(const void* a, const void * b) {
	return *(int*)a - *(int*)b;
}

int ��������(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}

int main()
{
	for (int& num : randomNumber) {
		num = uid(dre);
	}

	// qsort�� ����
	//���Ĺ�� = ��������;
	//���Ĺ�� = ��������;
	std::qsort(randomNumber.data(), randomNumber.size(), sizeof(int), ��������);

	for ( int num : randomNumber | std::views::take(1000)) {
		std::print("{:8}", num);
	}

	//save("����.cpp");
}