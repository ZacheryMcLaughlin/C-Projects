CC = g++ -g -std=c++11
exe_file = Zoo_Tycoon
monkey_file = Monkey
meerkat_file = Meerkat
sea_otter_file = Sea_Otter
animal_file = Animal
zoo_file = Zoo
driver_file = Zoo_Tycoon

$(exe_file): $(monkey_file).o $(meerkat_file).o $(sea_otter_file).o $(driver_file).o $(animal_file).o $(zoo_file).o
	$(CC) $(monkey_file).o $(meerkat_file).o $(sea_otter_file).o $(driver_file).o $(animal_file).o $(zoo_file).o -o $(exe_file)
 
$(monkey_file).o: $(monkey_file).cpp
	$(CC) -c $(monkey_file).cpp
 
$(meerkat_file).o: $(meerkat_file).cpp
	$(CC) -c $(meerkat_file).cpp
 
$(sea_otter_file).o: $(sea_otter_file).cpp
	$(CC) -c $(sea_otter_file).cpp
 
$(animal_file).o: $(animal_file).cpp
	$(CC) -c $(animal_file).cpp

$(zoo_file).o: $(zoo_file).cpp
	$(CC) -c $(zoo_file).cpp 	

$(driver_file).o: $(driver_file).cpp
	$(CC) -c $(driver_file).cpp 
 
clean:
	rm -f *.out *.o $(exe_file)
