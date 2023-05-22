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

#include <App/Document.h>
#include <Base/Console.h>
#include <Gui/Application.h>
#include <Gui/Command.h>
#include <Mod/Part/App/PartFeature.h>

//occ
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <Geom_Line.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_Parabola.hxx>
#include <Geom_Hyperbola.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_OffsetCurve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <gce_MakeParab.hxx>
#include <GC_MakeArcOfParabola.hxx>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//===========================================================================
//A COMMAND: Create 3D Line
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DLine)

CmdCreate3DLine::CmdCreate3DLine() : Command("Create_3D_Line")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DLine");
    sToolTipText = QT_TR_NOOP("Create 3D Line");
    sWhatsThis = "ZzmDesign_Create3DLine";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_Line";
    sAccel = "CTRL+L";
}

void CmdCreate3DLine::activated(int) {
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "Line3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    BRepBuilderAPI_MakeEdge mkBuilder(gp_Pnt(0.0, 0.0, 0.0), gp_Pnt(0.0, 40.0, 50.0));
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DLine::isActive() 
{ 
    return getDocument();
}


//===========================================================================
//A COMMAND: Create 3D Circle
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DCircle)

CmdCreate3DCircle::CmdCreate3DCircle() : Command("Create_3D_Circle")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DCircle");
    sToolTipText = QT_TR_NOOP("Create 3D Circle");
    sWhatsThis = "ZzmDesign_Create3DCircle";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_Circle";
    sAccel = "CTRL+C";
}

void CmdCreate3DCircle::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "Circle3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    auto circle = new Geom_Circle(gp_Circ());
    circle->SetRadius(50.0);
    BRepBuilderAPI_MakeEdge mkBuilder(circle);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DCircle::isActive() 
{
    return getDocument();
}


//===========================================================================
//A COMMAND: Create 3D Ellipse
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DEllipse)

CmdCreate3DEllipse::CmdCreate3DEllipse() : Command("Create_3D_Ellipse")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DEllipse");
    sToolTipText = QT_TR_NOOP("Create 3D Ellipse");
    sWhatsThis = "ZzmDesign_Create3DEllipse";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_Ellipse";
    sAccel = "CTRL+E";
}

void CmdCreate3DEllipse::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "Ellipse3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    auto ellipse = new Geom_Ellipse(gp_Elips());
    ellipse->SetMinorRadius(50.0);
    ellipse->SetMajorRadius(100.0);
    BRepBuilderAPI_MakeEdge mkBuilder(ellipse);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DEllipse::isActive() 
{ 
    return getDocument();
}

//===========================================================================
//A COMMAND: Create 3D Parabola
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DParabola)

CmdCreate3DParabola::CmdCreate3DParabola() : Command("Create_3D_Parabola")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DParabola");
    sToolTipText = QT_TR_NOOP("Create 3D Parabola");
    sWhatsThis = "ZzmDesign_Create3DParabola";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_Parabola";
    sAccel = "CTRL+P";
}

void CmdCreate3DParabola::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "Parabola3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }
    
    Geom_Parabola* parabola = new Geom_Parabola(gp_Parab());
    parabola->SetFocal(static_cast<double>(50));
    Geom_TrimmedCurve* curve = new Geom_TrimmedCurve(parabola, -174.0, 174.0);
    BRepBuilderAPI_MakeEdge mkBuilder(curve);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute(); 
}

bool CmdCreate3DParabola::isActive() 
{ 
    return getDocument();
}


//===========================================================================
//A COMMAND: Create 3D Hyperbola
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DHyperbola)

CmdCreate3DHyperbola::CmdCreate3DHyperbola() : Command("Create_3D_Hyperbola")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DHyperbola");
    sToolTipText = QT_TR_NOOP("Create 3D Hyperbola");
    sWhatsThis = "ZzmDesign_Create3DHyperbola";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_Hyperbola";
    sAccel = "CTRL+H";
}

void CmdCreate3DHyperbola::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "Hyperbola3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    Geom_Hyperbola* hyperbola = new Geom_Hyperbola(gp_Hypr());
    hyperbola->SetMajorRadius(static_cast<double>(500));
    hyperbola->SetMinorRadius(static_cast<double>(100));
    //截断后没看到图片显示出来，后面再看看双曲线u的参数
    auto trimmed = new Geom_TrimmedCurve(hyperbola, -100, 100);
    BRepBuilderAPI_MakeEdge mkBuilder(hyperbola);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DHyperbola::isActive() 
{
    return getDocument();
}

//===========================================================================
//A COMMAND: Create 3D Bezier
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DBezier)

CmdCreate3DBezier::CmdCreate3DBezier() : Command("Create_3D_Bezier")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DBezier");
    sToolTipText = QT_TR_NOOP("Create 3D Bezier");
    sWhatsThis = "ZzmDesign_Create3DBezier";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_BezCurve";
    sAccel = "CTRL+B";
}

void CmdCreate3DBezier::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "Bezier3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    TColgp_Array1OfPnt poles(1, 4);
    poles(1) = gp_Pnt(0.0, 0.0, 0.0);
    poles(2) = gp_Pnt(0.0, 50.0, 0.0);
    poles(3) = gp_Pnt(60.0, 0, 100.0);
    poles(4) = gp_Pnt(0.0, 0.0, 50.0);
    auto bezier = new Geom_BezierCurve(poles);
    BRepBuilderAPI_MakeEdge mkBuilder(bezier);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DBezier::isActive() 
{ 
    return getDocument(); 
}

//===========================================================================
//A COMMAND: Create 3D BSpline
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DBSpline)

CmdCreate3DBSpline::CmdCreate3DBSpline() : Command("Create_3D_BSpline")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DBSpline");
    sToolTipText = QT_TR_NOOP("Create 3D BSpline");
    sWhatsThis = "ZzmDesign_Create3DBSpline";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_BSpline";
    sAccel = "CTRL+B";
}

void CmdCreate3DBSpline::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "BSpline3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    TColgp_Array1OfPnt poles(1, 4);
    poles(1) = gp_Pnt(0.0, 0.0, 0.0);
    poles(2) = gp_Pnt(-100.0, 0.0, 0.0);
    poles(3) = gp_Pnt(100.0, 100.0, 0.0);
    poles(4) = gp_Pnt(100.0, 0.0, -100.0);

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

    Geom_BSplineCurve* bspline = new Geom_BSplineCurve(poles, weights, knots, mults, 3);
    BRepBuilderAPI_MakeEdge mkBuilder(bspline);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DBSpline::isActive() 
{ 
    return getDocument(); 
}

//===========================================================================
//A COMMAND: Create 3D Trimmed
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DTrimmed)

CmdCreate3DTrimmed::CmdCreate3DTrimmed() : Command("Create_3D_Trimmed")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DTrimmed");
    sToolTipText = QT_TR_NOOP("Create 3D Trimmed");
    sWhatsThis = "ZzmDesign_Create3DTrimmed";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_Trimmed";
    sAccel = "CTRL+B";
}

void CmdCreate3DTrimmed::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "trimmed3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    auto ellipse = new Geom_Ellipse(gp_Elips());
    ellipse->SetMinorRadius(50.0);
    ellipse->SetMajorRadius(100.0);
    auto trimmed = new Geom_TrimmedCurve(ellipse, -1, 2, true);
    BRepBuilderAPI_MakeEdge mkBuilder(trimmed);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DTrimmed::isActive() 
{ 
    return getDocument(); 
}

//===========================================================================
//A COMMAND: Create 3D Offset
//===========================================================================
DEF_STD_CMD_A(CmdCreate3DOffset)

CmdCreate3DOffset::CmdCreate3DOffset() : Command("Create_3D_Offset")
{
    sAppModule = "ZzmDesign";
    sGroup = QT_TR_NOOP("ZzmDesign");
    sMenuText = QT_TR_NOOP("Create3DOffset");
    sToolTipText = QT_TR_NOOP("Create 3D Offset");
    sWhatsThis = "ZzmDesign_Create3DOffset";
    sStatusTip = sToolTipText;
    sPixmap = "ZzmDesign_3D_Offset";
    sAccel = "CTRL+B";
}

void CmdCreate3DOffset::activated(int) 
{
    App::Document* doc = getDocument();
    auto feature = static_cast<Part::Feature*>(doc->addObject("Part::Feature", "Offset3D"));
    if (!feature) {
        Base::Console().Error("Failed to add Feature object");
        return;
    }

    auto ellipse = new Geom_Ellipse(gp_Elips());
    ellipse->SetMinorRadius(50.0);
    ellipse->SetMajorRadius(100.0);
    auto offset = new Geom_OffsetCurve(ellipse, 10, gp_Dir(0.0, 0.0, 1.0));
    BRepBuilderAPI_MakeEdge mkBuilder(offset);
    feature->Shape.setValue(mkBuilder.Shape());
    doc->recompute();
}

bool CmdCreate3DOffset::isActive() 
{ 
    return getDocument();
}


void CreateZzmDesignCommands3DGeometry(void)
{
    Gui::CommandManager& rcCmdMgr = Gui::Application::Instance->commandManager();
    rcCmdMgr.addCommand(new CmdCreate3DLine());
    rcCmdMgr.addCommand(new CmdCreate3DCircle());
    rcCmdMgr.addCommand(new CmdCreate3DEllipse());
    rcCmdMgr.addCommand(new CmdCreate3DParabola());
    rcCmdMgr.addCommand(new CmdCreate3DHyperbola());
    rcCmdMgr.addCommand(new CmdCreate3DBezier());
    rcCmdMgr.addCommand(new CmdCreate3DBSpline());
    rcCmdMgr.addCommand(new CmdCreate3DTrimmed());
    rcCmdMgr.addCommand(new CmdCreate3DOffset());
}
