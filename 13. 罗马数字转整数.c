/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-19 22:39:24
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-19 22:39:28
 * @FilePath: /CCODE/LC/1.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
int romanToInt(char * s)
{
    int map[126];
    map['I'] = 1;map['V'] = 5;map['X'] = 10;
    map['L'] = 50;map['C'] = 100;map['D'] = 500;
    map['M'] = 1000;
    int ans = 0,i = 0,len = strlen(s);
    for(i = 0;i < len && i+1 < len ;i++)
    {   //当前位置的罗马数字比右侧的小，则为负；否则为正
        if(map[s[i]] < map[s[i+1]]) ans -= map[s[i]];
        else ans += map[s[i]];
    }
    //加上最后一个罗马数字
    ans += map[s[i]];
    return ans;
}