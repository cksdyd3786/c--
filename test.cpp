#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream fin("triangle.txt");
    if(!fin)
        cerr<< "입력 파일 오픈 실패"<< endl;
    cerr<< "입력 파일 오픈 성공"<< endl;

    ofstream fout("triangle_result.txt");
    if(!fout)
        cerr<< "입력 파일 오픈 실패"<< endl;
    cerr<< "입력 파일 오픈 성공"<< endl;
    int num, a, b, c;
    while(fin>> num>> a>> b>> c){
        if(a+b>=c || b+c>=a || a+c>=b)
            fout<< num<< " X"<< endl;
        else if(a==b && b==c)
            fout<< num<< " 0 정삼각형"<< endl;
        else if(a==b || b==c || c==a)
            fout<< num<< " 0 이등변삼각형"<< endl;
        else   
            fout<< num<< " 0"<< endl;
    }
    cout<< "완료. 출력파일을 확인해보세요."<< endl;
    fin.close();
    fout.close();

}