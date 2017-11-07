/***************************************************************************
    Copyright (C) 2017 by ZhaoDongshuang
    Author: ZhaoDongshuang
    Email: imtoby@126.com
    Date: 2017/11/07
    File: TestItem.cpp
 ***************************************************************************/
#include "TestItem.h"

#include "Config.h"

class TestItemPrivate
{
public:
    TestItemPrivate(TestItem *parent)
        : q_ptr(parent)
        , name("test")
    {}

private:
    TestItem * const q_ptr;
    Q_DECLARE_PUBLIC(TestItem)

    QString name;
};

TestItem::TestItem(QObject *parent) :
    QObject(parent) ,
    d_ptr(new TestItemPrivate(this))
{
}

TestItem::~TestItem()
{
}

TestItem::TestItem(const TestItem &other, QObject *parent) :
    QObject(parent) ,
    d_ptr(new TestItemPrivate(this))
{
    d_ptr.swap(const_cast< QScopedPointer<TestItemPrivate>&>(other.d_ptr));
}

TestItem &TestItem::operator=(const TestItem &other)
{
    d_ptr.swap(const_cast< QScopedPointer<TestItemPrivate>&>(other.d_ptr));
    return *this;
}

QString TestItem::name() const
{
    C_D(TestItem);
    return d->name;
}

void TestItem::setName(const QString& name)
{
    Q_D(TestItem);
    if (name != d->name) {
        d->name = name;
        emit nameChanged();
    }
}
