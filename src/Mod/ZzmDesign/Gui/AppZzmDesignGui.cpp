/***************************************************************************
 *   Copyright (c) YEAR YOUR NAME <Your e-mail address>                    *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#include "PreCompiled.h"
#ifndef _PreComp_
# include <Python.h>
#endif

#include <Base/Console.h>
#include <Base/Interpreter.h>
#include <Base/PyObjectBase.h>
#include <Gui/Application.h>

#include "Workbench.h"

#include <CXX/Extensions.hxx>
#include <CXX/Objects.hxx>

#include <Gui/Language/Translator.h>

// use a different name to CreateCommand()
void CreateZzmDesignCommands(void);
void CreateZzmDesignCommands2DGeometry(void);
void CreateZzmDesignCommands3DGeometry(void);

//load resoure
void loadZzmDesignResource()
{
    // add resources and reloads the translators
    Q_INIT_RESOURCE(ZzmDesign);
    Gui::Translator::instance()->refresh();
}


namespace ZzmDesignGui {
class Module : public Py::ExtensionModule<Module>
{
public:
    Module() : Py::ExtensionModule<Module>("ZzmDesignGui")
    {
        initialize("This module is the ZzmDesignGui module."); // register with Python
    }

    virtual ~Module() {}

private:
};

PyObject* initModule()
{
    return Base::Interpreter().addModule(new Module);
}

} // namespace ZzmDesignGui


/* Python entry */
PyMOD_INIT_FUNC(ZzmDesignGui)
{
    if (!Gui::Application::Instance) {
        PyErr_SetString(PyExc_ImportError, "Cannot load Gui module in console application.");
        PyMOD_Return(0);
    }

    // instantiating the commands
    CreateZzmDesignCommands();
    CreateZzmDesignCommands2DGeometry();
    CreateZzmDesignCommands3DGeometry();

    ZzmDesignGui::Workbench::init();

    // ADD YOUR CODE HERE
    //
    //
    PyObject* mod = ZzmDesignGui::initModule();
    Base::Console().Log("Loading GUI of ZzmDesign module... done\n");

    //load resoure
    loadZzmDesignResource();

    PyMOD_Return(mod);
}
