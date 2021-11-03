// longestSubstring.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;



//************************************************************************************************************************************************************
/*
Method 1 (Simple : O(n3)) : We can consider all substrings one by one and check for each
substring whether it contains all unique characters or not.There will be n * (n + 1) / 2 substrings.
Whether a substring contains all unique characters or not can be checked in linear time by scanning it from left to right 
and keeping a map of visited characters.Time complexity of this solution would be O(n ^ 3).
*/

// C++ program to find the length of the longest substring
// without repeating characters

// This functionr eturns true if all characters in str[i..j]
// are distinct, otherwise returns false
bool areDistinct(string str, int i, int j)
{

    // Note : Default values in visited are false
    vector<bool> visited(26);

    for (int k = i; k <= j; k++)
    {
       // cout << "k =" << k<< endl;

        if (visited[str[k] - 'a'] == true)
        {
            cout << "visited true [str[k]  "<<str[k]  << endl;
            return false;
            
        }
        cout << "visited  is NOT true [str[k]"<< str[k] << endl;
//visited[str[k] - 'a'] = true;
    }
    
    return true;
}

// Returns length of the longest substring
// with all distinct characters.
int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int res = 0; // result

    //for every character in a string check
    for (int i = 0; i < n; i++)
    {
        cout << "Unique for i = " << i << endl;
        for (int j = i; j < n; j++)
        {
            cout << "Unique for j = " << j << endl;
            if (areDistinct(str, i, j))
            {
                cout << "aredistinct " << endl;
                res = max(res, j - i + 1);

            }
        }
    }
    return res;
}

//***************************************************************************************************************************************************************
	

/*



for (int k = 0; k < strs[i].size(); k++)
        {
            string temp = strs[i];
            if (prefix[k] != temp[k])
            {
                prefix.erase(k);

            }


        }

*/









string longestCommonPrefix(vector<string>& strs)
{

   
    string first = strs[0];
    string temp;
    int len = strs[0].length();

    for (int i = 0; i < strs.size(); i++)
    {
        if (len > strs[i].length()) len = strs[i].length();
        

    }
  
    if (len == 0) return  first.erase(0);
    first.erase(len);

    for (int i = 1; i < strs.size(); i++)
    {
        temp = strs[i];
      
        for (int k = 0; k < len; k++)
        {       
            if (first[k] != temp[k] && k == 0)return first.erase(0);
            if (first[k] != temp[k])
            {
                
               first.erase(k);
              len--;
               //cout << "first.erase k " << k << endl;
               //cout << "first " << first << endl;
                
             
            }
            //
        }

        
    }
    return first;

}


// Driver code
	int main()
	{
       // string str = "aacdef";
		//cout << "The input string is " << str << endl;
		//int len = longestUniqueSubsttr(str);
       // cout << "The length of the longest non-repeating character substring is " << len << endl;
            
       // cout << areDistinct(str, 0, 3);

     // vector<string> strs{ "flower", "flow", "flight" };
     //vector<string> strs { "ab", "a" };
     //vector<string> strs{ "a", "b" };
     //vector<string> strs{ "aaa", "aa", "aaa" };
      // vector<string> strs{ "abca", "aba", "aaab" };

       //vector<string> strs{ "dog", "racecar", "car" };
       
      
      
        cout << "LCP " << longestCommonPrefix(strs);
        
		return 0;
	}