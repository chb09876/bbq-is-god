#include <stdio.h>

int   len_arr(int arr[]) {
   int cnt = 0;
   while (arr[cnt] != '\0') {cnt++;}
   return (cnt);
}

void  selection_sort(int arr[]) {
   int tmp = 0;
   for (int i = 0; i < len_arr(arr)-1; i++) {
      for (int j = i + 1; j < len_arr(arr); j++) {
         if (arr[i] > arr[j]) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
         }
      }
   }
   for (int k = 0; k < len_arr(arr); k++) {
      printf("%d ", arr[k]);
   }
}

int main(void) {
   int   arr[6] = {2,1,4,5,7,6};
   selection_sort(arr);
   return (0);
}