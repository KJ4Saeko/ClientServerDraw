package Server;

import java.awt.Color;
import java.util.Scanner;

/**
 * PolygoneDraw est la classe responsable du dessin d'un polygone
 * 
 * @author SEGOUAT Elias - HOUANG Lucas
 */
public class PolygoneDraw extends FormeCOR {

	PolygoneDraw(FormeCOR obj) {

        super(obj);
    }

    /**
     * Charge la chaine de caractere envoyee par le client
     * Extrait les coordonnées des sommets d'un polygone et la couleur de celui-ci
     * @param msg 
     *           Chaine de caractere recue par le serveur
     * 
     * @return un boolean qui permet le bon deroulement de la fonction.
     */
    public boolean charger(final String msg) {
        if (msg.contains("Polygone")) {
            Scanner scanner = new Scanner(msg.substring(msg.indexOf(":") + 1, msg.length()));

            int	nbPoints = scanner.nextInt();
            int tabX[] = new int[nbPoints];
            int tabY[] = new int[nbPoints];
            
            for(int i = 0; i< nbPoints; i++) {
            	tabX[i] = scanner.nextInt();
            	tabY[i] = scanner.nextInt();
            }
            		
            Fenetre fen = new Fenetre();	
            int couleurPolygone = scanner.nextInt();
            switch(couleurPolygone) {
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
            
            fen.graphics.drawPolygon(tabX, tabY, nbPoints);
            fen.afficher();   
            scanner.close();
            return true;
        }

       
        return this.suivant(this, msg);
    }
}
