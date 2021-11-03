// String_and_Array.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<iostream>
#include<algorithm>
#include<vector>
#include <string>

using namespace std;


int solution2(string& S, vector<int>& C)
{
    int cost = 0;
    
    for (int i = 0; i < S.length(); i++)
    {

    }

    return cost;
}

int solution(string& S, vector<int>& C)
{
    
    int cost = 0;
    for (int i = 0; i < S.length(); i++)
    {
        cout << "i= " << i << endl;
        cout << "string begin " << S << endl;

        if (S[i] == S[i + 1])
        {
            
            if (C[i] <= C[i + 1])
            {
                cout << "usuwam S " << S[i] << endl;
                cout << "usuwam C " << C[i] << endl;
                S.erase(i,1);
               
                cost += C[i];
                C.erase(C.begin() + i);
                
            }
            else if(C[i] > C[i + 1])
            {
             
                cout << "usuwam S " << S[i] << endl;
                cout << "usuwam C " << C[i] << endl;
                S.erase(i+1,1);
                
                cost += C[i+1];
                C.erase(C.begin() + i+1);
               
            }
            cout << "string after " << S << endl;
            
            cost += solution(S,C);
            
        }


    }
    return cost;
}


int main()
{
    vector<int> c = { 0,1,2,3,4,5 };
    string s = "abccbd";

    //vector<int> c = { 1,2,1,2,1,2 };
    //string s = "aabbcc";

    //vector<int> c = { 3,4,5,6};
   //string s = "aaaa";

    //vector<int> c = { 10,5,10,5,10 };
    //string s = "ababa";

    std::cout <<"cost = " << solution(s, c);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
