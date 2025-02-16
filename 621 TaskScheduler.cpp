class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ++n;

        vector<int> numTasks(26, 0);
        for(const char& task : tasks)
            ++numTasks[task - 'A'];

        priority_queue<pair<int, char>> candidates; 
        for(int i = 0; i < 26; ++i) {
            if(numTasks[i])
                candidates.push({numTasks[i], i});
        }

        bool tasksIdling;
        int intervals = 0;
        vector<int> timeout(26, 0);
        while(true) {
            tasksIdling = false;
            for(int i = 0; i < 26; ++i) {
                if(timeout[i]) {
                    --timeout[i];

                    if(!timeout[i])
                        candidates.push({numTasks[i], i});
                    else
                        tasksIdling = true;
                } 
            }

            if(!candidates.empty()) {
                --numTasks[candidates.top().second];

                if(numTasks[candidates.top().second])
                    timeout[candidates.top().second] = n;

                candidates.pop();
            }
            else if(!tasksIdling)
                break;

            ++intervals;
        }

        return intervals;
    }
};