#!/bin/bash

for file in maps/*; do
	echo "------------------------------------------------"
	echo "$file"
	cat $file
	valgrind ./so_long $file
	echo "------------------------------------------------"
done
