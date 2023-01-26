#include "Library.h"
#include <iostream>
using namespace std;
#include "book.h"
#include "Author.h"
#include "date.h"
int main(int argc, char const *argv[]) {
 
        Library  b;
        b.addLivre ("Les miserables","HUGO","Victor","7683650978129","Francais","Tragedie",Date (4,3,1970),"82555587759",Date (1,1,1),{""});
        b.addLivre("La force de vivre","HUGO","Victor","7683650978129","Francais","Philo",Date (4,3,1970),"53321478366",Date (1,1,1),{""});
        b.addLivre("Benediction","Charles","Baudelaire","7683650978129","Francais","Comedie",Date (4,3,1970),"5423898764",Date (1,1,1),{""});
        b.addLivre("Le zahir","Paulo","Coelho","7683650978129","Francais","Tragique",Date (4,3,1970),"7413658995",Date (1,1,1),{""});
        b.addLivre("La boite a merveilles","Ahmed","sefroui","7683650978129","Francais","Histoire",Date (4,3,1970),"8541366478",Date (1,1,1),{""});
        b.addLivre("Les contemplations","HUGO","Victor","003","Francais","Histoire",Date (4,3,1970),"0059753008",Date (1,1,1),{""});
        b.addLivre("Les travailleurs de la mer","HUGO","Victor","003","Francais","Histoire",Date (4,3,1970),"0065429086",Date (1,1,1),{""});
        
         b.addLecteur("prince","prince","1",{""});
         b.addLecteur("Labnihi","elmehdi","2",{""});
         b.addLecteur("salma", "souiba","3",{""});
        
        b.addAuteur("001","BILIK","Jen",Date (1,1,2));
        b.addAuteur("002","REUZE","Emmanuel",Date (1,1,2));
        b.addAuteur("003","HUGO","Victor",Date (1,1,2));
        
         b.afficherLecteurs();
         b.afficherLivres();
        
         b.afficherAuteur();
         //b.afficherLivresLecteur("Le zahir","1");

         return 0;

}


        //b.EmprunterLivre("ti","idlecteur");
        //b.afficherLivresLecteur("12345678910","idLecteur");
         //b.restituerlivre("idLecteur","1234567891");
         //b.pourcentageEmprunt();
         //b.afficherLivresAuteur();
        //b.afficherLivres();
        /*Date a_day(7,31,2022);
 a_day.updateYear(-2000);
  std::cout << "a year: " << a_day.year() << std::endl;
  std::cout << "a day: " << toString(a_day) << std::endl;
  std::cout << "#day: " << dayOfYear(a_day) << std::endl;
  a_day.next();

  std::cout << "a day + 1: " << toString(a_day) << std::endl;
  std::cout << "#day: " << dayOfYear(a_day) << std::endl;*/

 //Book my_book("title","nom","prenom","12345","langue","type",Date (12,3,2018),"12345678910",Date (1,1,1),{"sjsjk"});
    //cout<<my_book.getLecteur();
  /*Emprunt mehdi("1234567891");
     mehdi.emprunter("123456",Date (12,3,2018));
     cout<<mehdi.getstatus()<<endl;
     cout<<mehdi.getidLecteur()<<endl;
     mehdi.rendre();
     cout<<mehdi.getstatus()<<endl;
     cout<<mehdi.getidLecteur();*/
   
    


