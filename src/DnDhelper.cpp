#include <QtQuick>
#include <sailfishapp.h>

#include "Spells.h"
#include <QCoreApplication>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDir>
#include <QFile>

int main(int argc, char *argv[])
{
    qmlRegisterType<Spells>("harbour.dndhelper.spells", 0, 1, "Spells");
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));

    QTextStream out(stdout);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    QString dbfile = SailfishApp::pathTo("qml/dnd35.db").path();
    QDir dbdir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    if (!dbdir.exists()) {
        dbdir.mkpath(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    }
    QFile dbcache(dbdir.path() + "/dnd35.db");
    if (!dbcache.exists()) {
        if (!QFile::copy(dbfile, dbcache.fileName())) {
            out << "Database copying failed, cannot continue :(" << endl;
            return 1;
        }
    }

    db.setDatabaseName(dbfile);
    if (!db.open()) {
        out << "Error reading database: " << db.lastError().text() << endl;
        return 1;
    }

    QScopedPointer<QQuickView> view(SailfishApp::createView());
    view->setSource(SailfishApp::pathTo("qml/DnDhelper.qml"));
    view->show();
    return app->exec();
}
