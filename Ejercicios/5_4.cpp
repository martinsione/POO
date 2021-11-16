#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Dict { 
    string key, value; 
};

class ConfigFile {
public:
    ConfigFile(string filepath) : config_in(filepath), m_filepath(filepath) {
        Dict aux; string s;
        while (getline(config_in, s)) {
            if (s[0] == '#') continue;
            aux.key = s.substr(0, s.find("="));
            aux.value = s.substr(s.find("=") + 1);
            v.push_back(aux);
        }
    }
    vector<Dict> VerTodosLosValores() { return v; }
    string verValor (int index) { return v[index].value; }
    void camiarValor (int index, string new_value) { v[index].value = new_value; }
    void guardarCambios () {
        ofstream config_out(m_filepath);
        for (size_t i=0; i<v.size(); i++)
            config_out << v[i].key << "=" << v[i].value << endl;
        config_out.close();
    } 
private:
    string m_filepath;
    vector<Dict>v;
    ifstream config_in;
};

int main() {
    ConfigFile facu("archives/5_4-config.txt");

    cout << facu.verValor(0);
    facu.camiarValor(0, "Calculo I");
    facu.guardarCambios();

    /* vector<Dict> values = facu.VerTodosLosValores(); */
    /* for(size_t i=0; i<values.size(); i++) { */
    /*     cout << values[i].key << " | " << values[i].value << endl; */
    /* } */

    return 0;
}

