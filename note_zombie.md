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

===================================================================================================

ALLOUER DES TABLEAUX ZOMBIE:
- Zombie* horde = new Zombie[N];
- delete[];

- on alloue sur l'objet Zombie le "N" qui signifie le nombre d'entree dans le tableau
- horde sera utiliser pour parcourir le tableau -> horde[i]

- recuperation et affichage :
for (int i = 0; i < N; i++){
		horde[i].setName(name);	->	permet de set les informations (stocker la saisie)
		horde[i].announce();	->	utilise la fonction membre
	}