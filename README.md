# vector
## notes
#### iterator
- Input Iterator : utilisés pour lire !=, ++, *</br>
- Output Iterator : utilisés pour écrire dans un container </br>
- Forward Iterator : est un InputIterator et un OutputIterator</br>
- Bidirectional Iterator : est un ForwardIterator mais qui peut se déplacer dans les deux directions (début à la fin ou de la fin vers le début)</br>
- Random Access Iterator
Il peut être vu comme un pointeur sur un élément d'un container et utilise des fonctions comme :

operator* : retourne l'élément pointé par l'itérateur</br>
operator++ : permet de passer à l'élément suivant</br>
operator== et operator!= permet de comparer deux itérateurs et s'ils pointent sur le même élément<br/>
Chaque container possède 4 fonctions à utiliser avec les itérateurs :

begin() : retourne un pointeur sur le premier élément du container</br>
end() : retourne un pointeur situé après le dernier élément du container</br> 
cbegin() : comme begin() mais constant (read-only)</br>
cend() :comme end() mais constant (read-only)</br>
Chaque container possède au moins 2 types d'itérateurs :

container::iterator : itérateur (read/write)</br>
container::const_iterator() : itérateur (read-only)</br> 

#### initializtion
###### types
- Value initialization, e.g. std::string s{};</br>
- Direct initialization, e.g. std::string s("hello");</br>
- Copy initialization, e.g. std::string s = "hello";</br>
- List initialization, e.g. std::string s{'a', 'b', 'c'};</br>
- Aggregate initialization, e.g. char a[3] = {'a', 'b'};</br>
- Reference initialization, e.g. char& c = a[0];</br>
###### Copy initialization
- Copy-initialization is less permissive than direct-initialization: explicit constructors are not converting constructors and are not considered for copy-initialization.<br>
<div dir="ltr" class="mw-geshi" style="text-align: left;"><div class="cpp source-cpp"><pre class="de1"><span class="kw1">struct</span> Exp <span class="br0">{</span> <span class="kw1">explicit</span> Exp<span class="br0">(</span><span class="kw4">const</span> <span class="kw4">char</span><span class="sy2">*</span><span class="br0">)</span> <span class="br0">{</span><span class="br0">}</span> <span class="br0">}</span><span class="sy4">;</span> <span class="co1">// not convertible from const char*</span>
Exp e1<span class="br0">(</span><span class="st0">"abc"</span><span class="br0">)</span><span class="sy4">;</span>  <span class="co1">// OK</span>
Exp e2 <span class="sy1">=</span> <span class="st0">"abc"</span><span class="sy4">;</span> <span class="co1">// Error, copy-initialization does not consider explicit constructor</span>
&nbsp;
<span class="kw1">struct</span> Imp <span class="br0">{</span> Imp<span class="br0">(</span><span class="kw4">const</span> <span class="kw4">char</span><span class="sy2">*</span><span class="br0">)</span> <span class="br0">{</span><span class="br0">}</span> <span class="br0">}</span><span class="sy4">;</span> <span class="co1">// convertible from const char*</span>
Imp i1<span class="br0">(</span><span class="st0">"abc"</span><span class="br0">)</span><span class="sy4">;</span>  <span class="co1">// OK</span>
Imp i2 <span class="sy1">=</span> <span class="st0">"abc"</span><span class="sy4">;</span> <span class="co1">// OK</span></pre></div></div>

#### SFINAE (Substitution Failure Is Not An Error) [source](http://yunes.informatique.univ-paris-diderot.fr/wp-content/uploads/cours/LOA/2019/128-Idiomes.pdf)
- means that when compiler try to substitute types in declaration of a function template, and this substitution fails, this is not considered an error, the compiler try to find another templates, to make the substitution, if he doens't succeed then it's an error.
- this can be used when you want to define a function of specific type for example, integral return defined function
```
template <bool B, typename T = void>
struct my_if 
{
};
template <typename T>
struct my_if<true,T> 
{
 typedef T type;
};
```

```
template <typename T>
typename my_if<std::is_integral<T>::value,T>::type uneFonction(T x);
```
###### install libc++
sudo apt update<br>
sudo apt install libc++abi1 libc6 libgcc1 libc++1</br>
sudo apt-get install libc++-dev

## insert
- every node has a value and height and left, right and parent node pointers
- search through the tree to find right place to insert the node
- if the node does exist before return it otherwise insert
- after insert the new node is assigned height of 0
- i update the height of every going from the new node to the root
- i check for imbalance going from the new node to the root
- after imbalance is found i do the necessary rotations, at most two rotation
 are sufficient to rebalance the tree

## rebalance
- after doing the rotations, the heigth of some node gets messed up
- i call a function that update height, the function gets as argument the node 
that was imbalanced and type of imbalance 
- the function checks if the imbalance was 'right right' or 'left left' it updates
the height of the imbalanced node and it's ancestors
- if the imbalace was 'right left' or 'left right' it updates the height of 
the imbalanced node , it's siblings and it's ancestors


## Links
- [Why is the copy constructor not called?](https://stackoverflow.com/questions/3663506/why-is-the-copy-constructor-not-called)
- [In-order iterator for binary tree](https://stackoverflow.com/questions/12850889/in-order-iterator-for-binary-tree)
- [LLVM Debian/Ubuntu nightly packages](https://apt.llvm.org/)
- [What is a symbol table?](https://stackoverflow.com/questions/69112/what-is-a-symbol-table)
- [typename c++ and order of compiling](https://stackoverflow.com/questions/59225508/typename-c-and-order-of-compiling)
- [Binary Search Tree - Copying one tree into another tree](https://stackoverflow.com/questions/40969075/binary-search-tree-copying-one-tree-into-another-tree)
