#!/bin/bash

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	for j in 1, 2, 4, 8; do
		./map_bench -b unsorted $i $j; 
	done;
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	for j in 1, 2, 4, 8; do
		./map_bench -b sorted $i $j; 
	done;
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	for j in 1, 2, 4, 8; do
		./map_bench -b bst $i $j; 
	done;
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	for j in 1, 2, 4, 8; do
		./map_bench -b rbtree $i $j; 
	done;
done

for i in 10, 100, 1000, 10000, 100000, 1000000, 10000000; do
	for j in 1, 2, 4, 8; do
		./map_bench -b treap $i $j; 
	done;
done
