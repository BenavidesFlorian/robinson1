#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Clause
{
private:
    int capa;  //taille du tableau tab
    int n;     //nombre de littéraux
    int* tab;  //tableau contenant les littéraux

   /*!
    * Vérifie si un littéral est dans la clause courante.
    * \param lit : littéral à rechercher
    * \return 1 si lit est dans la clause courante, -1 si -lit est dans la
    * clause courante, 0 sinon.
    */
    int isin(int lit);
			
    /*!
    * Agrandit si nécessaire le tableau de stockage de la clause courante.
    * \param newcapa : nouvelle capacité. Si la nouvelle capacité est inférieure
    * à l'ancienne, l'ancienne capacité est conservée et aucune action n'est
    * réalisée.
    * \param dup : si VRAI alors le contenu de l'ancien tableau de stockage est
    * dupliqué dans le nouveau (si applicable), sinon, l'ancien contenu est perdu.
    */
    void agrandir(int newcapa, bool dup);
public:

   /*!
    * Constructeur pa défaut : crée une clause vide da capacité 2.
    */
    Clause();

   /*!
    * Constructeurs pour cas particuliers (clauses unaires, binaire, ternaire)
    * \param w1 : premier littéral
    * \param w2 : second littéral
    * \param w3 : troisième littéral
    */
    Clause(int w1); Clause(int w1, int w2); Clause(int w1, int w2, int w3);

   /*!
    * Destruction complète d'une instance de Clause
    */
    ~Clause();

   /*!
    * Constructeur en copie. Crée une nouvelle clause identique à l'instance de
    * référence.
    * \param model : instance de référence
    */
    Clause(const Clause& model);

   /*!
    * Surcharge de l'opérateur d'affectation. Après exécution, L'instance de
    * destination contient les même littéraux que l'instance source, mais peut avoir
    * une plus grande capacité.
    * \param model : instance source
    * \return une référence à l'instance de destination
    */
    Clause& operator=(const Clause& model);

   /*!
    * Si le littéral lit est déjà dans la clause courante, cette méthode est sans effet.
    * Si la négation de ce littéral est dans la clause courante, un message d'erreur est
    * affiché.
    * Sinon lit est ajouté à la clause courante.
    *\param lit : littéral à ajouter
    */
    void add(int lit);

   /*!
    * Affiche la clause courante sur la sortie standard.
    */
    void affiche();
};

Clause::Clause()
{
    /*01*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=2;
	n=0;
	tab = new int[capa];
	/*02*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
}

Clause::Clause(int w)
{
    /*03*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=1;
	n=1;
	tab = new int[capa];
	/*04*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
	tab[0]=w;
}

Clause::Clause(int w1, int w2)
{
    /*05*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=2;
	n=2;
	tab = new int[capa];
	/*06*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
	tab[0]=w1; tab[1]=w2;
}

Clause::Clause(int w1, int w2, int w3)
{
    /*07*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
	capa=3;
	n=3;
	tab = new int[capa];
	/*08*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
	tab[0]=w1; tab[1]=w2; tab[2]=w3;
}

Clause::~Clause()
{
    /*09*/printf("-tableau<%p>\n",tab);
    delete[] tab;
    /*10*/printf("-Clause<%p>\n",this);
}

Clause::Clause(const Clause& model)
{
	/*11*/printf("+Clause<%p:%d>\n",this,sizeof(Clause));
    capa=model.capa;
    n=model.n;
    tab = new int[capa];
	/*12*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
    for(int i=0; i<n; i++)
        tab[i]=model.tab[i];
}

Clause& Clause::operator=(const Clause& model)
{
    n=model.n;
    agrandir(model.capa,false);
    for(int i=0; i<n; i++)
        tab[i]=model.tab[i];
    return *this;
}

void Clause::agrandir(int newcapa, bool dup)
{
    if(newcapa<=capa) return;
    /*13*/printf("+tableau<%p:%d>\n",tab,capa*sizeof(int));
    int* tmp = new int[newcapa];
    if(dup)
    {
        for(int i=0; i<n; i++)
        {
            tmp[i] = tab[i];
        }
    }
    /*14*/printf("-tableau<%p>\n",tab);
    delete[] tab;
    tab = tmp;
}

int Clause::isin(int lit)
{
    for(int i=0;i<n;i++){
				if(lit==tab[i])return 1;
				else{ if(-lit==tab[i])return -1;
						else return 0;
				}
	 }
}

void Clause::affiche()
{
    cout << "+Clause<" << &this << ":" << capa << ">" << endl;
    cout << "+tableau<" << &this.tab << ":" << capa << ">" << endl;
    cout << "[" << i;
    for(int i=0;i<n;i++){
    	cout << this.tab[i] << "," << endl;
    }
	 cout << "]" << endl;
    cout << "+Clause<" << this << ":" << capa << ">" << endl;
}

void Clause::add(int lit)
{
    /// A compléter
}

int main()
{
    /// A compléter (pour tester vos solutions)
    return 0;
}
