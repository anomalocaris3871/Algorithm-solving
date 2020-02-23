#include <fstream>
#include <list>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Card {
#define list list<int>
	vector<list> Deck;  // vector[0] -> Deck_A
	size_t N;           // vector[1] -> Deck_B
	size_t K;           // vector[2] -> Deck_C : A,B �� �����κ��� shuffle �� cut�� �� ���

private:
	void Shuffle(void){
		size_t cnt = 0, flag=0;

		list::iterator it = Deck[2].begin();
		list::iterator end_it = it;
		advance(end_it, (N+1)/2);
		Deck[0].splice(Deck[0].end(),Deck[2], it, end_it);  // Deck_C���� Deck_A�� ceiling(N/2)��ŭ �ű��

		it = Deck[2].begin();
		end_it = it;
		advance(end_it, N/2);
		Deck[1].splice(Deck[1].end(),Deck[2],it,end_it);    // Deck_C���� Deck_B�� floor(N/2)��ŭ �ű��

		while(cnt < N) {
			Deck[2].push_back(Deck[flag].front());      //Deck_A�� Deck_B���� ������ ���鼭 ī�带 ���� �� Deck_C�� �ű��.
			Deck[flag].pop_front();
			flag = (flag+1)%2;                          //Deck_A(vector[0]�� Deck_B(vector[1])�� ������ ������ �� �ֵ��� flag ���� ���.
			cnt++;
		}
	}

	void Cut(ifstream &ifs) {
		size_t beg, end;
		ifs >> beg >> end;
		list::iterator it = Deck[2].begin();
		list::iterator end_it;
		advance(it,beg-1);                       //it�� end_it�� �Է¹��� beg, end ��ġ�� advance�� ���� �ű��.

		end_it = it;
		advance(end_it, end-beg+1);
		Deck[2].splice(Deck[2].end(),Deck[2], it, end_it);  //splice�� ���� cut�ϱ�.
	}

public:
	Card(ifstream& ifs):Deck(3),N(0),K(0) {
		ifs >> N >> K;
		size_t cnt = 0;
		string handling;

		for(size_t i=1;i<=N;++i)
			Deck[2].push_back(i);

		list::iterator it;
		while(cnt < K) {
			ifs >> handling;
			if( handling == "Shuffle" )
				Shuffle();
			else{
				Cut(ifs);
			}
			cnt++;
		}
	}

	void print(ofstream& ofs) const {   //����Լ�.
		list::const_iterator it;

		it = Deck[2].begin();
		ofs << *it << ' ';

		advance(it,N/2-1);
		ofs << *it << ' ';

		it = --Deck[2].end();
		ofs << *it << endl;
	}
};

int main(void)
{
	ifstream ifs("card.inp");
	ofstream ofs("card.out");

	Card c(ifs);
	c.print(ofs);

	ifs.close();
	ofs.close();

	return 0;
}
