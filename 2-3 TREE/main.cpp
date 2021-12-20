#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    int *keys;
    int n;
    bool leaf;
    TreeNode **child;
    public:
      TreeNode(bool leaf);
      void insertnonfull(int k);
      void splitchild(int i,TreeNode *y);
      void traverse();
      friend class Tree;
};

class Tree
{
    TreeNode *root=NULL;
    public:
    
      void traverse(){
          if(root!=NULL)
          root->traverse();
      }
      void insert(int k);
};


TreeNode::TreeNode(bool leaf1)
{
   leaf=leaf1;
   n=0;
   child=new TreeNode *[4];
   keys=new int[3];
}

void Tree::insert(int k)
{
   if(root==NULL)
   {
     root=new TreeNode(true);
     root->n=1;
     root->keys[0]=k;
   }
   else
   {
      if(root->n==3)
      {
         TreeNode *s=new TreeNode(false);
         s->child[0]=root;
         s->splitchild(0,root);

         int i=0;

         if(s->keys[i]<k)
         i++;

         s->child[i]->insertnonfull(k);
         root=s;
      }
      else
      {
         root->insertnonfull(k);
      }
   }
}
void TreeNode::insertnonfull(int k)
{
    int i=n-1;
    if(leaf==true)
    {
       while(i>=0 && keys[i]>k)
       {
           keys[i+1]=keys[i];
           i--;
       }
       keys[i+1]=k;
       n=n+1;
    }
    else
    {
       while(i>=0 && keys[i]>k)
       i--;
       if(child[i+1]->n==3)
       {
          splitchild(i+1,child[i+1]);
          if(keys[i+1]<k)
          i++;

       }
       child[i+1]->insertnonfull(k);
    }
}

void TreeNode::splitchild(int i,TreeNode *y)
{
    TreeNode *z=new TreeNode(y->leaf);
    z->n=1;
    z->keys[0]=y->keys[2];
    if(y->leaf==false)
    {
        for(int j=0;j<2;j++)
        {
            z->child[j]=y->child[j+2];
        }
    }
    y->n=1;
    for(int j = n; j >= i + 1; j--) child[j + 1] = child[j];
    child[i+1]=z;
    for (int j = n - 1; j >= i; j--) keys[j+1] = keys[j]; 
    keys[i]=y->keys[1];
    n=n+1;
}
void TreeNode::traverse() {
	cout << "\n";
	int i;
	for(i = 0; i < n; i++) {
		if(leaf == false) child[i] -> traverse();
		cout << " " << keys[i];
	}
	if(leaf == false)
		child[i] -> traverse();

	cout << "\n";
}
int main() {
    Tree t;
    int num;
    printf("Enter the number of elements\n");
    scanf("%d",&num);
    
    int p=0;
    printf("Enter the elements of the array\n");
    
    for(int i=0;i<num;i++)
    {
        
        scanf("%d",&p);
        t.insert(p);
    }
    printf("HI\n");
    t.traverse();

  }
