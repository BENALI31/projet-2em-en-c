#include <stdio.h>
#include <stdlib.h> 
#include "projet_finale.h"

 


int main ( ) {
  struct tableau *tab2[5] ;
  struct tableau  tableau_eng[5] ;

 int i=1;
 int numero_tableau ;
 int numero_de_case_changer;
 int  valeur_modif ;
  
  int menu ;
  

   while  (1) {
 
                 
                             printf("          \n     ******************bonjour******************** \n");
                             printf("choisissez loption que vous desirez en valident le chiffre correspondant \n");
                             printf("******* -1- creation de tableau\n");
                             printf("******* -2- lecture dun tableau\n");
                             printf("******* -3- modification dun element dun tableau \n");
                             printf("******* -4-  sortire\n");  

                             scanf("%d", &menu);
 


                    switch (menu)
                     { 
                         case 1 : printf("********     /vous avez choisi la creation de tableau/   ********\n"); //creation de tableau
                         
                        printf("le tableau numero  %d\n",i);
                       if (i>4)  // la condition qui nous assure le respect du nombre de tableau autoriser 
                                    {
                                      printf("vous avez plus le droit de cree de tableau \n" );
                                      printf("le nombre max autoriser est de 4 tableaux \n" );
                                                   
                                    }
                                 else {
                                    tab2[i] =creationtab ();
                                    tableau_eng[i]=*tab2[i];
                                     i++; 
                                   }        
                       break ;   
                       case 2 : 
                              do {
                              printf("entrer le numero du tableau que vous desirez consulter  \n");
                              
                              scanf("%d", &numero_tableau );

                              }while (numero_tableau<=0||numero_tableau>i) ;

                                                                
                                 lect_tab (&tableau_eng[numero_tableau] );   
                       break ; 



                       case 3 : 
                       do { printf("entrer le numero du tableau que vous desirez modifier  \n");
                              scanf("%d", &numero_tableau );
                             //je verifie si je ne sort pas du nombre max des tableaux (4 au max ) 
                                    }while (numero_tableau>4 || numero_tableau<1);
                           printf("----------le tableau que vous desirez modifier--------  \n");
                           lect_tab (&tableau_eng[numero_tableau] );                                          
                      modification_tab (&tableau_eng[numero_tableau]) ;         // modifier un element du tableau                              
                       printf("---------le tableau apres modification------------  \n");
                       lect_tab (&tableau_eng[numero_tableau] );
                       
                       break ;

                      case 4 :
                           printf("exit .....\n");
                          exit(0);
                       break ;
                       default: 
                       printf("je n'ai pas saisie votre demande\n");
                       printf("je redemarre \n");
                       printf("\n\n\n");
                       main ();
                       break ;    // par default 
                           
                     } 
                         
                 }   
                 
                  return 0;
            }
    
