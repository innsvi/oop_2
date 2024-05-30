//Опис класу: Рядки: значення рядка (символи), конструктор за умовчанням, конструктор з параметрами, конструктор копіювання, метод обчислення довжини рядка, метод отримання значення рядка, перевантаження операторів додавання, вирахування

//Завдання: Описати клас, три об'єкти CS1, CS2, CS3, використовуючи різні конструктори; "вирахувати" з об’єкта CS3 символ '0'; "скласти" об'єкти CS2, CS3 і результат"помістити" до об’єкта CS1; результат дій вивести на екран


#include <iostream>

class Line{
    private:
        char *cstring;

        Line(const char* s, std::size_t n) // to avoid counting twice
        {
            cstring = new char[n];            // allocate
            memset(cstring, 0, n);            // zero out
            std::memcpy(cstring, s, n); // populate
        }
    public:
        explicit Line(const char* s = "")
        : Line(s, std::strlen(s) + 1)
        {
        }

        ~Line() // I. destructor
        {
            delete[] cstring; // deallocate
        }

        Line(const Line& other) // II. copy constructor
        : Line(other.cstring){ }

        Line& operator=(const Line& other) // III. copy assignment
        {
            if (this == &other)
                return *this;
    
            std::size_t n = std::strlen(other.cstring) + 1;
            char* new_cstring = new char[n];            // allocate
            std::memcpy(new_cstring, other.cstring, n); // populate
            delete[] cstring;                           // deallocate
            cstring = new_cstring;
    
            return *this;
        }

        operator const char* () const // accessor
        {
            return cstring;
        }

        int getLength(){
            return strlen(cstring);
        }
        char* getLine(){
            return cstring;
        }
        void print(){
            std::cout << cstring << std::endl;
        }
        Line operator+(const Line &line){
            char *newLine = new char[strlen(this->cstring) + strlen(line.cstring) + 1];
            strcpy(newLine, this->cstring);
            strcat(newLine, line.cstring);
            return Line(newLine);
        }
        Line operator-(const char &c){
            char *newLine = new char[strlen(this->cstring) + 1];
            int j = 0;
            for(int i = 0; i < strlen(this->cstring); i++){
                if(this->cstring[i] != c){
                    newLine[j++] = this->cstring[i];
                }
            }
            newLine[j] = '\0';
            return Line(newLine);
        }
};

int main(){
    Line CS1;
    Line CS2("CS20");
    Line CS3(CS2);
    std::cout << "CS1.getLength: " << CS1.getLength() << std::endl;
    std::cout << "CS2.getLength: " << CS2.getLength() << std::endl;
    std::cout << "CS2: " << CS2 << std::endl;
    std::cout << "CS3: " << CS3.getLine() << std::endl;
    CS3.print();
    //"вирахувати" з об’єкта CS3 символ '0'
    CS3 = CS3 - '0';
    CS3.print();
    // "скласти" об'єкти CS2, CS3 і результат"помістити" до об’єкта CS1;
    CS1 = CS2 + CS3;
    CS1.print();
    return 0;
}