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
    // Casos base
    if (n == NULL) {
        altura = 0;
        m = NULL;
    }
    else if (n->info == x) {
        altura = 0;
        m = n;
    }
    // Caso general
    else {
        int altura_izq, altura_der;
        node_arbre *i, *d;
        sub_arrel_aux(n->segE, i, x, altura_izq);
        sub_arrel_aux(n->segD, d, x, altura_der);

        // Caso 1: Los dos tienen x
        if (i != NULL and d != NULL) {
            if (altura_izq <= altura_der) {
                altura = altura_izq;
                m = i;
            }
            else {
                altura = altura_der;
                m = d;
            }
        }
        // Caso 2: x solo aparece en el lado izquierdo del arbol
        else if (i != NULL) {
            altura = altura_izq;
            m = i;
        }
        // Caso 3: x solo aparece en el lado derecho del arbol
        else if (d != NULL) {
            altura = altura_der;
            m = d;
        }
        // Caso 4: x no aparece en el arbol
        else {
            m = NULL;
            altura = 0;
        }
        
        if (m != NULL) ++altura;
    }
}
