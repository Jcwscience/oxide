#pragma once

#include <QObject>
#include <QQmlApplicationEngine>

class Controller : public QObject
{
    Q_OBJECT

public:
    int protectPid;
    explicit Controller(QQmlApplicationEngine* engine) : QObject(nullptr), _engine(engine), tasks(){
        _sortBy = "name";
    }
    Q_INVOKABLE QList<QObject*> getTasks();
    Q_INVOKABLE void sortBy(QString key);


signals:
    void sortByChanged();
    void reload();

private:
    int is_uint(std::string input);
    QString _sortBy;
    QQmlApplicationEngine* _engine;
    QList<QObject*> tasks;
    void sort();
};
