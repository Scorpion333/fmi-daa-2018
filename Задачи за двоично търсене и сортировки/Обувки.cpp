#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 1048576;
int number_of_pairs, number_of_guests, pairs[MAX], guests[MAX];

int main() {    
    ios::sync_with_stdio(false);

    cin >> number_of_pairs >> number_of_guests;

    for (int i = 0; i < number_of_pairs; i++) {
        cin >> pairs[i];
    }
    for (int i = 0; i < number_of_guests; i++) {
        cin >> guests[i];
    }
    sort(pairs, pairs + number_of_pairs);
    sort(guests, guests + number_of_guests);

    int previous_given_pair_index = -1;
    int i = 0;
    for (i = 0; i < number_of_guests; i++) {
        int current_given_pair_index = upper_bound(pairs + previous_given_pair_index + 1,
                                                   pairs + number_of_pairs,
                                                   guests[i] - 1)             // -1 because upper_bound compares using op.<
                                     - pairs;
        
        if (current_given_pair_index == number_of_pairs) {      // true <==> there's nothing bigger than guests[i] - 1
                                                                //           in the rest of the pairs
            break;                                              // If there's no pair for the guy who needs size guests[i],
        }                                                       // there are no pairs for the bigger-footed guys too.
        previous_given_pair_index = current_given_pair_index;
    }
    cout << i << '\n';      // We have satisfied the first i people.
}