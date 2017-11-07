/***************************************************************************
    Copyright (C) 2017 by ZhaoDongshuang
    Author: ZhaoDongshuang
    Email: imtoby@126.com
    Date: 2017/11/07
    File: ObjectModel.h
 ***************************************************************************/
#ifndef OBJECTMODEL_H_2DBDF593_DAA2_5084_8BE0_A727A0C68256
#define OBJECTMODEL_H_2DBDF593_DAA2_5084_8BE0_A727A0C68256

#include <QAbstractListModel>

class ObjectModelPrivate;

typedef QList<QObject* > QObjectList;

class ObjectModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ObjectModel(QObject *parent = 0);
    ~ObjectModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual QHash<int, QByteArray> roleNames() const;

    void insert(int index, QObject* object);
    void append(QObject* object);
    void push_front(QObject* object);
    void push_back(QObject* object);

    void replace(int index, QObject* object);
    void set(QObjectList * objectList);

    void remove(QObject* object);
    void remove(int index);
    void clear();

    QObject * get(int index);
    QObjectList* getAll();

private:
    QScopedPointer<ObjectModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(ObjectModel)
};

#endif // OBJECTMODEL_H_2DBDF593_DAA2_5084_8BE0_A727A0C68256
