#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
   int   idx;
   int   data;
   struct Node *next;
}node;

void  init_node(node *head) {
   head->next =NULL;
   head->idx = 1;
}

void  add_node(node *head, int data, int idx) {
   node *newnode = (node*)malloc(sizeof(node));

   newnode->next = head->next;
   head->next = newnode;
   newnode->data = data;
   newnode->idx = idx - 1;
}

int   re_num(int num, int N, int V) {
   if (num >= N) {
      if (num%(N - V + 1) == 0) {
         num = N - V + 1;
      }
      else if (num%(N - V + 1) == 1) {
         num = N - V + 2;
      }
      else {
         num = num%(N - V + 1);
      }  
   }
   return (num);
}


int  print_node(node *head, int num) {
   node *cur = head->next;
   while (cur != NULL) {
      if (cur->idx == num + 1) {
         printf("%d\n", cur->data);
         return (0);
      }
      cur = cur->next;
   }
   return (0);
} 

int main(void) {
   int N,M,V,i,data,num = 0;
   scanf("%d %d %d", &N, &M, &V);
   node *list = (node*)malloc(sizeof(node));
   
   init_node(list);
   while (i++ <= N) {
      scanf("%d", &data);
      add_node(list, data, i);
   }

   i = 0;
   while (i++ < M){
      scanf("%d", &num);
      print_node(list, re_num(num, N, V));
   }
   free(list);
   return (0);
}