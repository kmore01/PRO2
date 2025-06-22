/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const {
    return freq_aux(primer_node, x);
}

int freq_aux(node_arbre* n, const T& x) const {
    // Caso base
    if (n == NULL) return 0;
    // Caso general
    int izq = freq_aux(n->segE, x);
    int der = freq_aux(n->segD, x);
    if (n->info == x) return izq + der + 1;
    return izq + der;
}