/** @file StubBus.cpp
 *  @brief Implementação do stub da camada de negócio.
 *
 *  Neste arquivo contém as implementações das
 *  assinaturas dos métodos abstratos da interface
 *  de negócio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#include "StubBus.hpp"
#include "Persistence.hpp"

string StubBus::regPM(Registration *reg, ProjectManager *projManager){
    CheckType checkType = CheckType();
    AddProject addProj = AddProject();

    try{
        if(checkType(*reg) == CheckType::DEV)
            addProj(*projManager);
    }
    catch (PersistenceError err) {
        return err.what();
    }
    return "OK";
}

string StubBus::delPM(Registration *reg, ProjectManager *projManager){

}

string StubBus::regP(Registration *reg, Project *proj){

}

string StubBus::delP(Registration *reg, Project *proj){

}

string StubBus::regD(Registration *reg, Developer *dev){

}

string StubBus::delD(Registration *reg, Developer *dev){

}

string StubBus::editPersonalInfo(ProjectManager *projManager, Name *name){

}

string StubBus::editPersonalInfo(ProjectManager *projManager, Password *pass){

}

string StubBus::editPersonalInfo(ProjectManager *projManager, Phone *phone){

}

string StubBus::editPersonalInfo(Developer *dev, Name *name){

}

string StubBus::editPersonalInfo(Developer *dev, Password *pass){

}

string StubBus::editPersonalInfo(Developer *dev, Email *email){

}

string StubBus::editPersonalInfo(Developer *dev, Role *role){

}

string StubBus::editProjectInfo(Registration *reg, Project *proj){

}

string StubBus::showPersonalInfo(Registration *reg){

}

string StubBus::showProjectInfo(ProjectCode *projCode){

}
