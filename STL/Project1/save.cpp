//----------------------------------------------------
// save.cpp - �� �б� ���Ǹ� �� �����ϴ� �Լ�
//											2025.03.13
//----------------------------------------------------

#include <string_view>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include "save.h"

void save(std::string_view filename)
{
	// 1.���ڷ� ���޵� ������ �б� ���� ����.
	std::ifstream in{ filename.data() }; // RAII

	if (not in)
	{
		std::cout << filename << "�� �� �� �����ϴ�." << std::endl;
		exit(20250310);
	}

	// �����ߴٴ� ���� ȭ�鿡 ǥ��
	std::cout << filename << "(" << std::filesystem::file_size(filename) << " bytes) �����Ͽ����ϴ�." << std::endl;

	// 2.������� ������ ������ (�����̱� ����) ����
	std::ofstream out{ "2025 1�б� STL ��������.txt", std::ios::app }; // { } <- uniform initializer



	// �ð� ���
	auto now = std::chrono::system_clock::now(); // epoch�� ���� ����� tick ���� ��´�.
	auto utc = std::chrono::system_clock::to_time_t(now); // UTC
	auto lt = std::localtime(&utc); // �����ð�(�ѱ�)���� ����

	auto old = out.imbue(std::locale("Ko-KR")); // ��Ʈ���� ������ ����

	out << "\n" << "\n";
	out << "==========================================" << "\n";
	out << "������ �ð�: " << std::put_time(lt, "%c %A") << "\n";
	out << "==========================================" << "\n";
	out << "\n";

	out.imbue(old); // ���� �������� ����

	// 3.������ �о ������ ���Ͽ� �����δ�.
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}