#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("animal.txt");
    if (!fin) {
        cout << "������ ��ã��!" << endl;
        return 1;
    }

    string kor, eng;
    while (fin >> kor >> eng) {
        cout << kor << " - " << eng << endl;
    }
    return 0;
}
