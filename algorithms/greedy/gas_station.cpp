class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int tank=0, start=0;
        int total_gas=0, total_cost=0;
        for (int i=0; i<gas.size(); i++){
            tank = tank + gas[i]-cost[i];
            if (tank<0){
                start = i+1;
                tank = 0;
            }
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if (total_gas >= total_cost) return start;
        else return -1;
    }
};