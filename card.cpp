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
	size_t K;           // vector[2] -> Deck_C : A,B 두 덱으로부터 shuffle 및 cut을 한 결과

private:
	void Shuffle(void){
		size_t cnt = 0, flag=0;

		list::iterator it = Deck[2].begin();
		list::iterator end_it = it;
		advance(end_it, (N+1)/2);
		Deck[0].splice(Deck[0].end(),Deck[2], it, end_it);  // Deck_C에서 Deck_A로 ceiling(N/2)만큼 옮기기

		it = Deck[2].begin();
		end_it = it;
		advance(end_it, N/2);
		Deck[1].splice(Deck[1].end(),Deck[2],it,end_it);    // Deck_C에서 Deck_B로 floor(N/2)만큼 옮기기

		while(cnt < N) {
			Deck[2].push_back(Deck[flag].front());      //Deck_A와 Deck_B에서 번갈아 가면서 카드를 한장 씩 Deck_C로 옮기기.
			Deck[flag].pop_front();
			flag = (flag+1)%2;                          //Deck_A(vector[0]와 Deck_B(vector[1])를 번갈아 움직일 수 있도록 flag 변수 사용.
			cnt++;
		}
	}

	void Cut(ifstream &ifs) {
		size_t beg, end;
		ifs >> beg >> end;
		list::iterator it = Deck[2].begin();
		list::iterator end_it;
		advance(it,beg-1);                       //it과 end_it을 입력받은 beg, end 위치로 advance를 통해 옮기기.

		end_it = it;
		advance(end_it, end-beg+1);
		Deck[2].splice(Deck[2].end(),Deck[2], it, end_it);  //splice를 통해 cut하기.
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

	void print(ofstream& ofs) const {   //출력함수.
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
