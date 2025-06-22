/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
T max_suma_cami() {
    return max_suma_cami_aux(primer_node);
}



T max_suma_cami_aux(node_arbre* n) {
    // Caso base
    if (n == NULL) return 0;
    // Caso general
    T max_izq = max_suma_cami_aux(n->segE);
    T max_der = max_suma_cami_aux(n->segD);
    if (max_izq >= max_der) return n->info + max_izq;
    else return n->info + max_der;
}