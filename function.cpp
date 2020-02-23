#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <utility>

using namespace std;

ifstream ifs("function.inp");
ofstream ofs("function.out");

class func {
private:
	size_t n;
	size_t k1, k2;
	vector<vector<string>> container;
	vector<pair<string,string>> call_seq;
	stack<pair<size_t, size_t>> pt;

private:
	bool func_name(size_t i, size_t j) const {
		size_t k;
		for(k=0;k<n;++k)
			if(container[i][j] == container[k][0])
				break;
		if(k<n)
			return true;
		else
			return false;
	}

public:
	func(void):n(0),k1(0),k2(0) {
		ifs >> n >> k1 >> k2;
		size_t i=0;
		string v;
		while(i<n){
			vector<string> f;
			while(ifs >>v && v != "$") {
				f.push_back(v);
			}
			f.push_back("$");
			container.push_back(f);
			++i;
		}
	}
	void call(void) {
		size_t i=0,j=1;

		vector<string> dead;
		while(!(i==0 && j == container[0].size()-1)){
            if(dead.size()>2){
                size_t m;
                for(m=1;m<dead.size();++m)
                    if(dead[0] == dead[m])
                        break;
                if(m<dead.size()){
                    ofs << "DEADLOCK" << endl;
                    exit(-1);
                }

            }
			if(func_name(i,j)){
				pair<size_t, size_t>temp = make_pair(i,j+1);
				pt.push(temp);

				size_t k;
				for(k=0;k<n && !(container[k][0] == container[i][j]);++k)
					;
				if(k<n){
                    dead.push_back(container[i][j]);
					i = k;
					j = 1;
				}
			}else if(container[i][j] == "$"){
				pair<size_t, size_t> tmp = pt.top();
				i = tmp.first;
				j = tmp.second;
				pt.pop();
                dead.pop_back();
			}else {

				pair<string, string>tmp;
				tmp = make_pair(container[i][0], container[i][j]);
				call_seq.push_back(tmp);
				++j;
			}

		}
	}

	void print(void) const {
		if(k1 > call_seq.size())
			ofs << "NONE" << endl;
		else{
			for(size_t i=0;i<call_seq.size();++i)
				if(i == k1-1)
					ofs << call_seq[i].first << "-" << call_seq[i].second << endl;
		}

		if(k2 > call_seq.size())
			ofs << "NONE" << endl;
		else {
			for(size_t i=0;i<call_seq.size();++i)
				if(i == k2-1)
					ofs << call_seq[i].first << "-" << call_seq[i].second << endl;
		}
	}

};

int main(void)
{
	func f;
	f.call();
	f.print();
	return 0;
}


