
#set grid
set style line 1 \
    linecolor rgb 'green' \
    linetype 1 linewidth 2 \
    #pointtype 7 pointsize 1
set style line 2 \
    linecolor rgb 'blue' \
    linetype 3 linewidth 2 \
    #pointtype 5 pointsize 1
set style line 3 \
    linecolor rgb 'yellow' \
    linetype 2 linewidth 2 \
    #pointtype 5 pointsize 1    
set xlabel( "time (seconds)")
set ylabel (" distance (m)")
set key top left
set title "damped spring mass system"
set terminal png
set output "plot.png"

plot "solution.dat" using 1:2  title "overrdamped" with lines linestyle 1 ,\
 "solution1.dat" using 1:2  title "critically damped" with lines linestyle 2 ,\
  "solution2.dat" using 1:2  title "underdamped" with lines linestyle 3 


