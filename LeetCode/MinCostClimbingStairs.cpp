/*
//memoized solution
class Solution {
public:

    using hash_table = std::unordered_map<string, int>;
    int minCostHelper(vector<int>& steps, int cost, size_t i, hash_table& mem_table)
    {
        string key =to_string(i) + " : " + to_string(cost);
        if (mem_table.find(key) != mem_table.end())
            return mem_table[key];

        if (i < steps.size())
        {
            int curr = cost + steps[i];
            int result = min(minCostHelper(steps, curr, i + 1, mem_table), minCostHelper(steps, curr, i + 2, mem_table));

            mem_table[key] = result;
            return result;
        }
        else
            return cost;

    }

    int minCostClimbingStairs(vector<int>& cost) {
        hash_table mem_table; 
        return min(minCostHelper(cost, 0 , 0, mem_table), minCostHelper(cost, 0, 1, mem_table));

    }
};

*/


// dynamic programming solution 
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {

        
        std::vector<int> dp(cost.size(), INT_MAX);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < cost.size(); ++i)
            dp[i] =  cost[i] + min(dp[i - 1],dp[i - 2]);
            
        
        return min(dp[dp.size() - 2 ], dp[dp.size() -1]);

    }
};
