// https://codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/000000000085a709#analysis

/*
Problem
You're playing a card game as a single player.
There are N cards. The i-th card has integer i written on it.

You first shuffle N cards randomly and put them in a pile. Take the card at the top of the pile to your hand. Then repeat the following process until the pile becomes empty:

Check the card on the top of the pile.
If the number on the card is larger than the number on the last card you took, take the card.
Otherwise, discard the card.
The score of the game is the number of cards in your hand at the end. With the given number of cards N, what is the expected score of the game?

Input
The first line of the input contains the number of test cases, T. T lines follow. Each line contains a single integer N, the number of cards in the pile.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the expected score at the end of the game.

y will be considered correct if it is within an absolute or relative error of 10^(-6) of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1≤T≤100.

Test Set 1
1≤N≤10.
Test Set 2
1≤N≤10^6.
Test Set 3
1≤N≤10^18.

Input     Output
2  
1       Case #1: 1.0
2       Case #2: 1.5

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const long double euler= 0.57721566490153286060651209008240243104215933593992;

void test()
{
    int n; cin>>n;
    cout.precision(12);
    if(n<=1e6)
    {
        long double x= 0;
        for(int i=1; i<=n; i++)
            x+= (long double)1/i;
        cout<<x<<'\n';
    }
    else
        cout<<log((long double)n)+euler<<'\n';
}

signed main()
{
    iostream::sync_with_stdio(false);
    int q; cin>>q;
    for(int t=1; t<=q; t++)
    {
        cout<<"Case #"<<t<<": ";
        test();
    }
}


