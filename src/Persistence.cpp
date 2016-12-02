#include <string>

#include <../include/Persistence.hpp>

PersistenceError::PersistenceError()
{
    this->message = "Erro desconhecido no banco de dados.";
}

PersistenceError::PersistenceError(string message)
{
    this->message = message;
}

string PersistenceError::what()
{
    return this->message;
}

Project* GetProject::operator()(ProjectCode&) throw (PersistenceError)
{
    Project* p;

    this->SQLquery << "select * from Project where code=";
    this->SQLquery << ProjectCode.getProjectCode();

    this->run();

    if(returnList.empty())
        throw PersistenceError("O projeto não existe.")

    p = new Project(
        returnMap["name"],
        returnMap["code"],
        returnMap["manager"],
        returnMap["initDate"],
        returnMap["state"]
    );
    p->setEndDate(returnMap["endDate"]);
    p->setCurrCost(returnMap["currCost"]);
    p->setEstimateCost(returnMap["estCost"]);

    return p;
}

void EditProject::operator()(Project& p) throw (PersistenceError)
{
    this->SQLquery  << " update Project set"
                    << " name='" << p.getName() << "',"
                    << " manager='" << p.getManager() << "',"
                    << " initDate='" << p.getInitDate() << "',"
                    << " state='" << p.getState() << "',"
                    << " endDate='" << p.getEndDate() << "',"
                    << " currCost='" << p.getCurrCost() << "',"
                    << " estCost='" << p.getEstimateCost() << "',"
                    << " where code='" << p.getProjectCode() << "',";

    this->run();
}

void AddProject::operator()(Project& p) throw (PersistenceError)
{
    this->SQLquery  << " insert into Project values"
                    << " ("
                    << p.getName()      <<","
                    << p.getManager()   <<","
                    << p.getInitDate()  <<","
                    << p.getState()     <<","
                    << p.getEndDate()   <<","
                    << p.getCurrCost()  <<","
                    << p.getEstimateCost() << ","
                    << p.getProjectCode()  << ")";

    this->run();
}
