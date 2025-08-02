#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;
int main(){
    string writingInput;
    int consinance = 0;
    int vowels = 0;
    char previouscharicter = 'x';
    int cv = 0;
    int vv = 0;
    int vc = 0;
    int cc = 0;
    bool vow = false;
    array<char, 10> vowelist = {'a', 'e', 'i','o', 'u','A', 'E', 'I','O', 'U'};
    getline(cin, writingInput);
    for (char c : writingInput){
        vow = false;
        if(c != ' ' && c != '.' && c != ',' && c != '?' && c != '!' && c != '"' && c != ';' && c != '-'){
            for(char v : vowelist){
                if(v == c){
                    vowels ++;
                    if(previouscharicter == 'c'){
                        vc++;
                    }
                    if(previouscharicter == 'v'){
                        vv++;
                    }
                    previouscharicter = 'v';
                    vow = true;
                    break;
                }
            }
            if(vow != true){
                consinance ++;
                if(previouscharicter == 'c'){
                    cc++;
                }
                if(previouscharicter == 'v'){
                    cv++;
                }
                previouscharicter = 'c';
            }
            cout << c << " ";

        }
    }
    double cpercent = ((double)consinance / (consinance + vowels));
    double vpercent = ((double)vowels / (consinance + vowels));
    double predictedcc = cpercent * cpercent * 100;
    double predictedvv = vpercent * vpercent * 100;
    double predictedcv = cpercent * vpercent * 100;
    double predictedvc = vpercent * cpercent * 100;
    cpercent = cpercent * 100;
    vpercent = vpercent * 100;
    double totalpairs = cc + cv + vc + vv;
    double actualcc = ((double)cc / totalpairs) * 100;
    double actualcv = ((double)cv / totalpairs) * 100;
    double actualvc = ((double)vc / totalpairs) * 100;
    double actualvv = ((double)vv / totalpairs) * 100;
    cout << "\n";
    cout << "conconent: " << cpercent << "%" << "\n";
    cout << "vowel: " << vpercent << "%" << "\n";
    cout << "predicted cc: " << predictedcc << "%" << "\n";
    cout << "predicted cv: " << predictedcv << "%" << "\n";
    cout << "predicted vc: " << predictedvc << "%" << "\n";
    cout << "predicted vv: " << predictedvv << "%" << "\n";
    cout << "actual cc: " << actualcc << "%" << "\n";
    cout << "actual cv: " << actualcv << "%" << "\n";
    cout << "actual vc: " << actualvc << "%" << "\n";
    cout << "actual vv: " << actualvv << "%" << "\n";
    if(actualcc != predictedcc && actualcv != predictedcv && actualvc != predictedvc && actualvv != predictedvv){
        cout << "This is a dependent system, prooving Markovs theory. YOU DO NOT HAVE FREE WILL!!!!" << "\n";
    }else{
        cout << "This controdicts Markovs theory. YOU DO HAVE FREE WILL! congrats!" << "\n";
    }
}