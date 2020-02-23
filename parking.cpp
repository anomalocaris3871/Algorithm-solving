#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream ifs("parking.inp");
ofstream ofs("parking.out");

class parking {
	int k;
	int len;
    int n;
	vector<int> slot;
public:
	parking(void): k(0),len(0),n(0) {

		ifs >> k >> n;
		len = k;
		slot.assign(k,0);

	}
	void park(void) {
		int v;
		int cnt = 0;
		typedef vector<int>::iterator iter;

		while(ifs >> v) {
            cnt++;
            int i;

            for(i=0;i<len && !(v>0 && slot[i]==0);++i)
                ;
            if(i<len)
                slot[i] = v;

			if(v<0) {
				iter it = find(slot.begin(),slot.end(),-v);
				*it = 0;
				cnt=cnt-2;
				if(cnt == len/3) {
                    size_t mov = 0;
                    for(size_t i=0;i<len;++i)
                        if(slot[i] != 0)
                            slot[mov++] = slot[i];
                    for(int i=len/3;i<len;++i)
                        slot[i] = 0;

                    len = len/2;
                    if(len < k)
                        len = k;
                    slot.resize(len);
                }
            }


			if(cnt>len){
                size_t prev_len = len;
				len = len*2;
                slot.resize(len);
                slot[prev_len]= v;
			}
            /*for(int i=0;i<len;++i)
                cout << slot[i] << ' ';
            cout << endl;*/
		}
	}

	friend ostream& operator<<(ostream &os, const parking& pk) {
        for(int i=0;i<pk.len;++i)
            if(pk.slot[i]!=0){
                ofs << i+1 << ' ' << pk.slot[i] << endl;
            }
		return os;

	}
};

int main(void)
{
	parking pk;
	pk.park();
	cout << pk;
	return 0;
}
