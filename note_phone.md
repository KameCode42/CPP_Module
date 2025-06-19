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

===================================================================================================