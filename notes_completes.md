# NOTES COMPLÈTES C++

## 1. Notes Générales

CPP :

Compilation :
flags : -Wall -Wextra -Werror
flag : -std=c++98

Format des classe :
UpperCamelCase -> "BrickWall" = BrickWall.hpp

Les interdits :
Les mots-clés using namespace <ns_name> et friend sont interdits
Droit à la STL que dans les Modules 08 et 09
l’usage des Containers (vector/list/map/etc.) et des Algorithmes (tout ce qui requiert d’inclure <algorithm>) est interdit.

libraries :
#include <iostream>
#include <cstdlib> -> pour utiliser : system("clear") : permet d avoir un interface propre

--------------------------------------------------------------------------------------------------------------------------------------

LES BASES :

#include <iostream>

int	main(void)
{
	char	buff[512];

	std::cout << "hello" << std::endl;
	std::cout << "hello : ";
	std::cin >> buff;
	std::cout << "ton entree est : ["<< buff <<"]" << std::endl;
	return (0);
}

- dans la sortie standard, j'injecte hello, puis retour a la ligne
- pas de retour a la ligne
- recuperer une donnee depuis l entree standard, rediriger dans une variable = scanf -> permet d ecrire dans la console
- redirige dans la sortie standard, recupere le buff ecrit dans la console

sortie :
- hello est afficher
- on ecrit world
- la sortie dans le terminal sera -> ton entree est : [world]

--------------------------------------------------------------------------------------------------------------------------------------

CLASS & INSTANCE :

Declarer une class :

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class	Sample {//declaration d une class

public:

	Sample(void);	->	constructeur, lorsque que la class est instancier
	~Sample(void);	->	destructeur, lorsque que la class va etre detruite

};	->	important a terminer avec ;

#endif

-------------------------

Implementation de la class :

#include <iostream>
#include "SampleClass.hpp"

Sample::Sample(void)	->	dans la class Sample, acceder a la fonction Sample
{
	std::cout << "constructeur appeler" << std::endl;
	return;				->	le destructeur et le constructeur n'ont pas de type de retour
}

Sample::~Sample(void)
{
	std::cout << "destrcuteur appeler" << std::endl;
	return;
}

#include "SampleClass.hpp"

int	main(void)
{
	Sample	instance;
	return 0;
}

- variable instance de type Sample
- avec cette ligne le code du constructeur est executer
- une fois le arriver a return, le destructeur est execute

sortie :
constructeur appeler
destructeur appeler

--------------------------------------------------------------------------------------------------------------------------------------

ATTRIBUT MEMBRE & FONCTION MEMBRE :

variable dans la class et utiliser avec une instance afin que le class soit utile

class	Sample
{
public:

	int		foo;		->	c est un attribut, variable ici de type int

	Sample(void);
	~Sample(void);

	void	bar(void);	->	declarer une fonction membre
};

void	Sample::bar(void)
{
	std::cout << "membre fonction appeler" << std::endl;
	return;
}

int	main()
{
	Sample	instance;
	instance.foo = 42;
	std::cout << "instance =" << instance.foo << std::endl;
	instance.bar();
	return 0;
}

- la valeur 42 est assigner a la valeur foo
- permet d appeler la fonction membre bar, utiliser une fois instancier notre class

sortie :
constructeur appeler
instance =42
membre fonction appeler
destructeur appeler

--------------------------------------------------------------------------------------------------------------------------------------

THIS :

This est un pointeur donc utiliser '->'

Sample::Sample(void)
{
	std::cout << "constructeur appeler" << std::endl;

	this->foo = 42;	->	pointeur qui pointe sur l instance courante
	std::cout << "this foo = " << this->foo << std::endl;

	this->bar();	->	permet d appeler la fonction bar dans le hpp

	return;
}

int	main()
{
	Sample	instance;

	return 0;
}

sortie :
constructeur appeler
this foo = 42
membre fonction appeler
destrcuteur appeler

--------------------------------------------------------------------------------------------------------------------------------------

INITIALIZATION LIST :

class	Sample
{
public:

	char	a1;							->	initaliser les variable
	int		a2;
	float	a3;

	Sample(char p1, int p2, float p3);	->	la class prend des parametre
	~Sample(void);
};

Initialiser les 3 parametres en list :

Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)	->	syntaxe optimal, assigne l attribut a1 a la valeur p1
{
	std::cout << "constructeur appeler" << std::endl;

	std::cout << "a1 = " << this->a1 << std::endl;
	std::cout << "a2 = " << this->a2 << std::endl;
	std::cout << "a3 = " << this->a3 << std::endl;

	return;
}

int	main()
{
	Sample	instance('a', 42, 54.7);
	return 0;
}

--------------------------------------------------------------------------------------------------------------------------------------

CONST :

class	Sample
{
public:

	float const	pi;
	int			qd;

	Sample(float const f);
	~Sample(void);

	void	bar(void)const;
};

void	Sample::bar(void)const{
	std::cout << "pi = " << this->pi << std::endl;
	std::cout << "qd = " << this->qd << std::endl;

	this->qd = 0;	->	pas possible car const empeche la modification de la fonction membre

	return;
}

- const signifie que la fonction membre ne modifira jamais l instance courrant
- mettre const que si l on ne modifira plus la fonction membre

--------------------------------------------------------------------------------------------------------------------------------------

VISIBILITY :

class	Sample
{
public:

	int	public_foo;

	Sample(void);
	~Sample(void);

	void	public_bar(void)const;

private:

	int	_private_foo;

	void	_private_bar(void)const;
};

#endif

Sample::Sample(void)
{
	std::cout << "constructeur appeler" << std::endl;
	this->public_foo = 0;
	std::cout << "public = " << this->public_foo << std::endl;
	this->_private_foo = 0;
	std::cout << "private = " << this->_private_foo << std::endl;

	this->public_bar();
	this->_private_bar();

	return;
}

int	main()
{
	Sample	instance;

	instance.public_foo = 42;
	std::cout << "public = " << instance.public_foo << std::endl;

	instance.public_bar();

	return 0;
}

- public : possible d acceder depuis l interieur et exterieur de la class
- private : possible d acceder depuis l interieur de la class
- permet d avoir le choix de laisser des choses a l utilisateur et de garder certaine chose prive
- public et prive peuvent etre utiliser dans les fichiers autre que main
- ici public_foo peut etre modifier car public mais pas _private_foo qui lui est prive

--------------------------------------------------------------------------------------------------------------------------------------

CLASS VS STRUCT :

struct	Sample
{

	int	public_foo;

	Sample(void);
	~Sample(void);

	void	public_bar(void)const;
};

- meme structure qu une class
- une struct a part defaut un scope public tandis qu une class par defaut a un scope prive

--------------------------------------------------------------------------------------------------------------------------------------

ACCESSORS C++ :

class	Sample
{
public:

	Sample(void);
	~Sample(void);

	int		getFoo(void)const;
	void	setFoo(int v);

private:

	int	_foo;
};

#endif
- get -> recuprer la valeur d un attribut
- set -> setet un attribut
- get ou set suvie de l accesseur

int	Sample::getFoo(void)const
{
	return this->_foo;	->	renvoie une copie de l attribut _foo, l utilisateur peut modifier cette valeur
}

- va permettre a l utilisateur de modifier la variable avec ici une conditon si negatif erreur
void	Sample::setFoo(int v)
{
	if (v >= 0)
		this->_foo = v;
	return;
}

int	main()
{
	Sample	instance;

	instance.setFoo(42);//modifie la valeur
	std::cout << instance.getFoo() << std::endl;//recupere la valeur
	instance.setFoo(-42);
	std::cout << instance.getFoo() << std::endl;

	pour get

	Sample.getFoo()
	return 0;
}

--------------------------------------------------------------------------------------------------------------------------------------


## 2. Notes Projet Zombie

ZOMBIE :
- Le terme « Zombie » est choisi pour illustrer l’allocation et la durée de vie des objets

- En C++, la majorité des objets sont allocés sur la pile (stack) par défaut, et seulement lorsque la durée de vie ou la taille ne peut pas être déterminée à la compilation, on recourt au tas (heap) via new

- Implémenter deux modes d’allocation pour un même type d’objet (Zombie) et à visualiser leur cycle de vie
- Les objets « sur la pile » (déclarés localement) sont détruits automatiquement à la sortie de leur portée
- Les objets « sur le tas » (alloués via new) persistent jusqu’à appel explicite de delete

- Statique (pile) : rapide, gestion automatique, mais portée limitée
- Dynamique (tas) : flexible, portée plus longue, nécessite gestion explicite (risque de fuite mémoire)
- Destructeur pour le debug : afficher le nom au moment de la destruction permet de vérifier qu’on n’a pas de fuite ni de destruction multiple

new : (agit comme malloc pour le c)
- But : allouer dynamiquement de la mémoire sur le tas (heap) pour un objet ou un tableau d’objets

- Recherche un bloc de mémoire libre d’une taille suffisante dans le tas
- Si trouvé, réserve ce bloc et renvoie un pointeur vers le début de ce bloc, typé vers le type demandé
- Construit (appel du constructeur) l’objet à cet emplacement mémoire
- Quand la durée de vie de l’objet doit dépasser la portée d’une fonction (par exemple,
  persister jusqu’à la fin du programme ou jusqu’à un appel explicite à delete)

delete :
- But : libérer la mémoire précédemment allouée par new
- Appelle le destructeur de l’objet situé à l’adresse pointée
- delete ptr : pour un objet unique
- delete[] ptr : pour un tableau d’objets (les deux ne sont pas interchangeables)
- utiliser : dès que l’objet n’est plus nécessaire, pour éviter les fuites mémoire et limiter la fragmentation du tas
- chaque new doit avoir son delete
- chaque new[] doit avoir son delete[]

Allouer un zombie :
- Zombie *z = new Zombie("Alice");
- Alloue un bloc de mémoire de la taille nécessaire pour un objet Zombie sur le tas

Utilisation de z
- z->announce();

Libération de la mémoire
- delete z;

Pour la pile :
- la variable local ne sera pas un pointeur
- on peut l'implementer depuis la fonction membre variable.fonctionMembre

Allouer des tableaux zombie
- Zombie* horde = new Zombie[N];
- delete[];

- on alloue sur l'objet Zombie le "N" qui signifie le nombre d'entree dans le tableau
- horde sera utiliser pour parcourir le tableau -> horde[i]

- recuperation et affichage :
for (int i = 0; i < N; i++){
		horde[i].setN
		->	permet de set les informations (stocker la saisie)
		horde[i].announce();	->	utilise la fonction membre
	}

--------------------------------------------------------------------------------------------------------------------------------------

## 3. Notes Projet PhoneBook

NOTE PHONEBOOK :

LIBRARY :
<iomanip>
- Un header qui fournit des « manipulateurs » de flux (std::cout, std::cin, etc.).
- Permet de contrôler l’affichage (largeur de champ, alignement, précision, etc.) sans modifier la valeur des données.

Principaux manipulateurs  :
- std::setw(n)	Définit la largeur minimale du champ à n
- std::setfill(c)	Caractère de remplissage si la largeur est trop grande
- std::left / std::right	Alignement à gauche ou à droite
- std::setprecision(p)	Nombre de chiffres significatifs (pour flottants)
- std::fixed / std::scientific	Mode d’affichage des flottants

===================================================================================================

LES FT UTILES :

- getline
stocke dans une chaîne de caractères (std::string ou un tableau de char, selon la version utilisée)
int main() {
	std::string ligne;
	std::cout << "Entrez une ligne de texte : ";
	std::getline(std::cin, ligne);
	std::cout << "Vous avez entré : " << ligne << std::endl;
	return 0;
}

- std::cin	->	agit comme un scanf

- std::setw : dans <iomanip>
utilise std::setw pour chaque champ de largeur fixe.
Ajuste std::left ou std::right selon que tu veuilles l’alignement à gauche ou à droit
<< std::left << std::setw(10) << ton instance
<< std::right << std::setw(10) << ton instance

- substr :
Plutôt que de jouer sur des boucles ou des accès caractère par caractère,
substr(0, 9) vous donne directement la portion que vous voulez extraire.

===================================================================================================

CLASS CONTACT:

void setFirstName(const std::string& firstName);
- set permet de stocker l information, la saisie

const std::string& firstName
- const std::string = const str
- le & permet d eviter des stockage temp inutile

const std::string&	getFirstName()const;
- get va recuperer l'information, la saisie
- const signifie que le fichier sera lu en mode lecture et ne pourra pas etre modifier

std::string :
- Une classe de la lib standard (<string>) qui encapsule une suite de caractères de longueur dynamique
- std::string gère automatiquement la mémoire
- pas besoin d'allouer ni libérer manuellement un buffer (pas de new[]/delete[])
- La taille s’adapte : peux stocker aussi bien "Al" que "Alexandre" ou même une phrase plus longue
- pas beosin de gerer la taille
- gère automatiquement l’allocation et la libération mémoire, évitant les fuites

Caractéristiques principales :
- size()/length()	Nombre de caractères
- empty()	Teste si la chaîne est vide
- operator[]/at()	Accès direct à un caractère (avec vérification via at)
- append(), +	Concaténation
- substr(pos, len)	Extraction d’une sous-chaîne
- find(str)	Recherche d’une sous-chaîne
- compare()	Comparaison lexicographique
- c_str()	Conversion en C-string (const char*)

Private :
- En le déclarant private, tu empêches tout accès direct depuis l’extérieur
- seuls les getters et setters que tu exposes en public pourront lire ou modifier cette valeur
- Cela te permet de contrôler la validité (ex. refuser une chaîne vide)
- ou de déclencher d’autres actions lors du changement

===================================================================================================

CLASS PHONEBOOK:

void add_contact();		->	Ajoute un contact, écrase le plus ancien si le tableau est plein
void search_contact();	-> pour rechercher un contact et l'afficher
- ce sont les fonction auquelle l'utilisateur aura le droit

Private :
Contact array[8];	->	tableau pour 8 contacts
int _nextIndex;		->	où ajouter le prochain contact (0..7)
int _count;			->	nb de contacts actuellement (<=8)

===================================================================================================

IMPLEMENTATION DE LA CLASS CONTACT :

void	Contact::setFirstName(const std::string& firstName)
{
	this->_firstName = firstName;
}
- Ces méthodes servent uniquement à modifier l’attribut interne, pas à retourner une valeur
- this->... = .....
- Ajouter une valeur (setFirstName("Alice"))
- Action : tu appelles le setter depuis ton code (par exemple dans main.cpp).
- Effet : la méthode copie la chaîne "Alice" dans l’attribut privé _firstName de l’objet.

const std::string&	Contact::getFirstName()const
{
	return this->_firstName;
}
- Paramètres const std::string& : performance, pas de copies inutiles.
- std::string signifie que la fonction rend une copie de la chaîne stockée dans l’objet.
- return copie = return this->....
- Applicables uniquement aux getters :
- const : Si tu tentes d’écrire dans un attribut privé à l’intérieur de getName(), pas de compilation
- set va stocker la saisie et get l afficher

===================================================================================================

IMPLEMENTATION DE LA CLASS PHONEBOOK :

PhoneBook::PhoneBook() : _nextIndex(0), _count(0){
}
- permet d'inititer les valeur a 0 lors de la construction, el list

BUT DE PHONEBOOK.CPP
- implementer les ft add_contact et search_contact
- lire les saisie de l'utilisateur et les enregistrer dans set(ce sera dans add_contact)
- afficher les saisie de l'utilisateur avec get(ce sera dans search_contact)

add_contact :
- declare des variable locale
- le do while permet de reposer la question en cas d'erreur
- une fois, le contact on copie la valeur a l'attibut prive (il ne pourra pas etre modifier)

- this->_array = instance sur laquelle on veut travailler
- [this->_nextIndex] = utilises ton indice current_nb (de 0 à 7) pour sélectionner la bonne case du tableau
- .setFirstName(firstName); = setter copie alors la valeur dans l’attribut privé _lastName de ce contact

search_contact :
- afficher le tableau des contact en utilisant les get

- std::cout << std::right << std::setw(10) << "index";
permet d'afficher le text a droite dans une colonne de 10 caractere, setw utiliser dans iomanip

if (first.size() > 10)
	first = first.substr(0,9) + ".";
permet de controler si notre entree a plus de 10 caractere si c est le cas on tronque avec un .
grace a substr

===================================================================================================

MAIN :

if (!line.compare(add))
- permet de comparer l entree utilisateur avec notre demande

if (std::cin.eof())
- Après une opération de lecture qui tombe sur la fin du fichier (ou sur Ctrl-D / Ctrl-Z en terminal), 
  le drapeau EOF est levé et std::cin.eof() renvoie true.

- sert à détecter cette situation pour, par exemple, quitter proprement ton programme
  ou arrêter une boucle de lecture.

--------------------------------------------------------------------------------------------------------------------------------------

## 4. Les pointeurs

std::string	str = "HI THIS IS BRAIN"
- declarer la variable

std::string	*stringPTR = &str
- comme en c, c'est un pointeur vers la variable str

std::string	&stringREF = str
- référence à la variable string
- Elle agit comme un alias, un autre nom pour la même variable
- stringREF est exactement la même chose que string, juste un autre nom pour y accéder

- std::string	str = "HI THIS IS BRAIN";	->	a une adresse memoire
- std::string	*stringPTR = &str			->	&str récupère l’adresse mémoire de la variable str
- std::string	&stringREF = str			->	&stringREF devient une référence à str (même adresse, même contenu)

--------------------------------------------------------------------------------------------------------------------------------------

## 5. Weapon

- REF : ne peut pas etre null donc a utiliser sur HumanA qui est de toute facon armee
- PTR : peut etre null donc a utiliser sur HumanB qui peut ne pas etre armee au debut

Class HumanA :

HumanA(std::string name, Weapon &Weapon);
- Recevoir une référence à l’arme (pas une copie)
- L’enregistrer comme référence (puisque HumanA est toujours armé)
- Cela permet que si le type de l’arme change en dehors de HumanA, il voie ce changement automatiquement

- Voir le type de l’arme (affichage)	getType()
- Modifier le type de l’arme	setType("nouveau nom")
- Tu set pour changer (modifier une information)
- Tu get pour afficher (lire une information)

constructeur avec parametre :
- Weapon::Weapon(const std::string& type)
- Il permet de gagner du temps et de la clarté : tu crées directement une arme avec un type
- dans main	->	Weapon club("crude spiked club");

exemple :
- Tu crées une arme avec le type "club".
- Bob a cette arme
- Tu fais bob.attack() → il affiche "club" (grâce à getType())
- Tu fais setType("épée") sur la même arme
- Tu refais bob.attack() → il affiche "épée"

Weapon club	-> weapon de type variable club appeler ("sdsdfs")

--------------------------------------------------------------------------------------------------------------------------------------

## 6. filestreams

#include <fstream>
- utiliser std::ifstream	->	input file stream, pour les fichiers / par defaut fais le test ::in
- utiliser std::ofstream	->	output file stream / par defaut fais le test ::out et ::trunc
- std::ios::in				->	open for reading
- std::ios::out				->	open for writing
- std::ios::trunc			->	discard the contents of the stream when opening

#include <cstring>
- c_str permet de cast en const char et obtenir l'acces
- equivalent a ofs.open(outName.c_str(), std::ios::out | std::ios::trunc);

Exemple input:
- std::ifstream	ifs("numbers");	->	un ifstream qui s appelle ifs qui prend en parametre numbers,
  ca ouvre le fichier numbers, dans lequelle on va pouvoir lire des chose
- int	dst;	-> les deux entier qu on va lire dans le fichier
- int	dst2;
- ifs >> dst >> dst;	-> permet de lire une entree comme cin
- std::cout << dst << " " << dst2 << std::endl;	-> on affiche le contenu des variable
- ifs.close();	-> on ferme le fichier ifs

Exemple output :
std::ofstream	ofs("test.out");
ofs << "oktestout" << std::endl;	->	creer le fichier test.cout
ofs.close();

open :
- utiliser open pour ouvrir le fichier
- ifs.open(argv[1]);
- si utilise std::ifstream ifs(argv[1]);	->	ouverture via constructeur donc pas besoin de open

is_open :
- permet de verifier si le fichier existe
- exemple ifs.is_open(); ou if (!ifs) suffit

Exemple :
if (!ifs){
	std::cout << "Error, permission, inexistant" << std::endl;
		return 1;
}

std::string outName = argv[1]		->	range dans un string argv[1], filename car apprend prend une string
outName.append(".replace");			->	on concatene a filename le .replace
std::ofstream ofs(outName.c_str())	->	c_str permet de renvoyer un pointeur const char* vers une représentation en C-string (terminée par '\0') de la  chaîne.
									->equivalent a ofs.open(outName.c_str(), std::ios::out | std::ios::trunc);

BOUCLE ALGO :

while(std::getline(ifs, line))
- std::getline lit jusqu’au prochain retour à la ligne (ou jusqu’à EOF), remplit line sans inclure le '\n', et retourne true tant qu’il reste des lignes valides à lire

std::string	result;
- string ou l'on va copier le texte

size_t	start = 0;
- position de depart de la recherche / debut du fichier

size_t	pos = line.find(s1, start);
- exemple : make clean all
- start commence a m qui est 0
- si s1 est trouvee, pos recoit le resultat par ex pos = 5 qui est 'c' de clean

while(pos != std::string::npos)
- tant qu il y a des occurence

std::string::npos
- valeur renvoyée par find quand il ne trouve plus l’occurrence recherchée. 
- C’est la manière canonique et la plus lisible en C++ pour détecter la fin de tes recherches
if (pos == std::string::npos) {
    // plus aucune occurrence
}

result += line.substr(start, pos - start);
- en premier on extrait les choses qui precedent l'occurence
- dans l exemple make clean all, on extrait make qu on range dans result, result etant vide au debut
- donc la result = make

result += s2;
- on ajoute la s2 (chaine de remplacement) au result

start = pos + s1.length();
- repositionne start au bon endroit
- dans l'exemple make clean all, start sera placer apres clean
- pos = 5, length = 5, donc position de start = 10 depuis le debut du texte

pos = line.find(s1, start);
- on place pos a la prochaine occurence si y en a une et on recommence jusqu a plus aucune occurence

result += line.substr(start);
- permet d'extraire le reste du texte

ofs << result << std::endl;
- ecrit la chaîne result dans le fichier (tout le texte que tu as construit pour cette ligne)
- mettre std::endl car getline supprime le '\n'

--------------------------------------------------------------------------------------------------------------------------------------

## 7. Les pointeurs sur fonction membre

void Harl::complain(std::string level)
- fonction membre

std::string arrayLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
- déclare un tableau de 4 objets std::string

void (Harl::*arrayPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
- déclare et initialise un tableau de pointeurs vers les méthodes membres de Harl

if (arrayLevel[i] == level)
(this->*arrayPtr[i])();
- si la correspondance est juste on enregistre avec le pointeur l'adresse du message

--------------------------------------------------------------------------------------------------------------------------------------

## 8. switch case :

if (arrayLevel[i] == level)
break;
- dès le bon niveau trouver, sort immédiatement de la boucle et i conserve la valeur de l’indice correspondant.

- toujours finir par un default

--------------------------------------------------------------------------------------------------------------------------------------

## 9. Ad-hoc Polymorphisme :

class	Sample
{
	public
		Sample();
		~Sample();
	
	void bar(char const c)const;
	void bar(int const n)const;
	void bar(float const z)const;
	void bar(Sample const & i)const;
};

- 4 surcharges de la fonction membre bar
- Meme nom de fonction mais avec des parametres differents
- Permet d'utiliser seulement la fonction bar afin d'afficher les parametres differents

--------------------------------------------------------------------------------------------------------------------------------------

## 10. Operator overload  :

std::ostream : 
- met à disposition tous les operator<< nécessaires
- Signature générique = std::ostream& operator<<(std::ostream& os, const T& value);
- permet de chainer les arguments
- Retourner le même flux par référence pour optimiser (pas de copie) et permettre le chaînage fluide d’opérations d’insertion.


Operation arythmetique :

1 + 1 = operateur infixe
+ 1 1 = operateur prefixe
1 1 + = operateur postfixe

Notation fonctionnelle :
+(1, 1)= operateur prefixe	->	permet de comprendre la surcharge en c++
- simple fonction qui prend deux parametre

1.+(1)
- une instance appeler 1
- qui appelle la fonction membre +
- a laquelle on passe en parametre 1

class	Integer
{
	public
		Integer(int const n);	->	construite a partir d un entier n
		~Integer(void);//

		int getValue(void)const;	->	getter pour recuperer la valeur

		Integer& operator=(Integer const& rhs);	->	operateur d assignation
		Integer operator+(Integer const& rhs)const;	->	operator d addition

	private:
		int _n;
};

std::ostream& operator<<(std::ostream& other, Integer const& rhs);
- But : définir comment un objet rhs est affiché dans un flux de sortie (std::cout, fichier, etc.).

#endif

Integer& operator=(Integer const& rhs);
- this est le parametre cacher au debut des parametre a gauche
- rhs = right sera la sortie a droite
- on recupere la valeur avec get = this->_n = rhs.getValue();
- return *this pour recupere l adresse de Integer

Integer operator+(Integer const& rhs)const;
return Integer(this->_n + rhs.getValue());
- permet d additionner la valeur modifier + la valeur recupere par get
- on renvoie une copie de la class integer

std::ostream& operator<<(std::ostream& os, Fixed const& other) {
    os << other.getRawBits();
    return os;
}
- other quand on parle d’un second objet qu’on manipule ou qu’on affiche
- on sort sur os

--------------------------------------------------------------------------------------------------------------------------------------

## 11. Canonical form :
- Constructeur par défaut
- Constructeur de recopie
- Opérateur d’affectation
- Destructeur

class	Sample
	{
		public
			Sample(void);	->
			Sample(Sample const& src);
			~Sample(void);

			Sample& operator=(Sample const& rhs);

			int	getFoo(void);

		private:
			int _foo;
	};

	std::ostream& operator<<(std::ostream& other, Sample const& rhs);

	#endif

Canonical (4 choses obligatoire pour 42):

Sample(void);
- constructeur par defaut

Sample(Sample const& src);
- un constructeur par copie
- prend en parametre une instance de la class qu on est entrain de definir pour faire une copie de cette class
- dans fichier cpp :
- *this = src	->	on pointe pour recuperer l adresse

~Sample(void);
- destructeur

Sample& operator=(Sample const& rhs);
- mise a jour de l instance courante
- assigner une autre instance a partir de cette class

--------------------------------------------------------------------------------------------------------------------------------------

EXO FIXED :

HPP : Canonical form :
Fixed();
- constructeur par defaut

Fixed(Fixed const& src);
- copie de la class

~Fixed();
- destructeur

Fixed&	operator=(Fixed const& rhs);
- surcharge de l’opérateur d’affectation
- But : copier l’état (les données internes) d’un objet rhs dans un autre objet déjà existant (*this).

CPP :

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}
- Initialise le membre privé _value à 0. Utile pour garantir qu’un nouvel objet Fixed commence toujours avec une valeur connue.


Fixed::Fixed(Fixed const& src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
- Permet d’instancier un nouvel objet à partir d’un autre
- délègues la copie à l’opérateur = pour éviter de dupliquer le code de copie à deux endroits.


Fixed&	Fixed::operator=(Fixed const& rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}
- Permet de copier l’état (_value) d’un objet existant dans un autre déjà construit.
- retourne *this pour pouvoir chaîner les affectations (a = b = c;).
- a = Fixed(1234.4321f)	->	aussi un assignement par copie
- ou  si pas de fonction get = this->_value = rhs._value;



MAIN :

int	main(){
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;
	
	return 0;
}

Fixed a		->	Appel du constructeur par défaut avec value a 0
Fixed b(a)	->	crée b à partir de a, donc c’est Fixed::Fixed(Fixed const& src) qui est appelé
Fixed c		->	Encore un constructeur par défaut pour initialiser c a 0

c = b		->	Opérateur d’affectation par copie
				Ici tu n’es pas en train de créer un nouvel objet, tu réaffectes simplement l’état de b à c. C’est donc Fixed::operator=(Fixed const& rhs) qui est invoqué.


--------------------------------------------------------------------------------------------------------------------------------------

EXO FIXED EN PLUS :

static const int	bits = 8; = si bits vaut 8 c'est comme faire x256

l expression : 1 << bits -> décale le bit 1 de 8 positions vers la gauche.
0000 0001  (1 décimal)
1 0000 0000  (256 décimal)


Fixed::Fixed(const int n){
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << Fixed::bits;
}
- But : représenter l’entier n dans ton format fixed-point, où _value stocke en fait la valeur multipliée par 2bits
- << pour convertir entier → fixe
- donc n * 256


Fixed::Fixed(const float f){
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << bits));
}
- But : convertir la valeur flottante f en fixed-point, en conservant bits bits pour la partie fractionnelle.
- Multiplication par 2bits
- f * (1 << bits) déplace la virgule de bits positions vers la droite. 
- Ex. si f = 3.75 et bits = 8,
- 3.75 × 256 = 960.0
- si par exemple f * 256 vaut 959.6 roundf renvoie 960


- En soit premiere chose c est de convertir les chiffres en faisant *256

--------------

int	Fixed::toInt(void)const{
	return this->_value >> Fixed::bits;
}
- toInt() te donne juste la partie entière de ton fixed-point
- >> opération inverse de tes constructeurs : elles convertissent la valeur interne _value (fixed-point) en un entier ou en un flottant “lisible”.
- Exemple : si bits == 8 et _value == 960
- 960 / 256 = 3.75 donc = 3
- Comme c’est un décalage binaire, la partie fractionnelle est simplement “jetée” (pas d’arrondi)


float	Fixed::toFloat(void)const{
	return (float)(this->_value) / (1 << bits);
}
- / (1 << bits) permet de diviser par 256
- Exemple : si bits == 8 et _value == 960
- 960 / 256 = 3.75
- toFloat() te rend la valeur réelle (entier + fraction) en décimal.

- en soit deuxieme chose a faire est de diviser par 256 pour avoir le chiffre exact


std::ostream&	operator<<(std::ostream& os, Fixed const& other){
	os << other.toFloat();
	return os;
}
- permet d afficher comme ceci : std::cout << "a is " << a << std::endl;
- evite d utiliser get a chaque appel

--------------------------------------------------------------------------------------------------------------------------------------

4 opérateurs de arithmétiques : +, -, *, et /
- Fixed	operator+(Fixed const& src);
- Fixed	operator-(Fixed const& src);
- Fixed	operator*(Fixed const& src);
- Fixed	operator/(Fixed const& src);

4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
post-incrémentation, pré-décrémentation et post-décrémentation)
- Fixed& operator++();
- Fixed operator++(int);
- Fixed& operator--();
- Fixed operator--(int);

6 opérateur de comparaison : >, <, >=, <=, == et !=
- bool operator>(const X& lhs, const X& rhs)	->	lhs = this
- bool operator<(const X& lhs, const X& rhs)
- bool operator>=(const X& lhs, const X& rhs)
- bool operator<=(const X& lhs, const X& rhs)
- bool operator==(const X& lhs, const X& rhs)
- bool operator!=(const X& lhs, const X& rhs)


Multiplication (operator*) fait :

    produit 64 bits : 1293 × 512 = 662016

    décale à droite de 8 bits : 662016 >> 8 = 662016 / 256 = 2586

    construit Fixed(2586)

Valeur de b = 2586 / 256 = 10.1015625 → affiché 10.1016


result de la variable qui est incrementer ou vice versa

//pre incremente, +1 a la valeur, return l adress avce *this

//post incremente, return ancienne valeur et ensuite la valeur modifier

--------------------------------------------------------------------------------------------------------------------------------------

## 12. Heritage c++ :

class	<ta_classe> : public <class_principale>
exemple :
- class	<ta_classe> = chat
- public <class_principale> = animal
- le chat aura le comportement animal + son propre comportement
- un animal a des pattes et cour, le chat est aigris
- la class chat aura acces aux fonctions membre de la class animal

encapsulation :
- private : uniquement une instance de la class
- protected : accessible uniquement par une instance de la class ou d une instance de la class deriver
- public : accessible n importe ou
