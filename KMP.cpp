#include <iostream>
#include <vector>
#include <string>

using namespace std;

void GetNext(string& str, vector<int>& next) {
    next[0] = -1;
    int k = -1;
    int j = 0;

    while(j < str.size() - 1) {
        if( k == -1 || str[k] == str[j]) {
            ++k;
            ++j;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
}

int strStr(string &source, string &target) {
    if(target.size() > source.size()) return -1;
    if(target.size() == 0) return 0;
    /*
    // Brute Force

    for(int i = 0; i < source.size() - target.size() + 1; ++i) {
        for(int j = 0; j < target.size(); ++j) {
             if(source[i + j] == target[j]) {
                if(j == target.size() - 1) return i;
            }
            else {
                break;
            }
        }   
    }

    return -1;
    */

    // KMP algorithm
    int srclen = source.size();
    int tarlen = target.size();
    vector<int> next(tarlen);
    GetNext(target, next);

    int i = 0;
    int j = 0;
        
    while(i < srclen && j < tarlen) {
        if(j == -1 || source[i] == target[j]) {
            if(j == target.size() - 1) return i - j;
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }

    return -1;
}

int main() {
    string source = "abcde";
    string target = "e";

    cout << strStr(source, target) << endl;
    
    return 0;
}
