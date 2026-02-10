#include <memory>
#include <iostream>

/**
 * A simple class which just reports when it is created (constructor) and when it is destroyed (destructor).
*/
class Reporter
{
    public: 
    Reporter(std::string id_string) : ID(id_string)
    {
        std::cout << "Creating Reporter Object with ID: " << ID << std::endl;
    }

    ~Reporter()
    {
        std::cout << "Destroying Reporter Object with ID: " << ID << std::endl;
    }

    private:
    std::string ID;
};


int main()
{
    Reporter* reporter1 = new Reporter("reporter1_raw_pointer");

    std::unique_ptr<Reporter> reporter2 = std::make_unique<Reporter>("reporter2_unique_pointer");
    
    return 0;
}
