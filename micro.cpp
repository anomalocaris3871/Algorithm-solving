#include <bits/stdc++.h>

using namespace std;

class Micro {
    int N,M,k;
    vector<vector<string>> cul_medium;
    vector<vector<pair<int,int>>> Virus;
    bool isVirus(int r, int c) const{
        if( r<0 || c<0 || r>=M || c>=N )
            return false;
        else return cul_medium[r][c] == "#";
    }
public:
    Micro(ifstream& ifs){
        ifs >> N >> M >> k;
        cul_medium.assign(M,vector<string>(N));
        for(int i=0;i<cul_medium.size();++i)
            for(int j=0;j<cul_medium[i].size();++j)
                ifs >> cul_medium[i][j];
    }
    int get_M(void) const {
        return M;
    }
    int get_N(void) const {
        return N;
    }
    void find_virus(int r, int c) {
        pair<int,int> Locate = make_pair(r,c);
        queue<pair<int,int>> dump;
        dump.push(Locate);

        vector<pair<int,int>> tmp;

        while( !dump.empty()) {

            pair<int,int> Here = dump.front();
            dump.pop();

            int r = Here.first;
            int c = Here.second;
            if(cul_medium[r][c] == "#"){
                tmp.push_back(make_pair(r,c));
                cul_medium[r][c] = "_";

                if(isVirus(r-1,c)) dump.push(make_pair(r-1,c));
                if(isVirus(r+1,c)) dump.push(make_pair(r+1,c));
                if(isVirus(r,c-1)) dump.push(make_pair(r,c-1));
                if(isVirus(r,c+1)) dump.push(make_pair(r,c+1));
            }
        }
        if(tmp.size()>=k)
            Virus.push_back(tmp);
    }

    void print(ostream& ofs) const {
        int max_size = Virus[0].size();
        for(int i=1;i<Virus.size();++i){
            if(max_size < Virus[i].size())
                max_size = Virus[i].size();
        }
        ofs << Virus.size() << " " << max_size << endl;
    }
};

int main(void)
{
    ifstream ifs("micro.inp");
    ofstream ofs("micro.out");

    Micro m(ifs);
    for(int i=0;i<m.get_M();++i)
        for(int j=0;j<m.get_N();++j)
            m.find_virus(i,j);
    m.print(ofs);

    return 0;
}
