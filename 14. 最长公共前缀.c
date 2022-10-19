/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-19 22:40:14
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-19 22:41:53
 * @FilePath: /CCODE/LC/14. 最长公共前缀.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
char * longestCommonPrefix(char ** strs, int strsSize)
{
    //时间复杂度：O(col*row)   空间复杂度：O(1)
    int i = 0;
    for(i = 0;i < strlen(strs[0]);i++)
    {
        char c = strs[0][i];
        for(int j = 1;j < strsSize;j++)
        {
            if(i == strlen(strs[j]) || strs[j][i] != c)
            {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
}