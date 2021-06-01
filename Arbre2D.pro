# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = Arbre2D

QT = core gui widgets

HEADERS = \
   $$PWD/algorithm.hpp \
   $$PWD/astar_algo.hpp \
   $$PWD/bfs_algo.hpp \
   $$PWD/cell.hpp \
   $$PWD/dfs_algo.hpp \
   $$PWD/dijkstra_algo.hpp \
   $$PWD/graph2d.hpp \
   $$PWD/mainwindow.hpp \
   $$PWD/maze_generator.hpp \
   $$PWD/render_area.hpp \
   $$PWD/vec2.hpp

SOURCES = \
   $$PWD/algorithm.cpp \
   $$PWD/astar_algo.cpp \
   $$PWD/bfs_algo.cpp \
   $$PWD/cell.cpp \
   $$PWD/dfs_algo.cpp \
   $$PWD/dijkstra_algo.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp \
   $$PWD/maze_generator.cpp \
   $$PWD/render_area.cpp \
   $$PWD/vec2.cpp

INCLUDEPATH =

#DEFINES = 

FORMS += \
    mainwindow.ui

