/***************************************************************************
    Copyright (C) 2017 by ZhaoDongshuang
    Author: ZhaoDongshuang
    Email: imtoby@126.com
    Date: 2017/11/07
    File: main.cpp
 ***************************************************************************/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>

#include "ModelManager.h"
#include "ObjectModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // 向 QML 域注册 ObjectModel 类
    qmlRegisterUncreatableType<ObjectModel, 1>("com.test.model", 1, 0,
                                               "ObjectModel",
                                               "Cannot create ObjectModel");

    ModelManager* modelMgr = new ModelManager(&app);
    engine.rootContext()->setContextProperty("modelMgr", modelMgr);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // 初始化数据
    modelMgr->initData();

    int r = app.exec();

    if (modelMgr) {
        modelMgr->deleteLater();
        modelMgr = NULL;
    }

    return r;
}
