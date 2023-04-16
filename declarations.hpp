#ifndef DECLARATIONS
#define DECLARATIONS

#include <vector>

constexpr int MAXL = 256, N = 44;
constexpr unsigned int MAXN = 1000;

class NOD_PRODUS_DEPOZIT
{
public:
    char *ID_Produs;
    char *ID_Depozit;
    double Cantitate_Produs;
    NOD_PRODUS_DEPOZIT *prev_d;
    NOD_PRODUS_DEPOZIT *next_d;

public:
    NOD_PRODUS_DEPOZIT()
    {
        ID_Produs = (char *)malloc(MAXL * sizeof(char) + 1);
        ID_Depozit = (char *)malloc(MAXL * sizeof(char) + 1);
    }

    ~NOD_PRODUS_DEPOZIT()
    {
        free(ID_Produs);
        free(ID_Depozit);
    }
};

class NOD_DETALII_PRODUS
{
public:
    char *ID_Produs;
    char *Denumire_Produs;
    char *Categorie_Produs;
    double pret_produs;
    NOD_DETALII_PRODUS *prev_p;
    NOD_DETALII_PRODUS *next_p;

public:
    NOD_DETALII_PRODUS()
    {
        ID_Produs = (char *)malloc(MAXL * sizeof(char) + 1);
        Denumire_Produs = (char *)malloc(MAXL * sizeof(char) + 1);
        Categorie_Produs = (char *)malloc(MAXL * sizeof(char) + 1);
    }

    ~NOD_DETALII_PRODUS()
    {
        free(ID_Produs);
        free(Denumire_Produs);
        free(Categorie_Produs);
    }
};

class NOD_PRODUS_DEPOZIT_LOCAL
{
public:
    char *ID_Produs;
    char *ID_Oras;
    double cantitate_produs;
    NOD_PRODUS_DEPOZIT_LOCAL *prev_l;
    NOD_PRODUS_DEPOZIT_LOCAL *next_l;

public:
    NOD_PRODUS_DEPOZIT_LOCAL()
    {
        ID_Produs = (char *)malloc(MAXL * sizeof(char) + 1);
        ID_Oras = (char *)malloc(MAXL * sizeof(char)) + 1;
    }

    ~NOD_PRODUS_DEPOZIT_LOCAL()
    {
        free(ID_Produs);
        free(ID_Oras);
    }
};

class NOD_ORASE
{
public:
    char *ID_Oras;
    char *denumire_oras;
    double latitudine;
    double longitudine;
    NOD_ORASE *prev_o;
    NOD_ORASE *next_o;
public:
    NOD_ORASE()
    {
        ID_Oras = (char *)malloc(MAXL * sizeof(char) + 1);
        denumire_oras = (char *)malloc(MAXL * sizeof(char) + 1);
    }
    ~NOD_ORASE()
    {
        free(ID_Oras);
        free(denumire_oras);
    }
};

NOD_PRODUS_DEPOZIT *head_depozit = nullptr, *tail_depozit = nullptr;
NOD_DETALII_PRODUS *head_produs = nullptr, *tail_produs = nullptr;
NOD_PRODUS_DEPOZIT_LOCAL *head_local = nullptr, *tail_local = nullptr;
NOD_ORASE *head_oras = nullptr, *tail_oras = nullptr;

/*
struct oraseRomania
{
    char ID_Oras[100];
    char denumire_oras[100];
    double latitudine;
    double longitudine;
};

oraseRomania orase[44] = {
    {"1", "București", 44.4268, 26.1025},
    {"2", "Cluj-Napoca", 46.7712, 23.6236},
    {"3", "Timișoara", 45.7489, 21.2087},
    {"4", "Iași", 47.1585, 27.6014},
    {"5", "Constanța", 44.1765, 28.65},
    {"6", "Craiova", 44.3302, 23.7949},
    {"7", "Brașov", 45.6556, 25.6108},
    {"8", "Galați", 45.4257, 28.0316},
    {"9", "Ploiești", 44.9469, 26.0364},
    {"10", "Oradea", 47.0722, 21.9217},
    {"11", "Brăila", 45.2692, 27.9572},
    {"12", "Arad", 46.1667, 21.3167},
    {"13", "Pitești", 44.8606, 24.8678},
    {"14", "Sibiu", 45.7971, 24.1526},
    {"15", "Bacău", 46.5759, 26.9135},
    {"16", "Târgu Mureș", 46.5428, 24.5635},
    {"17", "Baia Mare", 47.6572, 23.568},
    {"18", "Buzău", 45.15, 26.8333},
    {"19", "Satu Mare", 47.7916, 22.8858},
    {"20", "Râmnicu Vâlcea", 45.0997, 24.3653},
    {"21", "Drobeta-Turnu Severin", 44.6319, 22.6561},
    {"22", "Suceava", 47.6433, 26.2473},
    {"23", "Piatra Neamț", 46.9296, 26.3692},
    {"24", "Târgoviște", 44.9347, 25.4592},
    {"25", "Focșani", 45.6961, 27.1864},
    {"26", "Tulcea", 45.1667, 28.8},
    {"27", "Reșița", 45.2975, 21.885},
    {"28", "Slatina", 44.4344, 24.3714},
    {"29", "Călărași", 44.2036, 27.3317},
    {"30", "Giurgiu", 43.9031, 25.9699},
    {"31", "Deva", 45.8833, 22.9},
    {"32", "Alba Iulia", 46.0667, 23.5833},
    {"33", "Zalău", 47.1966, 23.0635},
    {"34", "Sfântu Gheorghe", 45.8667, 25.7833},
    {"35", "Bistrița", 47.1367, 24.4962},
    {"36", "Huși", 46.6789, 28.0593},
    {"37", "Vaslui", 46.6333, 27.7333},
    {"38", "Râmnicu Sărat", 45.3833, 26.8167},
    {"39", "Turda", 46.5667, 23.7833},
    {"40", "Medgidia", 44.25, 28.2833},
    {"41", "Miercurea Ciuc", 46.35, 25.8},
    {"42", "Caracal", 44.1167, 24.35},
    {"43", "Sighetu Marmației", 47.9333, 23.8833},
    {"44", "Lupeni", 45.35, 23.25}};
*/

//double **matrice_drum = (double **)malloc(MAXN * sizeof(double *));
std::vector<std::vector<double>> matrice_drum(N, std::vector<double>(N, 0.0));

double distantaCalc(double lat1, double lon1, double lat2, double lon2);

void _init_();

void inserareDateDepozit(char *vID_Produs, char *vID_Depozit, double vCantitate_Produs);

void inserareDateProduse(char *vID_Produs, char *vDenumire_Produs, char *vCategorie_Produs, double vPret_Produs);

void inserareDateProduseLocal(char *vID_Oras, char *vID_Produs, double vCantitate_Produs_Local);

void insearareDateOrase(char *vID_Oras, char *vDenumire_Oras, double vLatitudine, double vLongitudine);

void afisareDateLocal();

void afisareDateDepozit();

void afisareDateProdus();

void statisticaStoc();

int distantaMinima(std::vector<double> distanta, std::vector<bool> vizitat);

void afisareSolutieDistanta(std::vector<double> distanta);

void dijkstra(int sursa);

void determinareStartAprovizionare();

#endif