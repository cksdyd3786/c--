#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream fin("triangle.txt");
    if(!fin)
        cerr<< "�Է� ���� ���� ����"<< endl;
    cerr<< "�Է� ���� ���� ����"<< endl;

    ofstream fout("triangle_result.txt");
    if(!fout)
        cerr<< "�Է� ���� ���� ����"<< endl;
    cerr<< "�Է� ���� ���� ����"<< endl;
    int num, a, b, c;
    while(fin>> num>> a>> b>> c){
        if(a+b>=c || b+c>=a || a+c>=b)
            fout<< num<< " X"<< endl;
        else if(a==b && b==c)
            fout<< num<< " 0 ���ﰢ��"<< endl;
        else if(a==b || b==c || c==a)
            fout<< num<< " 0 �̵�ﰢ��"<< endl;
        else   
            fout<< num<< " 0"<< endl;
    }
    cout<< "�Ϸ�. ��������� Ȯ���غ�����."<< endl;
    fin.close();
    fout.close();

}