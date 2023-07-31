// Shortest String That Contains Three Strings

class Solution {
private:
    // Function to check for a common part between two strings 'a' and 'b'
    // If string 'b' is found at the end of string 'a', then return 'a'
    // Otherwise, check for a common part between 'a' and 'b' and merge them while excluding the common part once
    // If no common part is found, merge 'a' and 'b' fully
    string checkCommonPart(string a, string b) {
        if (a.find(b) != string::npos) {
            return a;
        }
        for (int i = min(a.length(), b.length()); i >= 0; i--) {
            if (a.substr(a.length() - i) == b.substr(0, i)) {
                return a + b.substr(i);
            }
        }
        return a + b;
    }

    // Function to check if the merged string is valid and update the result
    void isValid(string merged, string& result) {
        // If the result string is empty or the merged string is shorter than the current result
        // Or if the lengths are the same but the merged string is lexicographically smaller
        // Update the result with the merged string
        if (result.empty() || merged.length() < result.length() || (merged.length() == result.length() && merged < result)) {
            result = merged;
        }
    }

public:
    // Function to find the minimum string formed by merging three input strings 'a', 'b', and 'c'
    string minimumString(string a, string b, string c) {
        vector<string> arr = {a, b, c};
        int n = arr.size();
        string result = "";

        // Generate all possible permutations of merging three strings 'a', 'b', and 'c'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && j != k && i != k) {
                        string merged = checkCommonPart(arr[i], arr[j]);
                        merged = checkCommonPart(merged, arr[k]);
                        isValid(merged, result);
                    }
                }
            }
        }

        return result;
    }
};