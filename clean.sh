#!/bin/bash

rm -rfv temp

for folder in */; do
    rm -rfv $folder/runner
    rm -rfv $folder/solution
    rm -rfv $folder/tc
    rm -rfv $folder.cph
    rm -rfv $folder*.aux
    rm -rfv $folder*.bin
    rm -rfv $folder*.exe
    rm -rfv $folder*.fdb_latexmk
    rm -rfv $folder*.fls
    rm -rfv $folder*.log
    rm -rfv $folder*.out
    rm -rfv $folder*.synctex.gz
    rm -rfv $folder*.zip
done
