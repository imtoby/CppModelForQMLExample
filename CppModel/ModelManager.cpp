/***************************************************************************
    Copyright (C) 2017 by ZhaoDongshuang
    Author: ZhaoDongshuang
    Email: imtoby@126.com
    Date: 2017/11/07
    File: ModelManager.cpp
 ***************************************************************************/
#include "ModelManager.h"
#include <QThread>

#include "TestItem.h"

class ModelManagerPrivate
{
public:
    ModelManagerPrivate(ModelManager *parent)
        : q_ptr(parent)
        , objectModel(NULL)
    {
    }

    void init();
    void uninit();

private:
    ModelManager * const q_ptr;
    Q_DECLARE_PUBLIC(ModelManager)

    ObjectModel* objectModel;
    QThread workerThread;
};

ModelManager::ModelManager(QObject *parent) :
    QObject(parent),
    d_ptr(new ModelManagerPrivate(this))
{
    Q_D(ModelManager);
    d->init();
}

ModelManager::~ModelManager()
{
    Q_D(ModelManager);
    d->uninit();
}

void ModelManager::initData()
{
    Q_D(ModelManager);
    QObjectList testItemList;
    for (int i=0; i<500; ++i) {
        TestItem* newTestItem = new TestItem(this);
        testItemList.append(newTestItem);
    }
    d->objectModel->set(&testItemList);
}

ObjectModel *ModelManager::objectModel()
{
    Q_D(ModelManager);
    return d->objectModel;
}

void ModelManagerPrivate::init()
{
    Q_Q(ModelManager);
    if (objectModel == NULL) {
        objectModel = new ObjectModel(q);
    }
}

void ModelManagerPrivate::uninit()
{
    if (objectModel) {
        objectModel->deleteLater();
        objectModel = NULL;
    }
}
