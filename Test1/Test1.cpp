#include <string>
class Student
{
private:
    string name;
    double courseAverage;
public:
    // set the 'name' of this student object to 'data' 
    void setName(string data)
    {
        this->name = data;
    }
    // Return this student object's 'name'
    string getName()
    {
        return this->name;
    }
    Student()
    {
        this->name = "tbd";
        this->courseAverage = 0.0;
    }
};

int main(int argc, char const *argv[])
{
    Student studentList [10];
    return 0;
}

