#ifndef SAVE_DATA_H
#define SAVE_DATA_H

int location;
struct Game_data;
//void save_data();

class Save_data{
  
private:

public:
  void save_data(Game_data* data, int* location);
};
  
#endif

