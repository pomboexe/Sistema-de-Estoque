#include <iostream>
#include <fstream>
#include <string>
#include "itens.h"
#include <stdlib.h>

using namespace std;

int main() {
	int SUP_ID, SUP_CARAC,SUP_QNTD;
	double SUP_PO;
	string SUP_NOME, SUP_TIPO;
	int select;
	int s = 99;
	ofstream fileout;
	ifstream filein;
	string ler;
		while (s !=7) {
			system("cls");
			cout << "+======BEM VINDO AVENTUREIRO======+\n";
			cout << "================MENU===============\n";
			cout << endl;

			cout << "1-Cadastrar Item\n";
			cout << "2-Lista Estoque\n";
			cout << "3-Apagar\n";
			cout << "4-Exportar Estoque\n";
			cout << "5-Importar Estoque\n";
			cout << "6-Sair\n";
			cin >> select;
			cout << endl;

				switch (select) {
				case 6:
					s=6;
					break;
				case 1:
					int option_cad;
					fileout.open("estoque.txt",ios::app);
					cout << "=============Cadastro==============\n";
					cout << "1-Armadura\n";
					cout << "2-Armamento\n";
					cout << "3-Consumivel\n";
					cin >> option_cad;
					cout << endl;

					switch (option_cad) {
					case 1: {
						cout << "=============Armadura==============\n";
						cout << "Digite o ID do item:";
						cin >> SUP_ID;
						cout << "Digite o Nome do item:";
						cin >> SUP_NOME;
						cout << "Digite o Tipo do item:";
						cin >> SUP_TIPO;
						cout << "Digite quanto em peças de ouro custara o item:";
						cin >> SUP_PO;
						cout << "Digite a Quantidade:";
						cin >> SUP_QNTD;
						cout << "Digite a durabilidade da armadura:";
						cin >> SUP_CARAC;
						cout << endl;

						Armadura Cad{ SUP_ID,SUP_NOME ,SUP_TIPO,SUP_PO,SUP_QNTD,SUP_CARAC };
						Cad.imprimeArmor();
						fileout << "ID:"<< SUP_ID<<"\nNome:"<<SUP_NOME << "\nTipo:" << SUP_TIPO << "\nCusto:" << SUP_PO << "Quantidade:" << SUP_QNTD << "\nDurabilidade:" << SUP_CARAC<<  " \n" << endl;
						fileout.close();
						system("pause");
						break;
						
					}
					case 2: {
						cout << "============Armamento==============\n";
						cout << "Digite o ID do item:";
						cin >> SUP_ID;
						cout << "Digite o Nome do item:";
						cin >> SUP_NOME;
						cout << "Digite o Tipo do item:";
						cin >> SUP_TIPO;
						cout << "Digite quanto em peças de ouro custara o item:";
						cin >> SUP_PO;
						cout << "Digite a Quantidade em estoque:";
						cin >> SUP_QNTD;
						cout << "Digite o Dano:";
						cin >> SUP_CARAC;
						cout << endl;

						Armamento Espada{ SUP_ID,SUP_NOME,SUP_TIPO,SUP_PO,SUP_QNTD,SUP_CARAC };
						Espada.imprimeArma();
						fileout << "ID:" << SUP_ID << "\nNome:" << SUP_NOME << "\nTipo:" << SUP_TIPO << "\nCusto:" << SUP_PO << "Quantidade:" << SUP_QNTD << "\nDano:" << SUP_CARAC << " \n" << endl;
						fileout.close();
						system("pause");
						break;
					}
					case 3: {
						cout << "============Consumivel==============\n";
						cout << "Digite o ID do item:";
						cin >> SUP_ID;
						cout << "Digite o Nome do item:";
						cin >> SUP_NOME;
						cout << "Digite o Tipo do item:";
						cin >> SUP_TIPO;
						cout << "Digite quanto em peças de ouro custara o item:";
						cin >> SUP_PO;
						cout << "Digite a Quantidade em estoque:";
						cin >> SUP_QNTD;
						cout << "Quantidade de Usos:";
						cin >> SUP_CARAC;
						cout << endl;

						Consumiveis Potion{ SUP_ID,SUP_NOME,SUP_TIPO,SUP_PO,SUP_QNTD,SUP_CARAC };
						Potion.imprimeConsumi();
						fileout << "ID:" << SUP_ID << "\nNome:" << SUP_NOME << "\nTipo:" << SUP_TIPO << "\nCusto:" << SUP_PO << "Quantidade:" << SUP_QNTD << "\nUsos:" << SUP_CARAC << " \n" << endl;
						fileout.close();
						system("pause");
						break;
						}
						  fileout.close();
					}
				case 2: {
					cout<<"=============Estoque==============\n";
					filein.open("estoque.txt");
					if (filein.is_open()) {
						while (getline(filein,ler)) {
							cout << ler<< endl;
						}
					}
					filein.close();
					system("pause");
					break;
					}
				case 3: {
					cout << "===========APAGAR============\n";
					int resposta;
					cout << "deseja apagar estoque?\n";
					cout << "1-sim || 2-não\n";
					cin >> resposta;
					cout << endl;
					if (resposta == 1) {
						remove("estoque.txt");
						system("pause");
						break;
					}
					else {
						cout << "Operação cancelada\n" << endl;
						system("pause");
						break;
					}

				}
				case 4: {
						cout << "===========EXPORTAR============\n";
						ofstream fileexpo;
						string caminho;
						cout << "**observação**\n";
						cout << "ao final digite o nome do seu arquivo e .txt no final\n"<<"exemplo import.txt\n";
						cout << "Digite o caminho que deseja enviar arquivo:\n";
						cin >> caminho;
						cout << endl;
						fileexpo.open(caminho);
						if (fileexpo.is_open()) {
							string passa;
							filein.open("estoque.txt");
							if (filein.is_open()) {
								while (getline(filein, passa)) {
									fileexpo << passa<<endl;
								}

							}	
						}
						else {
							cout << "exportação falhou";
						}
						filein.close();
						fileexpo.close();
						cout << "exportação bem sucessedida\n"<<endl;
						system("pause");
						break;
					}
				case 5: {
						cout << "===========IMPORTAR==============\n";
						ifstream fileimpo;
						string caminhoimpo;
						cout << "Digite o caminho que deseja receber arquivo:\n";
						cin >> caminhoimpo;
						cout << endl;
					
						fileimpo.open(caminhoimpo,ios::app);
						if (fileimpo.is_open()) {
							fileout.open("estoque.txt");
							while (getline(fileimpo, ler)){
								fileout << ler << endl;
							}
						}
						else {
							cout << "não foi possivel importar\n" << endl;
						}
						fileout.close();
						fileimpo.close();
						cout << "exportação bem sucessedida\n" << endl;
						system("pause");
						break;
						}	
				}
				};
				
			
		return 0;
}