#include <bits/stdc++.h>

using namespace std;

class Log {
#define ll long long

	struct Xnode {
		ll start;
		ll end;
		int segment;
		Xnode(size_t i, ll s, ll e):start(s),end(e),segment(i){}
	};
	size_t N;
	size_t K;
	list<Xnode> tuple;
public:
	Log(ifstream& ifs):N(0),K(0) {
		ifs >> N >> K;
	}
	void insert(ifstream& ifs) {
		size_t N_cnt = 0;
		while(N_cnt<N) {
			size_t i;
			ll s, e;

			ifs >> i >> s >> e;
			Xnode tmp(i,s,e);
			tuple.push_back(tmp);
			N_cnt++;
		}
	}

	void search(ifstream& ifs, ostream& ofs) {
		size_t K_cnt=0,cnt=0, Q;
		vector<ll> storage;

		while(K_cnt<K) {
			ifs >> Q;
			for(auto it = tuple.begin();it!=tuple.end();++it) {
				if(Q >= (*it).start && Q <= (*it).end){
					storage.push_back( (*it).segment );
				}
				else
					cnt++;
			}
			sort(storage.begin(),storage.end());

			if(cnt == tuple.size())
				ofs << 0 << " ";
			else
				copy(storage.begin(),storage.end(),
					ostream_iterator<ll>(ofs , " "));

			ofs << endl;
			storage.clear();
			cnt = 0;
			K_cnt++;
		}
	}
	friend ostream& operator<<(ostream& os, const Log& l){
		list<Xnode>::const_iterator iter;
		for(iter=l.tuple.begin();iter!=l.tuple.end();++iter)
			cout << (*iter).start << " " << (*iter).end << endl;
		return os;
	}
};

int main(void)
{
	ifstream ifs("log.inp");
	ofstream ofs("log.out");

	Log l(ifs);
	l.insert(ifs);
	l.search(ifs,ofs);
	//cout << l << endl;

	return 0;
}
