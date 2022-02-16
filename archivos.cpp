//Universidad Nacional de Colombia
// Facultad de Ingeniería
// Departamento de Ingeniería de Sistemas e Industrial
// Programación de Computadores
// Challenge 9
// Eder José Hernández Buelvas
#include <iostream>
#include <string>
#include <math.h>
#include<cstdlib>
#include<fstream>
using namespace std;
string clave="3008199360";
int i=0;

string codificar(string mensaje);
string decodificar(string strpalabra);
void regresarMenu();
string toBinary(int n);
string cifradoBinario(string mensaje);
void decisionmenu();

string descifradoBinario(string mensaje);
int todec(string bin);
void entrada();
string entradamensaje;
void salida();
int tipomenu=0;

char a;
int main(){
	system("cls");

decisionmenu();
	
}


void entrada(){

	
    ifstream archivoentrada;
    archivoentrada.open("salida.txt");
    if(archivoentrada.fail()){
        cout<<"no se abrio el archivo"<<endl;
        exit(1);
    }
    while(!archivoentrada.eof()){
        getline(archivoentrada,entradamensaje);
    }archivoentrada.close();

	a=entradamensaje[entradamensaje.size()-1];
	}
    
string lectura(){

    
	char prueba[entradamensaje.size()];
    
    
    
   
    for(int o=0; o<entradamensaje.size()-1; o++){
    	prueba[o]=entradamensaje[o];
    
	} 
	
	
    return prueba;
}

void salida(){

    ofstream archivo;
    archivo.open("salida.txt");
    if(archivo.fail()) cout<<"no se abrio el archivo"<<endl;
    
     if (tipomenu==1 && a=='d') cout<<"El archivo esta descifrado y su cifrado guardado es: "<<codificar(lectura()),  archivo<<codificar(lectura());
	 else if (tipomenu==1 && a=='c')cout<<"El archivo esta cifrado y su descifrado guardado es: "<<decodificar(lectura()), archivo<<decodificar(lectura());
     else if (tipomenu==2 && a=='d')cout<<"El archivo esta descifrado y su cifrado guardado es: "<<cifradoBinario(lectura()), archivo<<cifradoBinario(lectura());
     else if (tipomenu==2 && a=='c')cout<<"El archivo esta cifrado y su descifrado guardado es: "<<descifradoBinario(lectura()), archivo<<descifradoBinario(lectura());
    archivo.close();

}

string codificar(string mensaje){

	char cifrado;
	char descifrado=' ';
	char palabra[mensaje.size()];
	int j=0;
	for(int i=0; i<mensaje.size();i++){
		if(j==clave.size()) j=0;
		
		if (int(mensaje[i]^clave[j])<32){
			cifrado=mensaje[i];
		}else{cifrado=mensaje[i]^clave[j];}
		
		palabra[i]=cifrado;

    j=+1;
	} 
  string strpalabra=palabra;
	return strpalabra+"c";
}


string decodificar(string strpalabra){
 	char descifrado;
 	char decpalabra[strpalabra.size()];
		int l=0;
  	for (int k=0; k<strpalabra.size(); k++){
  	if(l==clave.size()) l=0;
    
    if (int(strpalabra[k]^clave[l])<32){
			descifrado=strpalabra[k];
		}else{ descifrado=strpalabra[k]^clave[l];}
    decpalabra[k]=descifrado;
 
 	 l=+1;}
	string strdecpalabra=decpalabra;
	
	return strdecpalabra+"d";
}
	

void regresarMenu(){
	char opcion=' ';
	cout<<"\n\n¿Desea regresar al menú principal? (s/n)\n\n";
	cin>>opcion;
	if (opcion=='s'){i++;
	main(); }
	else if (opcion=='n') exit(0);
	else cout<<"Digite una opción correcta"; system("cls"); regresarMenu();
	
}

void decisionmenu(){

	cout<<"\t\t\t Bienvenido a su sistema de encriptado, por favor ingrese su objetivo:\n\n";
			cout<<"Por favor, seleccione la metodología de cifrado o descifrado"<<endl<<endl;
	cout<<"\n1-->XOR\n";
	cout<<"\n2-->Corrimiento de BITS\n";
	cout<<"\n3-->Salir\n\n";
	cout<<"\nPor favor seleccione la opcion que desea realizar 1, 2 o 3 y presione enter\n\n";
	cin>>tipomenu;
	entrada();
	salida();
	cout<<endl<<"Muchas gracias por usar nuestro sistema."<<endl;
	regresarMenu();}
			

string toBinary(int n){
    string r;
   while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    } 
	string o;
	 
	for(int h=r.size()-1;h>=0;h--){
    	o+=r[h];
	}
    return o;
}

string cifradoBinario(string mensaje){
	string binariochar;
	string copiabinario;
	string cifrado;
	string llenado;
	for (int z=0;z<8;z++){
		binariochar+="0";
		copiabinario+="0";
	}
	for (int i=0;i<mensaje.size();i++){
		unsigned char signo = mensaje[i];
			llenado=toBinary(int(signo));
	
		int b=llenado.size()-1;
		for(int h=7; b>=0;h--){
			binariochar[h]=llenado[b];
			copiabinario[h]=llenado[b];
		b--;}
		
	if (llenado.size()==8){
		binariochar=llenado;
		copiabinario=llenado;}
		
		
		
		binariochar[0]=binariochar[7];
	for (int j=llenado.size(); j>0;j--){
		binariochar[j]=copiabinario[j-1];
		
	}
	
 unsigned char chardec=todec(binariochar);
 cifrado+=chardec;

	}return cifrado+"c";
}


int todec(string bin){
	
	int potencia=bin.size()-1;
	int sumas=0;
	int resultado=0;
	int copia=0;
	for(int l=0; l<bin.size();l++){
	int binario=bin[l]-'0';
	sumas=binario*pow(2,potencia);
	potencia--;
	resultado+=sumas;
	}
	return resultado;
	}

string descifradoBinario(string mensaje){
	string binariochar;
	string copiabinario;
	string cifrado;
	string llenado;
	string respaldo;
	for (int z=0;z<8;z++){
		binariochar+="0";
		copiabinario+="0";
		respaldo+="0";

	}
	for (int i=0;i<mensaje.size();i++){
		unsigned char signo=mensaje[i];
		
		llenado=toBinary(int(signo));

	

		
int b=llenado.size()-1;
		for(int h=7; b>=0;h--){
			binariochar[h]=llenado[b];
			copiabinario[h]=llenado[b];
		b--;
		}
	if (llenado.size()==8){
		binariochar=llenado;
		copiabinario=llenado;
	}
		binariochar[7]=binariochar[0];
		//	cout<<endl<<"después del ciclo"<<endl<<llenado<<endl<<binariochar<<endl<<"fin del ciclo"<<endl;
			
		
	for (int j=7; j>0;j--){
		binariochar[j-1]=copiabinario[j];
		
	}
	
 unsigned char chardec=todec(binariochar);
 cifrado+=chardec;

binariochar=respaldo;
copiabinario=respaldo;	}return cifrado+"d";
}
