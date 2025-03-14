
#include <vector>
#include <string>
#include "autocompleter.h" // need for recognizing h file.

using namespace std;
/*
	// For the mandatory running times below:
	// Assume that the length of every string is O(1). 

	public:

	private:
		// A helper class that stores a string and a frequency.
		class Entry
		{
			public:
				string s;
				int freq; 
		};

		// A helper class that implements a trie node.
		class Node
		{
			public:
				Node()
				{
					this->marked = false;
					for (int i = 0; i < 256; ++i)
						children[i] = nullptr; 
				}

				bool marked;
				vector<Entry> top;
				Node* children[256];
		};

		// Root of the trie-based data structure
		Node* root;

		// Number of marked nodes in the trie-based data structure
		int count;
*/
// Creates a new Autocompleter with an empty dictionary.
//
// Must run in O(1) time.
Autocompleter(){
	Node* root = new nullptr;
}

// Adds a string x to the dictionary.
// If x is already in the dictionary, does nothing.
//
// Must run in O(1) time.
void Autocompleter::insert(string x, int freq){
	// x already in dictionary
	//if str x not found in trie then return nothing.
	if(x == root->x){
		return;
	}
	
	// ptr at root node
	Node* arrow = root;
	//// for loop the given string and make nodes till the end of str
	for(int i = 0; i < x.length; i++){
		//make nodes if empty
		if(arrow->children[x[i]]==nullptr){
			arrow->children[x[i]]= new node;
		}

		//move the arrow along the string letter nodes created
		arrow = arrow->children[x[i]]

		//call the update_top_list to update top 3 words.
		update_top_list(arrow.top,(x,freq))
	}
 
	//update the marked as true in the end.
	arrow->marked= true;
	//update count for every word included to the dictionary trie(for size())
	count+=1;

}

//helper function that will update the top 3 frequent words when  a new word inserted.
void update_top_list(){


}
// Returns the number of strings in the dictionary.
// 
// Must run in O(1) time.
int Autocompleter::size(){
	//so  we will run theru the dictionary and just like linear. 
	//we will just update count given in class?
	//are we getting the size of the string word given? or get the word size of the word2txt?
	//or are we to get the size of the trie tree we made? 
	//how do we do that without left or  right nodes like AVL trees?

	//size() is the count of word inserted into the trie dictionary

	//return the count //as its already updated every time insert() is used.
	return count;
}












// Fills the vector T with the three most-frequent completions of x.
// If x has less than three completions, then 
// T is filled with all completions of x.
// The completions appear in T from most to least frequent.
// 
// Must run in O(1) time.
void Autocompleter::completions(string x, vector<string> &T){
	//i dont know how to draw this out
	//what is a vector in this context? is it like an array that holds top x like [1,2,3]
	//is this just an if statement solve?
	//do i still need the helper function update_top_list() after u make completions? 
	//completions will fill top with completions of x?
	//what are completions when a word is matched and inserted?
	//what is stirng x doing here just to check completions and insreted in the vector T?
	//
	// start at the root
	//ptr at root
	Node* arrow = root;
	// traverse trie flollowing x(move to the last node of x)
	//for character in x
	for(int i = 0; i< characters[x[i]]; i++){
		if (arrow->characters[x[i]]==nullptr){
			T.clear();
			return;
		}
	}
	
		//check if ptr on child is null
		// clear T and return nothing
		//move ptr down to the next child
	//Fill T with top words from last node of x(already sorted when inserted)
	T = arrow.Top;
}









