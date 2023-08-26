// Text Justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& word, int maxWidth) {
        vector<string> ans;
        int n = word.size();
        int i=0;
        while(i<n)
        {
            int lineLength = word[i].size();
            int j = i+1;
            while(j<n && lineLength + word[j].size() + (j-i) <= maxWidth)
            {
                lineLength = lineLength += word[j].size();
                j++;
            }

            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;

            string line;

            if(numWords == 1 || j == n)
            {
                line += word[i];

                for(int k=i+1;k<j;k++)
                {
                    line += ' ' + word[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else
            {
                int spaceBetweenWords = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);
                line = word[i];

                for(int k=i+1;k<j;k++)
                {
                    line += string(spaceBetweenWords, ' ');
                    if(extraSpaces > 0)
                    {
                        line += ' ';
                        extraSpaces--;
                    }
                    line += word[k];
                }
            }
            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};