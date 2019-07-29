typedef struct funcionario Funcionario;

typedef struct lista Lista;

Lista* criarLista ();

void desalocaLista(Lista* lista);

void insereElemento(Lista* lista);

void removeElemento(int matricula, Lista* lista);

void imprimeFuncionario(int matricula, Lista* lista);

void imprimeLista(Lista* lista);

Funcionario* buscaFuncionario(Lista* lista, int matricula);



