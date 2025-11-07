#!/bin/bash

is_palindrome() {
	local word="$1"
	local reversed=$(echo "$1" | rev)
	if [ "$word" = "$reversed" ]; then
		return 0
	else
		return 1
	fi
}

for word in "$@"; do
	if is_palindrome "$word"; then
		echo "'$word' - palindrome"
	else
		echo "'$word' - not palindrome"
	fi
done
