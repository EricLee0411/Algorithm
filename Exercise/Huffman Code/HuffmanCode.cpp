//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//int main(){
//	string s;
//	cin>>s;
//	vector<int> timeofletters;
//	vector<char> letters;
//	for(int i=0;i<s.size();i++){
//		int time=1;
//		for(int j=i+1;j<s.size();j++){
//			if(s[i]==s[j]&&s[i]!='0'&&s[j]!='0'){
//				time++;
//				s[j]='0';
//			}
//		}
//		if(s[i]!='0'){
//			timeofletters.push_back(time);//cout<<time<<" ";
//			letters.push_back(s[i]);
//		}
//	}
//	for(int i=0;i<timeofletters.size()-1;i++){
//		for(int j=i+1;j<timeofletters.size();j++){
//			if(timeofletters[i]>timeofletters[j]){
//				int temp=timeofletters[i];
//				timeofletters[i]=timeofletters[j];
//				timeofletters[j]=temp;
//				char temp1=letters[i];
//				letters[i]=letters[j];
//				letters[j]=temp1;
//			}
//		}
//	}
////	for(int i=0;i<letters.size();i++) cout<<letters[i]<<" "<<timeofletters[i]<<endl;
//	vector<string> reversehuffman(letters.size());
//	int tmp=0;
//	if(timeofletters.size()==1){
//		reversehuffman[0]+="1";
//	}
//	else{
//		for(int i=0;i<timeofletters.size()-1;i++){
//			tmp+=timeofletters[i];
//			if(tmp>=timeofletters[i+1]){
//				for(int j=0;j<i+1;j++) reversehuffman[j]+="1";
//				reversehuffman[i+1]+="0";
//			}
//			else if(tmp<timeofletters[i+1]){
//				for(int j=0;j<i+1;j++) reversehuffman[j]+="0";
//				reversehuffman[i+1]+="1";
//			}
//		}
//	}
//	
//	for(int i=0;i<reversehuffman.size();i++) {
//		reverse(reversehuffman[i].begin(),reversehuffman[i].end());
////		cout<<reversehuffman[i]<<endl;	
//	}
//	vector<int> decimalofhuffman(letters.size());
//	for(int i=0;i<letters.size();i++) {
//		for(int j=0;j<reversehuffman[i].size();j++) {
//			decimalofhuffman[i]+=(int(reversehuffman[i][j])-48)*pow(2,reversehuffman[i].size()-j-1);
//		}	
////		cout<<decimalofhuffman[i]<<endl;
//	}
//	for(int i=0;i<decimalofhuffman.size()-1;i++) {
//		for(int j=i+1;j<decimalofhuffman.size();j++) {
////			if(reversehuffman[i].size()>reversehuffman[j].size()){
////					char temp1=letters[i];
////					letters[i]=letters[j];
////					letters[j]=temp1;
////					string temp=reversehuffman[i];
////					reversehuffman[i]=reversehuffman[j];
////					reversehuffman[j]=temp;
////					int temp2=decimalofhuffman[i];
////					decimalofhuffman[i]=decimalofhuffman[j];
////					decimalofhuffman[j]=temp2;
////			}
////			else if(reversehuffman[i].size()==reversehuffman[j].size()){
////				if(decimalofhuffman[i]>decimalofhuffman[j]){
////					char temp1=letters[i];
////					letters[i]=letters[j];
////					letters[j]=temp1;
////					string temp=reversehuffman[i];
////					reversehuffman[i]=reversehuffman[j];
////					reversehuffman[j]=temp;
////				}
////			}
//			if(decimalofhuffman[i]>decimalofhuffman[j]){
//				char temp1=letters[i];
//				letters[i]=letters[j];
//				letters[j]=temp1;
//				string temp=reversehuffman[i];
//				reversehuffman[i]=reversehuffman[j];
//				reversehuffman[j]=temp;
//			}
//			else if(decimalofhuffman[i]==decimalofhuffman[j]){
//				if(reversehuffman[i].size()>reversehuffman[j].size()){
//					char temp1=letters[i];
//					letters[i]=letters[j];
//					letters[j]=temp1;
//					string temp=reversehuffman[i];
//					reversehuffman[i]=reversehuffman[j];
//					reversehuffman[j]=temp;
//				}
//			}
//		}	
//	}
////	for(int i=0;i<reversehuffman.size();i++) cout<<reversehuffman[i]<<endl;	
//	for(int i=0;i<letters.size();i++){
//		cout<<letters[i]<<":"<<reversehuffman[i]<<endl;
//	}
//}

// C++ program for Huffman Coding
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
vector<char> letter;
vector<string> hc;
// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {

	// One of the input characters
	char data;

	// Frequency of the character
	unsigned freq;

	// Left and right child of this node
	struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of
// min-heap (or Huffman tree) nodes
struct MinHeap {            

	// Current size of min heap
	unsigned size;

	// capacity of min heap
	unsigned capacity;

	// Attay of minheap node pointers
	struct MinHeapNode** array;
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq)
{
	struct MinHeapNode* temp
		= (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}

// A utility function to create
// a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)

{

	struct MinHeap* minHeap
		= (struct MinHeap*)malloc(sizeof(struct MinHeap));

	// current size is 0
	minHeap->size = 0;

	minHeap->capacity = capacity;

	minHeap->array
		= (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

// A utility function to
// swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,
					struct MinHeapNode** b)

{

	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx)

{

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

// A utility function to check
// if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{

	return (minHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0]
		= minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}

// A utility function to insert
// a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap,
				struct MinHeapNode* minHeapNode)

{

	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minHeap->array[i] = minHeapNode;
}

// A standard function to build min heap
void buildMinHeap(struct MinHeap* minHeap)

{

	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout<< arr[i];

	cout<<"\n";
}

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)

{

	return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)

{

	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)

{
	struct MinHeapNode *left, *right, *top;

	// Step 1: Create a min heap of capacity
	// equal to size. Initially, there are
	// modes equal to size.
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	// Iterate while size of heap doesn't become 1
	while (!isSizeOne(minHeap)) {

		// Step 2: Extract the two minimum
		// freq items from min heap
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		// Step 3: Create a new internal
		// node with frequency equal to the
		// sum of the two nodes frequencies.
		// Make the two extracted node as
		// left and right children of this new node.
		// Add this node to the min heap
		// '$' is a special value for internal nodes, not used
		top = newNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}

	// Step 4: The remaining node is the
	// root node and the tree is complete.
	return extractMin(minHeap);
}

void myprint(vector<char> l,int ls,vector<string> h,int hs){
	vector<int> decimalofhuffman(hs);
	for(int i=0;i<ls;i++) {
		for(int j=0;j<h[i].size();j++) {
			decimalofhuffman[i]+=(int(h[i][j])-48)*pow(2,h[i].size()-j-1);
		}	
//		cout<<decimalofhuffman[i]<<endl;
	}
	for(int i=0;i<decimalofhuffman.size()-1;i++) {
		for(int j=i+1;j<decimalofhuffman.size();j++) {
//			if(decimalofhuffman[i]>decimalofhuffman[j]){
//				char temp1=l[i];
//				l[i]=l[j];
//				l[j]=temp1;
//				string temp=h[i];
//				h[i]=h[j];
//				h[j]=temp;
//			}
//			else if(decimalofhuffman[i]==decimalofhuffman[j]){
//				if(h[i].size()>h[j].size()){
//					char temp1=l[i];
//					l[i]=l[j];
//					l[j]=temp1;
//					string temp=h[i];
//					h[i]=h[j];
//					h[j]=temp;
//				}
//			}
			if(h[i].size()>h[j].size()){
					char temp1=l[i];
					l[i]=l[j];
					l[j]=temp1;
					string temp=h[i];
					h[i]=h[j];
					h[j]=temp;
					int temp2=decimalofhuffman[i];
					decimalofhuffman[i]=decimalofhuffman[j];
					decimalofhuffman[j]=temp2;
			}
			else if(h[i].size()==h[j].size()){
				if(decimalofhuffman[i]>decimalofhuffman[j]){
					char temp1=l[i];
					l[i]=l[j];
					l[j]=temp1;
					string temp=h[i];
					h[i]=h[j];
					h[j]=temp;
					int temp2=decimalofhuffman[i];
					decimalofhuffman[i]=decimalofhuffman[j];
					decimalofhuffman[j]=temp2;
				}
			}
		}	
	}
	for (int i = 0; i < ls; i++)
		cout<<l[i]<<":"<<h[i]<<endl;
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(struct MinHeapNode* root, int arr[], int top)

{

	// Assign 0 to left edge and recur
	if (root->left) {

		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	// Assign 1 to right edge and recur
	if (root->right) {

		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	// If this is a leaf node, then
	// it contains one of the input
	// characters, print the character
	// and its code from arr[]
	if (isLeaf(root)) {

//		cout<< root->data <<": ";
		letter.push_back(root->data);
//		printArr(arr, top);
		int i;
		string s;
		for (i = 0; i < top; ++i)
			s+=char(arr[i]+48);
		hc.push_back(s);
	}
}

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)

{
	// Construct Huffman Tree
	struct MinHeapNode* root
		= buildHuffmanTree(data, freq, size);

	// Print Huffman codes using
	// the Huffman tree built above
	int arr[MAX_TREE_HT], top = 0;

	printCodes(root, arr, top);
}

// Driver code
int main()
{
	string s;
	cin>>s;
	int temp=0;
	string t=s;
	for(int i=0;i<t.size();i++){
		for(int j=i+1;j<t.size();j++){
			if(t[i]==t[j]&&t[i]!='0'&&t[j]!='0'){
				temp++;
				t[j]='0';
			} 
		}	
	}
	char arr[s.size()-temp];
	int freq[s.size()-temp];
	int k=0;
	for(int i=0;i<s.size();i++){
		int time=1;
		for(int j=i+1;j<s.size();j++){
			if(s[i]==s[j]&&s[i]!='0'&&s[j]!='0'){
				time++;
				s[j]='0';
			}
		}
		if(s[i]!='0'){
			freq[k]=time;//cout<<time<<" ";
			arr[k]=s[i];
			k++;
		}
	}
//	for(int i=0;i<sizeof(arr);i++){
//		cout<<arr[i]<<" "<<freq[i]<<endl;
//	}
	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);
//	for (int i = 0; i < letter.size(); i++)
//		cout<<letter[i]<<" "<<hc[i]<<endl;
//	cout<<letter.size()<<" "<<hc.size()<<endl;
	myprint(letter,letter.size(),hc,hc.size());
	return 0;
}

