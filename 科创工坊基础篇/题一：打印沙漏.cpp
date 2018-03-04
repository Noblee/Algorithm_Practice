#include <iostream>
#include <cmath>

using namespace std;

int print_star(int num, char c) {
    int n = (int) sqrt((num+1) / 2.0);
    for (int i = n; i > 0; i--, printf("\n")) {
        for (int j = 0; j < (n - i); j++)
            printf(" ");
        for (int j = 0; j < 2 * i - 1; j++)
            printf("%c", c);
    }
    for (int i = 2; i <= n; i++, printf("\n")) {
        for (int j = 0; j < (n - i); j++)
            printf(" ");
        for (int j = 0; j < 2 * i - 1; j++)
            printf("%c", c);
    }
    return num - 2 * n * n + 1;
}

int main() {
    int i;
    char c;
        cin >> i >> c;
        cout << print_star(i, c);
        cout<<endl;
    return 0;
}