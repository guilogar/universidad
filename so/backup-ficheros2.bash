#!/bin/bash

function condition_script() {
    echo "Condiciones del script."
    echo "-----------------------"
    echo
    echo "1º) Introducir un solo parametro."
    echo "2º) El parametro debe de ser un directorio."
    echo "3º) El directorio debe de tener permisos de escritura."
}

function util_tar() {
    OPTION=P
    if [ -f "$1.tgz" ]
        then
            echo -n "El fichero ya existe, ¿Desea eliminarlo o abortar el script? (E/A)"
            read OPTION
    fi
    if [ $OPTION = "E" ]
        then
            rm -rf "$1.tgz"
    elif [ $OPTION = "A" ]
        then
            echo "fin"
            exit
    fi
    tar -czf "$1.tgz" $2
    
    #Aun por terminar.
    for E in $2; do
        echo ${E%.*}
    done
}

echo "Comenzamos..."

if [ ! $# -eq 1 ] || [ ! -d $1 ] || [ ! -w $1 ]
    then
        echo "Cumple las condiciones del script."
        echo ""
        condition_script
        exit
fi

echo "El directorio donde se va a guardar la copia de seguridad es => $1"

#ls -la /etc

echo -n "Dime los ficheros a comprimir => "
read A
echo "Leído => $A"

current_date=$(date +%Y%m%d)

#rm -f               "$1/$current_date.tgz" 2> /dev/null
util_tar            "$1/$current_date" "$A"
chmod g+r,g-w,o-rwx "$1/$current_date.tgz"
