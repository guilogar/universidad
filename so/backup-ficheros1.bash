#!/bin/bash

function util_tar() {
    tar -czf "$1.tgz" $2
}

echo "Comenzamos..."
echo "El directorio donde se va a guardar la copia de seguridad es => $1"

#ls -la /etc

echo -n "Dime los ficheros a comprimir => "
read A
echo "Leído => $A"

current_date=$(date +%Y%m%d)

rm -f               "$1/$current_date.tgz" 2> /dev/null
util_tar            "$1/$current_date" "$A"
chmod g+r,g-w,o-rwx "$1/$current_date.tgz"
