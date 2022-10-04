#ifndef ALBUM_H
#define ALBUM_H

#include <QObject>
#include <QDate>
class Album
{
private:
    QString bandName;
    QString albumName;
    QDate releaseDate;
    QString Notes;
public:
    Album();
    const QString &getBandName() const;
    void setBandName(const QString &newBandName);
    const QString &getAlbumName() const;
    void setAlbumName(const QString &newAlbumName);
    const QDate &getReleaseDate() const;
    void setReleaseDate(const QDate &newReleaseDate);
    const QString &getNotes() const;
    void setNotes(const QString &newNotes);
};

#endif // ALBUM_H
