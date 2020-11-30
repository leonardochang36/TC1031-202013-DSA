#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

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


map<string, int> conexionesPorDia(string dia){
	map<string, int> sitios;
	for(Record r:conexiones){
		if(r.fecha==dia&&r.nombreDestino!="-"&&r.nombreDestino.find("reto.com")==string::npos){
			if(sitios.find(r.nombreDestino)==sitios.end()){
				sitios[r.nombreDestino]=1;
			}else{
				sitios[r.nombreDestino]++;
			}
		}
	}
	return sitios;
}

void top(int n, string fecha){
	map<string, int> sitios=conexionesPorDia(fecha);
	map<int, string> masVisitados;
	for(auto sitio:sitios){
		masVisitados[sitio.second]=sitio.first;
	}
	int count=0;
	for(auto i=masVisitados.rbegin(); i!=masVisitados.rend(); i++){
		cout<<i->second<<":"<<i->first<<endl;
		count++;
		if(count==n){
			return;
		}
	}
}

int main(int argc, char *argv[]){
	string val=argv[1];
	leerDatos("/mnt/c/Users/L03040561/Desktop/estruct/"+val+".csv");
	string fecha=conexiones[0].fecha;
	vector<string> dias;
	for(Record r: conexiones){
		if(r.fecha!=fecha){
			dias.push_back(fecha);
			fecha=r.fecha;
		}
	}
	for(int i=0; i<dias.size(); i++){
		cout<<"******************Top 5 del dia "<<dias[i]<<endl;
		top(5, dias[i]);
	}
	
	
}

