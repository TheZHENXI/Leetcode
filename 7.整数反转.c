
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x)
{
    int ans = 0;
    while(x)
    {
        if(x > 0 && ans*10 + x%10 > INT_MAX) return 0;
        if(x < 0 && ans*10 + x%10 < INT_MIN) return 0;
        ans = ans*10 + x%10;
        x /= 10;
    }
    return ans;
}