#include <stdio.h>
#include <stdlib.h> 
#include "projet_finale.h"



 
///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

struct tableau *creationtab ()  // fonction de creation de tableau
{
          int *taballoc = NULL;
         int i=0  ;
         int j=0  ;
          struct tableau tab; // declaration dun enregistrement de type tableau 
          struct tableau *tab_a_retourner; 

                              
                                 
                                  //recuperation des bornes du tableau 
                                   
                                   printf("\n     ---entrer lindice de la premire case---  \n");
                                   scanf("%d",&tab.indice_deb);
                                                                                               
                                   printf("\n      ---entrer lindice de la derniere case---  \n");
                                   scanf("%d",&tab.indice_fin);
             

              if (tab.indice_deb>tab.indice_fin) 
                                      {
                                          printf("la derniere valeur du tableau doit etre plus grande que la premiere \n");
                                          exit ;
                                      } 

     tab.taille=(tab.indice_fin-tab.indice_deb); // je recupere le nombre de case dans le tableau 
        tab.taille++; // pour que la borne soit prise 

        printf("\n ****    la taille du tableau choisie est de --> %d  \n   ",tab.taille);


         if (tab.taille <= 0 ) // je verifie si jai de la place pour continuer ou nn (une dexiemme verification )
                              
                               {
                                printf("//////il nya pas assez de place pour faire un tableau//// \n");
                                 exit(0); // verification si jai bien de la place pour faire un tableau  
                               }

            else 
                               {
                                  taballoc=malloc(tab.taille *sizeof(int)); // lallocation dynamique 
     
                                   if (taballoc ==NULL)
                              {
                                printf("///////lallocation na pas marcher/////// \n"); //verification de lallocation dynamique 
                                 exit(0); 
                               } 
                                }
                 tab.val_tableau =taballoc ;
                 for (i=0;i<tab.taille;i++) 
                {
                  j=i+tab.indice_deb;

                  printf("***   entrer la %d valeur du tableau \n",j );
                  
                scanf("%d",&tab.val_tableau[i]);
                }
///////////////////////////////////////////////////////// affichge du tableau //////////////////////////////
                          printf("                ///////votre tableau contient/////// \n"); 
                                          for (i=0;i<tab.taille;i++) 
                                             {
                                                printf(" %d\t /",tab.val_tableau[i]);

                                             }
                     
       
                     tab_a_retourner=&tab;
                     printf("    \n \n  \n");
                   return tab_a_retourner ;
           
         } 



//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// sous prog de modification dun element du tableau ////////////////////////
         void modification_tab (tableau *eng )

           {
            
           // int numero_tableau ;
            int numero_de_case_changer;
            int  valeur_modif ;

                  do {
                   printf("entrer le numero de la case a modifier   \n");
                            scanf("%d", &numero_de_case_changer );
            } while (numero_de_case_changer < (*eng).indice_deb || numero_de_case_changer > (*eng).indice_fin );
                          
          
          

                               
           printf("  ---la valeur que vous cherchez a modifier est de  %d\n",(*eng).val_tableau[numero_de_case_changer-(*eng).indice_deb ] ); 

          printf("   ---entrez la nouvelle valeur que vous cherchez a mettre dans le tableau \n" );
          scanf("%d", &valeur_modif );
          (*eng).val_tableau[numero_de_case_changer-(*eng).indice_deb ]=valeur_modif ;  // affectation dela nouvelle valeur dans lenregistrement 
        
                       }



//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// sous prog de lecture de tableau ////////////////////////

            void lect_tab (tableau *eng)

              {
                   int i=0;
                 int j; 
                 for (j=0 ;j<(*eng).taille;j++)

                             {
                              i=j+(*eng).indice_deb;
                              printf("la %d valeur du tableau %d \n",i,(*eng).val_tableau[j] );
                            
                             }
              }
////////////////////////////////////////////fin ////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
