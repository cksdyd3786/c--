#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("animal.txt");
    if (!fin) {
        cout << "파일을 못찾음!" << endl;
        return 1;
    }

    string kor, eng;
    while (fin >> kor >> eng) {
        cout << kor << " - " << eng << endl;
    }
    return 0;
}
