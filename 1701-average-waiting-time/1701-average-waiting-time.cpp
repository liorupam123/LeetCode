class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        if(n == 0){
            return n;
        }

        //customers[i][0] = arrivalTime
        //customers[i][1] = timeToCook

        int time = 0;
        double wait = 0;

        for(int i=0; i<n; i++){
            time = max(customers[i][0], time) + customers[i][1];
            wait += time - customers[i][0];
        }

        return wait / (double)n;
    }
};