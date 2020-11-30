#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Record{
	public:
	string fecha;
	string hora;
	string ipFuente;
	int puertoFuente;
	string nombreFuente;
	string ipDestino;
	int puertoDestino;
	string nombreDestino;
	
	Record(string f, string h, string iF, string pF, string nF, string iD, string pD, string nD){
		fecha=f;
		hora=h;
		ipFuente=iF;
		if(pF=="-"){
			puertoFuente=0;
		}else{
			
			try{
				puertoFuente=stoi(pF);
			}catch (const std::invalid_argument& ia){
				puertoFuente=0;
				cout<<"error"<<pD<<endl;
			}
		}
		nombreFuente=nF;
		ipDestino=iD;
		if(pD=="-"){
			puertoDestino=0;
		}else{
			try{
				puertoDestino=stoi(pD);
			}catch (const std::invalid_argument& ia){
				puertoDestino=0;
				cout<<"error"<<pD<<endl;
			}
		}
		nombreDestino=nD;
	}
	
	void imprimirRecord(){
		cout<<nombreFuente<<endl;
	}
};

vector<Record> conexiones;
void leerDatos(string path){
	ifstream fileIn;
	fileIn.open(path);
	string line, partes;
	vector<string> valores;
	while(getline(fileIn, line)){
		istringstream sIn(line);
		while(getline(sIn, partes, ',')){
			valores.push_back(partes);
		}
		if(valores[7].find('\r')!=valores[7].npos){
			valores[7]=valores[7].substr(0, valores[7].size()-1);
		}
		Record r(valores[0], valores[1], valores[2], valores[3], valores[4], valores[5], valores[6], valores[7]);
		conexiones.push_back(r);
		valores.clear();
	}
}





string isPrivate(string ip){
	if(ip=="-"){
		return "-1";
	}
	istringstream sIn(ip);
	string partes="";
	getline(sIn, partes, '.');
	int primerOcteto=stoi(partes);
	
	if(primerOcteto!=172 && primerOcteto!=10 && primerOcteto!=192){ 	
		return "-1";
	}
	getline(sIn, partes, '.');
	int segundoOcteto=stoi(partes);
	if((segundoOcteto==172 && (segundoOcteto<16 || segundoOcteto>32)) || (segundoOcteto==192 && segundoOcteto!=168)){
		return "-1";
	}

	getline(sIn, partes, '.');
	string ipPrivada=to_string(primerOcteto)+"."+to_string(segundoOcteto)+"."+partes+".0";
	return ipPrivada;
}

class Conexion{
	public:
	int puerto;
	string ipRemota;
	int puertoRemoto;
	string nombreRemoto;
	
	Conexion(int p, string ip, int pR, string nR){
		puerto=p;
		ipRemota=ip;
		puertoRemoto=pR;
		nombreRemoto=nR;
	}
};
	
class ConexionesComputadora{
	public:
	string ip;
	string nombre;
	list<Conexion> conexionesEntrantes;
	list<Conexion> conexionesSalientes;
	
	ConexionesComputadora(){
		ip="";
		nombre="";
	}
	
	ConexionesComputadora(string ip, string nombre){
		this->ip=ip;
		this->nombre=nombre;
	}
	
	void agregarEntrante(int p, string ip, int pR, string nombre){
		Conexion c(p, ip, pR, nombre);
		conexionesEntrantes.push_front(c);
	}
	
	void agregarSaliente(int p, string ip, int pR, string nombre){
		Conexion c(p, ip, pR, nombre);
		conexionesSalientes.push_back(c);
	}
	
	void contarRepetidas(){
		int contador=0;
		string actual="";
		for(Conexion c: conexionesSalientes){
			if(c.puertoRemoto==80 || c.puertoRemoto==443){
				if(c.ipRemota==actual){
					contador++;
					if(contador==3){
						cout<<"Encontrada 3 conexiones seguidas a";
						cout<<c.nombreRemoto<<" con ip "<<c.ipRemota<<endl;
					}
				}else{
					actual=c.ipRemota;
					contador++;
				}
			}else{
				contador=0;
			}
		}
	}
	
	void printEntrantes(){
		for(Conexion c: conexionesEntrantes){
			cout<<c.ipRemota<<",";
		}
		cout<<endl;
	}
};

int main(int argc, char *argv[]){
	string a="/mnt/c/Users/L03040561/Desktop/estruct/nuevo";
	string b=".csv";
	leerDatos(a+argv[1]+b);
	cout<<"Datos leidos"<<endl;
	unordered_map<string, ConexionesComputadora> computadoras;
	unordered_set<string> unicas;
	//cargar datos
	string toFind="reto.com";
	for (Record r: conexiones){
		if(r.nombreFuente.find(toFind)==string::npos){
			unicas.insert(r.nombreFuente);
		}
		if(r.nombreDestino.find(toFind)==string::npos){
			unicas.insert(r.nombreDestino);
		}
		if(computadoras.find(r.ipFuente)==computadoras.end()){
			ConexionesComputadora cc(r.ipFuente, r.nombreFuente);
			computadoras[r.ipFuente]=cc;
		}
		if(computadoras.find(r.ipDestino)==computadoras.end()){
			ConexionesComputadora cc(r.ipDestino, r.nombreDestino);
			computadoras[r.ipDestino]=cc;
		}
		computadoras[r.ipFuente].agregarSaliente(r.puertoFuente, r.ipDestino, r.puertoDestino, r.nombreDestino);
		computadoras[r.ipDestino].agregarEntrante(r.puertoDestino, r.ipFuente, r.puertoFuente, r.nombreFuente);
	}
	//Imprimir unicos:
	for(string sitio: unicas){
		//cout<<sitio<<endl;
	}
	//Pregunta 2
	unordered_map <string, string> nameToIP;
	for (Record r: conexiones){
		nameToIP[r.nombreFuente]=r.ipFuente;
		nameToIP[r.nombreDestino]=r.ipDestino;
	}
	cout<<nameToIP["88e9sl86u11nflsir86x.xxx"]<<endl;
	cout<<nameToIP["916t95wtls6d3sie7ew6.net"]<<endl;
	//Pregunta 3 y 4
	unordered_set<string> ipEntranteUnica;
	string ipRed="172.31.90.";
	int cantidad=0;
	for(int i=1; i<255; i++){
		string buscar=ipRed+to_string(i);
		if(computadoras.find(buscar)!=computadoras.end()){
			if(computadoras[buscar].conexionesEntrantes.size()>0){
				//cout<<buscar<<": "<<computadoras[buscar].conexionesEntrantes.size()<<endl;
				if(computadoras[buscar].conexionesEntrantes.size()<10){
					for(Conexion c: computadoras[buscar].conexionesEntrantes){
						ipEntranteUnica.insert(c.ipRemota);
					}
				}
				cantidad++;
			}
		}
	}
	cout<<"Cantidad: "<<cantidad<<endl;
	//Respondiendo 4
	for(string ip : ipEntranteUnica){
		cout<<ip<<endl;
	}
	//Pregunta 6
	for(Conexion c: computadoras["172.31.90.47"].conexionesSalientes){
		if(c.ipRemota=="172.31.90.47" || c.ipRemota=="110.174.125.114"){
			cout<<"encontrado"<<endl;
			break;
		}
	}
	//Pregunta 7
	for(Record r: conexiones){
		if(r.ipFuente=="172.31.90.47" && (r.ipDestino=="110.174.125.114" || r.ipDestino=="1.136.108.6")){
			cout<<"primera conexion: "<<r.fecha<<" via puerto "<<r.puertoDestino<<endl;
			break;
		}
	}
	return 0;
}