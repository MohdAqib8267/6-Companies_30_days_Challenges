class Solution {
 public:
//   Intuition
// Here we will apply greedy approach

// Approach
// In the question given that
// If there exists a solution, it is guaranteed to be unique
// -This lines clearly tells us that we have unique or no solution exists

// Here two cases are possible

// if our total_gas is less than our total cost in that case we can't complete our journey ,so will return -1
// Now we have a unique solution that means single starting_point exists
// To find that point we will keep track of my current_gas+=gas[i]-cost[i]
// lets suppose at any index our current gas became negative so we can clearly say that till that index all the gas station between ith and starting point are bad, starting point as well.
// So, this means we can start trying at next gas_station on the i+1 station
    
// Complexity
// Time complexity:O(N)
// Space complexity:O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0;
        int total_cost=0;
        int curr_gas=0;
        int starting_index=0;
        for(int i=0;i<n;i++){
            //calculate total gas
            total_gas += gas[i];
            //calculate total cost
            total_cost += cost[i];
            
            curr_gas += gas[i]-cost[i];
            if(curr_gas<0){
                //that clearly means, This index will never starting index
                //so we try for next index as a staring index
                starting_index=i+1;
                curr_gas=0;
            }
        }
        return (total_gas>=total_cost)?starting_index:-1;
    }
};