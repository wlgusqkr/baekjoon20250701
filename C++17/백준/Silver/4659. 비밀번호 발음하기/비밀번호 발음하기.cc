#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;

int main() {

    string str;
    while(cin >> str) {
        if(str.compare("end") == 0) {
            break;
        }
        bool bFalg = true;
        char beforeChar = str[0];
        bool bConsonant[3] = {false};
        bool bVowel[3] = {false};
        if((str.find("e") == string::npos) && (str.find("a") == string::npos) && (str.find("o") == string::npos) && (str.find("u") == string::npos) && (str.find("i") == string::npos)) {
            bFalg = false;
        }
        for (int i = 2; i < str.length(); i++) {
            fill(&bVowel[0], &bVowel[0] + 3, false);
            fill(&bConsonant[0], &bConsonant[0] + 3, false);
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i') {
                bVowel[0] = true;
            } else {
                bConsonant[0] = true;
            }
            
            for(int j = 1; j <= 2; j++) {
                if(str[i - j] == 'a' || str[i - j] == 'e' || str[i - j] == 'o' || str[i - j] == 'u' || str[i - j] == 'i') {
                    bVowel[j] = true;
                } else {
                    bConsonant[j] = true;
                }
            }
            if((bConsonant[0] == bConsonant[1]) && (bConsonant[1] == bConsonant[2])) {
                bFalg = false;
            }
            
        }
        for (int i = 1; i < str.length(); i++) {
            if(beforeChar == str[i]) {
                if(beforeChar == 'e' || beforeChar == 'o') {
                    
                } else {
                    bFalg = false;
                }
            }
            beforeChar = str[i];
        }
        
        if(bFalg == false) {
            cout << "<" << str << "> is not acceptable." << '\n';
        } else {
            cout << "<" << str << "> is acceptable." << '\n';
        }
    }
}
