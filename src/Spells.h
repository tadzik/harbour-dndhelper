#ifndef SPELLS_H
#define SPELLS_H

#include <QObject>
#include <QPointer>
#include <QSqlQuery>
#include <QSqlTableModel>

class Spells : public QSqlTableModel {
    Q_OBJECT

    QSqlQuery fullTextSearchQuery;
    virtual QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;

public:
    explicit Spells(QObject* = 0)
    {
        setTable("spell");
        setEditStrategy(QSqlTableModel::OnManualSubmit);
        setSort(1, Qt::AscendingOrder);
        select();
        setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
        setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
        //nameSearchQuery.prepare("SELECT name FROM spell WHERE altname LIKE ? ORDER BY name");
        fullTextSearchQuery.prepare("SELECT full_text FROM spell WHERE name = ? LIMIT 1");
    }

    Q_INVOKABLE void search(QString);
    Q_INVOKABLE QString getFullText(QString);

    enum ERoles {

    };
};

#endif
