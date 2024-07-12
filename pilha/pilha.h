typedef struct{
    char nome[100];
    char email[150];
    char fone[15];
} contato;


typedef struct{
	contato c;
	struct no* prox;
} no;


typedef struct{
     no *topo;
} pilha;
	
int push (pilha *p, contato c);	// retorna 1 se o empilhamento deu certo; retorna 0 se o empilhamento deu errado
								// recebe como parametro um contato c, os dados dessa struct devem ser copiados para o novo elemento criado

int pop  (pilha *p, contato *c);//retorna 1 se a remoção deu certo, retorna 0 se deu errado;
								//recebe como parametro um ponteiro para um contato c, que deve receber as informações removidas da pilha

int top  (pilha *p, contato *c);// mesmo que o pop, mas não remove;

int tamanho(pilha *p);

int empty(pilha *p); //retorna 1 se está vazia, senão retorna 0;

void inicializar(pilha *p);// atribui nulo para o topo da pilha