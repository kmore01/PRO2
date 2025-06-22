/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
    asub.primer_node = copia_node_arbre(primer_node);
    node_arbre* m;
    int altura;
    sub_arrel_rec(primer_node, m, x, altura);
    asub.primer_node = copia_node_arbre(m);
}

static void sub_arrel_rec(node_arbre* n, node_arbre* &m, const T& x, int &altura) {
    if (n == NULL) {
        altura = 0; // redundante
        m = NULL;
    }
    else if (n->info == x) {
        m = n;
        altura = 0;
    }
    else {
        node_arbre* i;
        node_arbre* d;
        int altura_izq;
        int altura_der;
        sub_arrel_rec(n->segE, i, x, altura_izq);
        sub_arrel_rec(n->segD, d, x, altura_der);

        if (i != NULL and d != NULL) {
            if (altura_izq <= altura_der) {
                m = i;
                altura = altura_izq;
            }
            else {
                m = d; 
                altura = altura_der;
            }
        }
        else if (i != NULL) {
            m = i;
            altura = altura_izq;
        }
        else if (d != NULL) {
            m = d;
            altura = altura_der;
        }
        else {
            m = NULL;
            altura = 0;
        }

        if (m != NULL) ++altura;
    }
}
