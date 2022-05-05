#ifndef __BIBLIOTECA_H
#include "Biblioteca.h"


/*! \mainpage <CENTER> L'esercizio più bello del mondo </CENTER>
    * \author <B> Fatone Simone </B>
    * \version <B> V2.0 </B>
    * \date <B> Consegna progetto: 05/05/2022 </B>
    * 
    * \section caratteristiche CARATTERISTICHE DEL PROGETTO
    *
    *  Il software permette di:
    * - Inserire un nuovo libro 
    * - Visualizzare l’intero catalogo della biblioteca
    * - Cancellare un libro
    * - Ricercare un particolare libro
    * - Effettuare delle modifiche
    */

void MessAvv()
{
   cout<<"\n\n ----------------------------------------------------------------------    \r\n";
   cout<<"     |                                                                    |    \r\n";
   cout<<"     | AVVISO :                                                           |    \r\n";
   cout<<"     |                                                                    |    \r\n";
   cout<<"     | Questa biblioteca dovrebbe essere seria.                           |    \r\n";
   cout<<"     | gli impiegati = impieg), per quanto riguarda l'archivio dei libri  |    \r\n";
   cout<<"     | i dati vengono memorizzati su un file calcolato in base al titolo  |    \r\n";
   cout<<"     | del libro.(dunque il file non e' unico come per gli studenti/imp)  |    \r\n";
   cout<<"     ----------------------------------------------------------------------    \r\n";
  
   cout<<"\n\nPremi un tasto per proseguire.";
   getch();
}

char StudMenu() 
{
   char scelta[5];
	clrscr();
   
   cout<<"\n* 1. Inserisci nuovo studente "<<endl;
   cout<<"\n* 2. Visualizza archivio studenti"<<endl;
   cout<<"\n* 3. Ricerca informazioni su uno studente"<<endl;
   cout<<"\n* 4. Modifica informazioni di uno studente"<<endl;
   cout<<"\n* 5  Cancellazione di uno studente "<<endl;
	cout<<"\n* 6. Pulizia del File archivio studenti "<<endl;
   cout<<"\n* p. <-Pagina precedente"<<endl;
  
   cout<<"\n\nScelta..";
   gets(scelta);
   LowChar(scelta); 
   return scelta[0];
}

char ImpMenu() 
{
   char scelta[5];
	
  
   cout<<"\n* 1. Inserisci nuovo impiegato "<<endl;
   cout<<"\n* 2. Visualizza archivio impiegati"<<endl;
   cout<<"\n* 3. Ricerca informazioni su un impiegato"<<endl;
   cout<<"\n* 4. Modifica informazioni di un impiegato"<<endl;
   cout<<"\n* 5  Cancellazione di un impiegato "<<endl;
   cout<<"\n* 6. Pulizia del File archivio impiegati "<<endl;
   cout<<"\n* p. <-Pagina precedente"<<endl;
   Formtext("",'*');
   cout<<"\n\nScelta..";
   gets(scelta);
   LowChar(scelta);
   return scelta[0];
}

char LibMenu()
{
   char scelta[5];
	clrscr();
   Formtext("menu-libri",'*');
	cout<<"\n* 1. Prestito di un libro "<<endl;
	cout<<"\n* 2. Restituzione di un libro "<<endl;
   cout<<"\n* 3. Inserisci nuovo libro "<<endl;
   cout<<"\n* 4. Ricerca veloce per titolo "<<endl;
	cout<<"\n* 5. Ricerca approfondita"<<endl;
   cout<<"\n* 6. Modifica i dati di un libro"<<endl;
   cout<<"\n* 7  Cancellazione di un libro "<<endl;
   cout<<"\n* 8. Visualizza tutti i libri dell'archivio"<<endl;
	cout<<"\n* p. <-Pagina precedente"<<endl;
	Formtext("",'*');
   cout<<"\n\nScelta..";
   
   return scelta[0];
}

char SearchMenu() 
{
   char scelta[5];
	clrscr();
   Formtext("menu per la ricerca approfondita",'*');
   cout<<"\n* 1. Ricerca per TITOLO + ISBN  "<<endl;
   cout<<"\n* 2. Ricerca per TITOLO + AUTORE"<<endl;
   cout<<"\n* 3. Ricerca per TITOLO + CASA EDITRICE "<<endl;
   cout<<"\n* p. <- Pagina precedente"<<endl;
	Formtext("",'*');
   cout<<"\n\nScelta...";
   
   return scelta[0];
}

char MainMenu()
{
   char scelta[5];
	clrscr();
	Formtext("main-menu",'*');
   cout<<"\n* 1. Archivio Studenti "<<endl;
   cout<<"\n* 2. Archivio Impiegati"<<endl;
   cout<<"\n* 3. Archivio Libri "<<endl;
   cout<<"\n* q. Exit"<<endl;
	Formtext("",'*');
   cout<<"\n\nScelta...";
   
   return scelta[0];
}

void Login()
{
  
  Impiegati miofile; 

  int i=1; 
  bool stato=false; 

  while(i<4) 
  {
     clrscr();
	  Formtext("",'*');
     cout<<"\n\nAccesso al programma...  "<<i<<"/3"<<endl<<endl;
     stato=miofile.Login();
	  if(stato==true)
	  {
  		cout<<"\n\nImpiegato connesso... ";
		Formtext("",'*');
      getch();
      i=4;
	  }
     i++;

  }

  if(stato==false) exit(0);

}  

void SceltaStudenti() 
{
	Studenti miofile;  
   bool test=false;   

   do
   {
   	switch(StudMenu())
      {
      	clrscr();
      	case '1': 
	      {
   	   	clrscr();
          	Formtext("inserimento dati studenti",'*');
	         miofile.Inserisci();
   	      cout<<"\n\nInserimento dello studente effettuato con successo";
      	 	
         }break;
         case '2': 
         {
	         clrscr();
          	Formtext("visualizzazione dell'archivio studenti",'*');
      	   miofile.Visualizza();
         	cout<<"\n\nFine dell' archivio studenti";
				Formtext("",'*');
   	      getch();
         }break;
         case '3': 
         {
      	   clrscr();
          	Formtext("Ricerca dati di uno studente",'*');
   	      miofile.Ricerca();
				cout<<"\n\nFine ricerca";
				Formtext("",'*');
      	   getch();
         }break;
         case '4': 
			{
	         clrscr();
          	Formtext("modifica dati di uno studente",'*');
            cout<<endl;
      	   miofile.Modifica();
				cout<<"\n\nFine modifica";
				Formtext("",'*');
   	      getch();
         }break;
         case '5':  
         {
         	clrscr();
          	Formtext("cancellazione di uno studente",'*');
            miofile.Cancella();
				cout<<"\n\nFine cancellazione";
				Formtext("",'*');
            getch();
         }break;
         case '6': 
         {
          	clrscr();
          	Formtext("pulizia dell'archivio studenti",'*');
            miofile.Pulisci();
				cout<<"\n\nFine pulizia archivio";
				Formtext("",'*');
            getch();
         }break;
			case 'p': test=true; break;
			default :
        	{
             cout<<"\nHai premuto un tasto non valido ...";
             getch();
             test=false;
         }
      };
	}while(test==false);
}

void SceltaImpiegati()
{
	Impiegati miofile;
   bool test=false;
 do
 {
   switch(ImpMenu())
   {
   	clrscr();
      case '1': 
      {
      	clrscr();
        	Formtext("inserimento dati impiegati",'*');
         miofile.Inserisci();
         cout<<"\n\nInserimento dell' impiegato effettuato con successo";
			Formtext("",'*');
         getch();
      }break;
      case '2':  
      {
      	clrscr();
			Formtext("visualizzazione dell'archivio impiegati",'*');
         miofile.Visualizza();
         cout<<"\n\nFine dell' archivio impiegati";
			Formtext("",'*');
         getch();
      }break;
      case '3':  
      {
      	clrscr();
       	Formtext("ricerca dati di un impiegato",'*');
         miofile.Ricerca();
         cout<<"\n\nFine ricerca";
			Formtext("",'*');
         getch();
      }break;
      case '4':  
      {
      	clrscr();
       	Formtext("modifica dati di un impiegato",'*');
         miofile.Modifica();
         cout<<"\n\nFine modifica";
			Formtext("",'*');
         getch();
      }break;
      case '5':   
      {
      	clrscr();
        	Formtext("cancellazione di un impiegato",'*');
         miofile.Cancella();
         cout<<"\n\nFine cancellazione";
			Formtext("",'*');
         getch();
      }break;
      case '6':   
      {
      	clrscr();
	     	Formtext("pulizia dell'archivio impiegati",'*');
         miofile.Pulisci();
         cout<<"\n\nFine pulizia archivio";
			Formtext("",'*');
         getch();
      }break;
      case 'p': test=true; break;
      default :
      {
      	cout<<"\nHai premuto un tasto non valido ...";
         getch();
         test=false;
      }
   };
 }while(test==false);
}

void SceltaSearchMenu() 
{
  	bool test;
	do
   {
   test=false;

   Libri Archivio;
   	switch(SearchMenu())
   	{
      	case '1': 
         {
         	clrscr();
	        	Formtext("ricerca dati di un libro",'*');
            Archivio.Carica();
            Archivio.RicercaI();
            cout<<"\n\nFine ricerca";
				Formtext("",'*');
            getch();
         }break;
         case '2': 
         {
         	clrscr();
           	Formtext("ricerca dati di un libro",'*');
            Archivio.Carica();
            Archivio.RicercaNa();
            cout<<"\n\nFine ricerca";
				Formtext("",'*');
            getch();
         }break;
         case '3':  
         {
         	clrscr();
           	Formtext("ricerca dati di un libro",'*');
            Archivio.Carica();
            Archivio.RicercaCe();
            cout<<"\n\nFine ricerca";
				Formtext("",'*');
            getch();
         }break;
         case 'p': test=true; break;
         default :
         {
         	cout<<"\nHai premuto un tasto non valido ...";
            getch();
            test=false;
         }
      };
   }while(test==false);
}

void SceltaLibri()
{
	bool test=false;
   do
   {
   Libri Archivio;
   	switch(LibMenu())
      {
      	clrscr();
         case '1':  
         {
         	clrscr();
     			Formtext("prestito di un libro",'*');
            Archivio.Carica();
            Archivio.Noleggia();
            cout<<"\n\nFine prestito";
				Formtext("",'*');
            getch();
         }break;
         case '2':  
         {
         	clrscr();
     			Formtext("restituzione di un libro",'*');
            Archivio.Carica();
            Archivio.Restituisci();
            cout<<"\n\nFine prestito";
				Formtext("",'*');
            getch();
         }break;
         case '3': 
         {
         	clrscr();
     			Formtext("inserimento dati libri",'*');
            Archivio.Inserisci();
            cout<<"\n\nInserimento del libro effettuato con successo";
				Formtext("",'*');
            getch();
         }break;
         case '4':   
         {
         	clrscr();
     			Formtext("ricerca dati di un libro",'*');
            Archivio.Carica();
            Archivio.RicercaT();
            cout<<"\n\nFine ricerca";
				Formtext("",'*');
            getch();
         }break;
      	case '5':  
         {
         	SceltaSearchMenu();
         }break;
         case '6': 
         {
         	clrscr();
     			Formtext("modifica dati di un libro",'*');
            Archivio.Carica();
            Archivio.Modifica();
            cout<<"\n\n Fine modifica";
				Formtext("",'*');
            getch();
         }break;
         case '7':  
         {
         	clrscr();
     			Formtext("cancellazione di un libro",'*');
            Archivio.Carica();
            Archivio.Cancella();
            cout<<"\n\nFine cancellazione";
				Formtext("",'*');
            getch();
         }break;
         case '8':  
         {
         	clrscr();
				Formtext("visualizzazione dell'intero archivio dei libri",'*');
            cout<<"\n Lettura files in corso...";
            Archivio.Visualizza();
            cout<<"\n\n Fine dell' archivio libri";
				Formtext("",'*');
            getch();
         }break;
         case 'p': test=true; break;
         default :
         {
         	cout<<"\n Hai premuto un tasto non valido ...";
            getch();
            test=false;
         }
      };
   }while(test==false);
}


void main()
{
  MessAvv();
  clrscr();
  Login();
  do{
  		clrscr(); 
      switch(MainMenu())
      {
        case '1':
                 {
                 	SceltaStudenti();
                 }break;
        case '2':
        			  {
                  SceltaImpiegati();
                 } break;

        case '3':
        			 {
                	SceltaLibri();
			       } break;

        case 'q': exit(0);
        default :
        			 {
                 	cout<<"\n Hai premuto un tasto non valido ...";
                  getch();
			       }
      };
    }while(1); 
}
