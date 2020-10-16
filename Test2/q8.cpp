#include <string>

using namespace std;
class NameList {
      string items[100];  // storage for values in list
      int    count;       // number of items in the list
public:
      NameList() // constructor
      {
          for (size_t i = 0; i < 100; i++)
          {
              this->items[i] = "";
              this->count = 0;
          }
          
      }

      bool addToEnd(string value) //returns true if adding to the end of the list worked, false if the list was full
      {
          if(this->count < 100) items[count] = value;
          else return false;
          count++;
          return true;
      }

      bool remove(string value) // removes a given value from the list, returns true if the name was found and false otherwise
      {
          for (size_t i = 0; i < this->count; i++)
          {
              int position = -1;
              if(this->items[i].compare(value) == 0)
              {
                  for (size_t j = i + 1; j < this->count; j++)
                  {
                      if(j >= this->count) 
                      {
                        items[j-1] = "";
                        return true;
                      }

                      items[j-1] = items[j]; 
                  }
                  
              }
          }
          return false;
      }

};