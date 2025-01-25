typedef struct fruta Fruta;

typedef struct No No;

No* criaNo(char * nome_da_fruta, float valor_por_kg_da_fruta);

No* inserirNoInicio(No * lista, char * nome_da_fruta, float valor_por_kg);

void exibirListaDeFrutas(No * lista);