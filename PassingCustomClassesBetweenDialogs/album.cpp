#include "album.h"

const QString &Album::getBandName() const
{
    return bandName;
}

void Album::setBandName(const QString &newBandName)
{
    bandName = newBandName;
}

const QString &Album::getAlbumName() const
{
    return albumName;
}

void Album::setAlbumName(const QString &newAlbumName)
{
    albumName = newAlbumName;
}

const QDate &Album::getReleaseDate() const
{
    return releaseDate;
}

void Album::setReleaseDate(const QDate &newReleaseDate)
{
    releaseDate = newReleaseDate;
}

const QString &Album::getNotes() const
{
    return Notes;
}

void Album::setNotes(const QString &newNotes)
{
    Notes = newNotes;
}

Album::Album()
{

}
