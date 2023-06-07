class Solution {
public:
   int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a or b or c){
            int lastbit_a = a & 1;
            int lastbit_b = b & 1;
            int lastbit_c = c & 1;
            if((lastbit_a | lastbit_b) == 0 && lastbit_c == 1) {
                ans++;
            }else if((lastbit_a | lastbit_b) == 1 && lastbit_c == 0){
                if(lastbit_a && lastbit_b) ans += 2;
                else ans++;
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return ans;
    }
};