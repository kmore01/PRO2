#include <iostream>
#include "BinTree.hh"

using namespace std;



#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

#include "BinTree.hh"

int getIdVar(string s)
{
 return atoi(s.substr(1).c_str());
}

int main()
{
 string s1, s2, s3, s4, s5, s6, s7;
 int numvars;
 cin >> s1 >> numvars >> s2;               // s1 consume numvars= y s3 consume ;
 vector<BinTree<int> > arboles(numvars);
 vector<int> arboles_medidas(numvars);
 vector<int> arboles_sumas(numvars);
 while (cin >> s1 >> s2) {
  if (s1[0] == 't') {
   int idvar = getIdVar(s1);
   if (s2 == "=BinTree(") {
    int value;
    cin >> value >> s3 >> s4 >> s5 >> s6 >> s7;
    int idvar1 = getIdVar(s4);
    int idvar2 = getIdVar(s6);

    BinTree<int> izq;
    int altura_izq = 0;
    int suma_izq = 0;
    if (arboles[idvar1].empty()) {
        izq = BinTree<int>();
    }
    else {
        izq = arboles[idvar1];
        altura_izq = arboles_medidas[idvar1];
        suma_izq = arboles_sumas[idvar1];
    }

    BinTree<int> der;
    int altura_der = 0;
    int suma_der = 0;
    if (arboles[idvar2].empty()) der = BinTree<int>();
    else {
        der = arboles[idvar2];
        altura_der = arboles_medidas[idvar2];
        suma_der = arboles_sumas[idvar2];
    }

    BinTree<int> aux(value, izq, der);
    arboles[idvar] = aux;
    arboles_medidas[idvar] = 1 + altura_izq + altura_der;
    arboles_sumas[idvar] = value + suma_izq + suma_der;
   } else if (s2 == "=") {
    cin >> s3 >> s4;
    int idvar1 = getIdVar(s3);
    if (s4 == ".left();") {
        arboles[idvar] = arboles[idvar1].left();
        arboles_medidas[idvar] = arboles_medidas[idvar1];
    } else {
        arboles[idvar] = arboles[idvar1].right();
        arboles_medidas[idvar] = arboles_medidas[idvar1];
        arboles_sumas[idvar] = arboles_sumas[idvar1]
    }
   }
  } else if (s1 == "cout<<") {
   int idvar = getIdVar(s2);
   cin >> s3;                       // arbol a imprimir

   BinTree<int> impr = arboles[idvar];
   
   impr.setOutputFormat(BinTree<int>::INLINEFORMAT);
   cout << impr << endl;
  } else if (s1 == "cout<<size(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   if (arboles[idvar].empty()) cout << 0 << endl;
   else cout << arboles_medidas[idvar];
   
  } else if (s1 == "cout<<sum(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   if (arboles[idvar].empty()) cout << 0 << endl;
   else cout << arboles_sumas[idvar] << endl;
  }
 }
}