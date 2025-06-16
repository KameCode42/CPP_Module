NOTE PHONEBOOK :

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

===================================================================================================




















<iomanip>
Qu’est-ce que c’est ?

    Un header qui fournit des « manipulateurs » de flux (std::cout, std::cin, etc.).

    Permet de contrôler l’affichage (largeur de champ, alignement, précision, etc.) sans modifier la valeur des données.

Principaux manipulateurs
Manipulateur	Usage
std::setw(n)	Définit la largeur minimale du champ à n
std::setfill(c)	Caractère de remplissage si la largeur est trop grande
std::left / std::right	Alignement à gauche ou à droite
std::setprecision(p)	Nombre de chiffres significatifs (pour flottants)
std::fixed / std::scientific	Mode d’affichage des flottants
Pourquoi l’utiliser dans PhoneBook ?

Pour afficher votre répertoire sous forme de tableau propre :

    Colonnes alignées

        Exemple : prénoms, noms, numéros de téléphone sur des colonnes de largeur fixe.

    Lisibilité accrue

        Remplissage par espaces ou zéros (numéro formaté), alignement cohérent même si les longueurs varient.

    Exemple d’usage pour un tableau PhoneBook

#include <iostream>
#include <iomanip>

void printHeader() {
    std::cout << std::setw(15) << std::left  << "Prénom"
              << std::setw(15) << std::left  << "Nom"
              << std::setw(12) << std::right << "Téléphone"
              << '\n'
              << std::string(42, '-') << '\n';
}

void printEntry(const std::string& first, 
                const std::string& last, 
                const std::string& phone) {
    std::cout << std::setw(15) << std::left  << first
              << std::setw(15) << std::left  << last
              << std::setw(12) << std::right << phone
              << '\n';
}

int main() {
    printHeader();
    printEntry("Alice", "Martin", "0123456789");
    printEntry("Bob",   "Lefevre", "0987654321");
}

Cela donne :

Prénom         Nom            Téléphone
------------------------------------------
Alice          Martin        0123456789
Bob            Lefevre       0987654321

======================================================================================================

La méthode que vous appellerez le plus souvent pour répondre aux contraintes du PhoneBook
(notamment la limite à 10 caractères et le « .» de troncature) sera :

Pourquoi substr ?

    Spécification du projet 42
    Chaque champ (Prénom, Nom, Numéro) ne doit pas dépasser 10 caractères à l’affichage ; si la chaîne est plus longue, on prend les 9 premiers caractères puis on ajoute un « . ».

    Fonction unique pour tronquer
    Plutôt que de jouer sur des boucles ou des accès caractère par caractère, substr(0, 9) vous donne directement la portion que vous voulez extraire.

    Clarté et simplicité
    Une seule ligne pour tronquer, facile à relire et à maintenir :

    std::string affichage = (s.size() > 10)
        ? s.substr(0, 9) + '.'
        : s;

Le rôle de <iomanip> et std::setw

Une fois vos chaînes tronquées, vous utiliserez aussi très souvent :

std::setw(10)

pour :

    Aligner chaque colonne sur 10 positions,

    Gérer automatiquement le remplissage (espaces par défaut) pour obtenir un tableau bien ordonné.

Mais la vraie « bête de travail » reste substr, car tout champ qui dépasse devra systématiquement passer par elle avant d’entrer dans le flux de sortie formaté par std::setw.
Exemple complet

#include <iostream>
#include <iomanip>
#include <string>

void printField(const std::string& s) {
    std::string f = (s.size() > 10) ? s.substr(0, 9) + "." : s;
    std::cout << std::setw(10) << f;
}

int main() {
    printField("Jonathan");      // "  Jonathan"
    printField("SuperLongName"); // "SuperLong."
    std::cout << "\n";
}

    substr (tronquer + point) est appelé pour chaque champ trop long.

    setw(10) aligne ensuite proprement les résultats.

En résumé, pour être optimal dans votre PhoneBook, maîtrisez avant tout std::string::substr ; std::setw viendra compléter votre solution côté affichage.

========================================================================================

