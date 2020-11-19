#Makefile
FLAGS = -pedantic-errors -std=c++11

save_data.o: save_data.cpp save_data.h
	g++ $(FLAGS) -c $<

village.o: village.cpp village.h save_data.h
	g++ $(FLAGS) -c $<

new_user.o: new_user.cpp new_user.h
	g++ $(FLAGS) -c $<

load_data.o: load_data.cpp load_data.h
	g++ $(FLAGS) -c $<

store.o: store.cpp store.h
	g++ $(FLAGS) -c $<

dungeon.o: dungeon.cpp dungeon.h
	g++ $(FLAGS) -c $<

main.o: main.cpp village.h new_user.h load_data.h store.h dungeon.h
	g++ $(FLAGS) -c $<

main: village.o new_user.o load_data.o store.o dungeon.o main.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f *.o main
	
.PHONY: clean
