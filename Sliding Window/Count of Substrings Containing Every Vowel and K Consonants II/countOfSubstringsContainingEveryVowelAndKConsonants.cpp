// Count of Substrings Containing Every Vowel and K Consonants II - O(N)

class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }

    long long atLeastK(string word, int k)
    {
        unordered_map<char, int> vowel;
        int notVowel = 0;
        int left = 0;
        int n = word.length();
        long long ans = 0;
        for(int right=0;right<n;right++)
        {
            if(isVowel(word[right]))
            {
                vowel[word[right]]++;
            }
            else
            {
                notVowel++;
            }

            while(vowel.size() == 5 && notVowel >= k)
            {
                ans += n - right;
                if(isVowel(word[left]))
                {
                    vowel[word[left]]--;
                }
                else
                {
                    notVowel--;
                }

                if(vowel[word[left]] == 0)
                {
                    vowel.erase(word[left]);
                }
                left++;
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k+1);
    }
};