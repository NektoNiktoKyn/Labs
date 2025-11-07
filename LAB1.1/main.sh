#!/bin/bash

for word in "$@"; do
	reversed=$(echo "$word" | rev)
	if [ "$word" = "$reversed" ]; then
		echo "'$word' - palindrome"
	else
		echo "'$word' - not palindrome"
	fi
done
