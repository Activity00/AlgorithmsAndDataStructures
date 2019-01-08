#include "stdlib.h"
#include "stdio.h"

int* insert_sort(int* nums, int count){
    int key, j;
    for(int i=1; i<count;i++){
       key = nums[i];
       j = i - 1;
       while(j >= 0 && nums[j] > key){
          nums[j+1] = nums[j];
          j--;
       }
       nums[j+1] = key;
    }
    return nums;
}

int main(){
    int *p;
    int nums[] = {1,3,7,2,5,8};
    p = insert_sort(nums,6);
    for(int i=0;i<6;i++){
      printf("%d\n",p[i]);
    }

}
