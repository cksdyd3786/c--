#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    double score, sum = 0.0, cnt = 0.0, ave;
    double maxscore = -100.0;
    string name, maxname;

    ifstream fin;
    fin.open("scores.txt");
    if(!fin){
        cerr<< "Error opening scores.txt"<< endl;
    }

    while(fin >> name >> score){
        cnt++;
        sum += score;
        if(score>maxscore){
            maxscore = score;
            maxname = name;
        }
    }
    ave = sum/cnt;

    fin.close();

    ofstream fout("result.txt");
    if(!fout){
        cerr<< "Error opening result.txt"<< endl;
    }

    fout<< "�� "<< cnt<< "��"<<endl;

    fout<< fixed<< setprecision(2); 
    fout<< "�հ�: "<< sum<< endl;
    fout<< "���: "<< ave<< endl;
    fout<< "�ְ���: "<< maxname<< " "<< maxscore<<endl;

    fout.close();

    cout<< "Results saved in result.txt."<<endl;
    
    return 0;
}