#include "estatico.c"

int main(){
// declaracao de variaveis
    int opcao, erro;
    aluno Aluno;
    livro Livro;
    banco infoAluno, infoLivro;

    cria(&infoAluno);
    cria(&infoLivro);

    printf("digite a opcao desejada: \n 1 - cadastro de usuario\n 2 - cadastro de livro\n");
    scanf("%d",&opcao);

    while(opcao != -1){
        switch(opcao){
            case 1: // cadastrar usuario;
                printf("nome: ");
                scanf(" %[^\n]s", Aluno.nome);
                printf("email: ");
                scanf(" %[^\n]s", Aluno.email);
                printf("telefone: ");
                scanf(" %[^\n]s", Aluno.telefone);
                printf("nusp: ");
                scanf(" %[^\n]s", Aluno.nusp);
                inserirAluno_fim(&infoAluno, &Aluno, &erro);
                imprimeBanco (&infoAluno);

                break;

            case 2: //cadastrar livro;
                printf("Titulo: ");
                scanf(" %[^\n]s", Livro.titulo);
                printf("Autor: ");
                scanf(" %[^\n]s", Livro.autor);
                printf("Editora: ");
                scanf(" %[^\n]s", Livro.editora);
                printf("isbn: ");
                scanf("%d", &Livro.isbn);
                printf("Edicao: ");
                scanf("%d", &Livro.edicao);
                printf("qtd: ");
                scanf("%d", &Livro.qtd);
                inserirLivro_fim(&infoLivro, &Livro, &erro);


                break;


            default:
                printf("\n\n caiu no default\n\n");


        }

    printf("digite a opcao desejada (-1 para sair)\n");
    scanf("%d",&opcao);
    }
    return 0;
}
