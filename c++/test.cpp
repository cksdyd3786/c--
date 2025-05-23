#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;
string kor[MAX], eng[MAX];

int main() {
    ifstream fin("animal.txt");
    if (!fin) {
        cout << "animal.txt ������ �� �� �����ϴ�." << endl;
        return 1;
    }

    int count = 0;
    while (fin >> kor[count] >> eng[count]) {
        count++;
        if (count >= MAX) break;
    }
    fin.close();

    string word;
    while (true) {
        cout << "���� �Է�: ";
        cin >> word;

        if (word == "Q" || word == "q") {
            cout << "bye" << endl;
            break;
        }

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (word == kor[i]) {
                cout << eng[i] << endl;
                found = true;
                break;
            } else if (word == eng[i]) {
                cout << kor[i] << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "�̵�� �ܾ��Դϴ�" << endl;
        }
    }

    return 0;
}
