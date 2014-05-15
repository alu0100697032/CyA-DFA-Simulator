//fichero dfa.cpp
#include "dfa.h"

//Constructor
dfa::dfa(){
	
	c = 7;
	//char fichero[50]; 
	cout << "Escriba el nombre del fichero a estudiar: \n";
	cin >> fichero;
	ifstream entrada(fichero);
	if(entrada.good()) {
		entrada >> f; 
		n_estados = f; //asignacion del numero de estados
		entrada >> e_ini; //asignacion del estado inicial
		DFA = new char*[f];
		for(int i = 0; i < f ; i++)
			DFA[i] = new char[c];
		char a[f];	
		for (int i = 0; i < f; i++){
			for (int j = 0; j < 7; j++){
				entrada >> a[j];
				DFA[i][j] = a[j];
			}		
		}	
		
	}else{
		cout << "No se a podido leer el fichero. Compruebe que es el correcto. \n";	
		exit(0);
	}		
	entrada.close();
	
}
//Destructor
dfa::~dfa(){
	
	for (int i = 0; i < f; i++)   // Borrar columnas
		delete [] DFA[i];
	delete [] DFA; 				// Borrar filas
	
}
//Funcion mostrar DFA
void dfa::mostrarDFA(){
	
	cout << n_estados << endl;
	cout << e_ini << endl;
	for (int i = 0; i < f; i++){
		for (int j = 0; j < c; j++){
			cout << DFA[i][j] << " " ; 
		}	
		cout << endl;		
	}	
}
//Funcion estado de muerte si o no
void dfa::e_muerte(){
	
	int aux5;
	for (int i = 0; i < f; i++){
		if(DFA[i][4] == DFA[i][6]){
			aux5 = DFA[i][1] - '0';
			if(aux5 == 0){
				cout << "	Hay estados de muerte: \n";
				cout << "	El estado " << DFA[i][0] << " es un estado de muerte \n";
			}	
		}
	}	
	cout << endl;
}

//Funcion comprobar cadena

void dfa::cadena(){
	
	//int aux2;
	char cadena[50];
	int tam;
	int e_act = e_ini;
	cout << "Introduzca una cadena para que el DFA la examine: \n";
	cin >> cadena;	
	tam = strlen(cadena);
	cout << "Cadena de entrada: " << cadena << endl;
	cout << "Estado actual	Etrada	Siguiente estado \n";
	for(int i = 0; i < tam; i++){
		cout << "      " << e_act << "            " << cadena[i] << "          ";	
		if(cadena[i] == DFA[e_act][3]){
			cout << DFA[e_act][4];
			e_act = DFA[e_act][4] - '0';
		}else if(cadena[i] == DFA[e_act][5]){
			cout << DFA[e_act][6];
			e_act = DFA[e_act][6] - '0';
		}	
		cout << endl;	
	}
	for (int k = 0; k < tam; k++){
		if(cadena[k] != 'a')
			if( cadena[k] != 'b')
				 if(cadena[k] != '0')
					 if(cadena[k] != '1')
						cout << "La cadena NO ES ACEPTADA \n";	
		//}else{
			//aux2 = DFA[e_act][1] -'0';
			//if (aux2 == 1)
				//cout << "La cadena es ACEPTADA \n";
			//else 
				//cout << "La cadena NO ES ACEPTADA \n";
		//}
													
	//}					
	//aux2 = DFA[e_act][1] -'0';
	//if (aux2 == 1)
		//cout << "La cadena es ACEPTADA \n";
	//else 
		//cout << "La cadena NO ES ACEPTADA \n";	
	}
}
