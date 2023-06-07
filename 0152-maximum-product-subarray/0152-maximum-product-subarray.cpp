class Solution {
public:
   
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
//         int minVal = arr[0];
//     int maxVal = arr[0];

//     int maxProduct = arr[0];

//     for (int i = 1; i < n; i++) {

//         // When multiplied by -ve number,
//         // maxVal becomes minVal
//         // and minVal becomes maxVal.
//         if (arr[i] < 0)
//             swap(maxVal, minVal);

//         // maxVal and minVal stores the
//         // product of subarray ending at arr[i].
//         maxVal = max(arr[i], maxVal * arr[i]);
//         minVal = min(arr[i], minVal * arr[i]);

//         // Max Product of array.
//         maxProduct = max(maxProduct, maxVal);
//     }

//     // Return maximum product found in array.
//     return maxProduct;
        
        //second method like kadane algo
        int prod = 1; int maxi = arr[0];
        for(int i = 0; i < arr.size(); i++){
            prod = prod*arr[i];
            maxi = max(prod, maxi);
            if(prod == 0) prod = 1;
        }
        prod = 1;
        for(int i = arr.size()-1; i >= 0; i--){
            prod = prod*arr[i];
            maxi = max(prod, maxi);
            if(prod == 0) prod = 1;
        }
        return maxi;

    }
};