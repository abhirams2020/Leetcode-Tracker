class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int start = 0, peak = -1, end = 0;
        int res = 0;
        for(int i=0;i<arr.size();i++){
            if(i>0 && i<arr.size()-1 && arr[i-1]<arr[i] && arr[i+1]<arr[i]){
                peak = i;
                
                start = i;
                while(start>0 && arr[start-1]<arr[start]){
                    start--;
                }
                
                end = i;
                while(end<arr.size()-1 && arr[end]>arr[end+1]){
                    end++;
                }
                
                res = max(res, end - start + 1);
            }
        }
        return res;
    }
};