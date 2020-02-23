#include<bits/stdc++.h>

using namespace std;

class Organ {
private:
    size_t N;
    int child_num = 0;
    int level = 0;
    vector<vector<string>> storage;
private:
    bool is_leaf(string leaf) const {
        size_t i,j;
        for(i=0;i<storage.size();++i)
            if(leaf == storage[i][1])
                break;
        if(!(i<storage.size()))
            return true;
        return false;
    }

    int get_child(string node){
        int i;
        if(child_num > N-1)
            return 0;
        for(i=0;i<storage.size();++i)
            if(storage[i][1] == node){
                child_num++;
                get_child(storage[i][0]);
            }
        return child_num;
    }

    int get_level(string node) {
        if(node == "0")
            return level;
        else{
            for(size_t i=0;i<storage.size();++i)
                if(node == storage[i][0]){
                    level++;
                    get_level(storage[i][1]);
                }
            return level;
        }
    }
public:
    explicit Organ(ifstream &ifs):N(0) {
        string f,s;
        size_t cnt = 0;
        ifs >> N;
        vector<string> tmp;

        while(cnt<N-1) {
            ifs >> f >> s;
            tmp.push_back(f);
            tmp.push_back(s);

            storage.push_back(tmp);
            tmp.clear();
            cnt++;
        }
    }
    void get_root(void) {
        size_t i,j;
        string root;
        for(i=0;i<storage.size();++i) {
            for(j=0;j<storage.size();++j)
                if(storage[i][1] == storage[j][0])
                    break;
            if(j>=storage.size())
                root = storage[i][1];
        }
        vector<string> tmp;
        tmp.push_back(root);
        tmp.push_back("0");
        storage.push_back(tmp);
    }
    void get_child(void) {
        for(size_t i=0;i<storage.size();++i){
            storage[i].push_back(to_string(get_child(storage[i][0])));
            child_num = 0;
        }
    }

    void get_level(void) {
        for(size_t i=0;i<storage.size();++i){
            storage[i].push_back(to_string(get_level(storage[i][1])));
            level = 0;
        }
    }

    void order(ofstream& ofs) {
        vector<tuple<int,int,string>> ordered;

        for(size_t i=0;i<storage.size();++i) {
            tuple<int,int,string> tmp;
            tmp = make_tuple(stoi(storage[i][2]), stoi(storage[i][3]),
                storage[i][0]);

            ordered.push_back(tmp);
        }

        sort(ordered.begin(),ordered.end(),
             [](const tuple<int,int,string> &it1, const tuple<int,int,string> &it2) {
                return tie(get<0>(it1), get<1>(it2), get<2>(it2)) > tie(get<0>(it2), get<1>(it1), get<2>(it1));
            });

        for(auto it = ordered.begin(); it!=ordered.end(); ++it)
            ofs << get<2>(*it) << " ";
        cout << endl;

    }
};

int main(void)
{
    ifstream ifs("org.inp");
    ofstream ofs("org.out");
    Organ o(ifs);
    o.get_root();
    o.get_child();
    o.get_level();
    o.order(ofs);

    ifs.close();
    ofs.close();

    return 0;
}
