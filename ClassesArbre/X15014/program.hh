/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
    int suma;
    node_arbre* res;
    arb_sumes_aux(primer_node, res, suma);
    asum.primer_node = res;
}

static void arb_sumes_aux(node_arbre* n, node_arbre* &res, int &suma) {
    // Caso base
    if (n == NULL) {
        suma = 0;
        res = NULL;
    }
    // Caso general
    else {
        suma = n->info;
        int suma_izq, suma_der;
        node_arbre *izq, *der;
        arb_sumes_aux(n->segE, izq, suma_izq);
        arb_sumes_aux(n->segD, der, suma_der);

        suma += suma_izq + suma_der;
        res = new node_arbre;       
        res->info = suma;
        res->segE = izq;
        res->segD = der;
    }
}