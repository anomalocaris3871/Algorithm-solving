#include <iostream>
#include <fstream>

using namespace std;

ifstream ifs("nanobot.inp");
ofstream ofs("nanobot.out");

class Matrix {
public:
	struct Pair {
		int x_cord, y_cord;
		int val;
	};
private:
	int row, col;
	Pair* p;
public:
	Matrix(int r, int c)
		:row(r), col(c), p(new Pair[row*col]) {

		int v = 0;
		int d_key = -1;
		int v_key = 1;
		int r_max = row;
		int c_max = col;
        int x = 1;
        int y = 0;

		int index = row*col;

        while(1){
            for(int i=0;i<r_max;++i){
                index = index + d_key*col;
                p[index].val = ++v;
                p[index].x_cord = x;
                p[index].y_cord = y += v_key;;
            }
            r_max--;

            if(r_max==row-col)
                break;

            d_key = -d_key;
            for(int i=0;i<c_max-1;++i){
                index = index + d_key;
                p[index].val = ++v;
                p[index].x_cord = x += v_key;
                p[index].y_cord = y;
            }

            v_key = -v_key;
            c_max--;

            if(c_max==col-row)
                break;
        }
	}
	~Matrix(void) {
        delete p;
	}

	void print_num(int x, int y) const {
		int i;
		for(i=0;i<row*col && !(p[i].x_cord == x && p[i].y_cord == y);++i)
            ;
		if(i<row*col)
            ofs << p[i].val << endl;
	}

	void print_cord(int v) const {
		int i;
		for(i=0;i<row*col && !(p[i].val == v);++i)
            ;
        if(i<row*col)
            ofs << p[i].x_cord << ' ' << p[i].y_cord << endl;

	}

/*	friend ostream& operator<<(ostream& os, const Matrix& m) {
		int i;
		for(i=0;i<m.row*m.col;++i){
            cout << m.p[i].val << "(" << m.p[i].x_cord << ',' << m.p[i].y_cord << ")" << '\t';
            if((i+1)%m.col==0)
                cout << endl;
		}
		return os;
	}
*/
};

int main(void)
{
	int row,col;
	int x_cord, y_cord;
	int val;

	ifs >> col >> row;
	ifs >> x_cord >> y_cord;
	ifs >> val;

	Matrix m(row,col);

    //cout << m << endl;

	m.print_num(x_cord,y_cord);
	m.print_cord(val);

	ifs.close();
	ofs.close();

	return 0;
}
