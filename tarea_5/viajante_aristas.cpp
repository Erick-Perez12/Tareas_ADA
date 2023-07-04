#include <iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
int poblacion = 0;
#define col 1
vector<vector<int>> guardar;
vector<vector<int>> re;
vector<int>resultado;
vector<int> apti;
vector<char> letra{'A', 'B', 'C', 'D', 'F'};
ofstream file("resultado.txt", ios::out);
int pesos[5][5];
void pes() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            if (i == k) {
                pesos[i][k] = 0;
            }
            else if (k > i) {
                pesos[i][k] = pesos[k][i] = 1 + rand() % (21 - 1);
            }
            else if (k < i) {
                pesos[k][i] = pesos[i][k];
            }
            file << pesos[i][k] << " ";
        }
        file << endl;
    }
}

void mostrar(vector<vector<int>> pr) {
    for (int i = 0; i < pr.size(); i++) {
        file << i << ") ";
        for (int j = 0; j < pr[i].size(); j++) {
            file << letra[pr[i][j]] << " ";
        }
        file << endl;
    }
}
void permutations(vector<int> str, int i, int n) {
    if (poblacion <= 49) {
        if (i == n - 1) {
            for (int k = 0; k < col; k++) {
                vector<int> aux;
                for (int j = 0; j < str.size(); j++) {
                    aux.push_back(str[j]);
                }
                guardar.push_back(aux);
                poblacion++;
            }
            return;
        }
        for (int j = i; j < n; j++) {
            swap(str[i], str[j]);
            permutations(str, i + 1, n);
            swap(str[i], str[j]);
        }
    }
}

void apt(vector<int> arr, vector<vector<int>>mat) {
    for (int j = 0; j < mat.size(); j++) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i != arr.size() - 1) {
                int aux = pesos[mat[j][i]][mat[j][i + 1]];
                sum = sum + aux;
            }
        }
        apti.push_back(sum);
    }
}

void most_fila(int pos, vector<vector<int>>mos) {
    for (int i = 0; i < mos[pos].size(); i++) {
        file << letra[mos[pos][i]] << " ";
    }
    file << endl;
}


void vs(vector<vector<int>> tor, vector<int>apt_, int val_A, int val_B) {
    if (apt_[val_A] > apt_[val_B]) {
        resultado.push_back(val_B);
        file << val_B << "   Aptitud:  " << apt_[val_B] << "   =>  ";
        most_fila(val_B, tor);
    }
    else {
        resultado.push_back(val_A);
        file << val_A << "   Aptitud:  " << apt_[val_A] << "   =>  ";
        most_fila(val_A, tor);
    }
}

void emp(vector<int> m) {
    for (int i = 0; i < m.size(); i++) {
        file << letra[m[i]] << " ";
    }
    file << endl;
}
void p_h(vector<vector<int>>tor, int p1, int p2) {
    file << "Padre 1: ";
    most_fila(p1, tor);
    file << "Padre 2: ";
    most_fila(p2, tor);
    vector<int>aux1;
    vector<int>aux2;
    for (int i = 0; i < tor[p1].size(); i++) {
        if (i == 1 or i == 4) {
            aux1.push_back(tor[p2][i]);
            aux2.push_back(tor[p1][i]);
        }
        if (tor[p1][i] != tor[p2][1] and tor[p1][i] != tor[p2][4]) {
            aux1.push_back(tor[p1][i]);
        }
        if (tor[p2][i] != tor[p1][1] and tor[p2][i] != tor[p1][4]) {
            aux2.push_back(tor[p2][i]);
        }
    }
    re.push_back(aux1);
    re.push_back(aux2);
    file << "Hijo 1: ";
    emp(aux1);
    file << "Hijo 2: ";
    emp(aux2);
    file << "------------------------------------------------ \n";

}

void PBX(vector<vector<int>> tor) {
    if (re.empty()) {
        for (int i = 0; i < resultado.size(); i++) {
            if (i + 1 < resultado.size()) {
                p_h(tor, resultado[i], resultado[i + 1]);
                i++;
            }
        }
    }
    else {
        re.clear();
        PBX(tor);
    }
}

void list_ap(vector<vector<int>>m, vector<int>aptit) {
    file << "\n Calcular la aptitud para cada individuo \n";
    for (int i = 0; i < m.size(); i++) {
        file << i << ")  ";
        for (int k = 0; k < m[0].size(); k++) {
            file << letra[m[i][k]] << " ";
        }
        file << "     " << aptit[i] << endl;;
    }
}

void torneo(vector<int> arr, vector<vector<int>> tor, int it) {
    apt(arr, tor);
    list_ap(tor, apti);
    srand(time(NULL));
    file << "\n **********ITERACION " << it + 1 << "**********\n";
    for (int i = 0; i < tor.size(); i++) {
        int auxA, auxB;
        auxA = rand() % tor.size();
        auxB = rand() % tor.size();
        if (auxA == auxB) {
            auxB = rand() % tor.size();
        }
        file << i << ") " << auxA << " - " << auxB << " ganador: ";
        vs(tor, apti, auxA, auxB);
    }
    file << "-------------------------------------------------\n";
    PBX(tor);
    file << "NUEVA POBLACION: \n";
    mostrar(re);
    resultado.clear();
    apti.clear();
}

int main() {
    vector<int> matriz{0, 1, 2, 3, 4};
    file << "ERICK JESUS PEREZ CHIPA \n";
    file << "Parametros: \n";
    file << " - Cantidad de individuos: 50\n";
    file << " - Cantidad de genes por individuo: 5\n";
    file << " - Seleccion por Torneo \n";
    file << " - Probabilidad de Cruzamiento : 0.5\n";
    file << " - Cruzamiento PBX\n";
    file << " - Probabilidad de Mutacion : 0.0\n";
    file << " - Mutacion de Intercambio\n";
    file << " - Cantidad de Iteraciones : 14\n \n";
    permutations(matriz, 0, matriz.size());

    file << "POBLACION INICIAL: \n";
    mostrar(guardar);
    file << "\n MATRIZ DEL PESO: \n";
    pes();
    torneo(matriz, guardar, 0);
    for (int i = 0; i < 12; i++) {
        torneo(matriz, re, i + 1);
    }

    file.close();
    return 0;
}