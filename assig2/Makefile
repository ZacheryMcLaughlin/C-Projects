CC = g++ -g -std=c++11
exe_file = driver
pizza_file = imp_pizza
restaurant_file = restaurant
menu_file = menu
driver_file = driver

$(exe_file): $(pizza_file).o $(restaurant_file).o $(menu_file).o $(driver_file).o
	$(CC) $(pizza_file).o $(restaurant_file).o $(menu_file).o $(driver_file).o -o $(exe_file)
 
$(pizza_file).o: $(pizza_file).cpp
	$(CC) -c $(pizza_file).cpp
 
$(restaurant_file).o: $(restaurant_file).cpp
	$(CC) -c $(restaurant_file).cpp
 
$(menu_file).o: $(menu_file).cpp
	$(CC) -c $(menu_file).cpp
 
$(driver_file).o: $(driver_file).cpp
	$(CC) -c $(driver_file).cpp 
 
clean:
	rm -f *.out *.o $(exe_file)
