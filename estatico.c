#include "estatico.h"

void cria(banco *B) {
     int i;
     for (i=0;i<TAM-1;i++)
         B->itens[i].prox=i+1;
     B->itens[TAM-1].prox=-1;
     B->pv=0;
     B->ini=-1;
     B->fim=-1;
}

void getnode(banco *B, int *pos) {
    if (B->pv!=-1) {
       *pos=B->pv;
       B->pv=B->itens[B->pv].prox;
       B->itens[*pos].prox=-1;
    }
    else *pos=-1;
}
void freenode(banco *B, int *pos) {
    B->itens[*pos].prox=B->pv;
    B->pv=*pos;
}
int EstaVazio(banco *B) {
    if (B->ini==-1)
       return(1);
    else return(0);
}
int EstaCheio(banco *B) {
    if (B->pv==-1)
       return(1);
    else return(0);
}
/*void inserirAluno_Comeco(banco *B, aluno *X, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].infoAluno=*X;
          B->itens[pos].prox=B->ini;
          B->ini=pos;
          if (B->fim==-1)
             B->fim=pos;
     }
}*/
void retirarAluno(banco *B, aluno *x, int *erro) {
     int pos;
     if (EstaVazio(B))
        *erro=1;
     else {
          *erro=0;
          *x=B->itens[B->ini].infoAluno;
          pos=B->ini;
          B->ini=B->itens[B->ini].prox;
          if (B->ini==-1)
             B->fim=-1;
          freenode(B,&pos);
     }
}
void inserirAluno_fim(banco *B, aluno *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].infoAluno=*x;
          B->itens[pos].prox=-1;
          if (B->fim!=-1)
             B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
             B->ini=pos;
     }
}

void retirarLivro(banco *B, livro *x, int *erro) {
     int pos;
     if (EstaVazio(B))
        *erro=1;
     else {
          *erro=0;
          *x=B->itens[B->ini].infoLivro;
          pos=B->ini;
          B->ini=B->itens[B->ini].prox;
          if (B->ini==-1)
             B->fim=-1;
          freenode(B,&pos);
     }
}
void inserirLivro_fim(banco *B, livro *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].infoLivro=*x;
          B->itens[pos].prox=-1;
          if (B->fim!=-1)
             B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
             B->ini=pos;
     }
}

void imprimeBanco (banco *B){
    printf("\n\n\n\n%s\n\n\n\n\n", B->itens[B->ini]->infoAluno.nome);
}
