#include<stdio.h>
#include<stdlib.h>

struct treenode{
  int availablesize;
  int availablesizeleft;
  int availablesizeright;
  int goright;
  int goleft;
  int fragmemtationsize;
  struct treenode* left;
  struct treenode* right;
  struct treenode* parent;
};

void insert(struct treenode* node,int processsize){
  if(node->goright==1){
    if(node->availablesizeright>= processsize){
      struct treenode* newnode = (struct treenode*) malloc(sizeof(struct treenode));
      node->right = newnode;
      newnode->parent=node;
      newnode->goright=1;
      newnode->availablesize=node->availablesizeright;
      newnode->goleft=0;
      newnode->availablesizeleft=newnode->availablesize/2;
      newnode->availablesizeright=newnode->availablesize/2;
      newnode->left=NULL;
      newnode->right=NULL;
      insert(newnode,processsize);
      return;
    }
    else if(node->availablesize>=processsize){
      node->fragmemtationsize=node->availablesize - processsize;
      if( node-> parent!=NULL){
        node->parent->availablesizeright=0;
        node->parent->goleft=1;
        node->parent->goright=0;
        struct treenode* temp;
        temp=node->parent;
        while(temp!=NULL){
          temp->availablesize-=temp->availablesizeleft;
          temp=temp->parent;
        }
      }
      node->availablesize=0;
      node->availablesizeleft=0;
      node->availablesizeright=0;
      node->goleft=0;
      node->goright=0;
      return;
    }
  }
  else if(node->goleft==1){
    if(node->availablesizeleft>= processsize){
      struct treenode* newnode = (struct treenode*) malloc(sizeof(struct treenode));
      node->left = newnode;
      newnode->parent=node;
      newnode->goright=1;
      newnode->availablesize=node->availablesizeleft;
      newnode->goleft=0;
      newnode->availablesizeleft=newnode->availablesize/2;
      newnode->availablesizeright=newnode->availablesize/2;
      newnode->left=NULL;
      newnode->right=NULL;
      insert(newnode,processsize);
      return;
    }
    else if( node->availablesize>=processsize){
      node->fragmemtationsize=node->availablesize - processsize;
      node->availablesize=0;
      if( node-> parent!=NULL){
        node->parent->availablesizeleft=0;
        node->parent->goleft=0;
        node->parent->goright=0;
      }
      node->availablesizeleft=0;
      node->availablesizeright=0;
      node->goleft=0;
      node->goright=0;
      return;
    }
  }
  else if(node->goleft==0 && node->goright==0){
    printf("There is not enought space for this process\n");
    return;
  }
}


void printtree(struct treenode* node){
  if(node->left!=NULL){
    printtree(node->left);
  }
  if(node->left==NULL && node->availablesizeleft!=0){
    printf("Available partition Size : %d\n", node->availablesizeleft);
  }

}

int main(){
  printf("Enter the total size of memory which is available\n");
  int n;
  scanf("%d",&n);
  struct treenode* root = (struct treenode*) malloc(sizeof(struct treenode));
  root->availablesize=n;
  root->left=NULL;
  root->right=NULL;
  root->parent=NULL;
  root->goright=1;
  root->goleft=0;
  root->availablesizeleft=n/2;
  root->availablesizeright=n/2;

  int flag=1;

  while( flag == 1){
    int temp;
    printf("What you want to do\n1.)Enter a process\n2.)Delete a process\n3.)print the buddy tree\n4.)Exit\n");
    scanf("%d",&temp);
    if(temp==1){
        printf("Enter the process size\n");
        int processsize;
        scanf("%d",&processsize);
        insert(root,processsize);
    }
    else if(temp==2){
      ;
    }
    else if(temp==3){
      printtree(root);
    }
    else if(temp==4){
      flag=0;
      printf("Bye Bye !!! Thanks for using me\n");
    }
    else{
      printf("You haven't entered the desired input.So restart the program\n");
      flag=0;
    }
  }

  return 0;
}
