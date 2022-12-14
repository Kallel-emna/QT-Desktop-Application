#ifndef CLIENT_H
#define CLIENT_H
#include<QSplashScreen>
#include <QApplication>
#include<QTimer>
#include<QThread>
#include"connection.h"
#include<QMessageBox>
#include<QString>
//#include<QRandomGenerator>
#include<QtGlobal>
#include<qsqlquerymodel.h>
class Client
{
private:
    QString cin,nom,prenom,adresse,num_tel,email,age,rech;
public:
    void set_cin(QString n);
    void set_nom(QString n);
    void set_prenom(QString n);
    void set_adresse(QString n);
    void set_num_tel(QString n);
    void set_email(QString n);
    void set_age(QString n);
    QString get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_num_tel();
    QString get_email();
    QString get_age();
    QString get_rech();
    void ajouter_client(Client c);
    void modifier_client(Client c);
    void supprimer_client(Client c);
    QSqlQueryModel* afficher_client();
    QSqlQueryModel* afficher_client_trie_nom();
    QSqlQueryModel* afficher_client_trie_prenom();
    QSqlQueryModel* afficher_client_trie_age();
    QSqlQueryModel* afficher_client_recherche(QString rech);
    float nbr_fidelite(float prix);
    float nbr_fidelite0();
    void nbr_fidelite2(float prix,QString nom);
    QString coupon_generator() const;
    void decre_pts_fidelite(QString nom);
    Client();
};

#endif // CLIENT_H
