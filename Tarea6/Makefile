all:
	cc -lm metodos.c tarea_6.c
	./a.out 0.02 
	gnuplot -e "set term png; set output 'Plano_x-y'; plot '0.dat' using 2:3 , '1.dat' using 2:3, '2.dat' using 2:3, '3.dat' using 2:3, '4.dat' using 2:3, '5.dat' using 2:3, '6.dat' using 2:3, '7.dat' using 2:3, '8.dat' using 2:3, '9.dat' using 2:3"
	gnuplot -e "set term png; set output 'Plano_x-z'; plot '0.dat' using 2:4 , '1.dat' using 2:4, '2.dat' using 2:4, '3.dat' using 2:4, '4.dat' using 2:4, '5.dat' using 2:4, '6.dat' using 2:4, '7.dat' using 2:4, '8.dat' using 2:4, '9.dat' using 2:4"
	gnuplot -e "set term png; set output 'Plano_y-z'; plot '0.dat' using 3:4 , '1.dat' using 3:4, '2.dat' using 3:4, '3.dat' using 3:4, '4.dat' using 3:4, '5.dat' using 3:4, '6.dat' using 3:4, '7.dat' using 3:4, '8.dat' using 3:4, '9.dat' using 3:4"
	
	cp Plano_x-y ./graficas
	cp Plano_x-z ./graficas
	cp Plano_y-z ./graficas
	make clean
	
clean:
	rm 0.dat
	rm 1.dat
	rm 2.dat
	rm 3.dat
	rm 4.dat
	rm 5.dat
	rm 6.dat
	rm 7.dat
	rm 8.dat
	rm 9.dat
	rm a.out
	rm Plano_x-y
	rm Plano_x-z
	rm Plano_y-z
	
