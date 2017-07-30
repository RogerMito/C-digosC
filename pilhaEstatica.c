/**
    CS-11 Asn 2, pilhaDinamica.cpp
    Purpose: Código simples que implementa o funcionamento de uma pilha dinâmica por meio dos conceitos
    de ponteiros e classes.

    @author Rogério de Oliveira Batista
    @version 1.0 07/10/16 
*/
#include <iostream>
#include <stdio.h>
#define tam 30
int topo =0;
int stack[tam];
using namespace std;

      void push(int number, int stack[])
      {
	      if(topo >= tam)
	      {
		      cout<<"\tA pilha esta cheia!"<<endl;
	      }
	      else
	      {
		      stack[topo] = number;
		      topo++;
	      }		
      }
      void pop ()
      {
	      if( empty() )
	      {
		      cout<<"\tA pilha esta vazia"<<endl;
	      }
	      else
	      {

		      stack[topo] = 0;
		      topo--;
	      }
      }
      void start(int n[])
      {
	      for(int i=0; i<tam; i++)
	      {
		      n[i] = 0;
	      }
      }
      bool empty ()
      {
	      if(topo <= 0)
	      {
		      return true;
	      }
	      else return false;
		
      }

      int main()
      {

      start(stack);
	      return 0;
      }
