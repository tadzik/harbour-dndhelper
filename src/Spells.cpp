#include "Spells.h"
#include <QDebug>

const char* COLUMN_NAMES[] = {
    "id",
    "name",
    "altname",
    "school",
    "subschool",
    "descriptor",
    "spellcraft_dc",
    "level",
    "components",
    "casting_time",
    "range",
    "target",
    "area",
    "effect",
    "duration",
    "saving_throw",
    "spell_resistance",
    "short_description",
    "to_develop",
    "material_components",
    "arcane_material_components",
    "focus",
    "description",
    "xp_cost",
    "arcane_focus",
    "wizard_focus",
    "verbal_components",
    "sorcerer_focus",
    "bard_focus",
    "cleric_focus",
    "druid_focus",
    "full_text",
    "reference",
    NULL
};

QHash<int, QByteArray> makeRoleNames()
{
    int idx = 0;
    QHash<int, QByteArray> roleNames;
    while( COLUMN_NAMES[idx]) {
            roleNames[Qt::UserRole + idx + 1] = COLUMN_NAMES[idx];
            idx++;
    }
    return roleNames;
}

QHash<int, QByteArray> Spells::roleNames() const
{
    static const QHash<int, QByteArray> roleNames = makeRoleNames();
    return roleNames;
}

QVariant Spells::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);
    if(role < Qt::UserRole)
    {
        value = QSqlTableModel::data(index, role);
    }
    else
    {
        const int column = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), column);
        value = QSqlTableModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

void Spells::search(QString q)
{
    setFilter("altname like '%" + q + "%'");
    /*QString param('%');
    param.append(q);
    param.append('%');
    nameSearchQuery.addBindValue(param);
    nameSearchQuery.exec();

    QStringList ret;

    while (nameSearchQuery.next()) {
        ret.append(nameSearchQuery.value(0).toString());
    }

    return ret;
    */
}

QString Spells::getFullText(QString q)
{
    qDebug() << "Looking for '" << q << "'";
    fullTextSearchQuery.addBindValue(q);
    fullTextSearchQuery.exec();
    fullTextSearchQuery.next();
    return fullTextSearchQuery.value(0).toString();
}
