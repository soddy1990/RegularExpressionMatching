//
//  main.cpp
//  RegularExpressionMatching
//
//  Created by 黄美强 on 15/4/30.
//  Copyright (c) 2015年 黄 美强. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool containsstar(string &s){
    if (s.find('*') != string::npos) {
        return true;
    }
    return false;
}
bool containsdotstar(string &s){
    size_t pos = s.find('.');
    while(pos != string::npos) {
        if (pos == s.length()-1) {
            return false;
        }
        if(s.at(pos+1) == '*')
            return true;
        else
            pos = s.find('.',pos+1);
    }
    return false;
}

bool isMatch(string s, string p) {
    size_t plen = p.length();
    size_t slen = s.length();
    if(slen <= 0)
        return true;
    if(!containsstar(p) && plen < slen){
        return false;
    }
    if(containsdotstar(p)){
        return true;
    }
    
    unsigned int lastmatch = 0;
    int i = 0;
    
    for(int j = 0; i<slen && j<plen;){
        if(i == 0){
            if(s.at(i) == p.at(j) || p.at(j) == '.'){
                lastmatch = j;
                i++;
            }
            if(i == slen)
                return true;
            j++;
            continue;
        }
        
        if(s.at(i) == p.at(j) || p.at(j) == '.'){
            i++;
            j++;
            if(i == slen)
                return true;
            continue;
        }
        if (p.at(j) == '*') {
            if(s.at(i) != p.at(j-1)){
                j++;
                continue;
            }
            while (i<slen) {
                i++;
            }
            if (i == slen) {
                return true;
            }
            j++;
            continue;
        }
        if(s.at(i) != p.at(j) && j == plen-1){
            return false;
        }
        else{
            j = lastmatch+1;
            i = 0;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    string a = "a";
    string b = ".";
    cout<<isMatch(a,b);
    return 0;
}
