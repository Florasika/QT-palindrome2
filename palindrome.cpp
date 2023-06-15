#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "palindrome.h"

Palindrome::Palindrome() : QWidget()
{
    //setFixedSize(300,75);

    texte = new QLineEdit;
    texte->setFocus();
    QWidget::connect(texte, SIGNAL(textChanged(QString)), this, SLOT(fonction()));

    palindrome = new QLabel;

    form = new QFormLayout(this);
    form->addRow("&Votre mot :",texte);
    form->addRow("&Résultat :",palindrome);
    setLayout(form);
}

bool Palindrome::isPalindrome (const QString& s) const
{
   int i , l ;
    l =  s.length();
   for ( i = 0 ; i < l / 2 ; i ++ )
   {
     if  ( s [ i ]  != s [ l - i - 1 ]  )  return  false ;
   }
   return  true ;
}

void Palindrome::fonction()
{
    if(texte->text().isEmpty())
    {
        palindrome->setText("");
    }
    else
    {
        QString reponse;
        QString contenu = texte->text();
        contenu = contenu.trimmed();
        bool ok;
        ok = isPalindrome(contenu);
        if(ok)
            reponse = "Ceci est un palindrome";
        else
            reponse = "Ceci n'est pas un palindrome";

        palindrome->setText(reponse);
    }
    texte->setFocus();
}


