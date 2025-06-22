/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
    if (primer_node != NULL) return buscar_aux(primer_node, x);
    return false;
}

static bool buscar_aux(node_arbreGen* n, const T& x) {
    // Caso base
    if (n->info == x) return true;
    // Caso general
    int i = 0;
    while (i < n->seg.size()) {
        if (buscar_aux(n->seg[i], x)) return true;
        ++i;
    }
    return false;
}