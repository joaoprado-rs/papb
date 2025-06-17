#include <iostream>
using namespace std;

int perm[8];
bool usado[8];
bool diag1[16];
bool diag2[16];
int count = 0;

void gen_col(int col, char input[8][8]) {
    if (col == 8) {
        count++;
        return;
    }

    for (int i = 0; i < 8; ++i) {
        if (input[col][i] == '*') continue;
        if (usado[i]) continue;
        if (diag1[col - i + 7]) continue;
        if (diag2[col + i]) continue;
        perm[col] = i;
        usado[i] = true;
        diag1[ col - i + 7 ] = true;
        diag2[ col + i ] = true;
        gen_col(col + 1, input);
        usado[i] = false;
        diag1[ col - i + 7 ] = false;
        diag2[ col + i ] = false;
    }
}

int main() {
    char input[8][8];
    for (int i = 0; i < 8; i++) {
        cin >> input[i];
    }

    gen_col(0, input);
    cout << count << endl;
}