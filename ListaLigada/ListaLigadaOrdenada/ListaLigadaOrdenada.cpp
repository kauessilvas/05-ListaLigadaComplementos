#include <iostream>
using namespace std;

struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
    menu();
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls");
        cout << "Menu Lista Ligada Ordenada" << endl << endl;
        cout << "1 - Inicializar Lista" << endl;
        cout << "2 - Exibir quantidade de elementos" << endl;
        cout << "3 - Exibir elementos" << endl;
        cout << "4 - Buscar elemento" << endl;
        cout << "5 - Inserir elemento" << endl;
        cout << "6 - Excluir elemento" << endl;
        cout << "7 - Sair" << endl << endl;

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;
        case 7:
            return;
        default:
            break;
        }

        system("pause");
    }
}

void inicializar()
{
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    cout << "Lista inicializada" << endl;
}

void exibirQuantidadeElementos() {
    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }

    cout << "Elementos:" << endl;
    NO* aux = primeiro;
    while (aux != NULL) {
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void inserirElemento()
{
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return;

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor < novo->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->valor == novo->valor) {
        cout << "Elemento ja existe!" << endl;
        free(novo);
        return;
    }

    if (anterior == NULL) {
        novo->prox = primeiro;
        primeiro = novo;
    }
    else {
        anterior->prox = novo;
        novo->prox = atual;
    }

    cout << "Elemento inserido!" << endl;
}

void buscarElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }

    int numero;
    cout << "Digite o elemento para buscar: ";
    cin >> numero;

    NO* aux = primeiro;
    while (aux != NULL && aux->valor <= numero) {
        if (aux->valor == numero) {
            cout << "ENCONTRADO" << endl;
            return;
        }
        aux = aux->prox;
    }

    cout << "ELEMENTO NAO ENCONTRADO" << endl;
}

void excluirElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }

    int numero;
    cout << "Digite o elemento para excluir: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor < numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL || atual->valor > numero) {
        cout << "ELEMENTO NAO ENCONTRADO" << endl;
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Elemento excluido!" << endl;
}

NO* posicaoElemento(int numero)
{
    NO* aux = primeiro;
    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}