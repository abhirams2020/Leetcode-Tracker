class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0 ; i<n && arr[i]<=0 ; i++){
            if(i!=0 && (arr[i]==arr[i-1])){ // i will proceed only at non duplicate positions
                continue;
            }
            int sum = -arr[i];
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                if(arr[lo]+arr[hi]==sum){
                    vector<int> temp = {arr[i],arr[lo],arr[hi]};
                    res.push_back(temp);
                    int curr_lo = lo;
                    int curr_hi = hi;
                    // * removing duplicate trick *
                    // move lo to right till it reaches a larger value
                    // move hi to left till it reaches a smaller value
                    while(lo<=n-1 && arr[lo]==arr[curr_lo]){
                        lo++;
                    }
                    while(hi>=i+1 && arr[hi]==arr[curr_hi]){
                        hi--;
                    }
                }
                else if(arr[lo]+arr[hi]<sum){ // if arr[lo] + arr[hi] < sum, means lo needs to increase
                    lo++;
                }
                else {  // if arr[lo] + arr[hi] > sum, means hi needs to decrease
                    hi--;
                }
            }
        }
        return res;
    }
};