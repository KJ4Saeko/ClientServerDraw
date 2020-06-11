package Server;

import java.awt.Color;
import java.util.Scanner;

/**
 * TriangleDraw est la classe responsable du dessin d'un triangle
 * 
 * @author SEGOUAT Elias - HOUANG Lucas
 */
public class TriangleDraw extends FormeCOR {

	TriangleDraw(FormeCOR obj) {

        super(obj);
    }

    /**
     * Charge la chaine de caractere envoyee par le client
     * Extrait les coordonnées des sommets du triangle et la couleur de celui-ci
     * @param msg 
     *           Chaine de caractere recue par le serveur
     * 
     * @return un boolean qui permet le bon deroulement de la fonction.
     */
    public boolean charger(final String msg) {
        if (msg.contains("Triangle")) {
            Scanner scanner = new Scanner(msg.substring(msg.indexOf(":") + 1, msg.length()));

            int		x1 = scanner.nextInt(),
                    y1 = scanner.nextInt(),
                    x2 = scanner.nextInt(),
                    y2 = scanner.nextInt(),
                    x3 = scanner.nextInt(),
                    y3 = scanner.nextInt(),
            		couleurTriangle = scanner.nextInt();
            Fenetre fen = new Fenetre();
            
            switch(couleurTriangle) {
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
            
       
            fen.graphics.drawLine(x1, y1, x2, y2);    
            fen.graphics.drawLine(x1, y1, x3, y3);
            fen.graphics.drawLine(x2, y2, x3, y3);
            fen.afficher();  
            scanner.close();
            return true;
        }

        
        return this.suivant(this, msg);
    }
}
