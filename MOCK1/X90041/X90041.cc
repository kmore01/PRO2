// Programa que maneja un diccionario de estudiantes y asignaturas

#include <iostream>
#include <map>
#include <set>

using namespace std;

// Procedimiento que inscribe a un estudiante a una asignatura
void enroll (map<string, set<string> > &e, map<string, set<string> > &a) {
    string estudiante, asignatura;
    cin >> estudiante >> asignatura;
    e[estudiante].insert(asignatura);
    a[asignatura].insert(estudiante);
}

// Procedimiento que elimina a un estudiante de una asignatura
void quit (map<string, set<string> > &e, map<string, set<string> > &a) {
    string estudiante, asignatura;
    cin >> estudiante >> asignatura;
    e[estudiante].erase(asignatura);
    a[asignatura].erase(estudiante);
}

// Procedimiento que imprime las asignaturas de un estudiante
void subjectsofstudent (map<string, set<string> > &e) {
    string estudiante;
    cin >> estudiante;
    bool printespacio = false;
    for (set<string>::iterator it = e[estudiante].begin(); 
        it != e[estudiante].end(); ++it) {
            if (printespacio) cout << ' ';
            printespacio = true;
            cout << *it;
    }
    cout << endl;
}

// Procedimiento que imprime los estudiantes de una asignatura
void studentsofsubject (map<string, set<string> > &a) {
    string asignatura;
    cin >> asignatura;
    bool printespacio = false;
    for (set<string>::iterator it = a[asignatura].begin(); 
        it != a[asignatura].end(); ++it) {
            if (printespacio) cout << ' ';
            printespacio = true;
            cout << *it;
    }
    cout << endl;
}

int main () {
    string accion;
    map<string, set<string> > estudiant; // map con el estudiante y sus asingaturas
    map<string, set<string> > asign; // map con la asignatura y sus estudiantes
    while (cin >> accion) {
        // inscribir a un estudiante en una asingatura
        if (accion == "ENROLL") { 
            enroll(estudiant, asign);
        }
        // eliminar a un estudiante de una asingatura
        else if (accion == "QUIT") { 
            quit(estudiant, asign);
        }
        // imprimir las asingaturas de un estudiante
        else if (accion == "SUBJECTSOFSTUDENT") {
            subjectsofstudent(estudiant);
        }
        // imprimir los estudiantes inscritos a una asignatura
        else { // "STUDENTSOFSUBJECT"
            studentsofsubject(asign);
        }
    }
}