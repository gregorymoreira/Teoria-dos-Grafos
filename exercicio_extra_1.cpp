#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;

typedef struct bt {
      char  conteudo;
      struct bt *esq;
      struct bt *dir;
   } node; // nó

//ponteiro para o nó raiz
node* root = NULL;
queue<node*> fila;

node *insereNoh(char valor, node* esq, node* dir)
{
	node *n = (node*)malloc(sizeof(node));
	if(n == NULL)
	{
		exit(1);
	}
	else
	{
		n->conteudo = valor;
		n->esq = esq;
		n->dir = dir;
	}
	return  n;
}


void dfs(){//recebe árvore e vertice

}

void bfs(){//recebe árvore e vértice

}

int main()
{

	string linha;
	ifstream txt("entrada.txt");
	if(txt.is_open())
	{
		while(! txt.eof())
		{
			getline(txt,linha);
			if(root != NULL)
			{
				node *aux = insereNoh(linha[0],NULL,NULL);
				fila.push(aux);
			}
			else
			{
				node *a = fila.front();
				if(linha[0] == a->conteudo)
				{//no ja criado, altera ele
					if(linha.length()==5)
					{
						node *aux1 = insereNoh(linha[2],NULL,NULL);
						node *aux2 = insereNoh(linha[4],NULL,NULL);
						a->esq = aux1;
						a->dir = aux2;
						fila.push(aux1);
						fila.push(aux2);
						fila.pop();
					}
					else if(linha.length()==3)
					{
						node *aux1 = insereNoh(linha[2],NULL,NULL);
						a->esq = aux1;
						fila.push(aux1);
						fila.pop();
					}
					else
					{
						a->esq = NULL;
						a->dir = NULL;
						fila.pop();
					}

				}
				else
				{
					if(linha.length() == 5)
					{
						node *aux1 = insereNoh(linha[2],NULL,NULL);
						node *aux2 = insereNoh(linha[4],NULL,NULL);
						node *aux = insereNoh(linha[0],aux1,aux2);
						fila.push(aux1);
						fila.push(aux2);
					}
					else if(linha.length() == 3)
					{
						node *aux1 = insereNoh(linha[2],NULL,NULL);
						node *aux = insereNoh(linha[0],aux1,NULL);
						fila.push(aux1);
					}
					else
					{
						insereNoh(linha[0],NULL,NULL);
					}
				}
			}

			//cout << linha.length() << endl;
			//cout << linha << endl;
		}
		txt.close();
	}
	else{
		cout << "Nao foi possivel abrir o arquivo" << endl;
	}

	return 0;
}
