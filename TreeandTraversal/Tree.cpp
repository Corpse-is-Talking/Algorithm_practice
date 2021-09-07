#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:

	Node* left = nullptr;
	Node* right = nullptr;
	char data;
	Node(char g_data)
	{
		data = g_data;
	}
};
void Postorder(Node* root)
{
	if (root == nullptr)
		return;
	
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data ;

}
void Predorder(Node* root)
{
	if (root == nullptr)
		return;
	cout << root->data ;
	Predorder(root->left);
	Predorder(root->right);

}
void Inorder(Node* root)
{
	if (root == nullptr)
		return;
	Inorder(root->left);
	cout << root->data ;
	Inorder(root->right);
}
int main()
{
	int n_node;
	cin >> n_node;
	vector<Node*> vec;
	for (char i = 'A'; i < 'A' + n_node; i++)
	{
		Node* temp = new Node(i);
		vec.push_back(temp);

	}
	for (int i = 0; i < n_node; i++)
	{
		char cur_node, left_c, right_c;
		cin >> cur_node >> left_c >> right_c;

		Node * cur_point = vec[cur_node - 'A'];
		if(left_c!='.')
			cur_point->left = vec[left_c - 'A'];
		if (right_c != '.')
			cur_point->right = vec[right_c - 'A'];

	}
	Node* root = vec[0];
	Predorder(root);
	cout << "\n";
	Inorder(root);
	cout << "\n";
	Postorder(root);


}