#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> v1;
   vector<int> v2(100,7);

   cout << "v1 size: " << v1.size() << " and capacity: " << v1.capacity() << endl;
   cout << "v1 empty: " << (v1.empty() ? "Y" : "N") << endl;
   cout << "v2 size: " << v2.size() << " and capacity: " << v2.capacity() << endl;
   v1.erase(remove(v1.begin(), v1.end(), 2), end(v1));
   v1.erase(remove(v1.begin(), v1.end(), 0), end(v1));
   cout << "v1 size: " << v1.size() << " and capacity: " << v1.capacity() << endl;
  return 0;
}
