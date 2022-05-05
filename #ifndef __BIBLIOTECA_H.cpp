#include <iostream>
#include <string>
using namespace std;

struct libro
{
   int isbn;
	string autore;
	string titolo;
	string editore;
	int pagine;
    int prezzo;
};
void scambia(libro &a, libro &b)
{
    libro appo=a;
    a=b;
    b=appo;
}

void caricamento(libro tutto[], int n)
{
   for(int i=0;i<n;i++)
   {
      cout<<"autore:";
      cin>>tutto[i].autore;
      cout<<"titolo:";
      cin>>tutto[i].titolo;
      cout<<"editore:";
      cin>>tutto[i].editore;
      cout<<"pagine:";
      cin>>tutto[i].pagine;
      cout<<"prezzo:";
      cin>>tutto[i].prezzo;
      tutto[i].isbn=n;
      cout<<endl;
   }
}

void ricerca(libro tutto[], int n)
   {
      int codiceisbn;

      cout<<"Inserire codice ISBN: ";
      cin>>codiceisbn;

      for(int i=0; i<n; i++)
         {
            if(codiceisbn==tutto[i].isbn)
               {
                  cout<<"AUTORE:"<<tutto[i].autore<<" "<<"TITOLO:"<<tutto[i].titolo<<" "<<"EDITORE:"<<tutto[i].editore<<" "<<"PAGINE:"<<tutto[i].pagine<<" "<<"PREZZO:"<<tutto[i].prezzo<<endl;
               }
         }
   }  

void ordineautore(libro tutto[],int n)
{

   for(int i=0;i<n-1;i++)
   {
      for (int j=i+1;j<n;j++)
      {
         if (tutto[i].autore>tutto[j].autore)
         {

            scambia(tutto[i],tutto[j]);
         }
      }
   }
}


void ordineprezzo(libro tutto[],int n)
{

   for(int i=0;i<n-1;i++)
   {
      for (int j=i+1;j<n;j++)
      {
         if (tutto[i].prezzo<tutto[j].prezzo)
         {

            scambia(tutto[i],tutto[j]);
         }
      }
   }
}

int main()
{
    int n=3;
    int a;
    libro tutto[3];

    cout<<"INSERISCI AUTORE,TITOLO,EDITORE,PAGINE,PREZZO DI UN LIBRO"<<endl;

    caricamento(tutto,n);


    do
    {
		cout<<"1)VISUALIZZAZIONE DEI LIBRI IN ORDINE DI AUTORE"<<endl;
		cout<<"2)VISUALIZZAZIONE DEI LIBRI IN ORDINE DI PREZZO"<<endl;
        cout<<"3)RICERCA LIBRO TRAMITE CODICE ISBN"<<endl;
		cout<<"4)ESCI"<<endl;
		cin>>a;

		if(a==1)
		{
		 ordineautore(tutto,n);
		  for(int i=0;i<n;i++)
		  {
			cout<<"AUTORE:"<<tutto[i].autore<<" "<<"TITOLO:"<<tutto[i].titolo<<" "<<"EDITORE:"<<tutto[i].editore<<" "<<"PAGINE:"<<tutto[i].pagine<<" "<<"PREZZO:"<<tutto[i].prezzo<<endl;
		  }
		}

		if(a==2)
		{
		  ordineprezzo(tutto,n);
		  for(int i=0;i<n;i++)
		  {
			cout<<"PREZZO:"<<tutto[i].prezzo<<" "<<"TITOLO:"<<tutto[i].titolo<<" "<<"EDITORE:"<<tutto[i].editore<<" "<<"PAGINE:"<<tutto[i].pagine<<" "<<"AUTORE:"<<tutto[i].autore<<endl;
		  }

        }
      
      if(a==3)
      {
         ricerca(tutto, n);
      }


     }while(a!=4);

   cout<<"e' stato un piacere ordinare i libri insieme a te";
    return 0;
}
