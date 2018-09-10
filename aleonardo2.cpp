/*Austin Leonardo*/
/*September 4th, 2018 */
/*Lab 2 | Binary Search */
// g++ -std=c++11 -o a.exe source file.cpp
#include <iostream>
using namespace std;

//creating the nodes for the Binary Search Tree
 struct bstNode
 {
  int data;
     bstNode* left;
     bstNode* right; 
 };
//function inserts node with data
bstNode* createNode(int data)
{
    bstNode* newNode = new bstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}
//Inserts Nodes
//reason why it is not simply void is to point at main 
//function to refer to the `root`
bstNode* Insert(bstNode* root, int data)
{
    if (root == NULL) 
    {
        root = createNode(data);
        //return root;
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else 
    {
        root->right = Insert(root->right,data);
    }
    return root;
}
bool Search(bstNode* root, int data){
    if (root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data <= root->data){
        return Search(root->left, data);
    }
     else{
        return Search(root->right, data);
    }

}
int main(){
    bstNode* root = NULL;
    // root = Insert(root,15);
    // root = Insert(root,10);
    // root = Insert(root,20);
    // root = Insert(root,25);
    // root = Insert(root,8);
    // root = Insert(root,12);
    int total;
    cout << "How many integers do you have?\n";
    cin >> total;
    int number;
    cout << "Enter Number being searched:\n";
    cin >> number; 
    ///////////////////
    int elements;
    int array[total];
    int i = 0;
    cout << "What are you numbers?\n";
    cin >> elements;
    while(i<total -1){
        array[i] = elements;
        cin >> elements;
        Insert(root, array[elements]);
        i++;
    }
    for (int i = total - 1; i >= 0; i--) 
    cout << "Your numbers were:" << array[i] << endl;
    // for(int i = 0; i < total; i++)
	// {
	// 	cout << "Your numbers were:\n" << array << endl;
	// }
    if (Search(root,number) == true){
        cout << "Number found!\n";
    }
    else {
        cout << "Number not found\n";
    }
 }

