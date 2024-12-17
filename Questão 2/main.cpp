#include <iostream>
#include <locale>
#include <string>
#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"
#include "AlunoEspecial.h"
#include "AlunoRegular.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "");

    cout << "criando alunos, professores, pessoas" <<
    "alunos regulares e alunos especiais, duas instancias de cada." << endl;

    Pessoa p1(5135135135, "Alberto");
    Pessoa p2(41572106401, "Bianca");
    Aluno a1(51285051514, "Carlos");
    Aluno a2(20148910239, "Catarina");
    Professor pr1(5012389542, "Débora");
    Professor pr2(20165841025, "Eduardo");
    AlunoEspecial ae1(98765432101, "Franciel");
    AlunoEspecial ae2(54632198720, "Gibson");
    AlunoRegular ar1(51236542185, "Hiago");
    AlunoRegular ar2(50062131240, "Iana");

    cout << "todo mundo criado, executando modificações..." << endl;

    cout << p1.getNome() <<" mudou nome para ";
    p1.setNome("Emanuelle");
    cout << p1.getNome() << endl;

    cout << p2.getNome() << " mudou seu cpf de " << to_string(p2.getCpf());
    p2.setCpf(5799862171);
    cout << " para " << to_string(p2.getCpf()) << endl;

    cout << a1.getNome() << " mudou sua matrícula de " << to_string(a1.getMatricula());
    a1.setMatricula(9876543);
    cout << " para " << a1.getMatricula() << endl;

    cout << a2.getNome() << ", que estava com carga horária incorreta de " << a2.getTempoEstudo();
    a2.setTempoEstudo(3);
    cout << " mudou para " << a2.getTempoEstudo() << ", agora ajustado." << endl;

    cout << pr1.getNome() << ", professor com situação " << pr1.getSituacao();
    pr1.setSituacao(1);
    pr1.setTempoServico(40);
    cout << " já tem " << pr1.getTempoServico() <<
        " de tempo de serviço e aposentou. Agora sua situação é " << pr1.getSituacao() <<
        " e seu siape mudou de " << pr1.getSiape();
    pr1.setSiape(6532980);
    cout << " para " << pr1.getSiape() << endl;

    pr2.setTempoServico(12);
    cout << "O tempo de serviço de " << pr2.getNome() << " é de " << pr2.getTempoServico() << endl;

    cout << "\nagora imprimindo todas as informações de todo mundo:" << endl << endl;

    p1.imprime("Objeto p1"); cout << endl;
    p2.imprime("Objeto p2"); cout << endl;
    a1.imprime("Objeto a1"); cout << endl;
    a2.imprime("Objeto a2"); cout << endl;
    pr1.imprime("Objeto pr1"); cout << endl;
    pr2.imprime("Objeto pr2"); cout << endl;
    ae1.imprime("Objeto ae1"); cout << endl;
    ae2.imprime("Objeto ae2"); cout << endl;
    ar1.imprime("Objeto ar1"); cout << endl;
    ar2.imprime("Objeto ar2"); cout << endl;


    system("pause");
}