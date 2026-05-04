# Algorithm Ford-Johnson

L’algorithme Ford-Johnson trie une séquence en formant des paires, en construisant une chaîne principale à partir des maximums, puis en insérant les minimums restants selon l’ordre Jacobsthal par recherche binaire afin de minimiser le nombre total de comparaisons.

---

## Jacobsthal

La suite de Jacobsthal sert uniquement à déterminer l’ordre dans lequel on insère les éléments restants dans la chaîne principale afin de limiter le nombre de comparaisons.

Suite jacob :  
0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, ...

### Calcul de la suite Jacobsthal

```
nouveau = dernier + (2 × celui d’avant)

J0 = 0
J1 = 1

J2 = J1 + 2 × J0
J2 = 1 + (2 × 0)
J2 = 1
```

---

## Notes

### parseLine
```
./a.out 34 4 66

Creer deux containers local temporaire
Boucle sur argc -> prend le premier nbr(argv[0])
Affecte dans une string pour parcourir un nbr comme -> 34
Check si 3 et 4 sont des digit, si oui -> erreur
Extrait le premier nbr et check si negatif ou > a INT_MAX
Cast long en int
Check si les containers contiennent des doublons
Push dans les containers temporaire jusqu a la fin du parsing
Une fois tout ok, copie le contenu dans les vrai containers
```

---

### makePairsVector
```
Creer des pairs pour reperer les min, max
Si la taille est impair, mettre le dernier nombre de coter
Boucle sur la taille de input
Copie les valeurs i et i + 1 afin de les comparer
Push dans le container pairs selon le min des pairs former
Avance de i + 2 -> compare le nbr suivant
```

---

### sortPairsByMax
```
Trier les paires par leur max
Compare le max du second de la pair et la trie
```

---

### buildMainChain
```
Construire la chaîne principale

Creer un vector local mainChain
Push le premier nbr de la pair -> il sera de toute maniere le plus petit
Push tous les second trier par leur max

mainChain contiendra le nbr le plus petit et les max.second de chaque pair
```

---

### buildPendings
```
Gerer les min en attente

Creer un vector local pending
Boucle sur la taille de pairs
Commence i = 1 car le premier first de la premiere pair est deja push
Push les first des pairs dans pending
```

---

### jacobsthalSuite
```
Creation de la suite de Jacobsthal

Creer un vector local jacob -> contiendra la suite jacobsthal
Boucle sur la taille de pending
Condition pour eviter les doublons
Calcul de la suite
```

---

### buildJacobOrder
```
Construire l’ordre final

Vector jacob -> contient la suite jacobsthal calculer
Vector order -> contiendra la liste final de l'ordre d'insertion

Push les index utile dans order
X = index a inserer

Forme des pairs avec les index jacobsthal
Permet d'inserer le x manquant pour le tri des valeur connu

Entree le reste des index dans un ordre decroissant
```

---

### binaryInsert
```
Insertion du nbr x sans casser l'ordre

But: couper la chaine en deux et de controler si le nbr mid et < || > que x

Insert l'element x qui se trouve a l index left
```

---

### insertPendings
```
Parcours order pour inserer les nbr de pending
Utilisation de binaryInsert
```

---

### fordJohnsonVector
```
Formation des pairs
Tri par leur max -> pour chaque pair
Construit la chaine principale
Construit la chaine pending
Construit la suite jacobsthal avec ses index
Insertion des pending dans la chaine principale dans l'ordre
Insert le dernier element si l'entree est impair
```

---

## Exemple de fonctionnement de l'algo

### Entrée utilisateur
```
input = 34 54 8 4 200 450 255 18 76 12 2
```

---

### makePairsVector
```
pairs = (34,54) (4,8) (200,450) (18, 255) (12, 76)
(trier selon min, max)

Last = 2 -> de coter
```

---

### sortPairsByMax
```
pairs = (4,8) (34,54) (12,76) (18, 255) (200,450)
```

---

### buildMainChain
```
mainChain = 4, 8, 54, 76, 255, 450
```

---

### buildPendings
```
pending = 34, 12, 18, 200
```

---

### jacobsthalSuite
```
jacob = 1 3
```

---

### buildJacobOrder
```
jacob = 1 3
order = 1 3

pairs jacob :
j0(a=1,b=3)
j1(a=3,b=5)

J0 :
x = b - 1 -> x = 2
2 > 1

order = 1 3 5 2

J1 :
x = b - 1 -> x = 4
4 > 3

order = 1 3 2 4
```

Ajout si pendingSize plus grand :
```
pendingSize = 10

x = 10
x > 5

order = 1 3 5 2 4 10 9 8 7 6
```

---

### binaryInsert
```
left = 0
right = mainchain.size = 6

mid = (0 + 6) / 2 -> 3
mainChain[76] < 34 -> non
right = 4

mid = (0 + 4) / 2 -> 2
mainChain[54] < 34 -> non
right = 3

mid = (0 + 3) / 2 -> 1
mainChain[8] < 34 -> oui
left = mid + 1 -> 2

Insertion à index 2
```

Résultat :
```
mainChain = 4, 8, 34, 54, 76, 255, 450
```

---

### insertPendings
```
mainChain = 4, 8, 54, 76, 255, 450
pending = 34, 12, 18, 200
order = 1 3 2 4
```

```
indexOrder = 1
x = pending[0] = 34
mainChain = 4, 8, 34, 54, 76, 255, 450

indexOrder = 3
x = pending[2] = 18
mainChain = 4, 8, 18, 34, 54, 76, 255, 450

indexOrder = 2
x = pending[1] = 12
mainChain = 4, 8, 12, 18, 34, 54, 76, 255, 450

indexOrder = 4
x = pending[3] = 200
mainChain = 4, 8, 12, 18, 34, 54, 76, 200, 255, 450
```

---

### Résultat final
```
mainChain = 4, 8, 12, 18, 34, 54, 76, 200, 255, 450
```

---

## Comparaison
```
vector plus rapide que deque

vector :
- stocke les éléments dans un seul bloc memoire

deque :
- stocke par blocs separes
```
