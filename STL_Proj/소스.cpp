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
	string name; // 이름, 길이[3, 15], ['a', 'z']로만 구성
	int score; // 점수
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	unique_ptr<char[]> p; // free store에 확보한 메모리

public:
	void write(ostream& os);
	void read(istream& is);
	void show() const
	{
		println("이름:{:<15}, 아이디:{:<16}, 점수:{:<16}, 자원:{:<16}", name, id, score, num);
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
	ifstream in{ "2025 STL 과제 파일 - 2021182009",ios::binary };
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

	cout << "평균 점수:" << sum / players.size() << endl; // 소수점 표현해야함


	//시간 너무 오래 걸림
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