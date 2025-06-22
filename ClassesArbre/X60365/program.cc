/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
    if (primer_node == NULL) return false;
    return buscar_aux(primer_node, x);
}

static bool buscar_aux(node_arbreGen* n, const T& x) {
    // Caso base
    if (n == NULL) return false;
    else if (n->info == x) return true;
    // Caso general
    for (int i = 0; i < n->seg.size(); ++i) {
        if (buscar_aux(n->seg[i], x)) return true;
    } 
    return false;
}