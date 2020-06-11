package Server;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferStrategy;

/**
 * Classe permettant de créer une fenetre d'une taille fixe dans 
 * laquelle on dessinera une forme geometrique.
 *  
 * @author SEGOUAT Elias - HOUANG Lucas
 */
public class Fenetre {

    Frame f1AR;
    BufferStrategy strategie;
    Graphics graphics;

    static short numero=0;

    Fenetre() {
        try {
            f1AR = new Frame(" Superbe Frame unique et inégalable n°" + (++numero));

            f1AR.setBounds(30, 60, 1200, 640); 

            f1AR.setVisible(true);             
            f1AR.setIgnoreRepaint(true);        

            f1AR.createBufferStrategy(1);  
            Thread.sleep(150);                       

            strategie = f1AR.getBufferStrategy();
            graphics = strategie.getDrawGraphics();
            
            f1AR.addWindowListener(new WindowAdapter() {
            	@Override
            	public void windowClosing(WindowEvent e) {
            		f1AR.setVisible(false);
            	}
            });
            
        	}

        catch (InterruptedException e) {
            
        }
    }
    
    /**
     * Affiche le contenu du tampon d'une fenetre
     * 
     */
    void afficher() {
        strategie.show();
        strategie.dispose();
    }
}
