#include <iomanip>
#include <string>
#include <map>
#include <utility>
#include "name.hpp"


std::pair<const Name, int> get_entry();
void list_entries(std::map<Name, int>& m);
void list_entries(std::map<Name, int, std::greater<Name> >& m);

int main(){
  name<Name, int> friends;
  cout << "friends empty: " << (friends.empty() ? "Y" : "N") << endl;
  //map creation and initialization c++11
  //map<Name, int> friends{{make_pair(Name("Draco", "Malfoy"), 25)}, {make_pair(Name("Cho", "Chang"), 54)}};
  //insert Entry
  friends.insert(make_pair(Name("Harry", "Potter"), 25));
  friends.insert(make_pair(Name("Draco", "Malfoy"), 11));
  friends.insert(make_pair(Name("Cho", "Chang"), 10));
  friends.insert(make_pair(Name("Oliver", "Wood"), 9));
  friends.insert(make_pair(Name("Fleur", "Delacour"), 8));
  friends.insert(make_pair(Name("Cedric", "Diggory"), 7));
  friends.insert(make_pair(Name("Fred", "Weasley"), 6));
  friends.insert(make_pair(Name("George", "Weasley"), 6));
  friends.insert(make_pair(Name("Neville", "Longbottom"), 5));
  friends.insert(make_pair(Name("Luna", "Lovegood"), 4));
  friends.insert(make_pair(Name("Rubeus", "Hagrid"), 3));
  friends.insert(make_pair(Name("Hermione", "Granger"), 2));
  friends.insert(make_pair(Name("Ron", "Weasley"), 1));

  cout << endl << "intial contents of friends[" << friends.size() <<"]:" endl;
  list_entries(friends);
  map<Name, int> friends_copy(friends);
  cout << "intial contents of friends copy [" << friends_copy.size() << "]" << endl;
  list_entries(friends_copy);

  char answer = 'y';
  cout << endl << endl << "adding an Entry: ";
  cin >> answer;
  cout << endl;
  while(answer== 'y'){
    pair<const Name, int> entry = get_entry();
    map<Name, int>::iterator it = friends.find(entry.first);
    if(it == friends.end()){
      friends.insert(get_entry());
    } else {
      //ask to update
      cout << "Entry(" << entry.first << " , " << entry.second << ") is already present, do you want to update (y or n)?: "
      cin >> answer;
      cout << endl;
      if(answer == 'y')
        it->second = entry.second;
    }
    cout << "adding an Entry: "
    cin >> answer;
    cout << endl;
  }
  cout << "contents of friends[" << friends.size() << "]: " << endl;
  list_entries(friends);

  //access
  Name key = Name("Cho", "Chang");
  cout << key << " karma is: " << friends[key] << endl;
  friends[key] = 39;
  cout << key << "karma is: " << friends.at(key) << endl;

  if(friends.erase(key))
    cout << key << " was removed bitch" << endl;
  else
    cout << key << " was not found" << endl;

  friends.erase(++friends.begin(), --friends.end());
  cout << "contents of friends [" << friends.size() << "]: " << endl;
  list_entries(friends);

  map<Name, int, greater<Name> > friends2;
  friends2.insert(make_pair(Name("Harry", "Potter"), 25));
  friends2.insert(make_pair(Name("Draco", "Malfoy"), 11));
  friends2.insert(make_pair(Name("Cho", "Chang"), 10));
  friends2.insert(make_pair(Name("Oliver", "Wood"), 9));
  friends2.insert(make_pair(Name("Fleur", "Delacour"), 8));
  friends2.insert(make_pair(Name("Cedric", "Diggory"), 7));
  friends2.insert(make_pair(Name("Fred", "Weasley"), 6));
  friends2.insert(make_pair(Name("George", "Weasley"), 6));
  friends2.insert(make_pair(Name("Neville", "Longbottom"), 5));
  friends2.insert(make_pair(Name("Luna", "Lovegood"), 4));
  friends2.insert(make_pair(Name("Rubeus", "Hagrid"), 3));
  friends2.insert(make_pair(Name("Hermione", "Granger"), 2));
  friends2.insert(make_pair(Name("Ron", "Weasley"), 1));
  cout << "intial contents of friends2 [" << friends2.size() << "]: " endl;
  list_entries(friends2);
}
 std::pair<const Name, int> get_entry() {
   string name1;
   string name2;
   int karma;

   cout << "Enter first and second names followed by the karma: "
 }

 void list_entries(map<Name, int>& m) {
   for(std::map<Name, int>::iterator it = m.begin(); it != m.end(); ++it) {
     cout << left << setw(30) <<it->first << right << setw(4) << it->second <<endl;
   }
   cout << endl << endl;
 }
 void list_entries(std::map<Name, int, std::greater<Name> >& m) {

 }
