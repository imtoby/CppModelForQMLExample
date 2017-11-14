/***************************************************************************
    Copyright (C) 2017 by ZhaoDongshuang
    Author: ZhaoDongshuang
    Email: imtoby@126.com
    Date: 2017/11/07
    File: ModelManager.h
 ***************************************************************************/
#ifndef MODELMANAGER_H_0E42B205_5B88_5E39_84B8_6A36CED83E8A
#define MODELMANAGER_H_0E42B205_5B88_5E39_84B8_6A36CED83E8A

#include <QObject>

#include "ObjectModel.h"

class ModelManagerPrivate;

class ModelManager : public QObject
{
    Q_OBJECT
public:
    explicit ModelManager(QObject *parent = 0);
    ~ModelManager();

    Q_INVOKABLE void initData();
    Q_INVOKABLE ObjectModel* objectModel();
    Q_INVOKABLE void testInsert();

private:
    QScopedPointer<ModelManagerPrivate> d_ptr;
    Q_DECLARE_PRIVATE(ModelManager)
};

#endif // MODELMANAGER_H_0E42B205_5B88_5E39_84B8_6A36CED83E8A
