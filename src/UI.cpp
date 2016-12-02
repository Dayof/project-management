/** @file UI.cpp
 *  @brief Implementação da Camada de Apresentação do sistema.
 *
 *  Neste arquivo contém as implementações dos
 *  métodos abstratos da interface da Camada de Apresentação
 *  Serve para apresentar uma ligação entre o usuário e
 *  o sistema.
 *
 *  @author Dayanne Fernandes
 */

#include "UI.hpp"

void clearScreen()
{
#ifdef WINDOWS
    system("cls");
#else
    // Assume POSIX
    system ("clear");
#endif
}

void UILoginUser::login(IUIManageManager *uIManageManager,
                        IUIManageProject *uIManageProject,
                        IUIManageDev *uIManageDev){
    string reg;
    bool contin = true;
    map<string, string> info;

    cout << "OLÁ, BEM VINDO AO SISTEMA DE GERENCIAMENTO DE PROJETO!" << endl;

    while(contin){
        try{
            cout << "Insira sua matrícula para realizar ações neste sistema (Ex: 00001): " << endl;
            cin >> reg;
            info = this->busLogin->autenticar(reg);
            cout << "Tipo da Entidade do registro: " << info["type"] << endl;

            if(info["type"] == "SysManager")
                uIManageManager->run();
            else if(info["type"] == "ManageProject")
                uIManageProject->run();
            else if(info["type"] == "Developer")
                uIManageDev->run();

        }
        catch(exception& err)
        {
            cout << err.what() << endl;
            cout << "Tente inserir novamente.." << endl;
        }
        catch(PersistenceError& pers_err)
        {
            cout << pers_err.what() << endl;
            cout << "Vamos criar este novo registro então.." << endl;
            uIManageManager->run();
        }
        contin = false;
    }
}

void UIManageManager::run(){
    int option;
    bool contin = true;

    while(contin)
    {
        cout << "MENU DE CRUD DO GERENCIADOR DO SISTEMA" << endl;
        cout << "1. Criar novo usuário" << endl;
        cin >> option;
        if(option == 1)
        {
            contin = false;
        }
    }

    contin = true;

    while(contin)
    {
        cout << endl << "Qual tipo de usuário gostria de criar?" << endl;
        cout << "1. Gerente de Projeto" << endl;
        cout << "2. Desenvolvedor" << endl;
        cin >> option;
        if(option == 1)
        {
            contin = false;
            cout << "Redirecionando para formulário de inserção de Gerente de Projeto..." << endl;
        }
        else if(option == 2)
        {
            contin = false;
            cout << "Redirecionando para formulário de inserção de Desenolvedor..." << endl;
        }
    }
}

void UIManageDev::run(){
    cout << "MENU DO DESENVOLVEDOR" << endl;
}

void UIManageProject::run(){
    cout << "MENU DE CRUD DO GERENCIADOR DE PROJETO" << endl;
}
