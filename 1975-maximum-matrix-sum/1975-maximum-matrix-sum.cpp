class Solution {
public:
    /*
	If number of -ve numbers are even, it means you can ALWAYS shift -1 in a
	fashion that you can cancel out the negative signs and make the numbers positive.
	So in that case, total sum (absolute value of all elements) will be your answer
	
	If number of -ve numbers are odd, then you can cancel out the negative sign 
	of large numbers so that they contribute to our over all sum.
	And notice that at the end, you will be left with one negative number.
	So, shift this negative sign to the smallest number
*/
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //we take biggest number in negative(means jiska positive me effect kam ho)
        int small=INT_MAX;
        long long count=0;//count negative numbers
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                
                if(matrix[i][j]<0){
                    count++;
                }
                
                //find smallest number(jiska sum per effect sbse kam ho)
                small = min(small,abs(matrix[i][j]));
                
            }
        }
        //simple se baat hai ki agar count positive even hua to sbhe negative number shift       //kr ke khud ko positive kr lenge koi negative nhi bachega to hum directlt sum //return denge
        if(count%2==0){
            return sum;
        }
        return sum-2*small; 
/*            agar count odd hua to hum dekhnge ki sum ko maximise krne k liye (count-1) elements to shifting kr k khud ko positive bna lenge bss ek number left reh jayega to maximise krne ke liye hum left us number ko chodenge jiska sum per effect kmm ho. jo ki hum small me nikal chuke */
/*            2 se multiply isliye q ki ek baar to humne usey positive kr k sum me jod rkha tha or ek baar uska negtive effect dalne ke liye example ke liye neechey
	/*		
			Why (sum-2*smallestMin) ????
				In simple words : You had first added that number, 
				so you need to subtract that addition and also in the
				end, you need to reduce the sum with that number.
				That's why we have to substract 2 times.
				See with the example below :
				[1,   2, 3]
				[-1, -2,-3]
				[1,   2, 3]
			
			
				Over all Sum "S"(all elements with abs value) = 18
				Negative count = 3 which is odd
				Smallest number which can be negative is "Min"= 1

				so, 
				[1,   2, 3]
				[-1,  2, 3]
				[1,   2, 3]

				Now, final sum "F" = 1 + 2 + 3 + (-1) + 2 + 3 + 1 + 2 + 3 = 16

				So, final result "F" = "S" - 2*Min  (i.e. 18 - 2*1) = 16
		*/
        
    }
};