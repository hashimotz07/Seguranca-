#include <bits\stdc++.h> //biblioteca de programação competitiva
#define int long long
#define pb push_back
using namespace std;

int32_t main()
{
    
    string texto; // texto a ser cifrado
    int k = 3;    // deslocamento
    cin >> texto;

    // deixa todo o texto em lower case
    string converter;
    for (int i = 0; i < texto.size(); i++)
    {
        if (isalpha(texto[i]))
            converter += tolower(texto[i]);
        else
        {
            converter += texto[i];
        }
    }

    // limpo a string texto e coloco a string convertida em lower case
    texto.clear();
    texto = converter;

    // é o cifras
    string texto_cifrado;
    for (int i = 0; i < texto.size(); i++)
    {
        if (isalpha(texto[i]))
        {
            int cesar = (k + 26) % 26; // formula do deslocamento da cifra de cesar
            texto_cifrado += char(texto[i] + cesar);
        }
        else
        {
            texto_cifrado += texto[i];
        }
    }

    cout << texto_cifrado;

    return 0;
}