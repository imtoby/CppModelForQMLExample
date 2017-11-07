/***************************************************************************
    Copyright (C) 2017 by ZhaoDongshuang
    Author: ZhaoDongshuang
    Email: imtoby@126.com
    Date: 2017/11/07
    File: TestItem.h
 ***************************************************************************/
#ifndef TESTITEM_H_B3E135CE_37B2_5BA7_B57A_AD850A413E91
#define TESTITEM_H_B3E135CE_37B2_5BA7_B57A_AD850A413E91

#include <QObject>

class TestItemPrivate;

class TestItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit TestItem(QObject *parent = 0);
    ~TestItem();

    TestItem(const TestItem &other, QObject *parent = 0);
    TestItem& operator=(const TestItem &other);

    QString name() const;
    void setName(const QString& name);

signals:
    void nameChanged();

private:
    QScopedPointer<TestItemPrivate> d_ptr;
    Q_DECLARE_PRIVATE(TestItem)
};

#endif // TESTITEM_H_B3E135CE_37B2_5BA7_B57A_AD850A413E91
