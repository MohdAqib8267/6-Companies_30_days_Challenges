class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1){
            //if only one seat then 100% probabilty that nth passesnger get their own seat
            return (double)1;
        }
        else{
            // The probability that the second passenger gets their own seat is 0.5 because they either take their own seat or pick a seat randomly. The probability that the third passenger gets their own seat is also 0.5 because they either take their own seat (if it is still available) or pick a seat randomly. Similarly, the probability that the fourth and fifth passengers get their own seat is also 0.5.
            
            //means that nth paasenger ke liye agar nth seat khali hai to wo uspe betheyga wrna randomely kisi or pe betheyga..... ab uski seat khali hone ki probability 1/2 hogi q ki khi first passenger na beth gya ho ab jo uske khali hone ki probability hogi whi nth passenger ke milne ki hogi 
            //yani aadhi to uske khali hone ki or aadhi baki sab randomely kisi per bethne ki
            //to jo khali hone per use milne ki probability 1/2 ho jayegi
            
            
            return (double)1/2;
        }
    }
};