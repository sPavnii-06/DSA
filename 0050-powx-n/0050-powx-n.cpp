class Solution {
public:
    double pow(double x, long long n){
        if(n==0) return 1;
        double half_ans=pow(x,n/2);
        if(n%2==0) return half_ans*half_ans;
        else return x*half_ans*half_ans;
    }
    double myPow(double x, int n) {
        long long power=n;
        if(n<0) return 1.0/pow(x,-power);
        return pow(x,power);
        
    }
};