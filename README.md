PUSH SWAP


Ce projet vous demande de trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles. 
Pour le réussir, vous devrezmanipuler différents algorithmes de tri et choisir la (ou les ?) solution la plus appropriéepour un classement optimisé des données.


SUJET : 
Le projet Push_swap est un projet d’algo simple et efficace : il faut trier. 
Vous avez à votre disposition un ensemble d’entiers, deux piles, et un ensemble d’instructions pour manipuler les piles.
Votre but ? Ecrire un programme en C nommé push_swap, qui calcule et affiche sur la sortie standard 
le plus petit programme dans le langage des instructions de Push_swap permettant de trier les entiers passés en paramètre.


OPERATION POSSIBLE :

sa : swap a
- intervertit les 2 premiers éléments au sommet de la pile a. 
- Ne fait rien s’il n’y en a qu’un ou aucun.

sb : swap b
- intervertit les 2 premiers éléments au sommet de la pile b. 
- Ne faitrien s’il n’y en a qu’un ou aucun. 

ss :
- sa et sb en même temps.

pa : push a
- prend le premier élément au sommet de b et le met sur a. 
- Ne faitrien si b est vide.

pb : push b
- prend le premier élément au sommet de a et le met sur b. 
- Ne faitrien si a est vide.

ra : rotate a
- décale d’une position vers le haut tous les élements de la pile a.
- Le premier élément devient le dernier.

rb : rotate b
- décale d’une position vers le haut tous les élements de la pile b.
- Le premier élément devient le dernier.

rr :
- ra et rb en même temps.

rra : reverse rotate a
- décale d’une position vers le bas tous les élements de la pile a. 
- Le dernier élément devient le premier.

rrb : reverse rotate b
- décale d’une position vers le bas tous les élements de la pile b. 
- Le dernier élément devient le premier.

rrr :
- rra et rrb en même temps.


UTILISATION : 

une instruction par ligne : calcul le nombre d'opération : 
./push_swap 3 2 1 | wc -l


checker : verifie si le programme push_swap tri correctement la liste.
./push_swap 3 2 1 | ./checker 3 2 1

ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG

avec un générateur de nombre aléatoire, ici celui de tharchen :
./genstack stacksize min max
ARG=`./genstack.pl 100 0 1000`; ./push_swap $ARG | ./checker $ARG

en complément sur bash : ./test_all.sh
calcul sur 50 test le plus grand nombre d'opération sur une liste de nombre aléatoires.

bareme de correction : 

pour 5 nombres   : - de 12   opérations.
pour 100 nombres : - de 700  opérations.
pour 500 nombres : - de 5500 opérations.