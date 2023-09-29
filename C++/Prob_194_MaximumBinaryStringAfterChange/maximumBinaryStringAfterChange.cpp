// Maximum Binary String After Change

class Solution {
public:
    /*
        Step 1 -> Count number of zeroes
        Step 2 Only one '0' will be left as baaki sb '0's club krke "00"--> "10" bnayege
         Dry run --> "110010101"

           -->  111010101 (00 -> 10)
           -->  111001101 (10 -> 01)
           -->  111101101 (00 -> 10)  00 -> 10 bna rha aur '10' jo bnra vo 01 bnjara
           -->  111101011 (10 -> 01)
           -->  111100111 (10 -> 01)
           -->  111110111 (00 -> 10)
        now see 1st zero i=2 index pe tha vo shift hogya apne se aage (no of zeroes -1) times = (2+4-1)= 5th 
        index  aur dekho 5th index pe hi 0 hai "111110111"
        
    */

    string maximumBinaryString(string binary) {
        int first = 0;
        int count = 0;
        int n = binary.length();
        for(int i=n-1;i>=0;i--)
        {
            if(binary[i] == '0')
            {
                count++;
                first = i;
            }
            binary[i] = '1';
        }

        if(!count)
        {
            return binary;
        }

        binary[first + count - 1] = '0';
        return binary;
    }
};