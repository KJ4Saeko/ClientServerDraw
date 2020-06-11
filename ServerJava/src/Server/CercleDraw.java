package Server;
import java.awt.Color;
import java.util.Scanner;
import java.lang.String;


/**
 * CercleDraw est la classe responsable du dessin d'un cercle
 * 
 * @author SEGOUAT Elias - HOUANG Lucas
 */


public class CercleDraw extends FormeCOR {
	
    CercleDraw(FormeCOR obj) {

        super(obj);
    }

    /**
     * Charge la chaine de caractere envoyee par le client
     * Extrait les coordonnées et la couleur du centre 
     * la taille du rayon et la couleur du cercle
     * @param msg 
     *           Chaine de caractere recue par le serveur
     * 
     * @return un boolean qui permet le bon deroulement de la fonction.
     */
    public boolean charger(final String msg) {
        if (msg.contains("Cercle")) {
            Scanner scanner = new Scanner(msg.substring(msg.indexOf(":")+1, msg.length()));
            
            int     xCentre = scanner.nextInt(),
                    yCentre = scanner.nextInt(),
                    rayon   = scanner.nextInt(),
            		couleurCercle = scanner.nextInt();

            Fenetre fen = new Fenetre();

            switch(couleurCercle) {
            	case 0 : fen.graphics.setColor(Color.black);
            	break;
            	case 1 : fen.graphics.setColor(Color.blue);
            	break;
            	case 2 : fen.graphics.setColor(Color.red);
            	break;
            	case 3 : fen.graphics.setColor(Color.green);
            	break;
            	case 4 : fen.graphics.setColor(Color.yellow);
            	break;
            	case 5 : fen.graphics.setColor(Color.cyan);
            	break;
            	default : fen.graphics.setColor(Color.black);
            	break;	
            }
   
            fen.graphics.drawOval(xCentre, yCentre, rayon, rayon);
            fen.afficher();  
            scanner.close();
            return true;
        }

        
        return this.suivant(this, msg);
    }
}
