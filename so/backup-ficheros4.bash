#!/bin/bash

#=============================
#===========FUNCIONES=========
#=============================

function util_tar() {
    local OPTION=P
    if [ -f "$1.tgz" -a $4 = "TRUE" ]
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
    echo "-------------$1"
    if [ $3 = "TRUE" ]
        then
            tar -cvzf "$1.tgz" $2
    else
        tar -czf "$1.tgz" $2
    fi
}

function comprobar_directorio() {
    if [ ! -d $1 ] || [ ! -w $1 ]
        then
            echo "No es un directorio válido."
            exit
    fi
}

#=============================
#===========PROGRAMA==========
#=============================

CURRENT_DATE=$(date +%Y%m%d)
VISIONAR_ARCHIVOS=FALSE
SOBREESCRIBIR=FALSE
NOMBRE_FICHERO=
DIRECTORIO=

while getopts :d:f:vo ARG
do
    case $ARG in
        d) DIRECTORIO=$OPTARG; comprobar_directorio $OPTARG;;
        :) echo "Argumento requerido para la opcion $OPTARG."; exit;;
        f) NOMBRE_FICHERO=$OPTARG;;
        :) echo "Argumento requerido para la opcion $OPTARG."; exit;;
        v) VISIONAR_ARCHIVOS=TRUE;;
        o) SOBREESCRIBIR=TRUE;;
        \?) echo "$OPTARG No es una opción válida.";;
    esac
done

echo "Comenzamos..."
echo "El directorio donde se va a guardar la copia de seguridad es => $DIRECTORIO"

echo -n "Dime los ficheros a comprimir => "
read FICHEROS
echo "Leído => $FICHEROS"

if [ -z $NOMBRE_FICHERO ]
    then
        NOMBRE_FICHERO=$(date +%Y%m%d)
fi

##rm -f               "$1/$current_date.tgz" 2> /dev/null
util_tar            "$DIRECTORIO/$NOMBRE_FICHERO" "$FICHEROS" "$VISIONAR_ARCHIVOS" "$SOBREESCRIBIR"
chmod g+r,g-w,o-rwx "$DIRECTORIO/$NOMBRE_FICHERO.tgz"
