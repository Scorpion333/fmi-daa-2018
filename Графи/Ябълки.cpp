#include<iostream>
using namespace std;

struct Apple {
    int row, col;
    void read();
    bool is_bad();
    bool is_valid();
    void make_bad();
    void make_neighbours_bad();
};

const int MAX_DIMENSION = 1000;
int rows, cols, days;

bool bad[MAX_DIMENSION + 1][MAX_DIMENSION + 1] = { false };
Apple bad_apples[MAX_DIMENSION * MAX_DIMENSION];
int bad_apples_number = 0;

void Apple::read() {
    cin >> row >> col;
}
bool Apple::is_bad() {
    return bad[row][col];
}
bool Apple::is_valid() {
    return 0 < row && row <= rows
        && 0 < col && col <= cols;
}
void Apple::make_bad() {
    if (is_valid() && !is_bad()) {
        bad[row][col] = true;
        bad_apples[bad_apples_number] = *this;
        bad_apples_number++;
    }
}
void Apple::make_neighbours_bad() {
    row++; make_bad(); row--;
    row--; make_bad(); row++;
    col++; make_bad(); col--;
    col--; make_bad(); col++;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> rows >> cols >> days;

    Apple apple;
    apple.read();
    apple.make_bad();
    if (cin) {
        apple.read();
        apple.make_bad();
    }

    for (int day = 1; day <= days; day++) {
        int bad_apples_number_yesterday = bad_apples_number;
        for (int i = 0; i < bad_apples_number_yesterday; i++) {
            bad_apples[i].make_neighbours_bad();
        }
    }
    cout << rows*cols - bad_apples_number << '\n';
}