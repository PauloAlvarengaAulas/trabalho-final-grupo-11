
#include <iostream>
#include <string>
using namespace std;

struct funcionario
{
    string nome;
    int cpf;
    float salario;
};

struct No
{
    funcionario dado;
    No *lig;
};

typedef struct No *NoPtr;

void insere(NoPtr &L, funcionario Novo)
{
    if (L == NULL)
    {
        L = new No;
        L->dado = Novo;
        L->lig = NULL;
    }

    else
    {
        NoPtr Ant = NULL;
        NoPtr Aux = L;

        while ((Aux != NULL) && (Aux->dado.cpf < Novo.cpf))
        {
            Ant = Aux;
            Aux = Aux->lig;
        }

        Aux = new No;
        Aux->dado = Novo;

        if (Ant == NULL)
        {
            Aux->lig = L;
            L = Aux;
        }

        else
        {
            Aux->lig = Ant->lig;
            Ant->lig = Aux;
        }
    }
}

bool remover(NoPtr &L, string rem)
{
    NoPtr Ant = NULL;
    NoPtr Aux = L;

    while ((Aux != NULL) && (Aux->dado.nome != rem && Aux->dado.cpf != atoi(rem.c_str())))
    {
        Ant = Aux;
        Aux = Aux->lig;
    }

    if (Aux == NULL)
    {
        return false;
    }

    if (Aux == L)
    {
        L = Aux->lig;
    }
    else
    {
        Ant->lig = Aux->lig;
    }

    cout<< "Excluido" << endl;
    delete Aux;

    return true;
}

void lista(NoPtr L)
{
    NoPtr Ant = NULL;
    NoPtr Aux = L;

    cout << "Funcionarios:\n";

    while ((Aux != NULL))
    {
        Ant = Aux;
        Aux = Aux->lig;
        cout << "\nNome: " << Ant->dado.nome << endl
             << "CPF: " << Ant->dado.cpf << endl
             << "Salario: R$" << Ant->dado.salario << endl;
    }
}

void menu(NoPtr &L)
{
    funcionario novo;
    string aRemover;
    int op;
    while (true)
    {
        cout << "        Menu" << endl
             << "1: Insere" << endl
             << "2: Mostrar Todos" << endl
             << "3: Remover" << endl
             << "4: Sair" << endl;

        cin >> op;
        system("clear");

        switch (op)
        {
        case 1:
            cout << "Insira o Nome do funcionario: ";
            getline(cin >> ws, novo.nome);

            cout << "Insira o CPF do funcionario: ";
            cin >> novo.cpf;

            cout << "Insira o Salario do funcionario: ";
            cin >> novo.salario;
            insere(L, novo);
            break;
        case 2:
            lista(L);
            break;
        case 3:
            cout << "Insira o Nome ou CPF do funcionario que deseja remover: ";
            getline(cin >> ws, aRemover);

            if (!remover(L, aRemover))
            {
                cout << "Nao foi possivel encontrar um funcionario com os dados passados.";
            }
            break;
        case 4:
            return;
        default:
            cout << "Opcao Invalida, tente novamente.\n";
            break;
        }
    }
}

int main()
{
    NoPtr L = NULL;

    menu(L);
}
