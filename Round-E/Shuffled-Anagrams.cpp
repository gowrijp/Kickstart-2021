// https://codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/000000000085a152
/*
Problem
Let S be a string containing only letters of the English alphabet. An anagram of S is any string that contains exactly the same letters as S (with the same number of 
occurrences for each letter), but in a different order. For example, the word kick has anagrams such as kcik and ckki.

Now, let S[i] be the i-th letter in S. We say that an anagram of S, A, is shuffled if and only if for all i, S[i]≠A[i]. 
So, for instance, kcik is not a shuffled anagram of kick as the first and fourth letters of both of them are the same. 
However, ckki would be considered a shuffled anagram of kick, as would ikkc.

Given an arbitrary string S, your task is to output any one shuffled anagram of S, or else print IMPOSSIBLE if this cannot be done.
*/

// MY Solution :/ (Accepted)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test; cin>>test;
    for(int t=1; t<=test;t++){
        string s; cin>>s;
        vector<int> dict(256, 0);
        bool flag = false;
        for(int i=0;i<s.length();i++){
            dict[s[i]]++;
            if(dict[s[i]]>(s.length())/2){
                cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
                flag = true;
                break;
            }
        }
        string str = s;
        if(!flag){
                 // s = ababab
            int n = s.length(); // sorted str = aaabbb
            sort(str.begin(), str.end());
            while(!flag){
            for(int i=0;i<n;i++){
                int x = 0;
                if(str[i]==s[i]){
                    while(str[i+x]==s[i] and i+x<n){
                        x++;
                    }
                    if(i+x == n) x--;
                    
                    if(str[i+x]!=str[i]){
                       char temp = str[i];
                        str[i] = str[i+x];
                        str[i+x] = temp; 
                    }
                    else{
                        x = -i;
                        while(i+x<n and str[i+x]==s[i]){
                        x++;
                        }
                        if(str[i+x]!=str[i]){
                           char temp = str[i];
                            str[i] = str[i+x];
                            str[i+x] = temp; 
                        }
                    }
                }
                
            }
            int count=0;
            for(int i=0;i<n;i++){
                if(str[i]!=s[i]) count++;
            }
            if(count==n) flag=true;
            }
            cout<<"Case #"<<t<<": "<<str<<endl;
        }
        
        
        
    }
}
