# Übung 3

## Aufgabe 2b

Matrix:

	sizeof(adj_matrix) + size * size / 8
	= 16 + 1000000 / 8
	= 125016

Liste:

	sizeof(adj_list) + size * sizeof(adj_node*) + kanten * sizeof(adj_node)
	= 16 + 1000 * 8 + kanten * 16

Ergebnisse:

	 n    | Matrix | Liste
	------+--------+----------
	    1 | 125016 |    24016
	   19 | 125016 |   310576
	  199 | 125016 |  3033616
	 1999 | 125016 | 16008016

## Aufgabe 2c

Die Liste belegt für ein n von 1-7 weniger Speicher.

## Aufgabe 3

Siehe `build/benchmark.csv` und `build/benchmark.png`

