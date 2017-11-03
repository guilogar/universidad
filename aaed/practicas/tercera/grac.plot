set xlabel "N (números de elementos)"
set ylabel "t(n) (tiempo en segundos)"

set style data linespoints

set terminal x11 1
plot "burbu.txt" title "Ordenación por intercambo directo", \
     "sel_directa.txt" title "Ordenación por selección directa", \
     "inser_directa.txt" title "Ordenación por inserción directa"

pause -1 "[Intro] para terminar\n"
