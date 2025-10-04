int leer_exp(const char* expr, int i, char* token);
void imprimir(char*token[1000]);
int leer(char* l,char** token);
void liberar(char* n[]);
int cantidad_de_variables(char** l);
void valores(char**l,int*A);
char** clonar(char** expr);
int evaluar_postfija(char** expr);