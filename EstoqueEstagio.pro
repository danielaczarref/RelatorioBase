#-------------------------------------------------
#
# Project created by QtCreator 2019-10-01T11:26:19
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EstoqueEstagio
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cadastro.cpp \
    relatorio.cpp \
    cadastrobase.cpp \
    negocio/cadastrobasenegocio.cpp \
    cadastrofilial.cpp \
    cadastrodepartamento.cpp \
    negocio/cadastrocategoria.cpp \
    negocio/cadastroproduto.cpp \
    negocio/cadastroestoque.cpp \
    cadastrosecao.cpp \
    listfilial.cpp \
    dominio/filial.cpp \
    dominio/departamento.cpp \
    dominio/secao.cpp \
    dominio/categoria.cpp \
    dominio/produto.cpp \
    dominio/estoque.cpp \
    listdepartamento.cpp \
    listsecao.cpp \
    listcategoria.cpp \
    listproduto.cpp \
    listrelatoriobase.cpp \
    dao/estoquedao.cpp \
    negocio/filtro.cpp

HEADERS += \
        mainwindow.h \
    cadastro.h \
    relatorio.h \
    cadastrobase.h \
    negocio/cadastrobasenegocio.h \
    cadastrofilial.h \
    cadastrodepartamento.h \
    negocio/cadastrocategoria.h \
    negocio/cadastroproduto.h \
    negocio/cadastroestoque.h \
    cadastrosecao.h \
    listfilial.h \
    dominio/filial.h \
    dominio/departamento.h \
    dominio/secao.h \
    dominio/categoria.h \
    dominio/produto.h \
    dominio/estoque.h \
    listdepartamento.h \
    listsecao.h \
    listcategoria.h \
    listproduto.h \
    listrelatoriobase.h \
    dao/estoquedao.h \
    negocio/filtro.h

FORMS += \
        mainwindow.ui \
    cadastro.ui \
    relatorio.ui \
    listfilial.ui \
    listdepartamento.ui \
    listsecao.ui \
    listcategoria.ui \
    listproduto.ui \
    listrelatoriobase.ui

DISTFILES +=
