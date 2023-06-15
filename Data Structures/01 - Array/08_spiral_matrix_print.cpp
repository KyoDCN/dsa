#include<iostream>
#include<vector>

using namespace std;

class SpiralMatrix {
    vector<vector<int>> m;
public:
    SpiralMatrix(int capacity) {
        m.reserve(capacity);
        for(auto v : m) {
            v.resize(capacity);
        }
    }

    SpiralMatrix(const vector<vector<int>> matrix) {
        this->m = matrix;
    }

    void print() {
        int size = m.size()-1;

        int top_row{0};
        int bottom_row{size};
        int left_col{0};
        int right_col{size};

        for(int i=0; i<m.size(); i++) {
            for(int i=top_row; i<=right_col; i++) {
                cout << m[top_row][i] << " ";
            }
            top_row++;

            for(int i=top_row; i<=bottom_row; i++) {
                cout << m[i][right_col] << " ";
            }
            right_col--;

            for(int i=right_col; i>=left_col; i--) {
                cout << m[bottom_row][i] << " ";
            }
            bottom_row--;

            for(int i=bottom_row; i>=top_row; i--) {
                cout << m[i][left_col] << " ";
            }
            left_col++;
        }
    }
};

int main() {
    vector<vector<int>> m{
        { 1,  2,  3,  4, 5},
        {16, 17, 18, 19, 6},
        {15, 24, 25, 20, 7},
        {14, 23, 22, 21, 8},
        {13, 12, 11, 10, 9}
    };

    SpiralMatrix sm(m);

    sm.print();
    return 0;
}