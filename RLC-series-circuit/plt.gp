
#set grid
set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 2 \
    #pointtype 7 pointsize 1
set style line 2 \
    linecolor rgb '#dd181f' \
    linetype 2 linewidth 2 \
    #pointtype 5 pointsize 1
set mxtics 
set mytics
set grid xtics ,ytics
set xlabel( "time (seconds)")
set ylabel (" charge (Coulobs)")
set key top left
set title "Transient response of LCR circuit "
set terminal png
set output "plot.png"

plot "solution.dat" using 1:2  title "Q (coulombs)" with lines linestyle 1 \
, "solution.dat" using 1:3 title "I ( Amperes)" with lines linestyle 2


