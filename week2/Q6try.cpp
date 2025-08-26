#include <bits/stdc++.h>
using namespace std;

class Element {
    public: 
        int row, col, val;
};

class SparseMatrix {
    public:
        int rows, cols;
        vector<Element> data;
        void addElement(int r, int c, int v) {
            if (v != 0) data.push_back({r, c, v});
        }

        void sortMatrix(){
            auto k = data.end()-1;
            for (auto i = data.begin(); i != data.end(); i++)
            {
                for (auto j = data.begin(); j != k; j++)
                {
                    if(j->row > (j+1)->row){
                        swap(*j, *(j+1));
                    }
                }
                k--;
                
            }

        }

        void display() {
            cout << "Row Col Val\n";
            // sortMatrix();
            for (auto &e : data) {
                cout << e.row << "   " << e.col << "   " << e.val << "\n";
            }
        }
};

SparseMatrix addMatrix(SparseMatrix a, SparseMatrix b){
    SparseMatrix res;

}

int main(){
    SparseMatrix mat;
    mat.addElement(0,0,3);
    mat.addElement(6,0,3);
    mat.addElement(0,2,3);
    mat.addElement(5,3,3);

    mat.display();
    mat.sortMatrix();
    mat.display();



    return 0;
}
