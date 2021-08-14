#include<iostream>
#include<stack>
#include<string>
using namespace std;
void SHOW(int** ADJ, int s)
{
char c;
cout << "\t";
for (int i = 0; i < s; i++)
cout << char('A' + i) << "\t";
cout << endl;
cout << endl;

for (int i = 0; i < s; i++)
{
cout << char('A' + i) << "|\t";
for (int j = 0; j < s; j++)
cout << ADJ[i][j] << "\t";
cout << endl;
}
}

void DFS(int** ADJ, int* data, int size)
{
bool* visited = new bool[size];
for (int i = 0; i < size; i++)
visited[i] = false;

stack<int> s;

s.push(0);

while (!s.empty())
{
int index = s.top();

if (!visited[index]) {
cout << data[index] << "\t";
visited[index] = true;
}

int i = 0;
for (; i < size; i++)
{
if (ADJ[index][i] != 0 && !visited[i])
{
s.push(i);
break;
}
}
if (i == size)
s.pop();

}

cout << endl;
}
int input(string m)
{
int data;
cout << m;
cin >> data;
return data;
}
int main()
{
int size = input("Enter NUMBER OF VERTICES : ");
int* data = new int[size];

for (int i = 0; i < size; i++)
data[i] = input("Enter value of vertice " + to_string(i + 1) + ": ");

int** adjacencyMatrix = new int*[size];

for (int i = 0; i < size; i++)

{
adjacencyMatrix[i] = new int[size];
for (int j = 0; j < size; j++)
adjacencyMatrix[i][j] = input("Enter value at VERTEX (" + to_string(i + 1) + ", " + to_string(j +

1) + "): ");
}

cout << endl;
cout << "Resultant Adjacency Matrix" << endl;
SHOW(adjacencyMatrix, size);

cout << endl;
cout << "Applying DFS : " << endl;
DFS(adjacencyMatrix, data, size);

system("pause");
}
