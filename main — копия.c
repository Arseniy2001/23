#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
struct tnode
{
  int key;
  char height;
  struct tnode *left;
  struct tnode *right;
};
int avl=0;
int height(struct tnode* p)
{
    return (p == NULL ? -1 : p->height);
}
struct tnode *addtree(struct tnode *p, int w) {
  if(p == NULL)
  {
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->key = w;
    p->height = 0;
    p->left = p->right = NULL;
  }
  else if (w < p->key){
      p->left = addtree(p->left, w);
    }
  else if (w > p->key){
     p->right = addtree(p->right, w);
    }
    if (height(p->left) >= height(p->right)){
        p->height=height(p->left)+1;
    }
    else p->height=height(p->right)+1;
  return p;
}

// Функция удаления поддерева
void freemem(struct tnode *tree) {
  if(tree!=NULL) {
      freemem(tree->left);
      freemem(tree->right);
      free(tree);
    }
}
// Функция вывода дерева
void treeprint(struct tnode *p) {
  if(p != NULL) {
    treeprint(p->left);
      printf("%d ", p->key);
      if (height(p->right) - height(p->left)>1){
          avl+=1;}
    treeprint(p->right);
  }
}
int main() {
  struct tnode *root;
  int word;
  root = NULL;
    scanf("%d",&word);
    while(word!=999)
    {
      root = addtree(root,word);
      scanf("%d",&word);
    }
  treeprint(root);
  freemem(root);
    if(avl>0){printf("\nНе является AVL");}
    else{printf("\nЯвляется AVL");}
  getchar();
  getchar();
}
