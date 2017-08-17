#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


typedef struct fcfile
{
  FILE* pfile;
  char path[8192];
  char mode[2];
  int key;

}fcfile_t;


typedef struct fctree
{
  fcfile_t file;
  struct fctreet* left;
  struct fctree_t* right;

}fctree_t;


int init_fctree(fctree_t** ppfctree)
{
  int ret = 0;

  (*ppfctree)->left = NULL;
  (*ppfctree)->right = NULL;

  return ret;
}


fctree_t* create_fcfile_node(char* filepath, const char* mode)
{
  fctree_t* ret_pfctree = NULL;
  fcfile_t* pfcfile = NULL;

  ret_pfctree = malloc(sizeof(fctree_t));
  memset(ret_pfctree, 0x00, sizeof(fctree_t));
  pfcfile = &ret_pfctree->file;

  if (pfcfile->pfile){

    if ((pfcfile->pfile = fopen(filepath, mode)) == NULL){

      goto create_fcfile_node_ret;
    }
  }

  snprintf(ret_pfctree->file.mode, 2, "%s", mode); 
  snprintf(ret_pfctree->file.path, 8192, "%s", filepath);
  ret_pfctree->left = NULL;
  ret_pfctree->right = NULL;

  return ret_pfctree;

 create_fcfile_node_ret:

  if (ret_pfctree){

    if (ret_pfctree->file.pfile){

      free(ret_pfctree->file.pfile);
    }

    free(ret_pfctree);
  }

  ret_pfctree = NULL;
  
  return ret_pfctree;
}


int main(){
  int ret = 0;

  return ret;
}
