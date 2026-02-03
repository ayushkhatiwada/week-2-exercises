#include <memory>
#include <iostream>
#include <string>
#include "Network_Types.h"

using namespace std;


int main()
{
    // declare a Hub 
    Hub hub("Hub 1");

    // declare a Node
    Node node;

    // set Node's Hub
    node.setHub(std::make_shared<Hub>(hub));

    // add Node to Hub list
    hub.addNode(std::make_unique<Node>(node));


    return 0;
}
