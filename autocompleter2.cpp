#include <vector>
#include <string>
#include "autocompleter.h" // need for recognizing h file.

using namespace std;

// Creates a new Autocompleter with an empty dictionary.
// Must run in O(1) time.
Autocompleter::Autocompleter(){
    root = new Node();
    count = 0;
}

// Adds a string x to the dictionary.
// If x is already in the dictionary, does nothing.
// Must run in O(1) time.
void Autocompleter::insert(string x, int freq){
    // Define a lambda to update the top list (has access to private members).
    auto update_top_list = [&](Node* node, const string &x, int freq) {
        if (node->top.size() < 3) {
            node->top.push_back({x, freq});
            for (size_t i = node->top.size() - 1; i > 0; i--) {
                if (node->top[i].freq > node->top[i - 1].freq) {
                    swap(node->top[i], node->top[i - 1]);
                }
            }
            return;
        }
        int minIndex = 0;
        for (int i = 1; i < 3; i++) {
            if (node->top[i].freq < node->top[minIndex].freq) {
                minIndex = i;
            }
        }
        if (freq > node->top[minIndex].freq) {
            node->top[minIndex] = {x, freq};
            for (int i = 2; i > 0; i--) {
                if (node->top[i].freq > node->top[i - 1].freq) {
                    swap(node->top[i], node->top[i - 1]);
                }
            }
        }
    };

    // Update the root's top list (for the empty prefix).
    update_top_list(root, x, freq);

    // Traverse the trie from the root.
    Node* arrow = root;
    for (int i = 0; i < x.length(); i++){
        if (arrow->children[(unsigned char)x[i]] == nullptr){
            arrow->children[(unsigned char)x[i]] = new Node();
        }
        arrow = arrow->children[(unsigned char)x[i]];
        update_top_list(arrow, x, freq);
    }
    arrow->marked = true;
    count += 1;
}

// Returns the number of strings in the dictionary.
// Must run in O(1) time.
int Autocompleter::size(){
    return count;
}

// Fills the vector T with the three most-frequent completions of x.
// If x has less than three completions, then 
// T is filled with all completions of x.
// The completions appear in T from most to least frequent.
// Must run in O(1) time.
void Autocompleter::completions(string x, vector<string> &T){
    Node* arrow = root;
    for (int i = 0; i < x.length(); i++){
        if (arrow->children[(unsigned char)x[i]] == nullptr){
            T.clear();
            return;
        }
        arrow = arrow->children[(unsigned char)x[i]];
    }
    T.clear();
    for (size_t i = 0; i < arrow->top.size(); i++){
        T.push_back(arrow->top[i].s);
    }
}
