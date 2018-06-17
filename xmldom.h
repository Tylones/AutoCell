#ifndef XMLDOM_H
#define XMLDOM_H

#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>
#include <QMap>

/*!
* \brief La classe est utilisée pour écrire et lire des fichiers XML
*
*/
class Xml_Dom : public QWidget
{
public:
    Xml_Dom();
    ~Xml_Dom();
    /*!
     * \brief readFile lit le contenu du fichier et remplit la QMap noeuds
     * \param file - QString contenant le nom du fichier
     */
    void readFile(const QString file);
    /*!
     * \brief writeFile écrit le contenu de noeuds dans le fichier XML
     * \param file - QString contenant le nom du fichier
     */
    void writeFile(const QString file);
    /*!
     * \brief getNoeud récupère la valeur associée a la clé "noeud"
     * \param noeud - QString coorespondant à une clé de noeuds
     * \return QString de la valeur associée à "noeud"
     */
    const QString getNoeud(const QString noeud) const;
    /*!
     * \brief setNoeud entre ou remplace une valeur dans la QMap noeuds
     * \param noeud - clé où entrer la valeur
     * \param value - valeur à entrer
     */
    void setNoeud(const QString noeud, const QString value);

private:
    QMap<QString, QString> noeuds;
};

#endif // XMLDOM_H
