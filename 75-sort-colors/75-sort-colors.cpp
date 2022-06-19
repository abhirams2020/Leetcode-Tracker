class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l=0, r=arr.size()-1;
        for(int i=0; i<=r; ){
            if(arr[i]==0){
                swap(arr[i],arr[l]);
                l++;
                i++;
            }
            else if(arr[i]==1){
                i++;
            }
            else if(arr[i]==2){
                swap(arr[i],arr[r]);
                r--;
            }
        }
    }
};