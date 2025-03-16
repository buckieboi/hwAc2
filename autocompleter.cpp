
// #include <vector>
// #include <string>
// #include "autocompleter.h" // need for recognizing h file.

// using namespace std;
// /*
// 	// For the mandatory running times below:
// 	// Assume that the length of every string is O(1). 

// 	public:

// 	private:
// 		// A helper class that stores a string and a frequency.
// 		class Entry
// 		{
// 			public:
// 				string s;
// 				int freq; 
// 		};

// 		// A helper class that implements a trie node.
// 		class Node
// 		{
// 			public:
// 				Node()
// 				{
// 					this->marked = false;
// 					for (int i = 0; i < 256; ++i)
// 						children[i] = nullptr; 
// 				}

// 				bool marked;
// 				vector<Entry> top;
// 				Node* children[256];
// 		};

// 		// Root of the trie-based data structure
// 		Node* root;

// 		// Number of marked nodes in the trie-based data structure
// 		int count;
// */
// // Creates a new Autocompleter with an empty dictionary.
// //
// // Must run in O(1) time.
// Autocompleter::Autocompleter(){
// 	Node* root = nullptr;
// }

// // Adds a string x to the dictionary.
// // If x is already in the dictionary, does nothing.
// //
// // Must run in O(1) time.
// void Autocompleter::insert(string x, int freq){
// 	// x already in dictionary
// 	//if str x not found in trie then return nothing.
// 	if(x == root->x){
// 		return;
// 	}
	
// 	// ptr at root node
// 	Node* arrow = root;
// 	//// for loop the given string and make nodes till the end of str
// 	for(int i = 0; i < x.length(); i++){
// 		//make nodes if empty
// 		if(arrow->children[x[i]]==nullptr){
// 			arrow->children[x[i]]= new node;
// 		}

// 		//move the arrow along the string letter nodes created
// 		arrow = arrow->children[x[i]]

// 		//call the update_top_list to update top 3 words.
// 		update_top_list(arrow.top,(x,freq));
// 	}
 
// 	//update the marked as true in the end of the created nodes of the word.
// 	arrow->marked= true;
// 	//update count for every word included to the dictionary trie(for size())
// 	count+=1;

// };




// //helper function that will update the top 3 frequent words when  a new word inserted.
// void update_top_list(node* arrow, x, freq){
// 	//so compare highest frequency for that prefix? 
// 	//whats putting the completed words in top?
// 	//so is insert() pushing into top when called? 
// 	// then update_top_list() will update top the most frequent words?
// 	// what parameters will update_top_list() take? (Node * new, vector<string> e)?
// 	//top needs to be sorted here before completions

// 	//pseudocode
// 	//if top list not full, add the word directly.

//     // Step 1: If top list is not full, add the word
//     if (node->top.size() < 3) {
//         node->top.push_back({x, freq});
        
//         // Sort manually in descending order based on frequency
//         for (int i = node->top.size() - 1; i > 0; i--) {
//             if (node->top[i].freq > node->top[i - 1].freq) {
//                 swap(node->top[i], node->top[i - 1]);
//             }
//         }
//         return;
//     }

//     // Step 2: Find the lowest frequency entry
//     int minIndex = 0;
//     for (int i = 1; i < 3; i++) {
//         if (node->top[i].freq < node->top[minIndex].freq) {
//             minIndex = i;
//         }
//     }

//     // Step 3: Replace if the new word has a higher frequency
//     if (freq > node->top[minIndex].freq) {
//         node->top[minIndex] = {x, freq};

//         // Sort again to maintain order
//         for (int i = 2; i > 0; i--) {
//             if (node->top[i].freq > node->top[i - 1].freq) {
//                 swap(node->top[i], node->top[i - 1]);
//             }
//         }
//     }
// }

// // Returns the number of strings in the dictionary.
// // 
// // Must run in O(1) time.
// int Autocompleter::size(){
// 	//so  we will run theru the dictionary and just like linear. 
// 	//we will just update count given in class?
// 	//are we getting the size of the string word given? or get the word size of the word2txt?
// 	//or are we to get the size of the trie tree we made? 
// 	//how do we do that without left or  right nodes like AVL trees?

// 	//size() is the count of word inserted into the trie dictionary

// 	//return the count //as its already updated every time insert() is used.
// 	return count;
// }












// // Fills the vector T with the three most-frequent completions of x.
// // If x has less than three completions, then 
// // T is filled with all completions of x.
// // The completions appear in T from most to least frequent.
// // 
// // Must run in O(1) time.
// void Autocompleter::completions(string x, vector<string> &T){

// 	// start at the root
// 	//ptr at root
// 	Node* arrow = root;
// 	// traverse trie flollowing x(move to the last node of x)
// 	//for character in x

// 	//so completions put top into T vector? 
// 	// why do we traverse the string here why not top? top is a vector? 
// 	//we traverse all the way to the end of the string, but what string? 
// 	//if the last element is not there in top then T vector will be empty? 
// 	for(int i = 0; i< characters[x[i]]; i++){
// 		if (arrow->characters[x[i]]==nullptr){
// 			T.clear();
// 			return;
// 		}
// 	}
	
// 		//check if ptr on child is null
// 		// clear T and return nothing
// 		//move ptr down to the next child
// 	//Fill T with top words from last node of x(already sorted when inserted)
// 	T = arrow.Top;
// }









