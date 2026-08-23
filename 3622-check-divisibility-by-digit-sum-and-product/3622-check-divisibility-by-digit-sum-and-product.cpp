class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;

        int temp = n;
        while(temp){
            sum += temp % 10;
            product *= temp % 10;
            temp /= 10;
        }

        return n % (sum + product) == 0;
    }
};