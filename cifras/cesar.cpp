#include <bits/stdc++.h> //biblioteca de programação competitiva
#define int long long
#define pb push_back
#define inacio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

int32_t main()
{
    inacio //tira o delay do cin e do cout

    string texto; // texto a ser cifrado
    int k = 3;    // deslocamento
    getline(cin, texto); //entrada do texto

    // deixa todo o texto em lower case
    string converter;
    for (int i = 0; i < texto.size(); i++)
    {
        if(isalpha(texto[i]))
            converter += tolower(texto[i]);
        else
            converter += texto[i];
    }

    //cout << converter << "\n";
    // limpo a string texto e coloco a string convertida em lower case
    texto.clear();
    texto = converter;

    // é o cifras 
    //complexidade O(n)
    string texto_cifrado;
    for (int i = 0; i < texto.size(); i++)
    {
        int cesar = (k + 26); // deslocamento da cifra de cesar

        //aqui fiz algo pra permanecer no range do alfabeto com as letras minusculas
        if(isalpha(texto[i]))
            texto_cifrado += char((texto[i] - 'a' + cesar) % 26 + 'a'); 
        else{
            texto_cifrado += texto[i];
        }
    }

    cout << texto_cifrado << "\n";

    //força bruta complexidade O(n^2)
    //função de descriptografas
    for(int i = 0; i < 26; i++){
        string texto_decifrado; //variavel para armezanar o texto a ser decifrado
        for(int j = 0; j < texto_cifrado.size(); j++){
            int cesar = (i + 26);
            if(isalpha(texto_cifrado[j]))
                texto_decifrado += char((texto[j] - 'a' + cesar) % 26 + 'a');
            else
                texto_decifrado += texto[j];
        }

        cout << texto_decifrado << "\n";
    }

    //distribuição de frequencia
    map<char, int> frequencia = {{'a', 1}};

    
    return 0;
}