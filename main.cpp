#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

string getInstructionType(const string& hex) {
    uint32_t instr = stoul(hex, nullptr, 16);
    uint8_t opcode = instr & 0x7F;

    switch (opcode) {
        case 0x33: return "R";
        case 0x13:
        case 0x03:
        case 0x67: return "I";
        case 0x23: return "S";
        case 0x63: return "B";
        case 0x37:
        case 0x17: return "U";
        case 0x6F: return "J";
        default: return "Nao definido";
    }
}

void processarArquivo(const string& nomeArquivo) {
    ifstream input(nomeArquivo);
    if (!input.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    string nomeSaida = nomeArquivo.substr(0, nomeArquivo.find(".")) + "_relatorio.txt";
    ofstream output(nomeSaida);
    if (!output.is_open()) {
        cerr << "Erro ao criar o arquivo de saída: " << nomeSaida << endl;
        return;
    }

    map<string, int> count;
    string line;

    output << "Relatório para " << nomeArquivo << "\n\n";

    while (getline(input, line)) {
        if (line.empty()) continue;
        string tipo = getInstructionType(line);
        count[tipo]++;
        output << "Instrução: " << line << " → Tipo: " << tipo << "\n";
    }

    output << "\nResumo por tipo:\n";
    for (const auto& [tipo, qtd] : count) {
        output << "Tipo " << tipo << ": " << qtd << (qtd > 1 ? " instruções" : " instrução") << "\n";
    }

    cout << "✅ Relatório gerado: " << nomeSaida << endl;

    input.close();
    output.close();
}

int main() {
    vector<string> arquivos = {
        "instrucoes1.hex",
        "instrucoes2.hex",
        "instrucoes3.hex"
    };

    for (const string& arquivo : arquivos) {
        processarArquivo(arquivo);
    }

    return 0;
}
