#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProductSubArray(const vector<int>& nums){
    if(nums.empty()) return 0;
    int maxProduct = nums[0];
    int currentMax=nums[0];
    int currentMin=nums[0];
    for(size_t i=1;i<nums.size();i++){
        if(nums[i]<0){
            swap(currentMax,currentMax);
        }
        currentMax = max(nums[i],nums[i]*currentMax);
        currentMin = min(nums[i],nums[i]*currentMin);
        maxProduct = max(maxProduct,currentMax);
    }
    return maxProduct;
}
int main(){
    vector<int> arr = {-2,0,3,4};
    cout << "Maximum product subarray : "<<maxProductSubArray(arr) <<endl;

    return 0;

}