

#include <iostream>
using namespace std;

int n,
table[100][100],
freqCol[100],
freqRow[100];
bool solutionFound = false;

bool isValidPlace(int x, int y) {
    if (freqRow[x] == 1 || freqCol[y] == 1)
        return false;
    int i = 0, j = 0;
    // Mark diagonals
    i = x + 1;
    j = y + 1;
    for (; i < n && j < n;) {
        if (table[i][j] == 1)
            return false;
        j++; i++;
    }
    i = x - 1;
    j = y - 1;
    for (; i >= 0 && j >= 0;) {
        if (table[i][j] == 1)
            return false;
        j--; i--;
    }
    i = x + 1;
    j = y - 1;
    for (; i < n && j >= 0;) {
        if (table[i][j] == 1)
            return false;
        j--; i++;
    }
    i = x - 1;
    j = y + 1;
    for (; i >= 0 && j < n;) {
        if (table[i][j] == 1)
            return false;
        j++; i--;
    }
    return true;

}
void backtrack(int step) {
    if (solutionFound)
        return;
    if (step == n) {
        solutionFound = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i][j] == 0)
                    cout << "_ ";
                else
                    cout << "* ";
            }
            cout << "\n";
        }
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!table[step][j] && isValidPlace(step, j)) {
            table[step][j] = freqRow[step] = freqCol[j] = 1;
            backtrack(step + 1);
            table[step][j] = freqRow[step] = freqCol[j] = 0;
        }
    }
}


int main() {
    cin >> n;
    backtrack(0);
    return 0;
}
