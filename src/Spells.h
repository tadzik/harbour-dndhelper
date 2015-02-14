#ifndef SPELLS_H
#define SPELLS_H

#include <QObject>
#include <QPointer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

class Spells : public QSqlTableModel {
    Q_OBJECT

public:
    explicit Spells(QObject *parent = 0, QSqlDatabase db = QSqlDatabase()) : QSqlTableModel(parent, db)
    {
        setTable("spell");
        setEditStrategy(QSqlTableModel::OnManualSubmit);
        setSort(1, Qt::AscendingOrder);
        select();
        //nameSearchQuery.prepare("SELECT name FROM spell WHERE altname LIKE ? ORDER BY name");
        fullTextSearchQuery.prepare("SELECT full_text FROM spell WHERE name = ? LIMIT 1");
    }

    QSqlQuery fullTextSearchQuery;
    virtual QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void search(QString);
    Q_INVOKABLE QString getFullText(QString);
};

#endif
