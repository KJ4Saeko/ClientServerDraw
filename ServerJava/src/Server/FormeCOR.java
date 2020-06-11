package Server;

import java.awt.*;
import java.util.Scanner;

/**
 * FormeCOR est la classe qui permet la mise en place du design 
 * pattern chain of responsability
 * 
 * @author SEGOUAT Elias - HOUANG Lucas
 */
public abstract class FormeCOR {

    protected FormeCOR chaine;  

    FormeCOR(FormeCOR suivant) {

        chaine = suivant;
    }

    abstract boolean charger(final String msg);

    /**
     * Fonction qui permet de passer d'un maillon a l'autre de la chaine
     * Si le maillon courant n'est pas capable de repondre.
     * @param obj : maillon courant
     * @param msg : message recu du client pour ce maillon
     * */
    boolean suivant(FormeCOR obj, final String msg) {

        if(obj.chaine != null)
            return obj.chaine.charger(msg);
        return false;
    }

}
