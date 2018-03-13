#include<stdio.h>
#include<stdlib.h>
int main(){
  FILE *fptr;
  fptr=fopen("name.txt","w");
  if(fptr==NULL){
    printf("error\n");
    exit(1);
  }
  printf("Enter n\n\n");
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Enter text\n");
    char new[10000];
    gets(new);
    fprintf(fptr, "%s\n",new);

  }
  fclose(fptr);
  return 0;
}
