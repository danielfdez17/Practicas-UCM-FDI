// Daniel Fernandez Ortiz
// PC03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <cstring>
using namespace std;

#define MAX_SIZE 100
#define LIM 1e9

int dist[MAX_SIZE][MAX_SIZE];
int caso = 1;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int a, b; cin >> a >> b;
    if (a == 0 && b == 0) return false;

    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            dist[i][j] = LIM;

    dist[a - 1][b - 1] = 1;

    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        dist[a - 1][b - 1] = 1;
    }

    for (int i = 0; i < MAX_SIZE; i++) dist[i][i] = 0;

    for (int k = 0; k < MAX_SIZE; k++)
        for (int i = 0; i < MAX_SIZE; i++)
            for (int j = 0; j < MAX_SIZE; j++) 
                dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k]);

    int cont = 0, suma = 0;

    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++) {
            if (dist[i][j] != LIM && i != j) {
                cont++;
                suma += dist[i][j];
            }
        }
    
    cout << "Case " << caso << ": average length between pages = " << setprecision(3) << fixed << (suma * 1.0 / cont) << " clicks\n";
    caso++;
    
    return true;    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
