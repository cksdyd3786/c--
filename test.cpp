#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long int n, num, numSize;

    cout<< "Á¤¼ö ÀÔ·Â: ";
    cin>> num;
    cout<< "ÀÚ¸´¼ö ÀÔ·Â: ";
    cin>> numSize;
    
    for(int i=1; i<numSize; i++){
        num /= 10;
    }
    if(num==0){
        cout<< "ÀÚ¸´¼ö ¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù.";
        return 0;
    }
    cout<<num%10;

    return 0;
}