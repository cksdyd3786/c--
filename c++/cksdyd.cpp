#include <iostream> 
using namespace std;
double myavg(int, int, int);

int main() {
int k, e, m;

cout << "국영수 점수 입력: "; 
cin >> k >> e >> m;
cout.precision(2);
cout << "평균은 " << myavg(k,e,m) << " 입니다." << endl; 
return 0;
}
double myavg(int a, int b, int c){
    double result;
    result = (a+b+c)/3.0;
    return result;
}