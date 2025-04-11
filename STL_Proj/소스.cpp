#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <array>
#include <print>
#include <algorithm>
#include <numeric>

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
	void write(ostream& os);
	void read(istream& is);
	void show() const
	{
		println("�̸�:{:<15}, ���̵�:{:<16}, ����:{:<16}, �ڿ�:{:<16}", name, id, score, num);
		cout << p.get() << endl;
	}
	int getScore() const { return score; };
	int getId() const { return id; };
};

void Player::write(ostream& os)
{
	os.write((char*)this, sizeof(Player));
	os.write((char*)p.get(), num);
}

void Player::read(istream& is)
{
	is.read((char*)this, sizeof(Player));
	p.release();
	p = make_unique<char[]>(num);
	is.read((char*)p.get(), num);
}

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

	auto max_score_player = max_element(players.begin(), players.end(), [](const Player& a, const Player& b)
		{
			return a.getScore() < b.getScore();
		});

	(*max_score_player).show();

	unsigned long long sum{};

	sum = accumulate(players.begin(), players.end(), 0LL, [](unsigned long long sum, const Player& a)
		{
			return sum + a.getScore();
		});

	cout << "��� ����:" << sum / players.size() << endl; // �Ҽ��� ǥ���ؾ���


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
}