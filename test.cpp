#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long int n, num, numSize;

    cout<< "���� �Է�: ";
    cin>> num;
    cout<< "�ڸ��� �Է�: ";
    cin>> numSize;
    
    for(int i=1; i<numSize; i++){
        num /= 10;
    }
    if(num==0){
        cout<< "�ڸ��� ������ ������ϴ�.";
        return 0;
    }
    cout<<num%10;

    return 0;
}