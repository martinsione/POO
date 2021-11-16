#include <iostream>
#include <vector>
using namespace std;
class LogSystem {
public:
	virtual void registrarMensaje(string msg) = 0;
	virtual void finalizar() { }
	virtual ~LogSystem() { }
};

void obtenerBeneficiados(int n, LogSystem &log) {
	log.registrarMensaje("Cargando archivo de datos");
	vector<Alumnos> v = cargarDatos("alumnos.dat");
	log.registrarMensaje("Filtrando Insuficientes");
	for(Alumno &a : v)
		filtrarInsuficientes(a.notas);
	log.registrarMensaje("Recalculando promedios");
	for(Alumno &a : v)
		a.prom = calcularPromedio(a.notas);
	log.registrarMensaje("Ordenando por promedio");
	ordenarVector(v,comparaPorPromedio);
	log.registrarMensaje("Guardando los "+to_string( n )+" mejores");
	v.resize( n );
	guardarDatos("becarios.dat");
	log.finalizar();
}

class CoutLogger : public LogSystem {
public:
	void registrarMensaje(string msg) override {
		cout << msg << endl;
	}
};

class VectorLogger : public LogSystem {
	vector<string> v;
public:
	void registrarMensaje(string msg) override {
		v.push_back(msg);
	}
	void finalizar() override {
		for(string msg : v)
			cout << msg << endl;
	}
};

int main() {
	LogSystem *log;
	cout << "1- CoutLogger, 2- VectorLogger ? ";
	int x; cin >> x;
	if (x==1) log = new CoutLogger;
	else      log = new VectorLogger;
	obtenerBeneficiados(10,*log);
	delete log;
}
