#include <iostream>
#include <string> 

using namespace std;  

int main() {
    int  k;
    cin >> k;
    string temp;
    cin >> temp;
    int i = 0;
    while (temp != "End") {
        if (i == k) {
            i = -1;
            cout << temp << endl;
        } else if (temp == "ChuiZi") {
            cout << "Bu" << endl;
        } else if (temp == "JianDao") {
            cout << "ChuiZi" << endl;
        } else if (temp == "Bu"){
            cout << "JianDao" << endl;
        }
        cin >> temp;
        i++;
    }
    return 0;  
} 
