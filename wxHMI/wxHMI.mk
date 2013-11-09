##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=wxHMI
ConfigurationName      :=Debug
WorkspacePath          := "D:\Projects\ws"
ProjectPath            := "D:\Projects\ws\wxHMI"
IntermediateDirectory  :=./Debug/obj
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Andrea
Date                   :=11/09/13
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./Debug/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="wxHMI.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=windres
LinkOptions            :=  $(shell wx-config --libs --debug) -mwindows
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)cndex 
ArLibs                 :=  "cndex.a" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cflags --debug) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/MainFrame$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter_bitmaps$(ObjectSuffix) $(IntermediateDirectory)/c_open$(ObjectSuffix) $(IntermediateDirectory)/c_distinta$(ObjectSuffix) $(IntermediateDirectory)/c_logger$(ObjectSuffix) $(IntermediateDirectory)/c_toolbar$(ObjectSuffix) $(IntermediateDirectory)/c_statusbar$(ObjectSuffix) $(IntermediateDirectory)/c_vclass$(ObjectSuffix) \
	$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug/obj"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/MainFrame$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame$(DependSuffix) -MM "MainFrame.cpp"

$(IntermediateDirectory)/MainFrame$(PreprocessSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame$(PreprocessSuffix) "MainFrame.cpp"

$(IntermediateDirectory)/wxcrafter$(ObjectSuffix): wxcrafter.cpp $(IntermediateDirectory)/wxcrafter$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter$(DependSuffix) -MM "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter$(PreprocessSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter$(PreprocessSuffix) "wxcrafter.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps$(ObjectSuffix): wxcrafter_bitmaps.cpp $(IntermediateDirectory)/wxcrafter_bitmaps$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter_bitmaps$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter_bitmaps$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter_bitmaps$(DependSuffix) -MM "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/wxcrafter_bitmaps$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter_bitmaps$(PreprocessSuffix) "wxcrafter_bitmaps.cpp"

$(IntermediateDirectory)/c_open$(ObjectSuffix): c_open.cpp $(IntermediateDirectory)/c_open$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/c_open.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/c_open$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/c_open$(DependSuffix): c_open.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/c_open$(ObjectSuffix) -MF$(IntermediateDirectory)/c_open$(DependSuffix) -MM "c_open.cpp"

$(IntermediateDirectory)/c_open$(PreprocessSuffix): c_open.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/c_open$(PreprocessSuffix) "c_open.cpp"

$(IntermediateDirectory)/c_distinta$(ObjectSuffix): c_distinta.cpp $(IntermediateDirectory)/c_distinta$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/c_distinta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/c_distinta$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/c_distinta$(DependSuffix): c_distinta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/c_distinta$(ObjectSuffix) -MF$(IntermediateDirectory)/c_distinta$(DependSuffix) -MM "c_distinta.cpp"

$(IntermediateDirectory)/c_distinta$(PreprocessSuffix): c_distinta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/c_distinta$(PreprocessSuffix) "c_distinta.cpp"

$(IntermediateDirectory)/c_logger$(ObjectSuffix): c_logger.cpp $(IntermediateDirectory)/c_logger$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/c_logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/c_logger$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/c_logger$(DependSuffix): c_logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/c_logger$(ObjectSuffix) -MF$(IntermediateDirectory)/c_logger$(DependSuffix) -MM "c_logger.cpp"

$(IntermediateDirectory)/c_logger$(PreprocessSuffix): c_logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/c_logger$(PreprocessSuffix) "c_logger.cpp"

$(IntermediateDirectory)/c_toolbar$(ObjectSuffix): c_toolbar.cpp $(IntermediateDirectory)/c_toolbar$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/c_toolbar.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/c_toolbar$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/c_toolbar$(DependSuffix): c_toolbar.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/c_toolbar$(ObjectSuffix) -MF$(IntermediateDirectory)/c_toolbar$(DependSuffix) -MM "c_toolbar.cpp"

$(IntermediateDirectory)/c_toolbar$(PreprocessSuffix): c_toolbar.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/c_toolbar$(PreprocessSuffix) "c_toolbar.cpp"

$(IntermediateDirectory)/c_statusbar$(ObjectSuffix): c_statusbar.cpp $(IntermediateDirectory)/c_statusbar$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/c_statusbar.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/c_statusbar$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/c_statusbar$(DependSuffix): c_statusbar.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/c_statusbar$(ObjectSuffix) -MF$(IntermediateDirectory)/c_statusbar$(DependSuffix) -MM "c_statusbar.cpp"

$(IntermediateDirectory)/c_statusbar$(PreprocessSuffix): c_statusbar.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/c_statusbar$(PreprocessSuffix) "c_statusbar.cpp"

$(IntermediateDirectory)/c_vclass$(ObjectSuffix): c_vclass.cpp $(IntermediateDirectory)/c_vclass$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projects/ws/wxHMI/c_vclass.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/c_vclass$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/c_vclass$(DependSuffix): c_vclass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/c_vclass$(ObjectSuffix) -MF$(IntermediateDirectory)/c_vclass$(DependSuffix) -MM "c_vclass.cpp"

$(IntermediateDirectory)/c_vclass$(PreprocessSuffix): c_vclass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/c_vclass$(PreprocessSuffix) "c_vclass.cpp"

$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "D:/Projects/ws/wxHMI/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)

-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/MainFrame$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/MainFrame$(DependSuffix)
	$(RM) $(IntermediateDirectory)/MainFrame$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxcrafter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxcrafter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxcrafter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/wxcrafter_bitmaps$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/wxcrafter_bitmaps$(DependSuffix)
	$(RM) $(IntermediateDirectory)/wxcrafter_bitmaps$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/c_open$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/c_open$(DependSuffix)
	$(RM) $(IntermediateDirectory)/c_open$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/c_distinta$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/c_distinta$(DependSuffix)
	$(RM) $(IntermediateDirectory)/c_distinta$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/c_logger$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/c_logger$(DependSuffix)
	$(RM) $(IntermediateDirectory)/c_logger$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/c_toolbar$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/c_toolbar$(DependSuffix)
	$(RM) $(IntermediateDirectory)/c_toolbar$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/c_statusbar$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/c_statusbar$(DependSuffix)
	$(RM) $(IntermediateDirectory)/c_statusbar$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/c_vclass$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/c_vclass$(DependSuffix)
	$(RM) $(IntermediateDirectory)/c_vclass$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/win_resources.rc$(ObjectSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/wxHMI"


