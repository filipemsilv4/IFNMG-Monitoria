#include <stdio.h>
#include <stdlib.h>

    //Preciso de um codigo que localize dentro de um vetor 2 numeros exisitentes que somados resultem em um numero alvo
    //Restriçoes 2 <= nums.length <= 104
    //-109 <= nums[i] <= 109
    //-109 <= target <= 109
    //Existe apenas uma resposta válida.

int* twoSum(int* nums, size_t numsSize, int target, int* returnSize){
    int *result = malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result;
}
int main (){
    int nums[] = {2,7,11,15};
    size_t numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, numsSize, target, &returnSize);
    printf("Os indices dos numeros que somados resultam no alvo são: %d e %d\n", result[0], result[1]);
    return 0;
}