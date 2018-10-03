/**
ALUNO: Gregory Henrique Moreira dos Santos Pereira
Matrícula: 161057600020
Componente currícular: Teoria dos Grafos 2018.2
Professor: João Victor Oliveira
*/

#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

typedef struct bt {
      char  conteudo;
      struct bt *esq;
      struct bt *dir;
      struct bt *pai;//modificação na estrutura de dados
   } node; // nó

//ponteiro para o nó raiz
node *root = NULL;

queue<node*> fila;
queue<node*> criados;
stack<node*> pilha;


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


node *dfs(node *rot,char letra){//recebe árvore e vertice
	if(rot == NULL){
		return NULL;
	}
	stack<node*> pilha;
	node *aux = rot;
	pilha.push(aux);
	//cout << "DFS: ";
	while(!pilha.empty()){
		aux = pilha.top();
		cout << aux->conteudo << " ";
		pilha.pop();
		if(letra == aux->conteudo){
			cout << endl;
			while(!pilha.empty()){
				pilha.pop();
			}
			return aux;
		}
		else{//primeiro o esquerdo depois o direito por causa da pilha
			if(aux->dir != NULL){
				pilha.push(aux->dir);
			}
			if(aux->esq != NULL){
				pilha.push(aux->esq);
			}
		}
	}
	while(!pilha.empty()){
		pilha.pop();
	}
	cout << "Nao encontrado!" << endl;
}

node *bfs(node *rot,char letra){//recebe árvore e vértice
	if(rot == NULL){
		return NULL;
	}
	queue<node*> fila;
	node *aux = rot;
	fila.push(aux);
	//cout << "BFS: ";
	while(!fila.empty()){
		aux = fila.front();
		cout << aux->conteudo << " ";
		fila.pop();
		if(letra == aux->conteudo){
			cout << endl;
			while(!fila.empty()){
				fila.pop();
			}
			return aux;
		}
		else{//primeiro o esquerdo e depois o direito por causa da fila
			if(aux->esq !=NULL){
				fila.push(aux->esq);
			}
			if(aux->dir !=NULL){
				fila.push(aux->dir);
			}	
		}	
	}
	while(!fila.empty()){
		fila.pop();
	}
	cout << "Nao encontrado!" << endl;
}

void imprimeDescendentes(node *rot,char letra){
	if(rot == NULL){
		cout << "Arvore nao existe!" << endl;
		exit(1);
	}
	stack<node*> pilha;
	node *aux = rot;
	bool imprime = false;
	pilha.push(aux);
	cout << "Descendentes do noh " << letra << ": ";
	while(!pilha.empty()){
		aux = pilha.top();
		//cout << aux->conteudo << " ";
		pilha.pop();
		if(imprime){
			cout << aux->conteudo << " ";
		}
		else if(letra == aux->conteudo){
			imprime = true;
			while(!pilha.empty()){
				pilha.pop();
			}

		}
		//primeiro o esquerdo depois o direito por causa da pilha
		if(aux->dir != NULL){
			pilha.push(aux->dir);
		}
		if(aux->esq != NULL){
			pilha.push(aux->esq);
		}
	}
	cout << endl;
	while(!pilha.empty()){
		pilha.pop();
	}
	//cout << "Nao encontrado!" << endl;
}

node *imprimePai(node *rot,char letra){
	if(rot == NULL){
		return NULL;
	}
	stack<node*> pilha;
	node *aux = rot;
	pilha.push(aux);
	cout << "O pai de " << letra << " eh: ";
	while(!pilha.empty())
	{
		aux = pilha.top();
		//cout << aux->conteudo << " ";
		pilha.pop();
		if(aux->dir != NULL){
			if(letra == aux->dir->conteudo){
				break;
			}
			else
				pilha.push(aux->dir);
		}
		if(aux->esq != NULL){
			if(letra == aux->esq->conteudo){
				break;
			}
			else
				pilha.push(aux->esq);
		}
	}
	 if(!fila.empty()){
	 	cout << "Nao encontrado!" << endl;
	 	while(!pilha.empty()){
			pilha.pop();
		}
	 	return NULL;
	 }
	else{
		cout << aux->conteudo << endl;
		while(!pilha.empty()){
			pilha.pop();
		}
		return aux;
	}
}

void imprimeIrmaos(node *rot,char letra){
	if(rot == NULL){
		cout << "Arvore nao existe!" << endl;
	}
	else{
		stack<node*> pilha;
		node *aux = rot;
		pilha.push(aux);
		cout << "O irmao de " << letra << " eh: ";
		while(!pilha.empty())
		{
			aux = pilha.top();
			//cout << aux->conteudo << " ";
			pilha.pop();
			if(aux->dir != NULL){
				if(letra == aux->dir->conteudo){
					break;
				}
				else
					pilha.push(aux->dir);
			}
			if(aux->esq != NULL){
				if(letra == aux->esq->conteudo){
					break;
				}
				else
					pilha.push(aux->esq);
			}
		}

		if(aux->esq != NULL && aux->esq->conteudo == letra && aux->dir != NULL){
			cout << aux->dir->conteudo << endl;
			while(!pilha.empty()){
				pilha.pop();
			}
		}
		else if(aux->dir != NULL && aux->dir->conteudo == letra && aux->esq != NULL){
			cout << aux->esq->conteudo << endl;
			while(!pilha.empty()){
				pilha.pop();
			}
		}
		else{
			cout << "Nao possui irmao" << endl;
			while(!pilha.empty()){
				pilha.pop();
			}
		}
	}
}

void imprimeTios(node *rot, char letra){//essa funçao nao está pronta
	if(rot == NULL){
		cout << "Arvore nao exite!" << endl;
	}
	else{
		stack<node*> pilha;
		node *aux = rot, *aux2;
		pilha.push(aux);
		while(!pilha.empty()){
			aux = pilha.top();
			pilha.pop();
			if(letra == aux->conteudo){
				aux = aux->pai;
				aux2 = aux->pai;
				if(aux2->esq != NULL && aux2->esq->conteudo != aux->conteudo){
					cout << "O tio de " << letra << " eh: " << aux2->esq->conteudo << endl;
					break;
				}
				else if(aux2->dir != NULL && aux2->dir->conteudo != aux->conteudo){
					cout << "O tio de " << letra << " eh: " << aux2->dir->conteudo << endl;
					break;
				}
				else{
					cout << letra << "nao possui tio"<< endl;
					break;
				}
			}
			else{//primeiro o esquerdo depois o direito por causa da pilha
				if(aux->dir != NULL){
					pilha.push(aux->dir);
				}
				if(aux->esq != NULL){
					pilha.push(aux->esq);
				}
			}
		}
		while(!pilha.empty()){
			pilha.pop();
		}
	}
}


void retornaAncestrais(node *rot,char letra){//essa função nao funciona
	if(rot == NULL){
		cout << "Arvore nao existe!" << endl;
	}
	else{
		stack<node*> pilha;
		node *aux = rot;
		pilha.push(aux);
		if(letra == aux->conteudo){
			cout << letra << " nao possui ancestrais" << endl;
		}
		else{
			while(!pilha.empty()){
				aux = pilha.top();
				pilha.pop();
				if(aux->conteudo == letra){
					cout << "Ancestrais(" << letra << "): ";
					while(aux->conteudo != rot->conteudo){
						cout << aux->pai->conteudo << " ";
						aux = aux->pai;
					}
					cout << endl;
					break;
				}
				else{
					if(aux->dir != NULL){
						pilha.push(aux->dir);
					}
					if(aux->esq != NULL){
						pilha.push(aux->esq);
					}
				}
			}
		}
	}
}

void criaArvore(){
	string linha;
	ifstream txt("entrada.txt");
	if(txt.is_open())
	{
		while(!txt.eof())
		{
			getline(txt,linha);
			if(fila.empty())
			{
				if(linha.length() == 5)
				{
					node *aux1 = insereNoh(linha[2],NULL,NULL);
					node *aux2 = insereNoh(linha[4],NULL,NULL);
					node *aux = insereNoh(linha[0],aux1,aux2);
					aux1->pai = aux;
					aux2->pai = aux;
					aux->pai = NULL;
					fila.push(aux1);
					fila.push(aux2);
					criados.push(aux);
					criados.push(aux1);
					criados.push(aux2);
				}
				else if(linha.length() == 3)
				{
					node *aux1 = insereNoh(linha[2],NULL,NULL);
					node *aux = insereNoh(linha[0],aux1,NULL);
					aux1->pai = aux;
					aux->pai = NULL;
					fila.push(aux1);
					criados.push(aux);
					criados.push(aux1);
				}
				else
				{
					node *aux = insereNoh(linha[0],NULL,NULL);
					aux->pai = NULL;
					criados.push(aux);
				}
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
						aux1->pai = a;
						aux2->pai = a;
						fila.push(aux1);
						fila.push(aux2);
						fila.pop();
					}
					else if(linha.length()==3)
					{
						node *aux1 = insereNoh(linha[2],NULL,NULL);
						a->esq = aux1;
						aux1->pai = a;
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
				// else
				// {
				// 	if(linha.length() == 5)
				// 	{
				// 		node *aux1 = insereNoh(linha[2],NULL,NULL);
				// 		node *aux2 = insereNoh(linha[4],NULL,NULL);
				// 		node *aux = insereNoh(linha[0],aux1,aux2);
				// 		aux1->pai = aux;
				// 		aux2->pai = aux;
				// 		fila.push(aux1);
				// 		fila.push(aux2);
				// 		criados.push(aux);
				// 		criados.push(aux1);
				// 		criados.push(aux2);
				// 	}
				// 	else if(linha.length() == 3)
				// 	{
				// 		node *aux1 = insereNoh(linha[2],NULL,NULL);
				// 		node *aux = insereNoh(linha[0],aux1,NULL);
				// 		aux1->pai = aux;
				// 		fila.push(aux1);
				// 		criados.push(aux);
				// 		criados.push(aux1);
				// 	}
				// 	else
				// 	{
				// 		node *aux = insereNoh(linha[0],NULL,NULL);
				// 		criados.push(aux);
				// 	}
				// }
			}

			//cout << linha.length() << endl;
			//cout << linha << endl;
		}
		txt.close();
		root = criados.front();
		while(!fila.empty()){
			fila.pop();
		}
	}
	else{
		cout << "Nao foi possivel abrir o arquivo" << endl;
	}
}


int main()
{
	criaArvore();

	cout << "DFS: ";
	node *buscaProfundidade = dfs(root,'F');
	cout << "BFS: ";
	node *buscaLargura = bfs(root,'F');
	imprimeDescendentes(root,'F');
	node *pai = imprimePai(root,'F');
	imprimeIrmaos(root,'F');
	imprimeTios(root, 'F');
	retornaAncestrais(root,'F');
	return 0;
}
