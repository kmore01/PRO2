/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
    if (primer_node == NULL) return;
    node_arbreNari* m;
    int suma;
    arbsuma_aux(primer_node, m, suma);
    asum.primer_node = m;
}

static void arbsuma_aux(node_arbreNari* n, node_arbreNari* &m, int &suma) {
    // Caso base
    if (n == NULL) {
        suma = 0;
        m = NULL;
        return;
    }
    // Caso general
    vector<node_arbreNari*> punteros(n->seg.size());
    suma = n->info;
    for (int i = 0; i < n->seg.size(); ++i) {
        int suma_prov;
        arbsuma_aux(n->seg[i], punteros[i], suma_prov);
        suma += suma_prov;
    }
    m = new node_arbreNari;
    m->info = suma;
    m->seg = punteros;
}