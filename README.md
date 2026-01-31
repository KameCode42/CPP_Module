algo ford-johnson etape

L’algorithme Ford-Johnson trie une séquence en formant des paires, en construisant une chaîne principale à partir des maximums, puis en insérant les minimums restants selon l’ordre Jacobsthal par recherche binaire afin de minimiser le nombre total de comparaisons.

La suite de Jacobsthal sert uniquement à déterminer l’ordre dans lequel on insère les éléments restants dans la chaîne principale afin de limiter le nombre de comparaisons.

0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, ...

nouveau = dernier + (2 × celui d’avant)

J0 = 0
J1 = 1

J2 = J1 + 2 × J0
J2 = 1 + 2 × 0
J2 = 1
