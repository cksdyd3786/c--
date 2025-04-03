#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n, sum = 0;
    
    ifstream fin;
    fin.open("a.txt");

    while(fin >> n) {
        sum += n;
    }

    fin.close();
    cout << "гу = " << sum << endl; 
    
    return 0;
}