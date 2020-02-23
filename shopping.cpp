#include <queue>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

ifstream ifs("shopping.inp");
ofstream ofs("shopping.out");

class shopping {
	int N;
	int k;
	vector<queue<pair<int,int> > > counter;
	vector<int> wait_t;
public:
	shopping(void):N(0), k(0) {
		ifs >> N >> k;
		counter = vector<queue<pair<int, int>>>(k);
		wait_t = vector<int>(k,0);
	}
	void push(void) {
		int cnt = 0;
		int num, stuff;

		if(k>N)
			k = N;

		for(int i=0;i<k;++i) {
			ifs >> num >> stuff;
			pair<int, int> tmp = make_pair(stuff, num);
			counter[i].push(tmp);
			wait_t[i] += stuff;
		}


		while ( cnt < N-k ) {
			int loc = 0;
			int min = wait_t[0];
			for(int i=0;i<k;++i){
				if(wait_t[i] < min){
					loc = i;
					min = wait_t[i];
				}
			}

			ifs >> num >> stuff;
			pair<int, int> tmp = make_pair(stuff, num);
			counter[loc].push(tmp);
			wait_t[loc] += stuff;
			cnt++;
		}
	}

	void pop(void) {
		int cnt = 0;
		while( cnt < N ) {
			for(int i=0;i<k;++i) {
				if(counter[i].empty()==true) {
					counter[i].push(make_pair(21,101));
				}
			}
			int min = counter[k-1].front().first;
			int loc = k-1;

			for(int i=k-1;i>=0;--i) {
				if( counter[i].front().first < min ) {
					min = counter[i].front().first;
					loc = i;
				}
			}
			ofs << counter[loc].front().second << endl;

			for(int i=0;i<k;++i){
				counter[i].front().first -= min;
			}
			counter[loc].pop();

			cnt++;
		}
	}

};

int main(void)
{
	shopping shp;
	shp.push();
	shp.pop();
	return 0;
}
