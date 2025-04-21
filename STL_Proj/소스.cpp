#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <array>
#include <print>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

class Player
{
private:
	string name; // �̸�, ����[3, 15], ['a', 'z']�θ� ����
	int score; // ����
	size_t id; // ���̵�, ��ġ�� ���̵� ���� �� ����
	size_t num; // free store�� Ȯ���� ����Ʈ ��
	unique_ptr<char[]> p; // free store�� Ȯ���� �޸�

public:
	void write(ostream& os)
	{
		os.write((char*)this, sizeof(Player));
		os.write((char*)p.get(), num);
	}

	void read(istream& is)
	{
		is.read((char*)this, sizeof(Player));
		p.release();
		p = make_unique<char[]>(num);
		is.read((char*)p.get(), num);
	}

	void show() const
	{
		println("�̸�:{:<15}, ���̵�:{:<16}, ����:{:<16}, �ڿ�:{:<16}", name, id, score, num);
		cout << p.get() << endl;
	}

	int getScore() const { return score; };
	int getId() const { return id; };
	string getName() const { return name; }

	char* getp() { return p.get(); };
	size_t getnum() { return num; };
};

array<Player, 250'0000> players;



int main()
{
	ifstream in{ "2025 STL ���� ���� - 2021182009",ios::binary };
	if (not in) return 2021182009;

	for (Player& data : players)
	{
		data.read(in);
	}

	players.back().show();

	auto maxelement = max_element(players.begin(), players.end(), [](const Player& lhs, const Player& rhs)
		{
			return lhs.getScore() < rhs.getScore();
		});

	(*maxelement).show();

	unsigned long long sum{};

	sum = accumulate(players.begin(), players.end(), 0LL, [](unsigned long long sum, const Player& a)
		{
			return sum + a.getScore();
		});

	long double average = static_cast<long double>(sum) / players.size();

	cout << fixed; //�̰ŷ� �Ҽ��� ǥ�� ����
	cout << "��� ����:" << average << endl; // �Ҽ��� ǥ���ؾ���


	//�ð� �ʹ� ���� �ɸ�
	//size_t cnt{};

	//for (size_t i = 0; i < players.size(); ++i)
	//{
	//	for (size_t j = i+1; j < players.size(); ++j)
	//	{
	//		if (players[i].getId() == players[j].getId())
	//		{
	//			++cnt;
	//		}
	//	}
	//}

	//cout << cnt;

	ofstream out{ "�������̵�.txt" };
	size_t countsame{ 0 };
	bool isFirstSame{ false };

	sort(players.begin(), players.end(), [](const Player& a, const Player& b)
		{
			return a.getId() < b.getId();
		});


	for (size_t i = 1; i < players.size(); ++i)
	{
		if (players[i].getId() == players[i - 1].getId())
		{
			if (!isFirstSame)
			{
				out << "�̸� :" << players[i - 1].getName() << ", ID :" << players[i - 1].getId();
				++countsame;
				isFirstSame = true;
			}
			out << " / " << "�̸� :" << players[i].getName() << ", ID :" << players[i].getId();
			++countsame;
		}
		else
		{
			if (isFirstSame) out << endl;
			isFirstSame = false;
		}
	}

	cout << "���� id�� ���� ��ü ��: " << countsame << '\n';

	size_t count10A{ 0 };

	for (Player& data : players)
	{
		sort(data.getp(), data.getp() + data.getnum());

		size_t acount = count(data.getp(), data.getp() + data.getnum(), 'a');
		if (acount >= 10)
		{
			++count10A;
		}
	}

	cout << "a�� 10���� �̻��� ��ü ��: " << count10A << '\n';

	size_t inputID{};
	while (true)
	{
		cout << "====================" << endl << "ID�� �Է��ϼ���. : ";
		if (!(cin >> inputID))
		{
			cin.clear(); // �����÷��� �����
			cin.ignore(100, '\n'); // �Է¹��� 100�� ����
			cout << "ID�Է��� �ùٸ��� �ʽ��ϴ�." << endl;
			continue;
		}

		sort(players.begin(), players.end(), [](const Player& lhs, const Player& rhs)
			{
				return lhs.getId() < rhs.getId();
			});

		for (const Player& data : players)
		{
		}
	}
}