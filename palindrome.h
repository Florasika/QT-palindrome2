#ifndef ESSAI_H
#define ESSAI_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>


class Palindrome : public QWidget
{
    Q_OBJECT
private:
    /*
     *Dans le but de rendre les test plus simples et l'application
     *Plus facile d'utilisation nous avons choisi de ne pas mettre
     *de bouton valider, mais un evenement TexteChange pour surveiller
     *La zone d'entrée et afficher un résultat
     *  en temps réel
    */
    QLineEdit *texte;
    QLabel *palindrome;
    QFormLayout *form;

public slots:
    void fonction();

public:
    Palindrome();
    bool isPalindrome (const QString& s) const;
};

#endif // ESSAI_H
