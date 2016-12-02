#include <string>
#include <map>
#include <sstream>
#include <vector>

#include "sqlite3.h"
#include <cstdio>

using namespace std;

/** Classe de exceção para erro de persistência */
class PersistenceError
{
private:
    /* String que conterá a mensagem de erro propriamente dita. */
    string message;

public:
    PersistenceError();
    PersistenceError(string);

    /** Retorna a mensagem de erro, relatando o que aconteceu. */
    string what();
};

class Table {
public:
    string name;
};


class IPersistence
{
private:
    string databaseName;
    sqlite3* db;
    char* message;
    int returnCode;

protected:
    static map<string, string> resultSet;
    static vector<string> resultList;
    stringstream SQLquery;

    void connect() throw (PersistenceError)
    {
        this->returnCode = sqlite3_open(databaseName.c_str(), &(this->db));
        if(this->returnCode != SQLITE_OK)
            throw PersistenceError("Erro na conexão com o banco de dados.");
    }

    static int digest(void* X, int argc, char** argv, char** colName)
    {
        for(int i=0; i<argc; ++i)
            resultSet[colName[i]] = argv[i];

        return 0;
    }

    static int filter(void* X, int argc, char** argv, char** colName)
    {
        for(int i=0; i<argc; ++i)
            resultList[i] = argv[i];

        return 0;
    }

    void disconnect() throw (PersistenceError)
    {
        this->returnCode = sqlite3_close(this->db);
        if(this->returnCode != SQLITE_OK)
            throw PersistenceError("Erro ao fechar a conexão com o banco de dados.");
    }

    void run()
    {
        this->returnCode = sqlite3_exec(
            this->db,
            this->SQLquery.str().c_str(),
            digest,
            0, &(this->message));

        if(this->returnCode != SQLITE_OK)
            throw PersistenceError("Erro ao executar SQL: " + this->SQLquery.str() + "\n" + this->message);
    }
    void filter()
    {
        this->returnCode = sqlite3_exec(
            this->db,
            this->SQLquery.str().c_str(),
            filter,
            0, &(this->message));

            if(this->returnCode != SQLITE_OK)
                throw PersistenceError("Erro ao executar SQL: " + this->SQLquery.str() + "\n" + this->message);
    }

public:
    IPersistence() throw (PersistenceError)
    {
        this->databaseName = "manager.db";
        this->connect();
    }

    ~IPersistence() throw (PersistenceError)
    {
        disconnect();
    }
};
