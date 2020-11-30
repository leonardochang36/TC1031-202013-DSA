#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>

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
	if(primerOcteto!=172 & primerOcteto==10 & primerOcteto==192){
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
};

int main(){
	leerDatos("/mnt/c/Users/L03040561/Desktop/equipo0.csv");
	cout<<"Datos leidos"<<endl;
	string ipUsar="10.100.8.92";
	ConexionesComputadora cc(ipUsar, "helen.reto.com");
	for (Record r: conexiones){
		if(r.ipFuente==ipUsar){
			cc.agregarSaliente(r.puertoFuente, r.ipDestino, r.puertoDestino, r.nombreDestino);
		}else if(r.ipDestino==ipUsar){
			cc.agregarEntrante(r.puertoDestino, r.ipFuente, r.puertoFuente, r.nombreFuente);
		}
	}
	cout<<"Agregadas conexiones"<<endl;
	//Ultima conexion recibida
	string ipUltimaEntrante=cc.conexionesEntrantes.front().ipRemota;
	cout<<"La ultima conexion entrante viene de: "<<ipUltimaEntrante;
	if(isPrivate(ipUltimaEntrante)=="-1"){
		cout<<" y no es de una direccion privada"<<endl;
	}else{
		cout<<" y es de una direccion privada"<<endl;
	}
	//Conexiones entrantes
	cout<<"Esta computadora ha recibido "<<cc.conexionesEntrantes.size()<<" conexiones"<<endl;
	//conexiones Salientes
	cout<<"Esta computadora ha hecho "<<cc.conexionesSalientes.size()<<" conexiones"<<endl;
	//Checar 3 ips repetidas
	cc.contarRepetidas();
	
	return 0;
}