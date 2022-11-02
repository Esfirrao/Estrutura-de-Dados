#include <iostream>
#include <iomanip>

using namespace std;

const int N = 10;

struct node {
    int id, qtd;
    string descricao;
    float valor;
};

node list[N] = {1, 3, "Chateau Dufort Vivens", 300.00, 2, 5, "Ballantine's Finest Escoces", 90.0,
                3, 20, "Antartica", 5.0, 4, 10, "Jack Daniels Honey", 143.91};
int final, aux, Bsc, ant, cont;
node val;
string nome;
bool sinal, conf;

bool insFim(node novoNode) {
    if (final != N - 1) {
        cin >> conf;
        if (conf == true) {
            final = final + 1;
            list[final] = novoNode;
            return true;
        }
    }
    return false;
} //funcionando - 14

bool insCom(node novoNode) {
    if (final != N - 1) {
        cin >> conf;
        if (conf == true) {
            final = final + 1;
            aux = final;
            while (aux != 0) {
                list[aux] = list[aux - 1];
                aux = aux - 1;
            }
            list[aux] = novoNode;
            return true;
        }
    }
    return false;
} //funcionando

bool insPosK(int k, node novoNode) {
    if (final != N - 1) {
        if (k >= 0 && k <= final) {
            cin >> conf;
            if (conf == true) {
                final = final + 1;
                aux = final;
                while (aux != k) {
                    list[aux] = list[aux - 1];
                    aux = aux - 1;
                }
                list[k] = novoNode;
                return true;
            }
        }
    }
    return false;
} //funcionando

bool remFim() {
    if (final >= 0) {
        aux = final - 1;
        cout << list[aux].id << endl << list[aux].qtd << endl << list[aux].descricao << endl << list[aux].valor << endl;
        cin >> conf;
        if (conf == true) {
            final = final - 1;
            return true;
        }
    }
    return false;
} //funcionando

bool remIni() {
    if (final >= 0) {
        aux = 0;
        cout << list[aux].id << endl << list[aux].qtd << endl << list[aux].descricao << endl << list[aux].valor << endl;
        cin >> conf;
        if (conf == true) {
            while (aux != final) {
                list[aux] = list[aux + 1];
                aux = aux + 1;
            }
            final = final - 1;
            return true;
        }
    }
    return false;
} //funcionando

bool remPosK(int k) {
    if (final >= 0) {
        aux = k;
        cout << list[aux].id << endl << list[aux].qtd << endl << list[aux].descricao << endl << list[aux].valor << endl;
        cin >> conf;
        if (conf == true) {
            while (aux != final) {
                list[aux] = list[aux + 1];
                aux = aux + 1;
            }
            final = final - 1;
            return true;
        }
    }
    return false;
} //funcionando

bool consAntK(int k) {
    if (final >= 0) {
        cin >> conf;
        if (conf == true) {
            aux = k;
            cout << list[aux - 1].id << list[aux - 1].qtd << list[aux - 1].descricao << list[aux - 1].valor;
            return true;
        }

    }
    return false;
} //funcionando

bool insPos2KTeste(int k) {
    if (final <= N - 1) {
        cin >> k;

        if (k >= 0 && k <= final) {
            cin >> conf;
            if (conf == true) {
                cin >> val.id >> val.qtd >> val.descricao >> val.valor;
                final = final + 1;
                aux = final;
                k = k + 2;
                while (aux != k) {
                    list[aux] = list[aux - 1];
                    aux = aux - 1;
                }
                list[k] = val;
                return true;
            }
        }
    }
    return false;
}//funcionando - 7

bool PosNome() {
    if (final <= N - 1) {
        if (final > -1) {
            cin >> nome >> conf;
            final = final + 1;
            aux = final;
            if (conf == true) {
                cin >> val.id >> val.qtd >> val.descricao >> val.valor;
                while (aux != 0 && list[aux].descricao != nome) {
                    list[aux] = list[aux - 1];
                    aux = aux - 1;
                }
                if (list[aux].descricao == nome) {
                    aux = aux + 1;
                    list[aux] = val;
                }
                return true;
            }
        }
    }
    return false;
}//funcionando - 6

bool InsAntX(int x) {
    if (final <= N - 1) {
        if (final > -1) {
            cin >> x >> conf;
            if (conf == true) {
                cin >> val.id >> val.qtd >> val.descricao >> val.valor;
                aux = 0;
                while (aux != final && list[aux].id != x) {
                    aux = aux + 1;
                    if (list[aux].id == x) {
                        list[aux - 1] = val;
                    }
                }
                return true;
            }
        }
    }
    return false;
} // funcionando - 8

/*bool RemY(int y) {
    if (final > -1) {
        cin >> y >> conf;
        if (conf == true) {
            aux = final;
            while (aux != 0 && list[aux].valor != y) {
                aux = aux - 1;
                list[aux] = list[aux + 1];
            }
            cout << list[aux].descricao << list[aux -1].descricao << list[aux+1].descricao;
        }
        final = final - 1;
        return true;
    }
    return false;
}*/ //com b.o


bool QtdMaiorX(int x) {
    if (final > -1) {
        cin >> x >> conf;
        if (conf == true) {
            aux = 0;
            cont = 0;
            while (aux <= final) {
                if (list[aux].valor >= x) {
                    cont = cont + 1;
                }
                aux = aux + 1;
            }
            cout << cont;
            return true;
        }
    }
    return false;
} // funcionando - 10



int main() {
    final = 4;
    conf = false;
/*   cin >> val.id >> val.qtd >> val.descricao >> val.valor >> conf;
    sinal = insCom(val);
    cout << list[0].id << endl << list[0].qtd << endl << list[0].descricao << endl << list[0].valor << endl;*/

    /*cin >> idBsc >> conf;
    sinal = consAntK(idBsc);
    cout << conf;cout << sinal;
*/
    // sinal = remIni();
    //sinal = PosNome();
    //sinal = insPos2KTeste(Bsc);
    sinal = RemY(Bsc);

}