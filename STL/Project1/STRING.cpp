//-------------------------------------------------------------------------------------------------
// STRING.cpp - STL�� ������ �����ϱ� ���� class / std::string�� �����ϰ� �ۼ�
//
// 2025. 4. 10 - ����
// 2025. 4. 10 - �������/�����Ҵ翬����, ����� �Լ��� ���� ����
//-------------------------------------------------------------------------------------------------
#include <memory>
#include <print>
#include "STRING.h"

size_t STRING::gid{ 0 };		// 2025. 4. 10 ������ȣ ����

STRING::STRING()
	: id{ ++gid }
{
	std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ����ּ�:{:16}",
		id, "����Ʈ����", num, (void*)this, (void*)p.get());
}

STRING::~STRING()
{
	std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ����ּ�:{:16}",
		id, "�Ҹ���", num, (void*)this, (void*)p.get());
}

STRING::STRING(const char* str) 
	: num{ strlen(str) }, id{ ++gid }
{
	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), str, num);

	std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ����ּ�:{:16}",
		id, "������(char*)", num, (void*)this, (void*)p.get());
};

// ��������ڿ� �����Ҵ翬���� 2025. 4. 10
STRING::STRING(const STRING& other)	// ���� ������ �Ҵ��� �̿��ؼ� �ڵ��϶�
	:id{ ++gid }
{
	*this = other;

	std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ����ּ�:{:16}",
		id, "���������", num, (void*)this, (void*)p.get());
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other) return *this; // [int* p = &a] => address of /// [int& r = a] => reference

	num = other.num;

	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	std::println("[{:6}] {:<16} �ڿ���:{:4}, �ּ�:{:16} �ڿ����ּ�:{:16}",
		id, "copy operator=", num, (void*)this, (void*)p.get());

	return *this;
}

size_t STRING::size() const 
{
	return num;
};

std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; ++i) {
		os << s.p[i];
	}
	return os;
}