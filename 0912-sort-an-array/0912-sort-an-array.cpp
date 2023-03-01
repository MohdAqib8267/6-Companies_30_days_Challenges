class Solution {
public:
    void merge(vector<int>& nums,int l,int mid,int r){
        int size1=mid-l+1;
        int size2=r-mid;
        int n1[size1], n2[size2];
        for(int i=0;i<size1;i++){
            n1[i]=nums[i+l];
        }
        for(int j=0;j<size2;j++){
            n2[j]=nums[mid+j+1];
        }
        
        //compare and sort
        int idx=l;
        int i=0,j=0;
        while(i<size1 and j<size2){
            if(n1[i]<=n2[j]){
                nums[idx++]=n1[i];
                i++;
            }
            else{
                nums[idx++]=n2[j];
                j++;
            }
        }
        
        //for remaining
        while(i<size1){
            nums[idx++]=n1[i];
            i++;
        }
        while(j<size2){
            nums[idx++]=n2[j];
            j++;
        }
    }
    void mergeSort(vector<int>& nums,int l,int r){
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums, l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        //merge sort
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};