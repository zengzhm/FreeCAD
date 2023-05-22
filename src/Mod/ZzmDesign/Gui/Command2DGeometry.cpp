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

#include <BRepBuilderAPI_MakeEdge2d.hxx>
#include <Base/Console.h>
#include <App/Document.h>
#include <Gui/Application.h>
#include <Gui/Command.h>
#include <Mod/Part/App/Part2DObject.h>

#include <BRepBuilderAPI_MakeEdge2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom2d_Ellipse.hxx>
#include <Geom2d_Hyperbola.hxx>
#include <Geom2d_Line.hxx>
#include <Geom2d_OffsetCurve.hxx>
#include <Geom2d_Parabola.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//===========================================================================
//A COMMAND: Create 2D Line
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DLine)

CmdCreate2DLine::CmdCreate2DLine()
  :Command("Create_2D_Line")
{
    sAppModule    = "ZzmDesign";
    sGroup        = QT_TR_NOOP("ZzmDesign");
    sMenuText     = QT_TR_NOOP("Create2DLine");
    sToolTipText  = QT_TR_NOOP("Create 2D Line");
    sWhatsThis    = "ZzmDesign_Create2DLine";
    sStatusTip    = sToolTipText;
    sPixmap       = "ZzmDesign_2D_Line";
    sAccel        = "CTRL+L";
}

void CmdCreate2DLine::activated(int) {
    App::Document* doc = getDocument();
    auto object = static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Line2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }

    BRepBuilderAPI_MakeEdge2d mkBuilder(gp_Pnt2d(0.0, 0.0), gp_Pnt2d(0.0, 50.0));
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate2DLine::isActive() 
{ 
    return getDocument();
}



//===========================================================================
//A COMMAND: Create 2D Circle
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DCircle)

CmdCreate2DCircle::CmdCreate2DCircle() : Command("Create_2D_Circle")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DCircle");
    sToolTipText = QT_TR_NOOP("Create 2D Circle");
    sWhatsThis = "ZzmDesign_Create2DCircle";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_Circle";
    sAccel = "CTRL+C";
}

void CmdCreate2DCircle::activated(int)
{
    App::Document* doc = getDocument();
    auto object = static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Circle2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }

    auto circle = new Geom2d_Circle(gp_Circ2d());
    circle->SetRadius(50.0);
    BRepBuilderAPI_MakeEdge2d mkBuilder(circle);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute(); 
}

bool CmdCreate2DCircle::isActive() 
{ 
    return getDocument(); 
}



//===========================================================================
//A COMMAND: Create 2D Ellipse
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DEllipse)

CmdCreate2DEllipse::CmdCreate2DEllipse() : Command("Create_2D_Ellipse")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DEllipse");
    sToolTipText = QT_TR_NOOP("Create 2D Ellipse");
    sWhatsThis = "ZzmDesign_Create2DEllipse";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_Ellipse";
    sAccel = "CTRL+E";
}

void CmdCreate2DEllipse::activated(int) 
{
    App::Document* doc = getDocument();
    auto object = static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Ellipse2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }

    auto ellipse = new Geom2d_Ellipse(gp_Elips2d());
    ellipse->SetMinorRadius(50.0);
    ellipse->SetMajorRadius(100.0);
    BRepBuilderAPI_MakeEdge2d mkBuilder(ellipse);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate2DEllipse::isActive() 
{
    return getDocument(); 
}


//===========================================================================
//A COMMAND: Create 2D Parabola
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DParabola)

CmdCreate2DParabola::CmdCreate2DParabola() : Command("Create_2D_Parabola")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DParabola");
    sToolTipText = QT_TR_NOOP("Create 2D Parabola");
    sWhatsThis = "ZzmDesign_Create2DParabola";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_Parabola";
    sAccel = "CTRL+P";
}

void CmdCreate2DParabola::activated(int) 
{
    App::Document* doc = getDocument();
    auto object = static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Parabola2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }
    
    Geom2d_Parabola* parabola = new Geom2d_Parabola(gp_Parab2d());
    parabola->SetFocal(static_cast<double>(50));
    auto trimmed = new Geom2d_TrimmedCurve(parabola, -174.0, 174.0);
    BRepBuilderAPI_MakeEdge2d mkBuilder(trimmed);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute(); 
}

bool CmdCreate2DParabola::isActive() 
{ 
    return getDocument();
}

//===========================================================================
//A COMMAND: Create 2D Hyperbola
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DHyperbola)

CmdCreate2DHyperbola::CmdCreate2DHyperbola() : Command("Create_2D_Hyperbola")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DHyperbola");
    sToolTipText = QT_TR_NOOP("Create 2D Hyperbola");
    sWhatsThis = "ZzmDesign_Create2DHyperbola";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_Hyperbola";
    sAccel = "CTRL+H";
}

void CmdCreate2DHyperbola::activated(int) 
{

    App::Document* doc = getDocument();
    auto object =
        static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Hyperbola2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }

    Geom2d_Hyperbola* hyperbola = new Geom2d_Hyperbola(gp_Hypr2d());
    hyperbola->SetMajorRadius(static_cast<double>(1));
    hyperbola->SetMinorRadius(static_cast<double>(1));
    //截断后没看到图片显示出来，后面再看看双曲线u的参数
    auto trimmed = new Geom2d_TrimmedCurve(hyperbola, -100, 100);
    BRepBuilderAPI_MakeEdge2d mkBuilder(trimmed);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate2DHyperbola::isActive() 
{ 
    return getDocument(); 
}


//===========================================================================
//A COMMAND: Create 2D Bezier
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DBezier)

CmdCreate2DBezier::CmdCreate2DBezier() : Command("Create_2D_Bezier")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DBezier");
    sToolTipText = QT_TR_NOOP("Create 2D Bezier");
    sWhatsThis = "ZzmDesign_Create2DBezier";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_Bezier";
    sAccel = "CTRL+B";
}

void CmdCreate2DBezier::activated(int) 
{
    App::Document* doc = getDocument();
    auto object =
        static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Bezier2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }


    TColgp_Array1OfPnt2d poles(1,3);
    poles(1) = gp_Pnt2d(0.0, 0.0);
    poles(2) = gp_Pnt2d(0.0, 50.0);
    poles(3) = gp_Pnt2d(60.0, 10.0);
    auto bezier = new Geom2d_BezierCurve(poles);
    BRepBuilderAPI_MakeEdge2d mkBuilder(bezier);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate2DBezier::isActive() 
{
    return getDocument();
}

//====================================================
//A COMMAND: Create 2D BSpline
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DBSpline)
CmdCreate2DBSpline::CmdCreate2DBSpline() : Command("Create_2D_BSpline")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DBSpline");
    sToolTipText = QT_TR_NOOP("Create 2D BSpline");
    sWhatsThis = "ZzmDesign_Create2DBSpline";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_BSpline";
    sAccel = "CTRL+B";
}

void CmdCreate2DBSpline::activated(int) 
{
    App::Document* doc = getDocument();
    auto object = static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "BSpline2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }

    TColgp_Array1OfPnt2d poles(1, 4);
    poles(1) = gp_Pnt2d(-50.4318, 15.5909);
    poles(2) = gp_Pnt2d(-20.2045, -23.5455);
    poles(3) = gp_Pnt2d(8.11364, 28);
    poles(4) = gp_Pnt2d(42.7955, -15.9091);

    TColStd_Array1OfReal weights(1, 4);
    weights(1) = 1.0;
    weights(2) = 1.0;
    weights(3) = 1.0;
    weights(4) = 1.0;

    TColStd_Array1OfReal knots(1, 2);
    knots(1) = 0.0;
    knots(2) = 1.0;

    TColStd_Array1OfInteger mults(1, 2);
    mults(1) = 4;
    mults(2) = 4;

    auto bspline = new Geom2d_BSplineCurve(poles, weights, knots, mults, 3);
    BRepBuilderAPI_MakeEdge2d mkBuilder(bspline);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
    
}

bool CmdCreate2DBSpline::isActive() 
{ 
    return getDocument(); 
}


//===========================================================================
//A COMMAND: Create 2D Trimmed
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DTrimmed)

CmdCreate2DTrimmed::CmdCreate2DTrimmed() : Command("Create_2D_Trimmed")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DTrimmed");
    sToolTipText = QT_TR_NOOP("Create 2D Trimmed");
    sWhatsThis = "ZzmDesign_Create2DTrimmed";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_Trimmed";
    sAccel = "CTRL+B";
}

void CmdCreate2DTrimmed::activated(int)
{
    App::Document* doc = getDocument();
    auto object = static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Trimmed2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }

    auto ellipse = new Geom2d_Ellipse(gp_Elips2d());
    ellipse->SetMinorRadius(50.0);
    ellipse->SetMajorRadius(100.0);
    auto trimmed = new Geom2d_TrimmedCurve(ellipse, -1, 2, true);
    BRepBuilderAPI_MakeEdge2d mkBuilder(trimmed);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate2DTrimmed::isActive() 
{ 
    return getDocument(); 
}

//===========================================================================
//A COMMAND: Create 2D Offset
//===========================================================================
DEF_STD_CMD_A(CmdCreate2DOffset)

CmdCreate2DOffset::CmdCreate2DOffset() : Command("Create_2D_Offset")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create2DOffset");
    sToolTipText = QT_TR_NOOP("Create 2D Offset");
    sWhatsThis = "ZzmDesign_Create2DOffset";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_2D_Offset";
    sAccel = "CTRL+B";
}

void CmdCreate2DOffset::activated(int) 
{
    App::Document* doc = getDocument();
    auto object = static_cast<Part::Part2DObject*>(doc->addObject("Part::Part2DObject", "Offset2D"));
    if (!object) {
        Base::Console().Error("Failed to add Part2DObject object");
        return;
    }

    auto ellipse = new Geom2d_Ellipse(gp_Elips2d());
    ellipse->SetMinorRadius(50.0);
    ellipse->SetMajorRadius(100.0);
    auto offset = new Geom2d_OffsetCurve(ellipse, 10);
    BRepBuilderAPI_MakeEdge2d mkBuilder(offset);
    object->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate2DOffset::isActive() 
{ 
    return getDocument();
}


void CreateZzmDesignCommands2DGeometry(void)
{
    Gui::CommandManager &rcCmdMgr = Gui::Application::Instance->commandManager();
    rcCmdMgr.addCommand(new CmdCreate2DLine());
    rcCmdMgr.addCommand(new CmdCreate2DCircle());
    rcCmdMgr.addCommand(new CmdCreate2DEllipse());
    rcCmdMgr.addCommand(new CmdCreate2DParabola());
    rcCmdMgr.addCommand(new CmdCreate2DHyperbola());
    rcCmdMgr.addCommand(new CmdCreate2DBezier());
    rcCmdMgr.addCommand(new CmdCreate2DBSpline());
    rcCmdMgr.addCommand(new CmdCreate2DTrimmed());
    rcCmdMgr.addCommand(new CmdCreate2DOffset());
}
