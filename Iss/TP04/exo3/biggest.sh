#! /bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <Dossier>"
    exit 1
fi

nom=""
nomTaille=0

for i in $1/*; do
    if test $(wc -m < $i) -gt $nomTaille; then
        nomTaille=$(wc -m < $i)
        nom=$i
    fi
done

echo $nom 