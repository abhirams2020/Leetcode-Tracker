class Solution {
public:
//     // BRUTE FORCE APPROACH
    
//     // from k=1, check if time taken less than h
//     // if time more than allowed, increase speed of eating
//     int solve(vector<int> &piles, int h, double k){
//         int time = 0;
//         // take ceil(piles[i]/k). if piles[i]=11,k=5 time taken will be 2 instead of 3.
//         for(auto i:piles){
//             time += ceil(i/k);
//         }
//         if(time<=h){
//             return k; 
//         }
//         return solve(piles,h,k+1);
//     }
    
//     int minEatingSpeed(vector<int>& piles, int h) {
//         return solve(piles,h,1);
//     }
    
    // BINARY SEARCH APPROACH
    
    // max possible speed is finishing each pile in 1 hour. In that case speed = max(piles[i])
    // do binary search from range k=1 to k=max(piles[i])
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1, maxSpeed = INT_MIN;
        for(auto i:piles){
            maxSpeed = max(maxSpeed, i);
        }
        while(minSpeed < maxSpeed){
            int time = 0;
            int midSpeed = minSpeed+(maxSpeed-minSpeed)/2;
            for(auto i:piles){
                time += ceil((double)i/midSpeed);
            }
            // if time taken with midSpeed <=h, move maxSpeed to midSpeed. Not midSpeed-1 since midSpeed is valid ans.
            // if time taken with midSpeed > h, move minSpeed to midSpeed + 1 since midSpeed is invalid ans.
            if(time<=h){
                maxSpeed = midSpeed;
            }
            else if(time>h){
                minSpeed = midSpeed+1;
            }
        }
        return maxSpeed;
    }
};