/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
    if (primer_node == NULL) return;
    int suma;
    node_arbreNari* res;
    arbsuma_aux(primer_node, res, suma);
    asum.primer_node = res;
}

static void arbsuma_aux(node_arbreNari* n, node_arbreNari* &res, int &suma) {
    // Caso base
    if (n == NULL) {
        suma = 0;
        res = NULL;
        return;
    }
    // Caso general
    res = new node_arbreNari;
    res->info = n->info;
    res->seg = vector<node_arbreNari*>(n->seg.size());
    suma = n->info;

    vector<int> sumas(n->seg.size());

    for (int i = 0; i < n->seg.size(); ++i) {
        arbsuma_aux(n->seg[i], res->seg[i], sumas[i]);
        suma += sumas[i];
    }

    res->info = suma;
}