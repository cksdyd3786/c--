#include <iostream> 
#include <fstream>
using namespace std;

int main(){
    char ch;
    int a = 0, b = 0, c = 0;
    fstream fin("a.txt");
    if(!fin) cerr<< "?? ?? ?? ??!"<< endl;

    while(cin>> ch){
        if(ch == ' '){
            a++;
        }
        else if(ch == '\n'){
            b++;
        }
        else{
            c++;
        }
    }

    cout<< a<< " "<< b<< " "<< c<< endl;

    return 0;
}
