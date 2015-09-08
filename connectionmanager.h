#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include<QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionManager(QObject *parent = 0){

    }
    void sendPost(QString key,QString value) {
        manager = new QNetworkAccessManager(this);
        QNetworkRequest request(QUrl("http://localhost:8888/games/Blackjack/mkv.php"));
        request.setHeader(QNetworkRequest::ContentTypeHeader,
                          "application/x-www-form-urlencoded");
        QUrlQuery postData;
        postData.addQueryItem(key,value);
        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(replyFinished(QNetworkReply*)));
        manager->post(request,postData.toString(QUrl::FullyEncoded).toUtf8());
    }

signals:
    void sendHttpStatusCode(int,QByteArray);

public slots:
    void replyFinished (QNetworkReply *reply) {
        if(reply->error()){
            qDebug() << "ERROR!";
            qDebug() << reply->errorString();
        }else{
            qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
            QByteArray data=reply->readAll();
            qDebug()<<data;
            emit sendHttpStatusCode(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(),data);
        }
        reply->deleteLater();
    }

private:
    QNetworkAccessManager *manager;
};

#endif // CONNECTIONMANAGER_H
