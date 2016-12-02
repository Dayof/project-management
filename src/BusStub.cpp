/** @file BusStub.cpp
 *  @brief Implementação do Stub da parte de negócio.
 *
 *  Neste arquivo contém os stubs das
 *  assinaturas dos métodos abstratos da interface de
 *  negócio.
 *
 *  @author Dayanne Fernandes
 */

#include "BusStub.hpp"

string BusStubManageManager::regPM(Registration *reg, ProjectManager *projManager){
    return "OK";
}

string BusStubManageManager::delPM(Registration *reg, ProjectManager *projManager){
    return "OK";
}

string BusStubManageProject::regP(Registration *reg, Project *proj){
    return "OK";
}

string BusStubManageProject::delP(Registration *reg, Project *proj){
    return "OK";
}

string BusStubManageDev::regD(Registration *reg, Developer *dev){
    return "OK";
}

string BusStubManageDev::delD(Registration *reg, Developer *dev){
    return "OK";
}

string BusStubShared::editPersonalInfo(Registration *reg, Name *name){
    return "OK";
}

string BusStubShared::editPersonalInfo(Registration *reg, Password *pass){
    return "OK";
}

string BusStubShared::editPersonalInfo(Registration *reg, Phone *phone){
    return "OK";
}

string BusStubShared::editPersonalInfo(Registration *reg, Email *email){
    return "OK";
}

string BusStubShared::editPersonalInfo(Registration *reg, Role *role){
    return "OK";
}

string BusStubManageProject::editProjectInfo(Registration *reg, ProjectCode *projCode, Name *name){
    return "OK";
}

string BusStubManageProject::editProjectInfo(Registration *reg, ProjectCode *projCode, Date *date, string init_end_date){
    return "OK";
}

string BusStubManageProject::editProjectInfo(Registration *reg, ProjectCode *projCode, Cost *projCost, string curr_estimate_cost){
    return "OK";
}

string BusStubManageProject::editProjectInfo(Registration *reg, ProjectCode *projCode, Developer *dev, Registration *oldDevReg){
    return "OK";
}

string BusStubManageProject::editProjectInfo(Registration *reg, ProjectCode *projCode, ProjectManager *projManager,  Registration *oldProjManagerReg){
    return "OK";
}

string BusStubManageProject::editProjectInfo(Registration *reg, ProjectCode *projCode,  ProjectState *state){
    return "OK";
}

map<string, string> BusStubShared::showPersonalInfo(Registration *reqReg, Registration *viewReg){
    map<string, string> info;

    info["name"]="Dayanne"
    info["reg"]="00002"
    info["pass"]="12345"

    return info;
}

map<string, string> BusManageProject::showProjectInfo(ProjectCode *projCode){
    map<string, string> info;

    info["name"]= "Projeto Sem Sentido"
    info["projcode"]="AAAAA"
    info["initdate"]="01/12/2020"
    info["enddate"]="01/12/2026"
    info["currentcost"]="2000.00"
    info["estimatecost"]="5000.00"

    return info;
}

string BusStubManageDev::addDevToProject(Registration *reg, ProjectCode *projCode, Developer *dev){
    return "OK";
}

string BusStubManageDev::delDevFromProject(Registration *reg, ProjectCode *projCode, Developer *dev){
    return "OK";
}
