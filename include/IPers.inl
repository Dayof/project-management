#include <string>
#include <list>
#include <sstream>

#include "sqlite3.h"

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

class Record {
public:
    string col;
    string value;
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
    static list<Record> returnList;
    stringstream SQLquery;

    void connect() throw (PersistenceError)
    {
        this->returnCode = sqlite3_open(databaseName.c_str(), &(this->db));
        if(this->returnCode != SQLITE_OK)
            throw PersistenceError("Erro na conexão com o banco de dados.");
    }

    void disconnect() throw (PersistenceError)
    {
        this->returnCode = sqlite3_close(this->db);
        if(this->returnCode != SQLITE_OK)
            throw PersistenceError("Erro ao fechar a conexão com o banco de dados.");
    }

    static int digestData(void* X, int argc, char** argv, char** colName)
    {
        Record line;

        for(int i=0; i<argc; ++i)
        {
            line.col = colName[i];
            line.value = argv[i];
            returnList.push_back(line);
        }

        return 0;
    }

    void run()
    {
        this->returnCode = sqlite3_exec(
            this->db,
            this->SQLquery.str().c_str(),
            this->digestData,
            0, &(this->message));
    }

public:
    IPersistence() throw (PersistenceError)
    {
        this->databaseName = "../manager.db";
        this->connect();
    }

    ~IPersistence() throw (PersistenceError)
    {
        disconnect();
    }
};
