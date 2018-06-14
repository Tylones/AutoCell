#include "xmldom.h"
#include <iostream>
#include <QDebug>
using namespace std;

Xml_Dom::Xml_Dom() : QWidget()
{
}

Xml_Dom::~Xml_Dom()
{

}

void Xml_Dom::readFile(const QString file)
{
    QDomDocument dom("mon_xml");
    QFile xml_doc(file);
    if(!xml_doc.open(QIODevice::ReadOnly))
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
    }
}

void Xml_Dom::writeFile(const QString file)
{
    QDomImplementation impl = QDomDocument().implementation();
    QString name = (file + ".xml");
    QDomDocument doc(impl.createDocumentType(name,"",""));
    QDomElement root = doc.createElement("AutoCell");
    root.setAttribute("name", file);
    doc.appendChild(root);
    QDomElement write_elem;
    for(auto n : noeuds.keys()){
        write_elem = doc.createElement(n);
        write_elem.appendChild(doc.createTextNode(noeuds.value(n)));
        root.appendChild(write_elem);
    }
    QString write_doc = doc.toString();
    QFile fichier(file + ".xml");
    if(!fichier.open(QIODevice::WriteOnly))
    {
        fichier.close();
        QMessageBox::critical(this,"Erreur","Impossible d'écrire dans le document XML");
        return;
    }
    QTextStream stream(&fichier);
    stream << write_doc;
    fichier.close();
}

const QString Xml_Dom::getNoeud(const QString noeud) const
{
    return noeuds.value(noeud);
}

void Xml_Dom::setNoeud(const QString noeud, const QString value)
{
    noeuds.insert(noeud, value);
}
