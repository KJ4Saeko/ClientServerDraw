package Server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * Création du thread et du socket : effectue les traitements des requêtes d'un client
 *
 * @author SEGOUAT Elias - HOUANG Lucas
 * */

public class ReceveurEnvoyeur extends Thread  {

    Socket socket;  int noConnexion; 

    BufferedReader fluxEntrant;	PrintStream fluxSortant;

    /**
     * Suppose socket déjà connecté vers le client n° noConnexion
     * @param noConnexion : n° du client
     * @param socket : socket par lequel transite les informations
     * @param groupe : groupe de thread permettant de créer notre Receveur envoyeur
     * */
    public ReceveurEnvoyeur(Socket socket, ThreadGroup groupe, int noConnexion) throws IOException {

        super(groupe,"ReceveurEnvoyeur");
        this.socket = socket;
        this.noConnexion = noConnexion;

        fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
        /* à présent fluxEntrant est prêt pour lire du texte provenant du client */

        fluxSortant = new PrintStream(this.socket.getOutputStream());
        /* à présent fluxSortant est prêt pour renvoyer des réponses textuelles au client */
    }


    /**
     * Fonction qui permet la reception de la reponse par le receveur envoyeur et de formaliser 
     * une chaine de retour, utilise le design pattern chain of responsability
     * */
    public void run() {
   
        String ligne, reponse;
        
        try  {
        		
        	ligne = fluxEntrant.readLine(); // saisit le texte du client
        	
            System.out.println(" Le client n° "+this.noConnexion+" a envoyé : ");
            System.out.println(ligne+"\n"); // écho de la question sur la console


            FormeCOR obj = new CercleDraw(new SegmentDraw(new TriangleDraw
            		(new PolygoneDraw(new TriangleDraw(new SegmentDraw(
            				new PolygoneDraw(new GroupeDraw(null)))))))); 
            
          
            if(obj.charger(ligne)) {
            	reponse = ligne.concat(" a ete cree.\n"); 
            }
            else reponse = "L'objet n'a pas pu etre cree.\n";
            
            fluxSortant.println(reponse); 
        }

        catch(IOException erreur) { System.err.println(" on ne peut pas lire sur le socket provenant du client");}

    }
}
