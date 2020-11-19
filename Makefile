#Makefile
FLAGS = -pedantic-errors -std=c+11

village.o: village.cpp village.h
	g++ $(FLAGS) -c $<

new_user.o: new_user.cpp new_user.h
	g++ $(FLAGS) -c $<

load_data.o: load_data.cpp load_data.h
	g++ $(FLAGS) -c $<

save_data.o: save_data.cpp save_data.h
	g++ $(FLAGS) -c $<

store.o: store.cpp store.h
	g++ $(FLAGS) -c $<

dungeon.o: dungeon.cpp dungeon.h
	g++ $(FLAGS) -c $<



