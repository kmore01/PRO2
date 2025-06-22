/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
T max_suma_cami() const {
    return max_suma_cami_aux(primer_node);
}

static T max_suma_cami_aux(node_arbre *n) {
    // Caso base
    if (n == NULL) return 0;
    // Caso general
    T izq = max_suma_cami_aux(n->segE);
    T der = max_suma_cami_aux(n->segD);
    if (izq >= der) return izq + n->info;
    return der + n->info;
}