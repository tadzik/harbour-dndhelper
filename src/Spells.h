#ifndef SPELLS_H
#define SPELLS_H

#include <QObject>
#include <QPointer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>

class Spells : public QSortFilterProxyModel {
    Q_OBJECT

    QSqlTableModel *tableModel;
    QSqlQuery fullTextSearchQuery;

public:
    explicit Spells(QObject *parent = 0) : QSortFilterProxyModel(parent)
    {
        tableModel = new QSqlTableModel(this, QSqlDatabase());
        tableModel->setTable("spell");
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tableModel->select();
        this->setSourceModel(tableModel);
        this->setFilterKeyColumn(1);
        this->sort(2, Qt::AscendingOrder);
        fullTextSearchQuery.prepare("SELECT full_text FROM spell WHERE name = ? LIMIT 1");
    }

    virtual QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex&, int) const;
    bool lessThan(const QModelIndex&, const QModelIndex&) const;

    Q_INVOKABLE void search(QString);
    Q_INVOKABLE QString getFullText(QString);
};

#endif
