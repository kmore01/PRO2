#include <iostream>
#include "Estudiant.hh"
#include <vector>

using namespace std;



int main () {
    int num_students, num_subjects, subjects_assigned;
    cin >> num_students >> num_subjects >> subjects_assigned;

    // Vector que contendra el identificador de cada materia
    vector<int> indetificator_subject(subjects_assigned);
    for (int i = 0; i < subjects_assigned; ++i) {
        cin >> indetificator_subject[i];
    }

    vector<Estudiant> stu(num_students);
    for (int i = 0; i < num_students; ++i) {
        int pos = 0, DNI;
        cin >> DNI;
        double ans = 0;
        
        for (int k = 1; k <= num_subjects; ++k) {    
            double mark;
            cin >> mark;
            if (pos < indetificator_subject.size() and k == indetificator_subject[pos]) { // cuenta
                ans += mark;
                ++pos;
            }
        }

        stu[i] = Estudiant (DNI);
		stu[i].afegir_nota(ans / subjects_assigned);
		stu[i].escriure();
    }
}