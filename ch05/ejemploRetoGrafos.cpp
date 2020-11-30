#include <iostream>
#include <unordered_map>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
template <class T>
class Vertice{
	public:
	T value;
	bool visited;
	unordered_map<Vertice<T> *, int> arcos;
	
	Vertice(T val){
		value=val;
		visited=false;
	}
	
	void agregarArcoPeso(Vertice<T> *sig, int peso){
		if(arcos.find(sig)==arcos.end()){
			arcos[sig]=peso;
		}
	}
	
	void agregarArco(Vertice<T> *sig){
		agregarArcoPeso(sig, 1);
	}
	
	void imprimirArcos(){
		cout<<value<<":";
		for(auto it=arcos.begin(); it!=arcos.end(); it++){
			cout<<it->first->value<<","<<it->second<<";";
		}
		cout<<endl;
	}
	
	int obtenerPeso(Vertice<T> *temp){
		if(arcos.find(temp)!=arcos.end()){
			return arcos[temp];
		}
		return 0;
	}
	
	bool seConecta(Vertice<T> *destino){
		if(arcos.find(destino)!=arcos.end()){
			return true;
		}
		return false;
	}
	
	int actualizarPeso(Vertice<T> *temp, int peso){
		arcos[temp]=peso;
	}
	
	int obtenerCantidadSiguientes(){
		return arcos.size();
	}
	
};

template <class T>
class Graph{
	public:
	unordered_map<T, Vertice<T> *> vertices;
	
	void agregarVertice(T value){
		if(vertices.find(value)==vertices.end()){
			Vertice<T> *nuevo=new Vertice<T>(value);
			vertices[value]=nuevo;
		}
	}
	
	void agregarOActualizar(T v1, T v2){
		agregarVertice(v1);
		agregarVertice(v2);
		int peso=vertices[v1]->obtenerPeso(vertices[v2]);
		if(peso!=0){
			vertices[v1]->actualizarPeso(vertices[v2], peso+1);
		}else{
			agregarArcoDirigidoPeso(v1, v2, 1);
		}
		
	}
	
	void agregarArcoDirigidoPeso(T v1, T v2, int peso){
		vertices[v1]->agregarArcoPeso(vertices[v2], peso);
	}
	
	void agregarArcoDirigido(T v1, T v2){
		this->agregarArcoDirigidoPeso(v1, v2, 1);
	}
	
	void agregarArcoPeso(T v1, T v2, int peso){
		agregarArcoDirigidoPeso(v1, v2, peso);
		agregarArcoDirigidoPeso(v2, v1, peso);
	}
	
	void agregarArco(T v1, T v2){
		agregarArcoPeso(v1, v2, 1);
	}
	
	int cantidadEntrantes(T v1){
		int cantidad=0;
		if(vertices.find(v1)!=vertices.end()){
			for(auto it=vertices.begin(); it!=vertices.end(); it++){
				if(it->second->seConecta(vertices[v1])){
					cantidad++;
				}
			}	
		}
		
		return cantidad;
	}
	
	
	int cantidadArcos(T v1){
		return vertices[v1]->obtenerCantidadSiguientes();
	}
	
	
	
	void imprimirGrafo(){
		for(auto it=vertices.begin(); it!=vertices.end(); it++){
			it->second->imprimirArcos();
		}
	}
	
	bool DFS(T v1, T v2){
		stack<Vertice<T> *> s;
		s.push(vertices[v1]);
		while(s.size()>0){
			Vertice<T> *actual=s.top();
			s.pop();
			actual->visited=true;
			if(actual==vertices[v2]){
				return true;
			}else{
				for(auto it=actual->arcos.begin(); it!=actual->arcos.end(); it++){
					if(it->first->visited!=true){
						s.push(it->first);
					}
				}
			}
		}
		return false;
	}
};	


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


void checarCantidadSalientes(string dia, string ip){
	Graph<string> g;
	for(Record r: conexiones){
		if(r.fecha==dia&&isPrivate(r.ipFuente)!="-1"&&isPrivate(r.ipDestino)!="-1"){
			g.agregarOActualizar(r.ipFuente, r.ipDestino);
		}
	}
	cout<<"Conexiones de "<<ip<<" en dia "<<dia<<":"<<g.cantidadArcos(ip)<<endl;
	cout<<"Conexiones entrantes a "<<ip<<" en dia "<<dia<<":"<<g.cantidadEntrantes(ip)<<endl;
	//g.imprimirGrafo();
}

void checarCantidadEntrantes(string dia, string nombre){
	Graph<string> g;
	for(Record r: conexiones){
		if(r.fecha==dia&&isPrivate(r.ipFuente)!="-1"&&isPrivate(r.ipDestino)=="-1"&&r.ipDestino!="-"){
			g.agregarOActualizar(r.nombreFuente, r.nombreDestino);
		}
	}
	//g.imprimirGrafo(); 
	cout<<"Conexiones entrantes a "<<nombre<<" en dia "<<dia<<":"<<g.cantidadEntrantes(nombre)<<endl;
}



int main(int argc, char *argv[]){
	string ip="172.31.90.47";
	string raro="916t95wtls6d3sie7ew6.net";
	string sitio="craigslist.org";
	string val=argv[1];
	leerDatos("/mnt/c/Users/L03040561/Desktop/estruct/nuevo"+val+".csv");
	string fecha=conexiones[0].fecha;
	vector<string> dias;
	for(Record r: conexiones){
		if(r.fecha!=fecha){
			dias.push_back(fecha);
			fecha=r.fecha;
		}
	}
	for(int i=0; i<dias.size(); i++){
		checarCantidadSalientes(dias[i], ip); 
	}
	for(int i=0; i<dias.size(); i++){
		checarCantidadEntrantes(dias[i], raro); 
	}
	for(int i=0; i<dias.size(); i++){
		checarCantidadEntrantes(dias[i], sitio); 
	}
	
	
	
	
	
}