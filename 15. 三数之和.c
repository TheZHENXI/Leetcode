/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-10-19 22:41:23
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-10-19 22:41:50
 * @FilePath: /CCODE/LC/15. 三数之和.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

//思路：枚举+双指针
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int row = 0;
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    int** ans = (int**)malloc(sizeof(int*)*19000);

    for(int i = 0;i < numsSize;i++)
    {
         //去重
        if(i > 0 && nums[i] == nums[i-1]) continue;
        //转换为求解两数的和为target
        int target = 0 - nums[i];
        int l = i + 1,r = numsSize -1;
        while(l < r)
        {  
            if(target == nums[l] + nums[r])
            {
                //将开辟数组存入ans中
                int* arr = (int*)malloc(sizeof(int) * 3);
                arr[0] = nums[i];
                arr[1] = nums[l];
                arr[2] = nums[r];
                ans[row++] = arr;
                //去重
                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;
                l++,r--;
            }
            else if(nums[l] + nums[r] < target)
            {
                l++;
            }
            else
            {    
                r--;
            }
        }
    }
    *returnSize = row;
    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
    for(int i = 0; i < row;i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return ans;
}