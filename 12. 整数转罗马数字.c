/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-19 22:38:28
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-19 22:38:32
 */
char * intToRoman(int num)
{
    char thousands[4][5] = {"","M","MM","MMM"};
    char hundreds[10][5] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char tens[10][5] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char ones[10][5] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

    char* res = (char*)calloc(16,sizeof(char));//最长15个字符加个\0
    strcat(res,thousands[num/1000]);     //num的千位转换
    strcat(res,hundreds[(num%1000)/100]);//num的百位转换
    strcat(res,tens[(num%100)/10]);      //num的十位转换
    strcat(res,ones[num%10]);            //num的个位转换

    return res;
}
