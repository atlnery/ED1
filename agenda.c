#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char numero[16];
    char whatsapp[2] // S ou N;
}Telefone;

typedef struct{
    char cep[11];
    int numero;
    char estado[3];
}Endereco;

typedef struct{
    char* nome;
    // char nome[40];
    int idade;
    char* email;
    Endereco endereco;
    Telefone* telefones[4];
    int qtdeContatos; // quantidade de contatos armazenados
}Pessoa;

typedef struct{
    char* descricao;
    Pessoa** pessoas;
    int tamVetor; // tamanho do vetor de pessoas
    int qtdePessoas; // quantidade de pessoas armazenadas
}Agenda;



// Reduzir o tamanho do vetor de pessoas pela metada quando a taxa de ocupação for inferior a 25%
void agenda_verificaReduzTamanho(Agenda* agenda);

int agenda_consultaPorEstado(Agenda* agenda, char* estado, Telefone** referencia);

void agenda_inserirPessoa(Agenda* agenda, Pessoa* p);

Pessoa* agenda_removerPessoa(Agenda* agenda, char* email);

void pessoa_desalocar(Pessoa* p);

Pessoa* pessoa_novo(char* nome, int idade, char* email);

void pessoa_defineEndereco(Pessoa* p, char* cep, int num, char* estado);

void pessoa_cadastrarContato(Pessoa* p, char* numero, char* flagWhats);


Pessoa* pessoa_novo(char* nome, int idade, char* email){
  Pessoa* novo = (Pessoa*) malloc(sizeof(Pessoa));
  novo->nome = (char*) calloc(strlen(nome) + 1, sizeof(char) );
  strcpy(novo->nome, nome);
  novo->idade = idade;
  novo->email = (char*) calloc(strlen(email) + 1, sizeof(char) );
  strcpy(novo->email, email);
  novo->qtdeContatos = 0;

  return novo;
}

void pessoa_defineEndereco(Pessoa* p, char* cep, int num, char* estado){
  strcpy(p->endereco.cep, cep);
  p->endereco.numero = num;
  strcpy(p->endereco.estado, estado);
}

void pessoa_cadastrarContato(Pessoa* p, char* numero, char* flagWhats){

  Telefone* contato = (Telefone*) malloc(sizeof(Telefone));
  strcpy(contato->numero, numero);
  strcpy(contato->whatsapp, flagWhats);

  p->telefones[p->qtdeContatos++] = contato;
}


int main(){
    Agenda* a1 = agenda_novo("pessoal");

    Pessoa* p1 = pessoa_novo("Joao", 30, "joao@gmail.com");
    Pessoa* p2 = pessoa_novo("Maria", 20, "maria@gmail.com");

    pessoa_defineEndereco(p1, "88.888-88", 100, "PR");
    pessoa_defineEndereco(p2, "99.999-99", 200, "SP");


    pessoa_cadastrarContato(p1, "(44) 91111-1111", "S");
    pessoa_cadastrarContato(p1, "(41) 92222-2222", "S");
    pessoa_cadastrarContato(p1, "(44) 3033-1234", "N");

    pessoa_cadastrarContato(p2, "(44) 94444-4444", "S");
    pessoa_cadastrarContato(p2, "(44) 95555-5555", "S");

    Telefone vetPR[100], vetSP[100];
    int qtdeTelefones;
    qtdeTelefones = agenda_consultaPorEstado(a1, "PR", &vetPR);
    qtdeTelefones = agenda_consultaPorEstado(a1, "SP", &vetSP);

    agenda_inserirPessoa(a1, p1);
    agenda_inserirPessoa(a1, p2);

    Pessoa* removido = agenda_removerPessoa(a1, "joao@gmail.com");

    pessoa_desalocar(removido);

}
