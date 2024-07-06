class Solution { // Could always use DP but I thought BFS would be faster? queue might just be too expensive...
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        while(coins.size() && coins.back() > amount)
            coins.pop_back();
        sort(coins.begin(), coins.end(), greater<int>());

        vector<int> min(amount + 1, 0); min[amount] = -1; min[0] = 0; 

        queue<int> bfs; bfs.push(0); int val;
        while(!bfs.empty()) {
            val = bfs.front(); bfs.pop();

            for(const int& coin : coins) {
                if(val + coin == amount)
                    return min[val] + 1;
                else if(val + coin < amount && !min[val + coin]) {
                    min[val + coin] = min[val] + 1;
                    bfs.push(val + coin);
                }
            }
        }

        return min[amount];

        /*
        sort(coins.begin(), coins.end());
        while(coins.size() && coins.back() > amount)
            coins.pop_back();

        vector<int> min(amount + 1, 1e4 + 1); min[0] = 0; 
        for(int i = 0; i < amount; ++i) {
            if(min[i] > 1e4)
                continue;
            
            for(const int& coin : coins) {
                if(i + coin <= amount)
                    min[i + coin] = std::min(min[i + coin], min[i] + 1);
                else
                    break;
            }
        }
        
        return min[amount] > 1e4 ? -1 : min[amount];
        */
    }
};