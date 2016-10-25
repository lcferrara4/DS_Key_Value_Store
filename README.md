Project 03 - Key-Value Store I
==============================

This [project] implements a variety of [map] backends for a basic [key-value
store].

[project]:          https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project03.html
[map]:              https://en.wikipedia.org/wiki/Associative_array
[key-value store]:  https://en.wikipedia.org/wiki/Key-value_database

1. Complexities of map backends:
	
	* Unsorted: 
	Insert: Best = O(1), Average = O(1), Worst = O(1)
	Search: Best = O(1), Average = O(n), Worst = O(n)

	* Sorted:
	Insert: Best = O(1), Average = O(n), Worst = O(n)
	Search: Best = O(1), Average = O(n), Worst = O(n)

	* BST:
	Insert: Best = O(1), Average = O(log(n)), Worst = O(n)
	Search: Best = O(1), Average = O(log(n)), Worst = O(n)

	* RBTree:
	Insert: Best = O(log(n)), Average = O(log(n)), Worst = O(log(n))
	Search: Best = O(log(n)), Average = O(log(n)), Worst = O(log(n))

	* Treap:
	Insert: Best = O(log(n)), Average = O(log(n)), Worst = O(n)
	Search: Best = O(log(n)), Average = O(log(n)), Worst = O(n)

2. map\_bench:

| Backend    | NITEMS    | PADLENGTH | Insert Time   | Search Time   |
|------------|-----------|-----------|---------------|---------------|
| UNSORTED   | 10        | 1         |
| UNSORTED   | 100       | 1         |
| UNSORTED   | 1000      | 1         |
| UNSORTED   | 10000     | 1         |
| UNSORTED   | 100000    | 1         |
| UNSORTED   | 1000000   | 1         |
| UNSORTED   | 10000000  | 1         |
| UNSORTED   | 10        | 2         |
| UNSORTED   | 100       | 2         |
| UNSORTED   | 1000      | 2         |
| UNSORTED   | 10000     | 2         |
| UNSORTED   | 100000    | 2         |
| UNSORTED   | 1000000   | 2         |
| UNSORTED   | 10000000  | 2         |
| UNSORTED   | 10        | 4         |
| UNSORTED   | 100       | 4         |
| UNSORTED   | 1000      | 4         |
| UNSORTED   | 10000     | 4         |
| UNSORTED   | 100000    | 4         |
| UNSORTED   | 1000000   | 4         |
| UNSORTED   | 10000000  | 4         |
| UNSORTED   | 10        | 8         |
| UNSORTED   | 100       | 8         |
| UNSORTED   | 1000      | 8         |
| UNSORTED   | 10000     | 8         |
| UNSORTED   | 100000    | 8         |
| UNSORTED   | 1000000   | 8         |
| UNSORTED   | 10000000  | 8         |
| SORTED     | 10        | 1         |
| SORTED     | 100       | 1         |
| SORTED     | 1000      | 1         |
| SORTED     | 10000     | 1         |
| SORTED     | 100000    | 1         |
| SORTED     | 1000000   | 1         |
| SORTED     | 10000000  | 1         |
| SORTED     | 10        | 2         |
| SORTED     | 100       | 2         |
| SORTED     | 1000      | 2         |
| SORTED     | 10000     | 2         |
| SORTED     | 100000    | 2         |
| SORTED     | 1000000   | 2         |
| SORTED     | 10000000  | 2         |
| SORTED     | 10        | 4         |
| SORTED     | 100       | 4         |
| SORTED     | 1000      | 4         |
| SORTED     | 10000     | 4         |
| SORTED     | 100000    | 4         |
| SORTED     | 1000000   | 4         |
| SORTED     | 10000000  | 4         |
| SORTED     | 10        | 8         |
| SORTED     | 100       | 8         |
| SORTED     | 1000      | 8         |
| SORTED     | 10000     | 8         |
| SORTED     | 100000    | 8         |
| SORTED     | 1000000   | 8         |
| SORTED     | 10000000  | 8         |
| BST        | 10        | 1         |
| BST        | 100       | 1         |
| BST        | 1000      | 1         |
| BST        | 10000     | 1         |
| BST        | 100000    | 1         |
| BST        | 1000000   | 1         |
| BST        | 10000000  | 1         |
| BST        | 10        | 2         |
| BST        | 100       | 2         |
| BST        | 1000      | 2         |
| BST        | 10000     | 2         |
| BST        | 100000    | 2         |
| BST        | 1000000   | 2         |
| BST        | 10000000  | 2         |
| BST        | 10        | 4         |
| BST        | 100       | 4         |
| BST        | 1000      | 4         |
| BST        | 10000     | 4         |
| BST        | 100000    | 4         |
| BST        | 1000000   | 4         |
| BST        | 10000000  | 4         |
| BST        | 10        | 8         |
| BST        | 100       | 8         |
| BST        | 1000      | 8         |
| BST        | 10000     | 8         |
| BST        | 100000    | 8         |
| BST        | 1000000   | 8         |
| BST        | 10000000  | 8         |
| RBTree     | 10        | 1         |
| RBTree     | 100       | 1         |
| RBTree     | 1000      | 1         |
| RBTree     | 10000     | 1         |
| RBTree     | 100000    | 1         |
| RBTree     | 1000000   | 1         |
| RBTree     | 10000000  | 1         |
| RBTree     | 10        | 2         |
| RBTree     | 100       | 2         |
| RBTree     | 1000      | 2         |
| RBTree     | 10000     | 2         |
| RBTree     | 100000    | 2         |
| RBTree     | 1000000   | 2         |
| RBTree     | 10000000  | 2         |
| RBTree     | 10        | 4         |
| RBTree     | 100       | 4         |
| RBTree     | 1000      | 4         |
| RBTree     | 10000     | 4         |
| RBTree     | 100000    | 4         |
| RBTree     | 1000000   | 4         |
| RBTree     | 10000000  | 4         |
| RBTree     | 10        | 8         |
| RBTree     | 100       | 8         |
| RBTree     | 1000      | 8         |
| RBTree     | 10000     | 8         |
| RBTree     | 100000    | 8         |
| RBTree     | 1000000   | 8         |
| RBTree     | 10000000  | 8         |
| Treap      | 10        | 1         |
| Treap      | 100       | 1         |
| Treap      | 1000      | 1         |
| Treap      | 10000     | 1         |
| Treap      | 100000    | 1         |
| Treap      | 1000000   | 1         |
| Treap      | 10000000  | 1         |
| Treap      | 10        | 2         |
| Treap      | 100       | 2         |
| Treap      | 1000      | 2         |
| Treap      | 10000     | 2         |
| Treap      | 100000    | 2         |
| Treap      | 1000000   | 2         |
| Treap      | 10000000  | 2         |
| Treap      | 10        | 4         |
| Treap      | 100       | 4         |
| Treap      | 1000      | 4         |
| Treap      | 10000     | 4         |
| Treap      | 100000    | 4         |
| Treap      | 1000000   | 4         |
| Treap      | 10000000  | 4         |
| Treap      | 10        | 8         |
| Treap      | 100       | 8         |
| Treap      | 1000      | 8         |
| Treap      | 10000     | 8         |
| Treap      | 100000    | 8         |
| Treap      | 1000000   | 8         |
| Treap      | 10000000  | 8         |

3. frequencies:

| Backend    | Text            | File Size | Elapsed Time  |
|------------|-----------------|-----------|---------------|
| UNSORTED   | beowulf         | 21189     | 0.002s        |
| SORTED     | beowulf         | 21189     |
| BST        | beowulf         | 21189     | 0.002s        |
| RBTree     | beowulf         | 21189     | 0.003s        |
| Treap      | beowulf         | 21189     | 0.004s        |
| UNSORTED   | peterpan        | 22260     | 0.002s        |
| SORTED     | peterpan        | 22260     |
| BST        | peterpan        | 22260     | 0.001s        |
| RBTree     | peterpan        | 22260     | 0.002s        |
| Treap      | peterpan        | 22260     | 0.003s        |
| UNSORTED   | junglebook      | 23057     | 0.003s        |
| SORTED     | junglebook      | 23057     |               |
| BST        | junglebook      | 23057     | 0.001s        |
| RBTree     | junglebook      | 23057     | 0.000s        |
| Treap      | junglebook      | 23057     | 0.007s        |

4. Conclusions:

	*
	*
	*

5. Member contributions: 

