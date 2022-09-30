#ifndef ITENS_H
#define ITENS_H

#include <string>
using namespace std;
//Itemização
class Item {
private:
	int id;
	string nome;
	string tipo;
	double custo;
	int quantidade;
public:
	Item(int, string, string, double,int);
	virtual void imprime();
	~Item() { };
};
//Armadura
class Armadura : public Item {
private:
	int durab;
public:
	Armadura(int, string, string, double, int,int);
	void imprimeArmor();
	~Armadura() { };
};
//Armas
class Armamento : public Item {
private:
	int dano;
public:
	Armamento(int, string, string, double, int,int);
	void imprimeArma();
	~Armamento() { };
};
//Consumiveis
class Consumiveis : public Item {
private:
	int usos;
public:
	Consumiveis(int, string, string, double, int, int);
	void imprimeConsumi();
	~Consumiveis() { };
};
#endif