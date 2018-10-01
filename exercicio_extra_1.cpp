#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

typedef struct bt {
      char  conteudo;
      struct bt *esq;
      struct bt *dir;
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
		exit(1);
	}
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
	}
	else if(aux->dir != NULL && aux->dir->conteudo == letra && aux->esq != NULL){
		cout << aux->esq->conteudo << endl;
	}
	else{
		cout << "Nao possui irmao" << endl;
	}

}

void imprimeTios(char letra){

}

void retornaAncestrais(char letra){

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
					fila.push(aux1);
					criados.push(aux);
					criados.push(aux1);
				}
				else
				{
					node *aux = insereNoh(linha[0],NULL,NULL);
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
						criados.push(aux);
						criados.push(aux1);
						criados.push(aux2);
					}
					else if(linha.length() == 3)
					{
						node *aux1 = insereNoh(linha[2],NULL,NULL);
						node *aux = insereNoh(linha[0],aux1,NULL);
						fila.push(aux1);
						criados.push(aux);
						criados.push(aux1);
					}
					else
					{
						node *aux = insereNoh(linha[0],NULL,NULL);
						criados.push(aux);
					}
				}
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
	node *buscaProfundidade = dfs(root,'E');
	cout << "BFS: ";
	node *buscaLargura = bfs(root,'E');
	imprimeDescendentes(root,'E');
	node *pai = imprimePai(root,'E');
	imprimeIrmaos(root,'B');

	return 0;
}
