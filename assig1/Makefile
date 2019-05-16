CC = g++ -g -std=c++11
exe_file = driver
imp_file = imp_wizard
driver_file = driver
$(exe_file): $(imp_file).o $(driver_file).o
	$(CC) $(imp_file).o $(driver_file).o -o $(exe_file)
$(imp_file).o: $(imp_file).cpp
	$(CC) -c $(imp_file).cpp
$(driver_file).o: $(driver_file).cpp
	$(CC) -c $(driver_file).cpp 
clean:
	rm -f *.out *.o $(exe_file)
