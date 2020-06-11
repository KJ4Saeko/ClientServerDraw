package Server;

import java.awt.Color;
import java.util.Scanner;

/**
 * GroupeDraw est la classe responsable du dessin d'un groupe de formes
 * 
 * @author SEGOUAT Elias - HOUANG Lucas
 */
public class GroupeDraw extends FormeCOR {

	GroupeDraw(FormeCOR obj) {

        super(obj);
    }

    /**
     * Charge la chaine de caractere envoyee par le client
     * Extrait les coordonnées des sommets d'une forme compose et la couleur de celle-ci
     * @param msg 
     *           Chaine de caractere recue par le serveur
     * 
     * @return un boolean qui permet le bon deroulement de la fonction.
     */
    public boolean charger(final String msg) {
        if(msg != null) {
            Scanner scanner1 = new Scanner(msg.substring(msg.indexOf(":") + 1, msg.length()));
            int nbForme = scanner1.nextInt();
            int couleurGroupe = scanner1.nextInt();
            
            Fenetre fen = new Fenetre();
            
            switch(couleurGroupe) {
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
            
            String splitChaine[] = msg.split(",");
            String formes[] = new String[nbForme+2];
       
            
            for(int k = 0; k < splitChaine.length; k++) {
            		formes[k] = splitChaine[k];
            	     System.out.println("Element " + k + formes[k]);
            	
            }
                    
            for(int i = 0; i<= nbForme; i++) {
            	//Pour un polygone
            	if(formes[i].contains("....")) {
            		formes[i] = formes[i].substring(6);
            		Scanner scanner = new Scanner(formes[i]);
            		System.out.println("Element " + i + ' ' + formes[i]);
                    int	nbPoints = scanner.nextInt();
                    int tabX[] = new int[nbPoints];
                    int tabY[] = new int[nbPoints];
                    
                    for(int j = 0; j< nbPoints; j++) {
                    	tabX[j] = scanner.nextInt();
                    	tabY[j] = scanner.nextInt();
                    }
                    fen.graphics.drawPolygon(tabX, tabY, nbPoints);
                    scanner.close();
            	}
            	//Pour un triangle
            	if(formes[i].contains("...")) {
            		formes[i] = formes[i].substring(5);
            		Scanner scanner = new Scanner(formes[i]);
            		System.out.println("Element " + i + ' ' + formes[i]);
            		int		x1 = scanner.nextInt(),
                            y1 = scanner.nextInt(),
                            x2 = scanner.nextInt(),
                            y2 = scanner.nextInt(),
                            x3 = scanner.nextInt(),
                            y3 = scanner.nextInt();

                    fen.graphics.drawLine(x1, y1, x2, y2);    
                    fen.graphics.drawLine(x1, y1, x3, y3);
                    fen.graphics.drawLine(x2, y2, x3, y3);
                    scanner.close();
            	}
            	//Pour un Segment
            	if(formes[i].contains("..")) {
            		formes[i] = formes[i].substring(4);
            		Scanner scanner = new Scanner(formes[i]);
            		System.out.println("Element " + i + ' ' + formes[i]);
                int		x1 = scanner.nextInt(),
                        y1 = scanner.nextInt(),
                        x2 = scanner.nextInt(),
                        y2 = scanner.nextInt();  
                
                	fen.graphics.drawLine(x1, y1, x2, y2);
                	scanner.close();
            	}
            	if(formes[i].contains(".")) {
            		formes[i] = formes[i].substring(3);
            		Scanner scanner = new Scanner(formes[i]);
            		System.out.println("Element " + i + ' ' + formes[i]);
                    int     xCentre = scanner.nextInt(),
                            yCentre = scanner.nextInt(),
                            rayon   = scanner.nextInt();
                    
                    fen.graphics.drawOval(xCentre, yCentre, rayon, rayon);
                    scanner.close();
            	}
            }
                  
            fen.afficher();  
            return true;
        }
            
        return this.suivant(this, msg);
    }
}
