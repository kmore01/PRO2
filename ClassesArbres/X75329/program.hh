
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) {
    return freq_aux(primer_node, x);
}

static int freq_aux(node_arbre* n, const T& x) {
    // Caso base
    if (n == NULL) return 0;
    // Caso general
    int izq = freq_aux(n->segE, x);
    int der = freq_aux(n->segD, x);
    int act = 0;
    if (n->info == x) ++act;
    return act + izq + der;
}