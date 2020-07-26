#!/usr/bin/env bash

if [ ! -d trash ]
then
	mkdir -p trash
fi

for i in $@;do
	if [ -f $i ]
	then
		if [ "$i" != "hidden.o" ]
		then
			mv $i trash
		fi
	else
		echo "File $i does not exist"
	fi
done

if [ -d trash ]
then
	find trash -mmin +60 -type f -delete
fi
