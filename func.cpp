#include "itens.h"
#include <iostream>
#include <string>

using namespace std;

Item::Item(int _ID, string _NOME, string _TIPO, double _PO, int _QNTD): id{ _ID }, nome{ _NOME }, tipo{ _TIPO }, custo{ _PO }, quantidade{_QNTD} {};

void Item::imprime() {
	cout << "ID: " << id <<"\n";
	cout << "Nome: " << nome << "\n";
	cout << "Tipo: " << tipo << "\n";
	cout << "Custo: " << custo << "\n";
	cout << "Quantidade:"<< quantidade<<"\n";
};

Armadura::Armadura(int _ID, string _NOME, string _TIPO, double _PO,int _QTND, int _DURAB): Item{_ID,_NOME,_TIPO,_PO,_QTND}, durab{_DURAB} {};
	void Armadura::imprimeArmor() {
	Item::imprime();
	cout << "Durabilidade: " << durab << "\n";

};
Armamento::Armamento(int _ID, string _NOME, string _TIPO, double _PO, int _QTND, int _DANO): Item{ _ID,_NOME,_TIPO,_PO,_QTND }, dano{_DANO} {};
	void Armamento::imprimeArma() {
	Item::imprime();
		cout << "Dano: " << dano << "\n";

	};
Consumiveis::Consumiveis(int _ID, string _NOME, string _TIPO, double _PO,int _QNTD, int _USOS): Item{_ID,_NOME,_TIPO,_PO,_QNTD}, usos{_USOS} {};
	void Consumiveis::imprimeConsumi() {
		Item::imprime();
		cout << "Quantidade de usos: " << usos << "\n";

	};
