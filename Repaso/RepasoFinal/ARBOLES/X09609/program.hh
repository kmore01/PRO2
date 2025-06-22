 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
    int altura;
    node_arbre* m;
    sub_arrel_aux(primer_node, m, x, altura);
    asub.primer_node = copia_node_arbre(m);
}

static void sub_arrel_aux(node_arbre* n, node_arbre* &m, const T& x, int &altura) {
    // Caso base
    if (n == NULL) {
        m = NULL;
        altura = 0;
        return;
    }
    else if (n->info == x) {
        m = n;
        altura = 0;
        return;
    }
    // Caso general
    int altura_izq, altura_der;
    node_arbre *izq, *der;
    sub_arrel_aux(n->segE, izq, x, altura_izq);
    sub_arrel_aux(n->segD, der, x, altura_der);
    // Caso1 1: Los dos tienen x
    if (izq != NULL and der != NULL) {
        if (altura_izq <= altura_der) {
            m = izq;
            altura = altura_izq;
        }
        else {
            m = der;
            altura = altura_der;
        }
    }
    // Caso 2: Solo la izquierda tiene x
    else if (izq != NULL) {
        m = izq;
        altura = altura_izq;
    }
    // Caso 3: Solo la derecha tiene x
    else if (der != NULL) {
        m = der;
        altura = altura_der;
    }
    // Caso 4: Ninguno tiene x
    else {
        m = NULL;
        altura = 0;
    }

    if (m != NULL) ++altura;
}