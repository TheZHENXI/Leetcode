
//思路没问题，提交越界
char * convert(char * s, int numRows)
{
    assert(s != NULL);
    int len = strlen(s);

    char** c = (char**)malloc(sizeof(char*)*numRows);
    for(int i = 0;i < numRows;i++)
    {
        c[i] = (char*)calloc(1111,sizeof(char));
    } 
    int down = -1;//方向
    int row = 0;//行数
    for(int i = 0;i < len;i++)
    {
        strncat(c[row],&s[i],1);
        if(row == 0 || row == numRows-1)
        {
            down = -down;
        }
        row += down;
    }
    for(int i = 1;i < numRows;i++)//合并
    {
        printf(c[i]);
        strcat(c[0],c[i]);
    }
    return c[0];
}