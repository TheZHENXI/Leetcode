bool isPalindrome(int x)
{
    if(x < 0) return false;
    //1.整数翻转
    int cp_x = x;
    int sum = 0;
    while(x)
    {
        //如果是回文数，则翻转前后一致，不会溢出
        if(x > 0 && sum > (INT_MAX - x%10)/10) return false;
        sum = sum*10 + x%10;
        x /= 10;
    }
    //2.翻转之后对比是否相等
    return cp_x == sum;
}