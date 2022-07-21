# 정렬
### 선택정렬 (Selection Sort)
![selection-sort-001](https://user-images.githubusercontent.com/87213815/180154153-0ff10e5f-0fef-4283-8c70-a6934ec70515.gif)
* 시간복잡도 : 최선,평균,최악 ->O(n^2)
```
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
```

### 버블정렬(bubble sort)
* 시간복잡도 : 최선,평균,최악 -> O(n^2)

```
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
```