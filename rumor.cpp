#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream ifs("rumor.inp");
ofstream ofs("rumor.out");

class Rumor {
	queue<size_t> seq;
	vector<size_t> check;
	vector< vector<size_t> > container;

	size_t N, x, d;
public:
	Rumor(void): N(0),x(0),d(0) {
		size_t cnt = 0;
		size_t v;
		vector<size_t> tmp;

		ifs >> N >> x >> d;

		check = vector<size_t>(N);

		while(cnt < N) {
			while(ifs >> v && v!=0){
				tmp.push_back(v);
			}
			sort(tmp.begin()+1,tmp.end());
			container.push_back(tmp);
			tmp.clear();

			cnt++;
		}
		/*for(size_t i=0;i<container.size();++i){
			for(size_t j=0;j<container[i].size();++j)
				cout << container[i][j] << ' ';
			cout << endl;
		}*/
	}

	void spread(void) {
		seq.push(x);
		check[x-1] += 1;
		size_t day = 0;
		size_t find;
		size_t final = x;

		while(!seq.empty() && day <= d) {
			find = seq.front();
            ofs << find << endl;
			seq.pop();

			size_t i,j;
			for(i=0;i<N && !(find == container[i][0]);++i)
				;
			if(i<N){
				for(j=1;j<container[i].size();++j){
					if(check[container[i][j]-1]==0){
						seq.push(container[i][j]);
					}
					check[container[i][j]-1] += 1;
				}
			}
			if(final == find){
				day++;
				final = seq.back();
			}
		}
	}

	void print_check(void) const {
		for(size_t i=0;i<check.size();++i)
			ofs << check[i] <<endl;
	}
};

int main(void)
{
	Rumor r;
	r.spread();
	//r.print_check();
	return 0;
}
