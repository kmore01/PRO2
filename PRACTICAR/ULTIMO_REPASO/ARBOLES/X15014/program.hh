/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    node_arbre* m;
    int suma;   
    arb_sumes_aux(primer_node, m, suma);
    asum.primer_node = copia_node_arbre(m);
}

static void arb_sumes_aux(node_arbre* n, node_arbre* &m, int &suma) {
    // Caso base
    if (n == NULL) {
        m = NULL;
        suma = 0;
        return;
    }
    // Caso general
    suma = n->info;
    node_arbre *izq, *der;
    int suma_izq, suma_der;
    arb_sumes_aux(n->segE, izq, suma_izq);
    arb_sumes_aux(n->segD, der, suma_der);

    suma += suma_izq + suma_der;
    m = new node_arbre;
    m->info = suma;
    m->segE = izq;
    m->segD = der;
}