#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// #include "contact.h"

// *********************************************
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12
#define MAX_AD 20
#define CAPACITY 3
//个人信息
struct PeoInfo
{
    char name[MAX_NAME];
    char Sex[MAX_SEX];
    char Tele[MAX_TEL];
    char AD[MAX_AD];
    /* data */
};
//通讯录类型
struct Contact 
{
    int size; //已添加的人数
    int capacity;//最大容量
    struct PeoInfo* data;//个人信息数组
    
};
//初始化
void InitContact(struct Contact* cp);
//打印显示
void ShowContact(struct Contact* cp);
//增加
void ADD(struct Contact* cp);
//删减
void Delete(struct Contact* cp);
void Search(struct Contact* cp);
void Modify(struct Contact* cp);
void Sort(struct Contact* cp);
void check(struct Contact* cp);
void destroy(struct Contact* cp);
const int FindByName(struct Contact* cp,char name[MAX_NAME]);
// *********************************************








//***************************************************************
void mean()
{
    printf("*************************************\n");
    printf("***********1.ADD       2.Delete******\n");
    printf("***********3.Search    4.Modify******\n");
    printf("***********5.Show      6.Sort********\n");
    printf("***********0.Exit********************\n");
}

int main()
{
    
    int input = 0;
    //创建通讯录
    struct Contact con;
   
    InitContact(&con);
    do
    {
        mean();
        printf("请选择>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                ADD(&con);
                break;
            case 2:
                Delete(&con);
                break;
            case 3:
                Search(&con);
                break;
            case 4:
                Modify(&con);
                break;
            case 5:
                ShowContact(&con);
                break;
            case 6:
                Sort(&con);
                break;            
            default:
                break;
        }
        /* code */
    } while (input);
    destroy(&con);
    return 0;
}
//****************************************************************


// ****************************************
#include <stdio.h>
// #include "contact.h"

void InitContact(struct Contact* cp)
{
    cp->data = (struct PeoInfo*)malloc(sizeof(struct PeoInfo)*3);
    cp->size = 0;
    cp->capacity = CAPACITY;
}

void ShowContact(struct Contact* cp)
{
    if(cp->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        printf("%-20s\t%-5s\t%-12s\t%-20s\n","名字","性别","电话","地址");
        for (int i = 0; i < cp->size; i++)
        {
            printf("%-20s\t%-5s\t%-12s\t%-20s\n",
            cp->data[i].name,
            cp->data[i].Sex,
            cp->data[i].Tele,
            cp->data[i].AD);
            /* code */
        }
    }
}

void ADD(struct Contact* cp)
{
    check(cp);
    printf("请输入联系人信息>\n");
    printf("姓名>");
    scanf("%s",&cp->data[cp->size].name);
    printf("性别>");
    scanf("%s",&cp->data[cp->size].Sex);
    printf("电话>");
    scanf("%s",&cp->data[cp->size].Tele);
    printf("地址>");
    scanf("%s",&cp->data[cp->size].AD);
    cp->size++;
}

void Delete(struct Contact* cp)
{
    char name[MAX_NAME];
    if(cp->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        printf("请输入要删除联系人的名字>");
        scanf("%s",&name);
        int pos = FindByName(cp,name);
        if(-1 == pos)
        {
            printf("找不到该联系人\n");
        }
        else
        {
            for(int i = pos;i < cp->size-1;i++)
            {
                cp->data[i] = cp->data[i+1];
            }
            cp->size--;
            printf("删除成功\n");
        }
        
    }
}

//-1表示找不到，
const int FindByName(struct Contact* cp,char name[MAX_NAME])
{
    for(int i = 0;i <cp->size;i++)
    {
        if(0 == strcmp(cp->data[i].name,name))
        {
            return i;
        }
    }
    return -1;
}

void Search(struct Contact* cp)
{
    char name[MAX_NAME];
    printf("请输入你要查找人的姓名>");
    scanf("%s",name);
    int pos = FindByName(cp,name);
    if(-1 == pos)
    {
        printf("通讯录无此人\n");
    }
    else
    { 
        printf("%-20s\t%-5s\t%-12s\t%-20s\n","名字","性别","电话","地址");
        printf("%-20s\t%-5s\t%-12s\t%-20s\n",
                        cp->data[pos].name,
                        cp->data[pos].Sex,
                        cp->data[pos].Tele,
                        cp->data[pos].AD);
    }
}

void Modify(struct Contact* cp)
{
    char name[MAX_NAME];
    printf("请输入你要修改人的姓名>");
    scanf("%s",name);
    int pos = FindByName(cp,name);
    if(-1 == pos)
    {
        printf("通讯录无此人\n");
    }
    else
    { 
        printf("姓名>");
        scanf("%s",&cp->data[pos].name);
        printf("性别>");
        scanf("%s",&cp->data[pos].Sex);
        printf("电话>");
        scanf("%s",&cp->data[pos].Tele);
        printf("地址>");
        scanf("%s",&cp->data[pos].AD);
    }
}

void Sort(struct Contact* cp)
{
    for(int i = 0;i < cp->size-1;i++)
    {
        for(int j = i;j < cp->size-1-i;j++)
        {
            if( strcmp(cp->data[j].name,cp->data[j+1].name) >0 )
            {
                char tmp[MAX_NAME];
                strcpy(tmp,cp->data[j].name);
                strcpy(cp->data[j].name , cp->data[j+1].name);
                strcpy(cp->data[j+1].name , tmp);

                // strcpy(tmp,cp->data[j].name);
                // strcpy(cp->data[j].name , cp->data[j+1].name);
                // strcpy(cp->data[j+1].name , tmp);
                //                 strcpy(tmp,cp->data[j].name);
                // strcpy(cp->data[j].name , cp->data[j+1].name);
                // strcpy(cp->data[j+1].name , tmp);
                //                 strcpy(tmp,cp->data[j].name);
                // strcpy(cp->data[j].name , cp->data[j+1].name);
                // strcpy(cp->data[j+1].name , tmp);
            }
        }
    }
}

void check(struct Contact * cp)
{
    if(cp->size == cp->capacity)
    {
        struct PeoInfo* ptr= (struct PeoInfo*)realloc(cp->data,(cp->capacity+2)*sizeof(struct PeoInfo));
        if(ptr != NULL)
        {
            cp->data = ptr;
            cp->capacity += 2;
            printf("开辟成功\n");
        }
        else
        {
            printf("增容失败\n");
        }
    }
}
void destroy(struct Contact* cp)
{
    free(cp->data);
    cp->data = NULL;
}

// ****************************************