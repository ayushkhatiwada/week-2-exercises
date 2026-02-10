#include <memory>
#include <string>
#include "Network_Types.h"

using namespace std;


int main()
{
    // declare a Hub 
    std::shared_ptr<Hub> hub1 = std::make_shared<Hub>("Hub 1");
    std::weak_ptr<Hub> hub1_weak_ptr = hub1;

    // declare a Node
    std::unique_ptr<Node> node1 = std::make_unique<Node>();

    // set Node's Hub
    node1->setHub(hub1_weak_ptr);

    // add Node to Hub list
    hub1->addNode(node1);


    return 0;
}
