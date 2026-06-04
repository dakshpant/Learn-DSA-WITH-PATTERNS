#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool canConstruct(string ransomNote, string magazine){
    unordered_map<char, int> have;
    unordered_map<char, int> need;
    for(int i = 0; i < ransomNote.size(); i++ ){
        need[ransomNote[i]]++;
    }
    for(int i = 0; i < magazine.size(); i++ ){
        have[magazine[i]]++;
    }

    for(auto i : need){
        int needChar = i.first;
        int freq_NeedChar = i.second;
        
        int freq_NeedChar_In_Have = have[needChar];
        if(freq_NeedChar_In_Have < freq_NeedChar){
            return false;
        }
    }
    return true; 

}

int main(){
    string ransomNote = "aa";
    string magazine = "aab";
    bool ans = canConstruct(ransomNote,magazine);
    cout<< ans << endl;
    return 0;
}