// Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas=0;
        int totalCost=0;
        for(int i=0;i<n;i++)
        {
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalGas < totalCost)  // if total cost is greater than total gas fuel then we can't cover all stations hence return -1
        {
            return -1;
        }
        int ramainingGas = 0;
        int index = 0;
        for(int i=0;i<n;i++)
        {
            ramainingGas+=gas[i]-cost[i];
            // if at any point ramainingGas will negative than this means our decided index will not be the answer and we have to take new index
            if(ramainingGas < 0)
            {
                index = i+1;      // newIndex can be the next gas station
                ramainingGas = 0;
            }
        }
        return index;
    }
};