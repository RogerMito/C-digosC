#include <iostream>
#include <string.h>
//Feito por: Rogério de Oliveira Batista
//Universidade Federal de Itajubá - UNIFEI
//Engenharia de Computação
//Contato: rogerio_oliveira1992@hotmail.com
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class No
{
private:
	int number;
	No *prox;

public:

	No(int number)
	{
		this -> number = number;
		this -> prox = NULL;
	}
	
	int getNumber()
	{
		return number;
	}
	void setNumber(int number)
	{
		this -> number = number;
	}
	No * getProx()
	{
		return prox;
	}
	
	void setProx( No * prox)
	{
		this -> prox = prox;
	}
	
};
	
class Lista
{
	      private:
	
	      No * inicio;
	      No * fim;
	      int tam;
	
	      public:
	
	      Lista()
	      {
		      this -> inicio = NULL;
		      this -> fim = NULL;
		      tam = 0;
		
	      }
	      Lista (int number)
	      {
	      tam =0;
		      inicio = new No(number);
		      inicio = fim;
		      tam++;
	      }
	      No * getInicio()
	      {
		      return this -> inicio;
	      }
	//Verifica se a lista está vazia
	bool empty()
	{
		if (inicio == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//Insere elementos no início da lista
	void insert (int number)
	{
		No * novo = new No (number);
		
		if(empty())
		{
			inicio = novo;
			fim = novo;
			tam++;
		}
		else
		{
			novo -> setProx(inicio);
			inicio = novo;
			tam++;
		}
		
	}
	//Imprime a lista interativamente
	void print()
	{
		No * print = inicio;
		if(empty())
		{
			cout<<"\tPilha vazia!"<<endl;
		}
		else
		{
		
		while (print != NULL)
		{
			cout<<"\t "<<print->getNumber()<<endl;
			print = print -> getProx();
		}
		}
		
	}
	//Imprime a lista recursivamente.
	void printRecursiva(No * print)
	{
		if(empty())
		{
			cout<<"\tPilha vazia!"<<endl;
		}
		else
		{
			if(print -> getProx() == NULL)
			{
				cout<<"\t"<<print->getNumber()<<endl;
				return;
			}
			else
			{
				
				cout<<"\t"<<print->getNumber()<<endl;
				print = print -> getProx();
				printRecursiva(print);
			}
		}
		
	
	}
	//Remove elementos do inicio da lista.
	void removeStart()
	{

		if(empty() == 0)
		{
		//1 elemento
			if(inicio->getProx() == NULL)
			{
				//delete inicio -> getProx();
				inicio = fim = NULL;
				delete inicio -> getProx();
				tam--;
			}
			else
			{
		
				No * aux;
				
				aux = inicio->getProx();
				inicio->setProx(NULL);
				delete inicio -> getProx();
				inicio = aux;
				tam--;
				
				
			}
		}
		
	}
	//Remove elementos do final da lista.
	void removeEnd()
	{
		if(empty() == 0)
		{
			if(inicio->getProx() == NULL)
			{
				inicio = fim = NULL;
				tam--;
			}
			else
			{
			No * run = inicio;
				while (run)
				{
					if ((run -> getProx()) == fim ) //identificação de um nó anterior ao fim
					{
						run -> setProx(NULL);
						delete fim -> getProx();
						fim = run;
						tam--;
					}
					run = run -> getProx();
				}
			}
		}
	}
	//Retorna o tamanho da lista.
	int getTam()
	{
		return tam;	
	}
	//Realiza a pesquisa de um registro na lista.
	No * search(int key)
	{
	      No * find = inicio;
	      if(empty())
		{
			cout<<"\tPilha vazia!"<<endl;
		}
		else
		{
		
		while (find != NULL)
		{
		      if((find -> getNumber()) == key)
		      {
		            return find;
		      }
		      
		      find = find -> getProx();
		
		}
		     return NULL;
		}
	}
	
};
int main()
{
char op = 's';
int val = 0;
Lista * list = new Lista(0);
do
{
cout<<"\t1 Inserir no inicio da lista"<<endl;
cout<<"\t2 Inserir no final da lista"<<endl;
cout<<"\t3 Imprimir lista"<<endl;
cout<<"\t4 Remover no inicio da lista"<<endl;
cout<<"\t5 Remover no fim da lista"<<endl;
cout<<"\t6 Remover em qualquer lugar da lista"<<endl;
cout<<"\t7 Imprimir lista recursivamente"<<endl;
cout<<"\t8 Localizar item"<<endl;
cout<<"\ts Sair"<<endl;
cin>>op;
system("clear");
switch (op)
{
	case '1' :
	cout<<"\tDigite o número a ser inserido no inicio"<<endl;
	cin>>val;
	list ->insert(val);
	cout<<"\tLista apos a insercao"<<endl;
	list -> print();
	break;
	case '2' :
	cout<<"\tDigite o número a ser inserido no fim"<<endl;
	cin>>val;
	
	break;
	case '5':
	list ->removeEnd();
	cout<<"\tLista apos a remocao no fim"<<endl;
	list -> print();
	break;
	case '4':
	list ->removeStart();
	cout<<"\tLista apos a remocao no inicio"<<endl;
	list -> print();
	break;
	case '7':
	list -> printRecursiva(list -> getInicio());
	break;
	case '8' :
	cout<<"\tInforme o codigo a ser pesquisado"<<endl;
	cin>>val;
	No * aux;
	aux = list -> search(val);
	if(aux != NULL)
	{
	      cout<<"\t"<<aux->getNumber()<<endl;
	}
	else
	{
	      cout<<"\tElemento não localizado!"<<endl;
	}
	break;
	case 's':
	return 0;
	break;
	
	default:
	cout<<"\tOpção inválida!"<<endl;
	break;
}

}while(op != 's');


return 0;
}
