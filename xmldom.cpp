#include "xmldom.h"
#include <iostream>
#include <QDebug>
using namespace std;

Xml_Dom::Xml_Dom(const QString file) : QWidget()
{
    QDomDocument dom("mon_xml");
    QFile xml_doc(file);
    if(!xml_doc.open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return;
    }
    if (!dom.setContent(&xml_doc))
    {
        xml_doc.close();
        QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
        return;
    }
    QDomElement dom_element = dom.documentElement();
    QDomNode noeud = dom_element.firstChild();
    QDomElement element = noeud.toElement();
    while(!noeud.isNull())
    {
        if(!element.isNull())
            noeuds[element.tagName()].append(element.text());
        noeud = noeud.nextSibling();
        element = noeud.toElement();
        //qDebug() << element.tagName();
    }

}

Xml_Dom::~Xml_Dom()
{

}

const QString Xml_Dom::getNoeud(const QString noeud) const
{
    return noeuds.value(noeud);
}
