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
    Xml_Dom();
    ~Xml_Dom();
    void readFile(const QString file);
    void writeFile(const QString file);
    const QString getNoeud(const QString noeud) const;
    void setNoeud(const QString noeud, const QString value);

private:
    QMap<QString, QString> noeuds;
};

#endif // XMLDOM_H
