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
