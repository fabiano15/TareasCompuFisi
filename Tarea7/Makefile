all:
	cc -lm metodos.c tarea_7.c
	./a.out 1000
	gnuplot -e "set term png; set output 'Plano_t-R'; plot '0.dat' using 1:2 "
	gnuplot -e "set term png; set output 'Plano_t-v'; plot '0.dat' using 1:3 "
	gnuplot -e "set term png; set output 'Plano_t-P'; plot '0.dat' using 1:4 "
	
	
	make clean
	
clean:
	rm 0.dat
	rm a.out

	
