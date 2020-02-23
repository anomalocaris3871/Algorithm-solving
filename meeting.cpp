#include <bits/stdc++.h>

using namespace std;

class Meet {
    const int intsec = 2;
    const int load = 1;
    int N;
    char f1,f2,f3;
    vector<list<char>> downtown;
    map<char,bool> checklist;

public:
    Meet(ifstream& ifs) {
        ifs >> N >> f1 >> f2 >> f3;
        int cnt=0;
        char vertex;
        while(cnt<N) {
            list<char> tmp;
            while(ifs>> vertex && vertex!='$') {
                tmp.push_back(vertex);
            }
            auto it = *(tmp.begin());
            checklist.insert(make_pair(it,false));
            downtown.push_back(tmp);
            cnt++;
        }
    }
    int BFS(char v, char dst) {
        int weight = 0;
        checklist.find(v)->second = true;
        queue<char> que;
        que.push(v);
        char last = v;

        while(!que.empty()) {
            char que_v= que.front();
            que.pop();

            if(que_v == dst){
                weight -= intsec;
                for(auto it = checklist.begin(); it!=checklist.end();++it)
                    it->second = false;
                break;
            }

            int i;
            for(i=0;i<downtown.size();++i)
                if(*(downtown[i].begin()) == que_v)
                    break;
            if(i<downtown.size()) {
                for(auto lit = ++downtown[i].begin();lit !=downtown[i].end();++lit)
                    if(checklist.find(*lit)->second != true){
                        que.push(*lit);
                        checklist.find(*lit)->second = true;
                    }
            }
            if(last == que_v) {
                weight += load + intsec;
                last = que.back();
            }

        }
        return weight;
    }

    void Max(ofstream &ofs) {
        vector<pair<int,char>> loc;
        int cnt = 0;
        while(cnt < N) {
            int l = *(downtown[cnt].begin());
            int max_v = 0;
            if(BFS(f1,l) > BFS(f2,l))
                if(BFS(f1,l) > BFS(f3,l))
                    max_v = BFS(f1,l);
                else
                    max_v = BFS(f3,l);
            else
                if(BFS(f2,l) > BFS(f3,l))
                    max_v = BFS(f2,l);
                else
                    max_v = BFS(f3,l);
            loc.push_back(make_pair(max_v,l));
            cnt++;
        }

        sort(loc.begin(),loc.end(),[](const pair<int,char>& p1,const pair<int,char>& p2){
            if(p1.first == p2.first)
                return p1.second < p2.second;
            else
                return p1.first < p2.first;
             });
        auto loc_it = loc.begin();
        ofs << loc_it->second << endl << loc_it->first << endl;
    }
    /*void print(void) {
        for(auto vit = downtown.begin(); vit!=downtown.end();++vit) {
            for(auto lit = (*(vit)).begin(); lit != (*(vit)).end(); ++lit)
                cout << *(lit) << " ";
            cout << endl;
        }
    }*/
};

int main(void)
{
    ifstream ifs("meeting.inp");
    ofstream ofs("meeting.out");
    Meet m(ifs);
    m.Max(ofs);


    //m.print();
    return 0;
}
