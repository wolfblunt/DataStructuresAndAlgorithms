// Slot Game

#include <bits/stdc++.h> 
int slotColorNumber(char a)
{
    if(a=='B')
        return 0;
    if(a=='G')
        return 1;
    if(a=='R')
        return 2;
    
    return 3;
}
int slotScore(string &original, string &guess)
{
	vector<int> frequency(4, 0);
    int points=0;
    for(int i=0;i<original.size();i++)
    {
        if(original[i]==guess[i])
            points+=2;
        else
            frequency[slotColorNumber(original[i])]+=1;
    }
    for(int i=0;i<guess.size();i++)
    { 
        if((original[i]!=guess[i]) && (frequency[slotColorNumber(guess[i])] > 0))
        {
            points+=1;
            frequency[slotColorNumber(guess[i])]=0;
        }
    }
    return points;
}