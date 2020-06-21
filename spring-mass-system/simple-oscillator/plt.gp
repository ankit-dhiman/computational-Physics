
#set grid
set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 2 \
    #pointtype 7 pointsize 1
set style line 2 \
    linecolor rgb '#dd181f' \
    linetype 1 linewidth 2 \
    #pointtype 5 pointsize 1
set xlabel( "time (seconds)")
set ylabel (" distance (m)")
set key top left
set title "Simple harmonic oscillator"
set terminal png
set output "plot.png"

plot "solution.dat" using 1:2  title "x(t)" with lines linestyle 1 


