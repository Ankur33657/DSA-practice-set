class Solution {
public:
    int digit(int x){
      int cnt=0;
        while(x!=0){
            cnt++;
            x/=10;
        }
        return cnt;
    }
    int reverse(int x) {
        long long num=0;
        int d=digit(x);
        
        while(x!=0){
            int rem=x%10;
            if(num<-(pow(2,31)) || num>(pow(2,31)))return 0;
            num=num+(rem*(pow(10,d-1)));
            
            d--;
            x=x/10;
        }
        return num;
    }
};