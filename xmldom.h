#ifndef XMLDOM_H
#define XMLDOM_H

#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>
#include <QMap>

class Xml_Dom : public QWidget
{
public:
    Xml_Dom(const QString file);
    ~Xml_Dom();
    const QString getNoeud(const QString noeud) const;
private:
    QMap<QString, QString> noeuds;
};

#endif // XMLDOM_H
