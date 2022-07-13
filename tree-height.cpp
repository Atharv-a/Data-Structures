// Tree height breadth first search implementation, given that atleast one root is present in the tree 


#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
#include <queue>
using namespace std;
#define ll long long
class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  ll root=0;
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if(parent_index==-1)
     root=child_index;
    else if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }


  int maxHeight = 1;
  queue<pair<Node*,ll>> a;
  Node *b=&nodes[root];
  a.push({b,1});

  while(!a.empty())
  {
     Node *t=a.front().first;
     if(t->children.size()!=0)
     {
          for(int j=0;j<t->children.size();j++)
           a.push({t->children[j],a.front().second+1});
     }
     a.pop();
      if(a.front().second>maxHeight)
      maxHeight=a.front().second;
  }
 
    
  std::cout << maxHeight <<"\n";
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
