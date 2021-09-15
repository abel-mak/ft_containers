# vector
## notes
### iterator
- Input Iterator : utilisés pour lire !=, ++, *</br>
- Output Iterator : utilisés pour écrire dans un container </br>
- Forward Iterator : est un InputIterator et un OutputIterator</br>
- Bidirectional Iterator : est un ForwardIterator mais qui peut se déplacer dans les deux directions (début à la fin ou de la fin vers le début)</br>
- Random Access Iterator
Il peut être vu comme un pointeur sur un élément d'un container et utilise des fonctions comme :

operator* : retourne l'élément pointé par l'itérateur
operator++ : permet de passer à l'élément suivant
operator== et operator!= permet de comparer deux itérateurs et s'ils pointent sur le même élément
Chaque container possède 4 fonctions à utiliser avec les itérateurs :

begin() : retourne un pointeur sur le premier élément du container
end() : retourne un pointeur situé après le dernier élément du container
cbegin() : comme begin() mais constant (read-only)
cend() :comme end() mais constant (read-only)
Chaque container possède au moins 2 types d'itérateurs :

container::iterator : itérateur (read/write)
container::const_iterator() : itérateur (read-only)
