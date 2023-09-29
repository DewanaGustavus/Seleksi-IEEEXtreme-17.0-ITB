#!/bin/bash

alphabet=({A..Z})
index=0
folders=$(ls -d */) # make sure just generated problem folder in cwd

for folder2 in $folders; do
    letter=${alphabet[index]}
    folder=${folder2::-1}
    folder3=${folder//[-]/ }
    echo "Creating Problem $letter $folder3"
    ./generate-problem.sh $letter $folder "$folder3" 1 256 Result
    echo " "
    ((index++))
done
