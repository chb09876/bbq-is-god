#include <stdio.h>

int   len_arr(int arr[]) {
   int   cnt = 0;
   while (arr[cnt] != '\0') {cnt++;}
   return (cnt);
}

void  bubble_sort(int arr[]) {
   int   tmp = 0;

   for (int i = 0; i < len_arr(arr); i++) {
      for (int j = 0; j < len_arr(arr) - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
         }
      }
   }
   for (int k = 0; k < len_arr(arr); k++) {
      printf("%d ", arr[k]);
   }
}

int main(void) {
   int   arr[5] = {2,4,6,1,4};
   bubble_sort(arr);
   return (0);
}