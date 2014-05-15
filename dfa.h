//fichero dfa.h
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
using namespace std;

//clase dfa

class dfa{
	
	private:
	
		//int* e_acep;
		char** DFA;
		int n_estados;
		int e_ini;
		int c;
		int f;
		char fichero[50];
		int* e_siga;
		int* e_sigb;
		
	public:
	
		dfa();
		~dfa();
		void mostrarDFA();
		void e_muerte();
		void cadena();
};
