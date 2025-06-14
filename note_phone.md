std::string
Qu’est-ce que c’est ?

    Une classe de la bibliothèque standard (<string>) qui encapsule une suite de caractères de longueur dynamique.

    Internement, elle gère automatiquement l’allocation et la libération mémoire, évitant les fuites et la complexité liée aux C-strings (char*).

Caractéristiques principales
Méthode	Description
size()/length()	Nombre de caractères
empty()	Teste si la chaîne est vide
operator[]/at()	Accès direct à un caractère (avec vérification via at)
append(), +	Concaténation
substr(pos, len)	Extraction d’une sous-chaîne
find(str)	Recherche d’une sous-chaîne
compare()	Comparaison lexicographique
c_str()	Conversion en C-string (const char*)
Pourquoi l’utiliser dans PhoneBook ?

    Sécurité

        Pas de buffer overflow : on n’a pas à prévoir manuellement la taille du buffer.

    Simplicité

        Concaténation aisée (s1 + " " + s2), comparaison lexicographique (if (a < b)), conversion aisée pour affichage ou envoi à std::ostream.

    Richesse fonctionnelle

        Recherche, découpage, insertion, suppression… indispensables pour manipuler noms, prénoms, numéros, etc.

    Exemple

#include <string>
#include <iostream>

int main() {
    std::string firstName = "Jean";
    std::string lastName = "Dupont";
    std::string fullName = firstName + " " + lastName;
    std::cout << "Nom complet : " << fullName << " (" 
              << fullName.size() << " caractères)\n";
}

================================================================================

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

void addContact(const Contact& c);
// Ajoute un contact, écrase le plus ancien si le tableau est plein

void displaySummary() const;
// Affiche l’en-tête puis un résumé (tableau) de tous les contacts

bool displayContact(int idx) const;
// Affiche tous les détails d’un contact donné par son index (0-based)
// Renvoie false si index invalide

=====================================================================


class contact :

const signifie que le fichier sera lu en mode lecture et ne pourra pas etre modifier

std::string :
std::string gère automatiquement la mémoire : tu n’as pas à allouer ni libérer manuellement un buffer (pas de new[]/delete[]).
La taille s’adapte : tu peux stocker aussi bien "Al" que "Alexandre" ou même une phrase plus longue, sans te soucier de dépasser une taille fixe.

En le déclarant private, tu empêches tout accès direct depuis l’extérieur : seuls les getters et setters que tu exposes en public pourront lire ou modifier cette valeur.
Cela te permet de contrôler la validité (ex. refuser une chaîne vide) ou de déclencher d’autres actions lors du changement.

void setName(str name);
Ces méthodes servent uniquement à modifier l’attribut interne, pas à retourner une valeur.
this->... = .....

str getName() const;
std::string signifie que la fonction rend une copie de la chaîne stockée dans l’objet.
return copie = return this->....
Applicables uniquement aux getters :
Le const : Si tu tentes d’écrire dans un attribut privé à l’intérieur de getName(), le compilateur te refusera la compilation.

Ajouter une valeur (setFirstName("Alice"))
this->... = .....
Action : tu appelles le setter depuis ton code (par exemple dans main.cpp).
Effet : la méthode copie la chaîne "Alice" dans l’attribut privé _firstName de l’objet.

Lire une valeur (getFirstName())
return copie = return this->....
Action : tu appelles le getter pour récupérer la valeur stockée.
Effet : la méthode retourne une copie de la chaîne _firstName.

Paramètres const std::string& : performance, pas de copies inutiles.

set va stocker la saisie et get l afficher

Contact c;
std::string input;

// Saisie utilisateur
std::cout << "First Name: ";
std::getline(std::cin, input);
c.setFirstName(input);    // ← on stocke la saisie dans l’attribut _firstName via le setter

// Plus tard, pour afficher ou traiter :
std::cout << "You entered: " << c.getFirstName() << std::endl;
          // ← on récupère la valeur via le getter (copie ou référence const)


#include <cstdlib>
pour utiliser : system("clear") : permet d avoir un interface propre