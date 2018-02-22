#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>

typedef struct tableau tableau;
struct tableau 
{
int  indice_deb;
int  indice_fin;
int  *val_tableau;
int  *Numero_tab;
int   taille;
};
 

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
                                printf("///////lallocation na pas marcher bayy/////// \n"); //verification de lallocation dynamique 
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
                          printf("                ///////votre tableau contien/////// \n"); 
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
                          
          
          

                               
           printf("  ---la valeur que vous chercher a modifier est de  %d\n",(*eng).val_tableau[numero_de_case_changer-(*eng).indice_deb ] ); 

          printf("   ---entrez la nouvelle valeur que vous chercher a mettre dans le tableaux \n" );
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
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////


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
                         case 1 : printf("********     /vous avez choisie la creation de tableau/   ********\n"); //creation de tableau
                         
                        printf("le tableau numero  %d\n",i);
                       if (i>4)  // la condition qui nous assure le respect du nombre de tableau autoriser 
                                    {
                                      printf("vous avez plus le drois de cree de tableau \n" );
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
                       printf("---------le tableau apret modification------------  \n");
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
    