#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // The initial value of to depends on whether n is odd or even
   int from = 0, to = 1, aux = 2, candidate = 1, move = 0;
   
   if(n % 2 == 0) {
       int temp = to;
       to = aux;
       aux = temp;
   }
   
    // Initialize the towers
    for(int i = n + 1; i >= 1; --i) {
      t[0].push_back(i);
      //t[1].push_back(n+1);
      //t[2].push_back(n+1);
    }
   
	t[1].push_back(n+1);
    t[2].push_back(n+1);
   
   while (t[1].size() < n + 1) { // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
      
      // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      t[to].push_back(t[from].back());
      t[from].resize(t[from].size() - 1);
     
      int fromCA = (to + 1) % 3;
      int fromCB = (to + 2) % 3;
      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      if (t[fromCA].back() < t[fromCB].back())
         from = fromCA;
      else
         from = fromCB;
         
      // candidate = the ring on top of the t[from] tower
      candidate = t[from].back();
    
      int toCA = (from + 1) % 3;
      int toCB = (from + 2) % 3;
      // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
      // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
      if (candidate < t[toCA].back() && candidate < t[toCB].back()) {
      	int tempMove = move + 1;

      	if (n % 2 == 1) {
      		to = toCA;
      	} else {
      		to = toCB;
      	}
      	
      } else if (candidate < t[toCA].back()) {
      	to = toCA;
       } else if (candidate < t[toCB].back()) {
      	to = toCB;
      }

   }
   
   return 0;
}
