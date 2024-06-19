/*@ <authors>
 *
 * Daniel Fernandez Ortiz: TAIS 21
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MOD 1000000000;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>
int throwingDice(int k, int s) {
   vector<vector<int>>dp(k, vector<int>(s + 1, 1));

   for (int i = 1; i < k; ++i) {
      for (int j = 1; j <= s; ++j) {
         dp[i][j] = dp[i - 1][j];
         if (j > i)
            dp[i][j] += dp[i][j - i - 1];
      }
   }

   return dp[k - 1][s];
}

void resuelveCaso() {
      int k, s; cin >> k >> s;
      cout << throwingDice(k, s) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
