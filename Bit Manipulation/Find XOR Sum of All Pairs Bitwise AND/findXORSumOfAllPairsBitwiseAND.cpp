// Find XOR Sum of All Pairs Bitwise AND

class Solution {
public:
    /*
        - (a1 & bi) XOR (a2 & bi) XOR ... XOR (an & bi) is the same as (a1 XOR a2 XOR ... XOR an) & bi
        - we calculate XOR sum of the first array xa. Then, the final result is 
            (xa & b1) XOR (xa & b2) XOR ... XOR (xa & bm), 
          resulting in a linear solution.
    */

    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor_arr1 = arr1[0];
        int n1 = arr1.size();
        for(int i=1;i<n1;i++)
        {
            xor_arr1 = xor_arr1^arr1[i];
        }

        int ans = 0;
        for(auto b: arr2)
        {
            ans = ans ^ (xor_arr1 & b);
        }

        return ans;
    }
};