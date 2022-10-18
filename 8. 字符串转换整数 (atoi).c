/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-18 20:54:15
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-18 20:54:47
 * @FilePath: /CCODE/8. 字符串转换整数 (atoi).c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int myAtoi(char * s)
{
    int start = 0, len = strlen(s);
    //1.跳过前导空格
    while(s[start] == ' ') start++;
    if(start == len) return 0;
    //2.读取'+' 、'-'
    int sign = 1;
    if(s[start] == '-') 
    {
        sign = -1;
        start++;
    }
    else if(s[start] == '+') start++;
    //3.读取数字符号
    long  ans = 0;
    for(int i = start;i < len && isdigit(s[i]);i++)
    {
        int x = s[i] - '0';
        ans = ans*10 + x*sign;
        //4.判断溢出
        if(ans >= INT_MAX) return INT_MAX;
        if(ans <= INT_MIN) return INT_MIN;
    }
    


    return ans;
}