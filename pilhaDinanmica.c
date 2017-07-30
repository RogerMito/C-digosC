/**
    CS-11 Asn 2, pilhaDinamica.cpp
    Purpose: Código simples que implementa o funcionamento de uma pilha dinâmica por meio dos conceitos
    de ponteiros e classes.

    @author Rogério de Oliveira Batista
    @version 1.0 07/10/16 
*/
#include <iostream>

using namespace std;

class Item{

      private:
      int number
      Item * prox;

      public:

      Item()
      {
            number=-1;
            prox=NULL:
      }
      
      int getNumber()
      {
            return number;
      }
      void setNumber(int number)
      {
            this->number=number;
      }
      Item * getItem()
      {
            return prox;
      }
      void setItem(Item * prox)
      {
            this->prox=prox;
      }
      

};

class Stack
{
      private:
      Item * topo;
      int tam;
      
      public:
      
      Stack()
      {
            topo = NULL;
            tam = 0;
      }
      
      void push(int number)
      {
      Item * item = new Item();
            
            if(empty())
            {
                  topo = item;
                  item -> setNumber(number);
                  tam++;
                   
            }
            else
            {
                  topo -> setProx(item);
                  topo = item;
                  topo -> setNumber(number);
                  tam++;
            }     
      }
      void pop()
      {
            if(empty())
            {
                  cout<<"\tPilha vazia"<<endl;
            }
            else
            {
                  if(topo -> getProx() == NULL)
                  {
                        delete topo -> getProx();
                        tam--;
                  }
                  else
                  {
                        No * aux;
                        aux = topo;
                        topo = topo -> getProx();
                        delete aux -> getProx();
                  }
            }
      }
      bool empty()
      {
            if(topo == NULL)
            {
                  return true;
            }
            else return false;
      }
      void print()
      {
      No * print = topo;
      
      if(empty())
      {
            cout<<"\tPilha vazia"<<endl;
      }
      else
            while (topo != NULL)
            {
                cout<<"\t"<<topo -> getNumber() <<endl;
                topo = topo -> getProx();
            }
      }
      
      
      
};

int main()
{
      char op = 's';
      int n;
      Stack * stack = new Stack();
      do{
      
      cout<<"\t 1 Empilhar"<<endl;
      cout<<"\t 2 Desempilhar"<<endl;
      cin>>op;
      
      switch(op)
      {
            case '1':
            cout<<"\tDigite o número a ser empilhado"<<endl;
            cin>>n;
            stack -> push(n);
            stack -> print();
            break;
            
            case '2':
           stack -> pop();
           stack -> print();
            break;
            
      }
      }while(op != 's');
      return 0;
}
