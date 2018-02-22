

typedef struct tableau tableau;
struct tableau 
{
int  indice_deb;
int  indice_fin;
int  *val_tableau;
int  *Numero_tab;
int   taille;
};

struct tableau *creationtab ();
void modification_tab (tableau *eng );
void lect_tab (tableau *eng);
