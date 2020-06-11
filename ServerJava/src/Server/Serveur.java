package Server;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Serveur est la classe permettant de créer la connexion avec le client
 * en fonction d'un port et d'une adresse
 * 
 * @author SEGOUAT Elias - HOUANG Lucas
 */
public class Serveur {

    static final short PORT_SERVEUR = 8000;

    /**
     * Fonction principale du serveur
     */
    public static void main(String[] args)throws Exception {

    	boolean modeServeur = true; //Mode server -- Mode Sauvegarde
    	if(modeServeur == true) {
    		ServerSocket serveur;
            serveur = new ServerSocket(PORT_SERVEUR); // place un serveur à l'écoute sur un port

            System.out.println("serveur démarré : "+serveur);

            InetAddress cetteMachine;
            int portLocal;
            ThreadGroup groupe;

            portLocal = serveur.getLocalPort();

            cetteMachine = InetAddress.getLocalHost();

            System.out.println("adresse IP du serveur : "+cetteMachine.getHostAddress());
            System.out.println("port du serveur : "+portLocal);

            groupe = new ThreadGroup("socketsClients");
            int noConnexion = 0;

            while(true) {

                Socket nouveauClientSocket;
                ReceveurEnvoyeur nouveauClientThread;
                
                nouveauClientSocket = serveur.accept(); // On attend qu'un nouveau client se connecte
                ++noConnexion;
                System.out.println("Connexion reussie n° : "+noConnexion);

                nouveauClientThread = new ReceveurEnvoyeur(nouveauClientSocket, groupe, noConnexion);
                nouveauClientThread.start();
            }
            	
        } else {
        	FormeCOR obj = new CercleDraw(new SegmentDraw(new TriangleDraw
            		(new PolygoneDraw(new CercleDraw(new SegmentDraw(new TriangleDraw(
            				new PolygoneDraw(null))))))));
        	try {
        		InputStream flux=new FileInputStream("../../ClientCpp/ClientCpp/Sauvegarde/sauvegardeForme.txt");
        		InputStreamReader lecture = new InputStreamReader(flux);
        		BufferedReader buff = new BufferedReader(lecture);
        		String ligne, reponse;
        		while((ligne = buff.readLine())!= null) {
        			System.out.println(ligne);
        			if(obj.charger(ligne)) reponse = ligne.concat(" a ete cree.\n");
                    else reponse = "Fin de création des objets\n";
        			System.out.println(reponse);
        		}
        		buff.close();
        	}
        	catch (Exception e) {
        		System.out.println(e.toString());
        	}
        }
    }
}

