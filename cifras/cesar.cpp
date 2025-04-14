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

    cout << "-----cifra de cesar----- \n";
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
    
    cout << "-----forca bruta----- \n";
    //força bruta complexidade O(n*26)
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

    cout << "-----distribuicao de frequencia----- \n";
    //tabela da lingua portuguesa
    vector<double> tabela = {13.9, 1, 4.4, 5.4, 12.2, 1, 1.2, 0.8,
    6.9, 0.4, 0.1, 2.8, 4.2, 5.3, 10.8, 2.9, 0.9, 6.9, 7.9, 4.9, 4,
    1.3, 0, 0.3, 0, 0.4};

    double menor_erro = 1e15; //seto com um valor "infinito"
    int melhor_chave = 0;

    //vejo quais são as possibilidades e escolho a mais provavel
    for(int i = 0; i < 26; i++){
        //igual a força bruta
        string texto_decifrado;
        for(int j = 0; j < texto_cifrado.size(); j++){
            int cesar = (i + 26);
            if(isalpha(texto_cifrado[j]))
                texto_decifrado += char((texto_cifrado[j] - 'a' + cesar) % 26 + 'a');
            else
                texto_decifrado += texto_cifrado[j];
        }
        int c = 0; // contador
        vector<int> v(26, 0);//guarda a quantidade de letras
        for(int j = 0; j < texto_decifrado.size(); j++){
            if(isalpha(texto_decifrado[j])){
                v[texto_decifrado[j] - 'a']++;
                c++; //referencia massa à linguagem
            }
        }
        //frequencia relativa
        vector<double> frequencia(26, 0);
        for(int j = 0; j < 26; j++){ 
            frequencia[j] = (100 * v[j]) / c; 
        }

        //calcula o erro
        double erro = 0;
        for(int j = 0; j < 26; j++){
            //diferença entre a frequencia relativa e a frequencia da tabela 
            erro += abs(frequencia[j] - tabela[j]);
        }
        //verifica o menor erro e escolhe a melhor chave
        if(erro < menor_erro){
            menor_erro = erro;
            melhor_chave = i;
        }
    }

    //resposta mais provavel usando
    //o metodo de distribuicao de frequencia 
    string possivel_resposta;
    for (int i = 0; i < texto_cifrado.size(); i++)
    {
        int cesar = (melhor_chave + 26); // deslocamento da cifra de cesar
        if(isalpha(texto[i]))
            possivel_resposta += char((texto_cifrado[i] - 'a' + cesar) % 26 + 'a'); 
        else{
            possivel_resposta += texto_cifrado[i];
        }
    }

    cout << possivel_resposta << "\n";

    return 0;
}