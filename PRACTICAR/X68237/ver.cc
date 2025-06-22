node_arbre* subarrel(const T& x, node_arbre* a, int &cont, bool &found) {
    node_arbre* aux;
    if (a == NULL) {
        cont = 0;
        found = false;
        aux = NULL;
    }
    else if (a->info == x) {
        aux = a; 
        cont = 0
        found = true;
    }
    else {
        int cl;
        bool fl;
        node_arbre* left = subarrel(x, a->segE, cl, fl);

        int cr;
        bool fr;
        node_arbre* right = subarrel(x, a->segD, cr, fr);

        if (fl and fr) {
            if (cl <= cr) {
                aux = left;  
                cont = cl;
                found = fl;    
            }
            else {
                aux = right;
                cont = cr;
                found = fr;
            }
        }
        else if (fl) {
            aux = left;
            cont = cl;
            found = fl;
        }
        else if (fr) {
            aux = right;
            cont = cr;
            found = fr;
        }
        else aux = NULL;

        if (aux != NULL) ++cont
    }
    return aux;
}

 void sub_arrel(Arbre& asub, const T& x) {
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
    int cont;
    bool found;
    node_arbre* aux = subarrel(x, primer_node, cont, found);
    asub.copia_node_arbre(aux);
 }