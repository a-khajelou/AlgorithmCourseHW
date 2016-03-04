#include <iostream>
#include "LinkedGraph.h"
#include "ArrayGraph.h"
#include "MarriageProblem.h"

using namespace std;

int main() {
    cout<<"Marriage Problem :\n======================"<<endl;
    testMarriageProblem();
    cout<<"\ntopological sort : \n==================="<<endl;
    testGraphTopologicalSort();
    cout<<"\ngraph traversal : \n==================="<<endl;
    testBfsAndDfs();
    return 0;
}