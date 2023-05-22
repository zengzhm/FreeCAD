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
#endif

#include "Workbench.h"
#include <Gui/MenuManager.h>
#include <Gui/ToolBarManager.h>


using namespace ZzmDesignGui;

/// @namespace ZzmDesignGui @class Workbench
TYPESYSTEM_SOURCE(ZzmDesignGui::Workbench, Gui::StdWorkbench)

Workbench::Workbench()
{
}

Workbench::~Workbench()
{
}
//2Dgeometry
Gui::MenuItem* Workbench::setupMenuBar() const
{
    Gui::MenuItem* root = StdWorkbench::setupMenuBar();
    Gui::MenuItem* item = root->findItem( "&Windows" );
    Gui::MenuItem* geometry = new Gui::MenuItem;
    root->insertItem(item, geometry);

    // 2d geometry
    Gui::MenuItem* geometry_2d = new Gui::MenuItem;
    geometry_2d->setCommand("Create 2d geometry");
    *geometry_2d << "Create_2D_Line"
                 << "Create_2D_Circle"
                 << "Create_2D_Ellipse"
                 << "Create_2D_Parabola"
                 << "Create_2D_Hyperbola"
                 << "Create_2D_Bezier"
                 << "Create_2D_BSpline"
                 << "Create_2D_Trimmed"
                 << "Create_2D_Offset";

    // 3d geometry
    Gui::MenuItem* geometry_3d = new Gui::MenuItem;
    geometry_3d->setCommand("Create 3d geometry");
    *geometry_3d << "Create_3D_Line"
                 << "Create_3D_Circle"
                 << "Create_3D_Ellipse"
                 << "Create_3D_Parabola"
                 << "Create_3D_Hyperbola"
                 << "Create_3D_Bezier"
                 << "Create_3D_BSpline"
                 << "Create_3D_Trimmed"
                 << "Create_3D_Offset";

    *geometry << geometry_2d 
              << geometry_3d;

    return root;
}

Gui::ToolBarItem* Workbench::setupToolBars() const
{
    Gui::ToolBarItem* root = StdWorkbench::setupToolBars();
    Gui::ToolBarItem* geometry_2d = new Gui::ToolBarItem(root);
    geometry_2d->setCommand("Create 2d geometry");
    *geometry_2d << "Create_2D_Line"
                 << "Create_2D_Circle"
                 << "Create_2D_Ellipse"
                 << "Create_2D_Parabola"
                 << "Create_2D_Hyperbola"
                 << "Create_2D_Bezier"
                 << "Create_2D_BSpline"
                 << "Create_2D_Trimmed"
                 << "Create_2D_Offset";


    Gui::ToolBarItem* geometry_3d = new Gui::ToolBarItem(root);
    geometry_3d->setCommand("Create 3d geometry");
    *geometry_3d << "Create_3D_Line"
                 << "Create_3D_Circle"
                 << "Create_3D_Ellipse"
                 << "Create_3D_Parabola"
                 << "Create_3D_Hyperbola"
                 << "Create_3D_Bezier"
                 << "Create_3D_BSpline"
                 << "Create_3D_Trimmed"
                 << "Create_3D_Offset";

    return root;
}
