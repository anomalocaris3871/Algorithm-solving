#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

ifstream ifs1("syslog.txt");
ifstream ifs2("log.inp");
ofstream ofs("log.out");

class log_class {
	size_t **day;
	vector<size_t> time;
	size_t n;
public:
	log_class(void): day(0),time(0),n(0) {
		ifs1 >> n;
		n=n+1;
		day = new size_t*[3];
		for(size_t i=0;i<3;++i)
			day[i] = new size_t[n];
	}

	void set(void) {
	    clock_t start;
	    clock_t end;

		size_t v;
		size_t cnt = 1;
		size_t len;
		for(size_t i=0;i<3;++i)
			day[i][0] = 0;
		time.push_back(0);

		start = clock();
		while(cnt<n){
			ifs1 >> day[0][cnt];
			while(ifs1 >> v && v!=0)
				time.push_back(v);
            len = time.size()-1;
            day[1][cnt] = len;
			cnt++;
		}
        day[2][1] = day[1][1];
        for(size_t i=2;i<n;++i)
            day[2][i] = day[1][i] - day[1][i-1];
		end = clock();

        cout << ((double)(end - start))/(long)CLOCKS_PER_SEC << " sec" << endl;
	}

	void count(void) const {
		size_t k;
		ifs2 >> k;
		size_t ds, ts, de, te;

		while(ifs2 >> ds >> ts >> de >> te) {
            size_t num = 0;
			for(size_t i=1;i<n;++i) {
				if(day[0][i] > ds && day[0][i] < de)
                    num += day[2][i];

				else if(day[0][i] == ds && day[0][i] != de) {
					vector<size_t>::const_iterator sub_beg = lower_bound(time.begin()+1+day[1][i-1],time.begin()+1+day[1][i],ts);
					num += (time.begin()+1+day[1][i]) - sub_beg;
				}
				else if(day[0][i] == de && day[0][i] != ds) {
					vector<size_t>::const_iterator sub_end = upper_bound(time.begin()+1+day[1][i-1],time.begin()+1+day[1][i],te);
					//cout << *sub_end << ' ' << *(time.begin()+1+day[1][i-1]);
					num += sub_end - (time.begin()+1+day[1][i-1]);
				}
				else if(day[0][i] == ds && day[0][i] == de) {
					vector<size_t>::const_iterator sub_beg = lower_bound(time.begin()+1+day[1][i-1],time.begin()+1+day[1][i],ts);
					vector<size_t>::const_iterator sub_end = upper_bound(time.begin()+1+day[1][i-1],time.begin()+1+day[1][i],te);
					num += sub_end - sub_beg;
				}

			}
            ofs << num << endl;
		}
	}
};

int main(void)
{
	log_class l;
	l.set();
	l.count();
    return 0;
}
