class Solution {
public:
    void moveZeroes(vector<int>& arr) {
       int j=0; //keep maintain non zero element
	for(int i=0;i<arr.size();i++){
		if(arr[i]!=0){
			//that's mean wha per non zero h to j++ kreneg hi
			swap(arr[i],arr[j]);
			j++;
		}
	}
	return;
    }
};