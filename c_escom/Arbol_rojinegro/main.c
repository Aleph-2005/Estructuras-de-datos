#include <stdio.h>
#include "arbol_RN.h"
int cmp(void *a,void*b)
{
    
    if(*((int*)a)>=*((int*)b))
        return 1;
    return -1;
}
int main()
{
    int va = 100, vb = 60, vc = 145, vd = 21,ve=76,vf=32,vg=110,vh=150;
    int* a = &va;
    int* b = &vb;
    int* c = &vc;
    int* d = &vd;
    int* e = &ve;
    int* f = &vf;
    int* g = &vg;
    int* h = &vh;
    struct nodo_RN* root=crearnodo(a,0);
    insert_nodo(root,b,cmp);
    insert_nodo(root,c,cmp);
    insert_nodo(root,d,cmp);
    insert_nodo(root,e,cmp);
    insert_nodo(root,f,cmp);
    insert_nodo(root,g,cmp);
    insert_nodo(root,h,cmp);
    ExportaGraphizint(root);

}