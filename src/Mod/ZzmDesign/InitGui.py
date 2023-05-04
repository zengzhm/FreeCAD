# ZzmDesign gui init module
# (c) 2001 Juergen Riegel LGPL

class ZzmDesignWorkbench (Workbench):
    "ZzmDesign workbench object"
    def __init__(self):
        self.__class__.Icon = FreeCAD.getResourceDir() + "Mod/ZzmDesign/Resources/icons/ZzmDesignWorkbench.svg"
        self.__class__.MenuText = "ZzmDesign"
        self.__class__.ToolTip = "ZzmDesign workbench"

    def Initialize(self):
        # load the module
        import ZzmDesignGui

    def GetClassName(self):
        return "ZzmDesignGui::Workbench"

Gui.addWorkbench(ZzmDesignWorkbench())
