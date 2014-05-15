#include "dfa.cpp"

int main(){

	int eleccion;
	cout << "Pulse 1 para leer el DFA o cualquier otra número para salir. \n";
	cin >> eleccion;
	cout << endl;
	if(eleccion == 1){		
		dfa A;
		while (eleccion != 0){
			cout << " Elija una de las siguientes opciones: \n" << endl;
			cout << "	-Pulse 2 para mostrar el DFA. \n";
			cout << "	-Pulse 3 para indicar cuales son los estados de muerte. \n";
			cout << "	-Pulse 4 para leer una cadena y que el DFA la examine. \n";
			cout << "	-Pulse 0 para salir del programa. \n" << endl;
			cout << "	Elección: ";
			cin >> eleccion;
			cout << endl;
			if (eleccion == 2 || eleccion == 3 || eleccion == 4){
				switch(eleccion){
					case 2: {
						A.mostrarDFA();
						cout << endl;
					};break;
					case 3: {A.e_muerte();};
						break;
					case 4: {A.cadena();};
						break;
					case 0: ;break;	
					default:  break;
				}//endwitch
			}else{
				cout << " Elija una de las opciones propuestas, por favor. \n" << endl;
				cout << "	-Pulse 2 para mostrar el DFA. \n";
				cout << "	-Pulse 3 para indicar cuales son los estados de muerte. \n";
				cout << "	-Pulse 4 para leer una cadena y que el DFA la examine. \n";
				cout << "	-Pulse 0 para salir del programa. \n" << endl;
			}		
		}
	}else{ 
		cout << "Programa cerrado\n" << endl;
	}
	return 0;
}
