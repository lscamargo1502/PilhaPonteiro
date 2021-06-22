// PilhaPonteiro.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>

bool Pilha_Construtor();
bool Pilha_Destrutor();
bool Pilha_Vazia();


int Pilha_Contador = 0;

struct TipoCelula {
	int item;
	TipoCelula* prox;
};

TipoCelula* Topo;

bool Pilha_Construtor() {
	Topo = NULL;
	Pilha_Contador = 0;

	return true;
};

bool Pilha_Destrutor() {
	TipoCelula* Temp;
	if (Pilha_Vazia()) {
		return false;
	}
	else {
		while(Topo != NULL){
			Temp = Topo;
			Temp->prox = NULL;

			Topo = Topo->prox;
			free(Temp);
		}
		Pilha_Contador = 0;
		return true;
	}

};

bool Pilha_Vazia() {
	if (Topo == NULL) {
		return true;
	}
	else
		return false;
};

int Pilha_Tamanho() {
	return Pilha_Contador;
};

bool Pilha_Pop(int& valor) {
	TipoCelula* Temp;
	if (Pilha_Vazia()) {
		return false;
	}
	else {
		valor = Topo->item;
		Temp = Topo;
		Topo = Topo->prox;

		Temp->prox = NULL;
		free(Temp);

		Pilha_Contador--;
		return true;
	}

};

bool Pilha_Push(int valor) {
	TipoCelula* NovaCelula = (TipoCelula*) malloc(sizeof(TipoCelula));
	if (NovaCelula == NULL) {
		return false;
	}
	else {
		NovaCelula->item = valor;
		NovaCelula->prox = Topo;
		Topo = NovaCelula;

		Pilha_Contador++;

		return true;
	}

};


int Pilha_Get() {
	int valor;
	if (Pilha_Vazia()) {
		return false;
	}
	else {

		valor = Topo->item;
		return valor;
	}

};

bool Pilha_Imprime() {

	if (!Pilha_Vazia()) {
		TipoCelula* Temp;
		/*int i, j;
		Temp = Topo;
		j = Pilha_Contador;
		for(i=1; i<=Pilha_Contador; i++) {

			std::cout << "Item n: ";
			std::cout << j; std::cout << ": ";
			std::cout << Temp->item;
			std::cout << "\n";
			Temp = Temp->prox;
			j--;
		}
		return true;
		free(Temp);*/
		/*Outro modo de fazer abaixo:*/
		int i;
		i = Pilha_Contador;
		for (Temp = Topo; Temp != NULL; Temp = Temp->prox) {

			std::cout << "Item n: ";
			std::cout << i << ": ";
			std::cout << Temp->item;
			std::cout << "\n";
			i--;
		}
		free(Temp);
	}
	else {
		return false;
	}
}


int main()
{
	Pilha_Construtor();

	int i;

	for (i = 1; i <= 10; i++) {
		Pilha_Push(rand()%100 * i);
	}

	std::cout << "\nElementos na pilha: ";
	std::cout << Pilha_Contador;
	std::cout << "\n";
	Pilha_Imprime();

	Pilha_Destrutor();
		
}



