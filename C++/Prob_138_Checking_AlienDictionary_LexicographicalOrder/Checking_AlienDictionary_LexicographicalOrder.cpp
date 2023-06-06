// Checking_AlienDictionary_LexicographicalOrder

#include <bits/stdc++.h> 

bool isSortedLexicographically(string& word1, string& word2, string& orders) {
    int len1 = word1.length();
    int len2 = word2.length();
    int i = 0;

    while (i < len1 && i < len2) {
        int index1 = orders.find(word1[i]);
        int index2 = orders.find(word2[i]);

        if (index1 < index2) {
            return true;
        } else if (index1 > index2) {
            return false;
        }

        i++;
    }

    return len1 <= len2;
}

bool alienDictonary(int n, vector<string> &w, string &orders)
{
    for (int i = 1; i < n; i++) {
        if (!isSortedLexicographically(w[i - 1], w[i], orders)) {
            return false;
        }
    }

    return true;
}