#include <bits/stdc++.h>
#include <cstring>
#include <windows.h>
#define MAX 7
using namespace std;

bool isSafe(int row, int col, int m[][MAX],
                 int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 ||
                  col == n || visited[row][col]
                           || m[row][col] == 0)
        return false;
    return true;
}

void printPathUtil(int row, int col, int m[][MAX],
              int n, string& path, vector<string>&
               possiblePaths, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1
               || col == n || visited[row][col]
                           || m[row][col] == 0)
        return;

    if (row == n - 1 && col == n - 1) {
        possiblePaths.push_back(path);
        return;
    }

    visited[row][col] = true;

    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n,
                 path, possiblePaths, visited);
        path.erase(path.end()-1);
    }

    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n,
                   path, possiblePaths, visited);
        path.erase(path.end()-1);
    }

    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n,
                   path, possiblePaths, visited);
        path.erase(path.end()-1);
    }

    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n,
               path, possiblePaths, visited);
        path.erase(path.end()-1);
    }

    visited[row][col] = false;
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> possiblePaths;
    string path;
    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));

    printPathUtil(0, 0, m, n, path,
                      possiblePaths, visited);

    return possiblePaths;
}

void display(int m[][MAX],int n)
{
    int x=178,y=176;
    system("CLS");
    cout<<"\n\n\tMAZE :   "<<(char)x<<(char)x<<" are Walls and "<<(char)y<<(char)y<<" are Spaces\n\n\t";
    cout<<"Entry ->";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(m[i][j] == 0)
                cout<<(char)x<<(char)x;
            else
                cout<<(char)y<<(char)y;
            cout<<" ";
        }
        if(i==n-1)
            cout<<"-> Exit";
        cout<<"\n\n\t\t";
    }
}

int main()
{
    int choice,z,a,le=100,b,e,f;
    char c,rm;
    string s;
    vector <string> path;

    cout<<"\n\n\n\t|\\  /|    /\\    ----/  |----        |---- |---| |   \\      / |---- |---|"<<endl;
    Sleep(500);
    cout<<"\t| \\/ |   /  \\      /   |__    ___   |____ |   | |    \\    /  |___  |___|"<<endl;
    Sleep(500);
    cout<<"\t|    |  /----\\    /    |                | |   | |     \\  /   |     | \\"<<endl;
    Sleep(500);
    cout<<"\t|    | /      \\  /____ |_____       ____| |___| |___   \\/    |____ |  \\_"<<endl;
    Sleep(500);

    r:

    int d[MAX][MAX], m[MAX][MAX] = { { 1, 0, 0, 0, 0, 0, 0 },
                                     { 1, 1, 1, 1, 1, 0, 0 },
                                     { 1, 1, 1, 0, 1, 0, 0 },
                                     { 0, 1, 0, 0, 1, 0, 0 },
                                     { 0, 1, 0, 0, 1, 1, 1 },
                                     { 0, 1, 0, 0, 1, 0, 1 },
                                     { 0, 1, 1, 1, 1, 0, 1 } };
    int n = sizeof(m) / sizeof(m[0]);

    cout<<"\n\n\tChoice 1 :\tEnter your own Maze";
    cout<<"\n\n\tChoice 2 :\tGenerate a Randomized Maze";
    cout<<"\n\n\tChoice 3 :\tExit Game";
    cout<<"\n\n\tEnter your Choice : ";
    cin>>z;
    cout<<"\n\t";
    switch(z)
    {
        case 1: for(b=0; b<n; b++){
                    for(e=0; e<n; e++){
                        cin>>d[b][e];
                        m[b][e] = d[b][e];
                    }
                    cout<<"\n\t";
                }
        break;

        case 2: //It will take the predefined maze
        break;

        case 3: goto last;

        default: cout<<"\n\n\tInvalid Choice";
    }
    l:
        system("CLS");
    cout<<"\n\n\tChoice 1 :\tDisplay Maze";
    cout<<"\n\n\tChoice 2 :\tCheck if my entered Path is correct?";
    cout<<"\n\n\tChoice 3 :\tFind all Possible Paths in The Maze";
    cout<<"\n\n\tChoice 4 :\tShortest Route out of Maze";
    cout<<"\n\n\tChoice 5 :\tExit Game";
    cout<<"\n\n\tEnter your Choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1: display(m,n);
        break;

        case 2: cout<<"\n\tEnter your path : ";
                cin>>s;
                path=printPath(m, n);
                if (path.empty())
                    cout<<"\n\n\tNo Possible Paths\n\n\tTherefore,";
                if (find(path.begin(), path.end(), s) != path.end())
                    cout<<"\n\n\tIt is a Valid Path";
                else
                    cout<<"\n\n\tIt is not a Valid Path";
        break;

        case 3: path=printPath(m, n);
                for (int i = 0; i < path.size(); i++)
                    cout<<"\n\tPath "<< i+1 << " " << path[i] << " ";
        break;

        case 4: path = printPath(m,n);
                if (path.empty())
                    cout<<"\n\n\tNo Possible Paths\n\n\tTherefore,";
                else{
                    for (int i = 0; i < path.size(); i++)
                        {
                            if(le>path[i].length())
                                {a=i;   le=path[i].length();}
                        }
                        cout<<"\n\n\tShortest Path is : "<<path[a];
                    }
        break;

        case 5: goto last;
        default: cout<<"Invalid";
        break;
    }

    cout<<"\n\n\tDo You Want To Perform more operations of the same Maze[ Y / N] : ";
    cin>>c;
    if(tolower(c) == 'y')
    {
        system("CLS");
        goto l;
    }

    cout<<"\n\n\tDo You Want To Regenerate Maze [ Y / N] : ";
    cin>>rm;
    if(tolower(rm) == 'y')
    {
        system("CLS");
        goto r;
    }

    cout<<"\n\n\tDo You Want To Continue [ Y / N] : ";
    cin>>rm;
    if(tolower(rm) == 'y')
    {
        system("CLS");
        goto r;
    }
    last:
    return 0;
}
