#include<bits/stdc++.h>
using namespace std;
struct node {
    int count;
    node *next[26];
    node()
    {
        count = 0;
        int i;
        for(i=0; i<26; i++)
        {
            next[i] = NULL;
        }
    }

};
node *root = new node();
void insert(string s)
{
    node *current = root;
    int i;
    for(i=0; i<s.length(); i++)
    {
        if(current->next[s[i] - 'a'] == NULL)
        {
            current->next[s[i] - 'a'] = new node();
        }
        ++current->count;
        current = current->next[s[i] - 'a'];
    }
}
int searchQuery(string s)
{
    node *current = root;
    int i;
    for(i=0; i<s.length(); i++)
    {
        if(current->next[s[i] - 'a'] == NULL)
        {
            return 0;
        }
        current = current->next[s[i] - 'a'];
    }
    return current->count;
}
int main()
{
    insert("abcd");
    insert("abacd");
    insert("abccd");
    insert("aabcd");
    cout<<searchQuery("aabc")<<endl;

    cout<<searchQuery("dabc")<<endl;

    cout<<searchQuery("abcc")<<endl;

    cout<<searchQuery("ab")<<endl; 

}
